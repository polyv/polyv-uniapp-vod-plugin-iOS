//
//  PLVVodDownloadModule.m
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/9/7.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodDownloadModule.h"
#import "PLVVodUtils.h"
#import <PLVVodSDK/PLVVodSDK.h>

@interface PLVVodDownloadModule ()
/// 是否已经初始化了下载列表数组
@property (nonatomic, assign) BOOL getDownloadListFinish;
/// getDownloadList 方法的回调（调用该方法时尚未从异步方法里面获取到下载队列时）
@property (nonatomic, copy) WXModuleKeepAliveCallback getDownloadListCallback;
/// 下载信息字典（vid 为键，PLVVodDownloadInfo 对象为值）
@property (nonatomic, strong) NSMutableDictionary<NSString *, PLVVodDownloadInfo *> *downloadInfoDict;
/// 下载信息字典（vid 为键，WXModuleKeepAliveCallback 对象为值）
@property (nonatomic, strong) NSMutableDictionary<NSString *, WXModuleKeepAliveCallback> *callbackDict;
/// 下载进度回调任务队列
@property (nonatomic, strong) dispatch_queue_t serialQueue;
/// 上一次调用完进度变更回调的时间
@property (nonatomic, strong) NSDate *lastTime;
/// 最小下载进度回调间隔
@property (nonatomic, assign) double callbackInterval;

@end

@implementation PLVVodDownloadModule

#pragma mark - Life Cycle

- (instancetype)init {
    self = [super init];
    if (self) {
        [self downloadSetting];
    }
    return self;
}

#pragma mark - Getter & Setter

- (NSMutableDictionary<NSString *, PLVVodDownloadInfo *> *)downloadInfoDict {
    if (!_downloadInfoDict) {
        _downloadInfoDict = [NSMutableDictionary dictionary];
    }
    return _downloadInfoDict;
}

- (NSMutableDictionary<NSString *, WXModuleKeepAliveCallback> *)callbackDict {
    if (!_callbackDict) {
        _callbackDict = [NSMutableDictionary dictionary];
    }
    return _callbackDict;
}

- (void)setGetDownloadListFinish:(BOOL)getDownloadListFinish {
    _getDownloadListFinish = getDownloadListFinish;
    if (getDownloadListFinish && self.getDownloadListCallback) {
        [self getDownloadList:nil callback:self.getDownloadListCallback];
    }
}

#pragma mark - Initialization

- (void)downloadSetting {
    self.serialQueue = dispatch_queue_create("net.polyv.vod", DISPATCH_QUEUE_SERIAL);
    self.lastTime = [NSDate date];
    self.callbackInterval = 1;
    
    __weak typeof(self) weakSelf = self;
    PLVVodDownloadManager *downloadManager = [PLVVodDownloadManager sharedManager];
    
    // 获取所有下载任务信息(缓冲中，已缓存)
    [downloadManager requestDownloadInfosWithCompletion:^(NSArray<PLVVodDownloadInfo *> *downloadInfos) {
        for (PLVVodDownloadInfo *info in downloadInfos) {
            weakSelf.downloadInfoDict[info.vid] = info;
        }
        weakSelf.getDownloadListFinish = YES;
    }];
    
    // 单个视频下载完成回调
    downloadManager.downloadCompleteBlock = ^(PLVVodDownloadInfo *info) {
        WXModuleKeepAliveCallback callback = weakSelf.callbackDict[info.vid];
        if (callback) {
            NSDictionary *retValue = @{@"downloadStatus": @"finished", @"downloadPercentage": @(100)};
            NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:info.vid];
            callback(ret, NO);
            [weakSelf.callbackDict removeObjectForKey:info.vid];
        }
    };
    
    // 下载错误统一回调
    downloadManager.downloadErrorHandler = ^(PLVVodVideo *video, NSError *error) {
        if (video && weakSelf.downloadInfoDict[video.vid]) {
            WXModuleKeepAliveCallback callback = weakSelf.callbackDict[video.vid];
            if (callback) {
                NSDictionary *retValue = @{@"downloadStatus": @"failed", @"errMsg": error.localizedDescription};
                NSDictionary *ret = @{video.vid: retValue};
                callback(ret, YES);
            }
        }
    };
}

#pragma mark - Public

WX_EXPORT_METHOD(@selector(getDownloadList:callback:))

- (void)getDownloadList:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (!callback) {
        return;
    }
    
    if (!self.getDownloadListFinish) {
        self.getDownloadListCallback = callback;
        return;
    }
    
    NSMutableArray *downloadList = [NSMutableArray array];
    for (NSString *vid in self.downloadInfoDict) {
        PLVVodDownloadInfo *downloadInfo = self.downloadInfoDict[vid];
        //新增下载列表数据返回信息
        NSDictionary *subDict = [PLVVodDownloadModule
                             formatDownloadInfoToDictionary:downloadInfo];
        [downloadList addObject:subDict];
    }
    
    NSDictionary *ret = [NSDictionary dictionaryWithObject:downloadList forKey:@"downloadList"];
    callback(ret, NO);
}

WX_EXPORT_METHOD(@selector(addDownloader:callback:))

- (void)addDownloader:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSArray *downloadArr = options[@"downloadArr"];
    if (!downloadArr || ![downloadArr isKindOfClass:[NSArray class]] || [downloadArr count] == 0) {
        return;
    }
    
    for (NSDictionary *dict in downloadArr) {
        if (!dict || ![dict isKindOfClass:[NSDictionary class]] || dict.count == 0) {
            continue;
        }
        
        NSString *vid = [PLVVodUtils stringValueWithDictionary:dict forKey:@"vid" defaultValue:nil];
        if (![PLVVodUtils isValidString:vid]) {
            continue;
        }
        
        if (![PLVVodUtils validateVid:vid]) {
            if (callback) {
                NSDictionary *retValue = @{@"errMsg": @"vid无效"};
                NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:vid];
                callback(ret, NO);
            }
            continue;
        }
        
        // ----- 判断该 vid 视频是否已存在
        if (self.downloadInfoDict[vid]) {
            continue;
        }
        
        NSInteger level = [dict[@"level"] integerValue];
        if (level < 1 || level > 3) {
            if (callback) {
                NSDictionary *retValue = @{@"errMsg": @"请传入正确的码率"};
                NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:vid];
                callback(ret, NO);
            }
            continue;
        }
        
        __weak typeof(self) weakSelf = self;
        [PLVVodVideo requestVideoPriorityCacheWithVid:vid completion:^(PLVVodVideo *video, NSError *error) {
            if (callback) {
                if (error || video == nil || !video.available) {
                    NSDictionary *retValue = @{@"errMsg": @"下载器创建失败"};
                    NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:vid];
                    callback(ret, NO);
                } else {
                    PLVVodDownloadInfo *downloadInfo = [[PLVVodDownloadManager sharedManager] downloadVideo:video quality:level];
                    if (downloadInfo) {
                        weakSelf.callbackDict[vid] = callback;
                        downloadInfo.progressDidChangeBlock = ^(PLVVodDownloadInfo *info) {
                            [weakSelf downloadProgressChanged:info];
                        };
                        downloadInfo.stateDidChangeBlock = ^(PLVVodDownloadInfo *info) {
                            [weakSelf downloadStatusChanged:info];
                        };
                        weakSelf.downloadInfoDict[vid] = downloadInfo;
                    } else {
                        PLVVodQuality videoQuality = [PLVVodDownloadManager videoExist:vid];
                        if (videoQuality > 0) {
                            downloadInfo = [[PLVVodDownloadManager sharedManager] requestDownloadInfoWithVid:vid];
                            weakSelf.downloadInfoDict[downloadInfo.vid] = downloadInfo;
                            NSDictionary *retValue = @{@"downloadStatus": @"finished", @"downloadPercentage": @(100)};
                            NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:vid];
                            callback(ret, NO);
                        } else {
                            NSDictionary *retValue = @{@"errMsg": @"下载器创建失败"};
                            NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:vid];
                            callback(ret, NO);
                        }
                    }
                }
            }
        }];
    }
}

WX_EXPORT_METHOD(@selector(setDownloadCallbackInterval:))

- (void)setDownloadCallbackInterval:(NSDictionary *)options {
    double interval = [options[@"seconds"] doubleValue];
    self.callbackInterval = (interval > 0) ? interval : 1;
}

WX_EXPORT_METHOD_SYNC(@selector(isVideoExist:))

- (NSDictionary *)isVideoExist:(NSDictionary *)options {
    NSString *errMsg = nil;
    
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils validateVid:vid]) {
        errMsg = @"vid无效";
    }
    
    NSInteger level = [options[@"level"] integerValue];
    if (level < 1 || level > 3) {
        errMsg = @"请传入正确的码率";
    }
    
    NSDictionary *ret = nil;
    if (errMsg) {
        ret = @{@"errMsg": errMsg};
    } else {
        PLVVodQuality videoQuality = [PLVVodDownloadManager videoExist:vid];
        ret = @{@"exist": @(videoQuality == level)};
    }
    return ret;
}

WX_EXPORT_METHOD(@selector(startDownloader:callback:))

- (void)startDownloader:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils isValidString:vid]) {
        if (callback) {
            callback(@{@"errMsg": @"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid": vid, @"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    __weak typeof(self) weakSelf = self;
    [[PLVVodDownloadManager sharedManager] startDownloadWithVid:vid];
    PLVVodDownloadInfo *downloadInfo = [[PLVVodDownloadManager sharedManager] requestDownloadInfoWithVid:vid];
    downloadInfo.progressDidChangeBlock = ^(PLVVodDownloadInfo *info) {
        [weakSelf downloadProgressChanged:info];
    };
    downloadInfo.stateDidChangeBlock = ^(PLVVodDownloadInfo *info) {
        [weakSelf downloadStatusChanged:info];
    };
    self.downloadInfoDict[vid] = downloadInfo;
}

WX_EXPORT_METHOD(@selector(startAllDownloader))

- (void)startAllDownloader {
    [[PLVVodDownloadManager sharedManager] startDownload];
    
    __weak typeof(self) weakSelf = self;
    [[PLVVodDownloadManager sharedManager] requstDownloadProcessingListWithCompletion:^(NSArray<PLVVodDownloadInfo *> *downloadInfos) {
        for (PLVVodDownloadInfo *downloadInfo in downloadInfos) {
            downloadInfo.progressDidChangeBlock = ^(PLVVodDownloadInfo *info) {
                [weakSelf downloadProgressChanged:info];
            };
            downloadInfo.stateDidChangeBlock = ^(PLVVodDownloadInfo *info) {
                [weakSelf downloadStatusChanged:info];
            };
            weakSelf.downloadInfoDict[downloadInfo.vid] = downloadInfo;
        }
    }];
}

WX_EXPORT_METHOD(@selector(stopDownloader:callback:))

- (void)stopDownloader:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils isValidString:vid]) {
        if (callback) {
            callback(@{@"errMsg": @"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid": vid, @"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    [[PLVVodDownloadManager sharedManager] stopDownloadWithVid:vid autoNext:NO];
}

WX_EXPORT_METHOD(@selector(stopAllDownloader))

- (void)stopAllDownloader {
    [[PLVVodDownloadManager sharedManager] stopDownload];
}

WX_EXPORT_METHOD(@selector(deleteVideo:callback:))

- (void)deleteVideo:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils isValidString:vid]) {
        if (callback) {
            callback(@{@"errMsg": @"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid": vid, @"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    [PLVVodDownloadManager removeVideoWithVid:vid error:nil];
    [[PLVVodDownloadManager sharedManager] removeDownloadWithVid:vid error:nil];
    [self.downloadInfoDict removeObjectForKey:vid];
}

WX_EXPORT_METHOD(@selector(deleteAllVideo))

- (void)deleteAllVideo {
    [PLVVodDownloadManager removeAllVideoWithError:nil];
    [[PLVVodDownloadManager sharedManager] removeAllDownloadWithComplete:nil];
    [self.downloadInfoDict removeAllObjects];
}

//监听所有下载事件状态
WX_EXPORT_METHOD(@selector(setListenDownloadStatus:callback:))

- (void)setListenDownloadStatus:(NSDictionary *)options
                       callback:(WXModuleKeepAliveCallback)callback {
    if (!callback) return;
    
    if (!self.getDownloadListFinish) {
        self.getDownloadListCallback = callback;
        return;
    }
    
    __weak typeof(self) weakSelf = self;
    for (NSString *vid in self.downloadInfoDict) {
        PLVVodDownloadInfo *downloadInfo = self.downloadInfoDict[vid];
        weakSelf.callbackDict[vid] = callback;
        downloadInfo.progressDidChangeBlock = ^(PLVVodDownloadInfo *info) {
            [weakSelf downloadProgressChanged:info];
        };
        downloadInfo.stateDidChangeBlock = ^(PLVVodDownloadInfo *info) {
            [weakSelf downloadStatusChanged:info];
        };
    }
}

#pragma mark - Private

- (void)downloadProgressChanged:(PLVVodDownloadInfo *)info {
    __weak typeof(self) weakSelf = self;
    dispatch_async(self.serialQueue, ^{
        double timeDiff = [[NSDate date] timeIntervalSinceDate:weakSelf.lastTime];
        if (timeDiff > weakSelf.callbackInterval || info.progress >= 1) {
            weakSelf.lastTime = [NSDate date];
            WXModuleKeepAliveCallback callback = weakSelf.callbackDict[info.vid];
            if (callback) {
                NSMutableDictionary *retValue = [[NSMutableDictionary alloc] init];
                retValue[@"downloadPercentage"] = @(info.progress * 100);
                NSString *statusStr = [self statusStringWithStatus:info.state];
                if (statusStr) {
                    retValue[@"downloadStatus"] = statusStr;
                }
                NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:info.vid];
                callback(ret, YES);
            }
        }
    });
}

- (void)downloadStatusChanged:(PLVVodDownloadInfo *)info {
    NSString *statusStr = [self statusStringWithStatus:info.state];
    if (!statusStr) {
        return;
    }
    
    WXModuleKeepAliveCallback callback = self.callbackDict[info.vid];
    if (callback) {
        NSDictionary *retValue = @{@"downloadStatus": statusStr};
        NSDictionary *ret = [NSDictionary dictionaryWithObject:retValue forKey:info.vid];
        BOOL keep = (info.state != PLVVodDownloadStateSuccess);
        if (!keep) {
            [self.callbackDict removeObjectForKey:info.vid];
        }

        if (self.callbackDict.allKeys.count>0) {
            callback(ret, YES);
        } else {
            callback(ret, NO);
        }
    }
}

- (NSString *)statusStringWithStatus:(PLVVodDownloadState)status {
    NSString *statusStr = nil;
    if (status == PLVVodDownloadStatePreparing ||
        status == PLVVodDownloadStatePreparingStart ||
        status == PLVVodDownloadStateReady) {
        statusStr = @"ready";
    } else if (status == PLVVodDownloadStateRunning) {
        statusStr = @"downloading";
    } else if (status == PLVVodDownloadStateStopped ||
               status == PLVVodDownloadStateStopping) {
        statusStr = @"stopped";
    } else if (status == PLVVodDownloadStateSuccess) {
        statusStr = @"finished";
    } else if (status == PLVVodDownloadStateFailed) {
        statusStr = @"failed";
    }
    return statusStr;
}
+ (NSMutableDictionary *)formatDownloadInfoToDictionary:(PLVVodDownloadInfo *)info {
    NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
    dic[@"vid"] = info.vid;
    dic[@"duration"] = @(info.duration);
    dic[@"title"] = info.title;
    dic[@"progress"] = @(info.progress);
    dic[@"fileSize"] = @(info.filesize);
    dic[@"level"]=@(info.quality);
    
    return dic;
}

@end

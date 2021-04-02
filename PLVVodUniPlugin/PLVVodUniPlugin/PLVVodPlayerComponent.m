//
//  PLVVodPlayerComponent.m
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/9/1.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodPlayerComponent.h"
#import "WeexSDK.h"
#import "WXConvert.h"
#import "PLVVodUtils.h"
#import "PLVVodConfig.h"
#import "PLVMarquee.h"
#import <PLVVodSDK/PLVVodSDK.h>
#import <Photos/Photos.h>

static NSString *kPlayStatusEvent = @"onPlayStatus";
static NSString *kPositionChangeEvent = @"positionChange";
static NSString *kPlayErrorEvent = @"onPlayError";

typedef NS_ENUM(NSInteger, PLVUniPlaybackState) {
    PLVUniPlaybackStateUnknow = 0,
    PLVUniPlaybackStateStart,
    PLVUniPlaybackStatePause,
    PLVUniPlaybackStateStop,
    PLVUniPlaybackStateComplete
};

typedef NS_ENUM(NSInteger, PLVUniPlayErrorType) {
    PLVUniPlayErrorTypeUnConfig = 0,
    PLVUniPlayErrorTypeIllegalVid,
    PLVUniPlayErrorTypePlayError
};

@interface PLVVodPlayerComponent ()

// 不带皮肤播放器
@property (nonatomic, strong) PLVVodPlayerViewController *videoPlayer;

// 打开时是否自动播放，默认 YES
@property (nonatomic, assign) BOOL autoPlay;
// seek 类型，0 为根据关键帧 seek（默认），1 为精准 seek
@property (nonatomic, assign) NSInteger seekType;
// 是否开启防录屏。默认为NO，不开启
@property (nonatomic, assign) BOOL disableScreenCAP;
// 是否开启记忆播放位置，默认 NO
@property (nonatomic, assign) BOOL rememberLastPosition;

/// 前端注册的播放状态事件监听
@property (nonatomic, assign) BOOL onPlayStatus;
/// 防止快进、快退、seek 时重复发送 start 事件
@property (nonatomic, assign) BOOL notSendStartEvent;
/// 用于用户触发 stop 方法的时候 ，阻止原生 pause 状态的回调，替换成 stop
@property (nonatomic, assign) BOOL stopEvent;

/// 前端注册的播放出错事件监听
@property (nonatomic, assign) BOOL onPlayError;

/// 前端注册的播放进度变更事件监听，一秒钟回调一次
@property (nonatomic, assign) BOOL positionChange;
/// positionChange事件定时器
@property (nonatomic, strong) NSTimer *positionEventTimer;

@end

@implementation PLVVodPlayerComponent

#pragma mark - Life Cycle

- (instancetype)initWithRef:(NSString *)ref type:(NSString *)type styles:(NSDictionary *)styles attributes:(NSDictionary *)attributes events:(NSArray *)events weexInstance:(WXSDKInstance *)weexInstance {
    if (self = [super initWithRef:ref type:type styles:styles attributes:attributes events:events weexInstance:weexInstance]) {
        if (attributes[@"autoPlay"]) {
            _autoPlay = [WXConvert BOOL: attributes[@"autoPlay"]];
        } else {
            _autoPlay = YES;
        }
        
        if (attributes[@"seekType"]) {
            _seekType = [WXConvert NSInteger: attributes[@"seekType"]];
        }
        if (_seekType != 1) {
            _seekType = 0;
        }
        
        if (attributes[@"disableScreenCAP"]) {
            _disableScreenCAP = [WXConvert BOOL: attributes[@"disableScreenCAP"]];
        } else {
            _disableScreenCAP = NO;
        }
        
        if (attributes[@"rememberLastPosition"]) {
            _rememberLastPosition = [WXConvert BOOL: attributes[@"rememberLastPosition"]];
        } else {
            _rememberLastPosition = NO;
        }
    }
    return self;
}

- (UIView *)loadView {
    self.videoPlayer = [[PLVVodPlayerViewController alloc] init];
    return self.videoPlayer.view;
}

- (void)viewDidLoad {
    self.videoPlayer.autoplay = _autoPlay;
    self.videoPlayer.seekType = _seekType;
    self.videoPlayer.videoCaptureProtect = _disableScreenCAP;
    self.videoPlayer.rememberLastPosition = _rememberLastPosition;
    self.videoPlayer.isVideoToolBox = [PLVVodConfig sharedConfig].isVideoToolBox;
    
    __weak typeof(self) weakSelf = self;
    self.videoPlayer.playbackStateHandler = ^(PLVVodPlayerViewController *player) {
        PLVUniPlaybackState state = PLVUniPlaybackStateUnknow;
        switch (player.playbackState) {
            case PLVVodPlaybackStateStopped:
                state = PLVUniPlaybackStateStop;
                break;
            case PLVVodPlaybackStatePlaying:
                if (weakSelf.notSendStartEvent) {
                    weakSelf.notSendStartEvent = NO;
                } else {
                    state = PLVUniPlaybackStateStart;
                }
                break;
            case PLVVodPlaybackStatePaused:
                state = weakSelf.stopEvent ? PLVUniPlaybackStateStop : PLVUniPlaybackStatePause;
                weakSelf.stopEvent = NO;
                break;
            default:
                break;
        }
        if (weakSelf.onPlayStatus && state != PLVUniPlaybackStateUnknow) {
            NSString *playbackState = [weakSelf playbackStateStringWithType:state];
            if (playbackState) {
                [weakSelf fireEvent:kPlayStatusEvent params:@{@"detail":@{@"playbackState":playbackState}} domChanges:nil];
            }
        }
    };
    
    self.videoPlayer.reachEndHandler = ^(PLVVodPlayerViewController *player) {
        if (weakSelf.onPlayStatus) {
            NSString *playbackState = [weakSelf playbackStateStringWithType:PLVUniPlaybackStateComplete];
            if (playbackState) {
                [weakSelf fireEvent:kPlayStatusEvent params:@{@"detail":@{@"playbackState":playbackState}} domChanges:nil];
            }
        }
    };
    
    self.videoPlayer.preparedToPlayHandler = ^(PLVVodPlayerViewController *player) {
        if (weakSelf.onPlayStatus) {
            [weakSelf fireEvent:kPlayStatusEvent params:@{@"detail":@{@"preparedToPlay":@(player.preparedToPlay)}} domChanges:nil];
        }
    };
}

- (void)viewWillUnload {
    [self removeTimer];
}

#pragma mark - 前端事件

/// 前端注册的事件会调用此方法
/// @param eventName 事件名称
- (void)addEvent:(NSString *)eventName {
    if ([eventName isEqualToString:kPlayStatusEvent]) {
        _onPlayStatus = YES;
    } else if ([eventName isEqualToString:kPositionChangeEvent]) {
        _positionChange = YES;
        [self addTimer];
    } else if ([eventName isEqualToString:kPlayErrorEvent]) {
        _onPlayError = YES;
    }
}

/// 对应的移除事件回调方法
/// @param eventName 事件名称
- (void)removeEvent:(NSString *)eventName {
    if ([eventName isEqualToString:kPlayStatusEvent]) {
        _onPlayStatus = NO;
    } else if ([eventName isEqualToString:kPositionChangeEvent]) {
       _positionChange = NO;
        [self removeTimer];
    } else if ([eventName isEqualToString:kPlayErrorEvent]) {
       _onPlayError = NO;
    }
}

#pragma mark - Public

WX_EXPORT_METHOD(@selector(setVid:callback:))

- (void)setVid:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *userId = [PLVVodSettings sharedSettings].userid;
    if (![PLVVodUtils isValidString:userId]) {
        PLVUniPlayErrorType type = PLVUniPlayErrorTypeUnConfig;
        NSString *status = [self playErrorStringWithType:type];
        if (status && _onPlayError) {
            [self fireEvent:kPlayErrorEvent params:@{@"detail":@{@"errCode":@(type), @"errEvent": status}} domChanges:nil];
        }
        return;
    }
    
    NSString *vid = options[@"vid"];
    if (![PLVVodUtils isValidString:vid]) {
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid":vid, @"errMsg": @"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils isVideoArrowPlay:vid]) {
        PLVUniPlayErrorType type = PLVUniPlayErrorTypeIllegalVid;
        NSString *status = [self playErrorStringWithType:type];
        if (status && _onPlayError) {
            [self fireEvent:kPlayErrorEvent params:@{@"detail":@{@"errCode":@(type), @"errEvent": status}} domChanges:nil];
        }
        return;
    }
    
    __weak typeof(self) weakSelf = self;
    [PLVVodVideo requestVideoPriorityCacheWithVid:vid completion:^(PLVVodVideo *video, NSError *error) {
        if (error) {
            PLVUniPlayErrorType type = PLVUniPlayErrorTypePlayError;
            NSString *status = [weakSelf playErrorStringWithType:type];
            NSString *statusWithCode = [NSString stringWithFormat:@"%@(#%zd)", status, error.code];
            if (status && weakSelf.onPlayError) {
                [weakSelf fireEvent:kPlayErrorEvent params:@{@"detail":@{@"errCode":@(type), @"errEvent": statusWithCode}} domChanges:nil];
            }
        } else {
            NSInteger level = [options[@"level"] integerValue];
            if ((level < 0 || level > 3)) {
                if (callback) {
                    callback(@{@"vid":vid, @"errMsg": @"请传入正确的码率！"}, NO);
                }
            } else {
                if (level == 0) {
                    [weakSelf.videoPlayer setVideo:video];
                } else {
                    [weakSelf.videoPlayer setVideo:video quality:level];
                }
            }
        }
    }];
}

WX_EXPORT_METHOD(@selector(setURL:callback:))

- (void)setURL:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *urlString = options[@"url"];
    if (![PLVVodUtils isValidString:urlString]) {
        return;
    }
    
    if (![PLVVodUtils validateUrlString:urlString]) {
        if (callback) {
            callback(@{@"url":urlString, @"errMsg": @"url无效"}, NO);
        }
        return;
    }
    
    self.videoPlayer.video = nil;
    NSURL *url = [NSURL URLWithString:urlString];
    [self.videoPlayer setURL:url];
}

WX_EXPORT_METHOD(@selector(changeToPortrait))

- (void)changeToPortrait {
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    BOOL isPortrait = UIInterfaceOrientationIsPortrait(orientation);
    if (!isPortrait) {
        [self rotateOrientation:UIInterfaceOrientationPortrait];
    }
}

WX_EXPORT_METHOD(@selector(changeToLandscape))

- (void)changeToLandscape {
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    BOOL isPortrait = UIInterfaceOrientationIsPortrait(orientation);
    if (isPortrait) {
        [self rotateOrientation:UIInterfaceOrientationLandscapeLeft];
    }
}

/// 旋转设备到指定方向
- (void)rotateOrientation:(UIInterfaceOrientation)orientation {
    if ([[UIDevice currentDevice] respondsToSelector:@selector(setOrientation:)]) {
        SEL selector = NSSelectorFromString(@"setOrientation:");
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:[UIDevice instanceMethodSignatureForSelector:selector]];
        [invocation setSelector:selector];
        [invocation setTarget:[UIDevice currentDevice]];
        int val = (int)orientation;
        [invocation setArgument:&val atIndex:2];
        [invocation invoke];
    }
}

WX_EXPORT_METHOD(@selector(start))

- (void)start {
    [self.videoPlayer play];
}

WX_EXPORT_METHOD(@selector(pause))

- (void)pause {
    [self.videoPlayer pause];
}

WX_EXPORT_METHOD(@selector(stop))

- (void)stop {
    self.stopEvent = YES;
    [self.videoPlayer setCurrentPlaybackTime:0];
    [self.videoPlayer pause];
}

WX_EXPORT_METHOD(@selector(forward:))

- (void)forward:(NSDictionary *)options {
    self.notSendStartEvent = YES;
    CGFloat seconds = [options[@"seconds"] floatValue];
    NSTimeInterval currentPlaybackTime = self.videoPlayer.currentPlaybackTime;
    if (seconds > 0) {
        NSTimeInterval jump = MIN(self.videoPlayer.duration, currentPlaybackTime + seconds);
        [self.videoPlayer setCurrentPlaybackTime:jump];
    }
}

WX_EXPORT_METHOD(@selector(rewind:))

- (void)rewind:(NSDictionary *)options {
    self.notSendStartEvent = YES;
    CGFloat seconds = [options[@"seconds"] floatValue];
    NSTimeInterval currentPlaybackTime = self.videoPlayer.currentPlaybackTime;
    if (seconds > 0) {
        NSTimeInterval jump = MAX(0, currentPlaybackTime - seconds);
        [self.videoPlayer setCurrentPlaybackTime:jump];
    }
}

WX_EXPORT_METHOD(@selector(seekTo:))

- (void)seekTo:(NSDictionary *)options {
    self.notSendStartEvent = YES;
    CGFloat seconds = [options[@"seconds"] floatValue];
    if (seconds >= 0) {
        NSTimeInterval jump = MIN(self.videoPlayer.duration, seconds);
        [self.videoPlayer setCurrentPlaybackTime:jump];
    }
}

WX_EXPORT_METHOD(@selector(isPlaying:callback:))

- (void)isPlaying:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        BOOL isPlaying = self.videoPlayer.playbackState == PLVVodPlaybackStatePlaying;
        callback(@{@"isPlaying": @(isPlaying)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(showMarquee:))

- (void)showMarquee:(NSDictionary *)options {
    NSString *content = [PLVVodUtils stringValueWithDictionary:options forKey:@"marquee" defaultValue:@"Polyv uni-app Plugin"];
    NSString *color = [PLVVodUtils stringValueWithDictionary:options forKey:@"color" defaultValue:@"0xFFE900"];
    
    CGFloat duration = [options[@"duration"] floatValue];
    if (duration == 0) {
        duration = 10;
    }
    CGFloat interval = [options[@"interval"] floatValue];

    CGFloat alpha = [options[@"alpha"] floatValue];
    if (alpha == 0) {
        alpha = 1;
    }
    NSInteger font = [options[@"font"] integerValue];
    if (font == 0) {
        font = 16;
    }
    
    // 限制字体、alpha值的上下限
    font = MIN(MAX(5, font), 72);
    alpha = MIN(MAX(0, alpha), 1);
    
    // 初始化跑马灯
    PLVMarquee *marquee = [[PLVMarquee alloc] init];
    marquee.type = PLVMarqueeTypeRoll;
    marquee.timeIntervalConstant = YES;
    
    // 根据参数配置跑马灯
    marquee.content = content;
    marquee.displayDuration = duration;
    marquee.maxRollInterval = interval;
    marquee.color = [PLVVodUtils colorWithHexString:color alpha:1];
    marquee.alpha = alpha;
    marquee.font = [UIFont systemFontOfSize:font];
    
    //设置跑马灯
    [self.videoPlayer setMarquee:marquee];
}

WX_EXPORT_METHOD(@selector(setVolume:))

- (void)setVolume:(NSDictionary *)options {
    CGFloat volume = [options[@"volume"] floatValue];
    volume = MIN(MAX(volume, 0), 1);
    [self.videoPlayer setPlaybackVolume:volume];
}

WX_EXPORT_METHOD(@selector(getVolume:callback:))

- (void)getVolume:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        double volume = self.videoPlayer.playbackVolume;
        callback(@{@"volume": @(volume)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(setSpeed:))

- (void)setSpeed:(NSDictionary *)options {
    CGFloat speed = [options[@"speed"] floatValue];
    if (speed == 0) {
        speed = 1;
    }
    speed = MIN(MAX(speed, 0.5), 2);
    [self.videoPlayer setPlaybackRate:speed];
}

WX_EXPORT_METHOD(@selector(getSpeed:callback:))

- (void)getSpeed:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        double speed = self.videoPlayer.playbackRate;
        callback(@{@"speed": @(speed)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(changeLevel:callback:))

- (void)changeLevel:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSInteger level = [options[@"level"] integerValue];
    if (level < 0 || level > 3) {
        if (callback) {
            callback(@{@"errMsg": @"请传入正确的码率"}, NO);
        }
        return;
    }
    [self.videoPlayer switchQuality:level];
}

WX_EXPORT_METHOD(@selector(getCurrentLevel:callback:))

- (void)getCurrentLevel:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        double level = self.videoPlayer.video ? self.videoPlayer.quality : 0;
        callback(@{@"currentLevel": @(level)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(getLevelNum:callback:))

- (void)getLevelNum:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        if (self.videoPlayer.video) {
            callback(@{@"levelNum": @(self.videoPlayer.video.qualityCount)}, NO);
        } else {
            callback(@{@"levelNum": @(0)}, NO);
        }
    }
}

WX_EXPORT_METHOD(@selector(getDuration:callback:))

- (void)getDuration:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        NSTimeInterval duration = self.videoPlayer.duration;
        if (isnan(duration)) {
            duration = 0;
        }
        callback(@{@"duration": @(duration)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(getBufferPercentage:callback:))

- (void)getBufferPercentage:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        NSTimeInterval playableDuration = MAX(0, self.videoPlayer.playableDuration);
        NSTimeInterval duration = MAX(0, self.videoPlayer.duration);
        float progress = 100.0 * playableDuration / duration;
        progress = MIN(progress, 100);
        callback(@{@"bufferPercentage": @(progress)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(getCurrentPosition:callback:))

- (void)getCurrentPosition:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    if (callback) {
        NSTimeInterval currentPlaybackTime = MAX(0, self.videoPlayer.currentPlaybackTime);
        callback(@{@"currentPosition": @(currentPlaybackTime)}, NO);
    }
}

WX_EXPORT_METHOD(@selector(snapshot:))

- (void)snapshot:(NSDictionary *)options {
    UIImage *snapshot = [self.videoPlayer snapshot];
    
    __weak typeof(self) weakSelf = self;
    void (^authorizedHandler)(void) = ^() {
        dispatch_async(dispatch_get_main_queue(), ^{
            UIImageWriteToSavedPhotosAlbum(snapshot, weakSelf, @selector(image:didFinishSavingWithError:contextInfo:), nil);
        });
    };
    
    PHAuthorizationStatus status = [PHPhotoLibrary authorizationStatus];
    switch (status) {
        case PHAuthorizationStatusNotDetermined:{
            // 请求权限
            [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
                if (status == PHAuthorizationStatusAuthorized) {
                    authorizedHandler();
                }
            }];
        }break;
        case PHAuthorizationStatusAuthorized:{
            authorizedHandler();
        }break;
        case PHAuthorizationStatusDenied:
        case PHAuthorizationStatusRestricted:{
            // 前往设置页
            NSString *message = [NSString stringWithFormat:@"无法获取您的照片权限，请前往设置"];
            UIAlertController *alertController = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
            [alertController addAction:[UIAlertAction actionWithTitle:@"去设置" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                NSURL *settingURL = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
                if ([[UIApplication sharedApplication] canOpenURL:settingURL]) {
                    [[UIApplication sharedApplication] openURL:settingURL];
                } else {
                    NSLog(@"无法打开 URL: %@", settingURL);
                }
            }]];
            [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alertController animated:YES completion:nil];
        }break;
    }
}

-  (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    NSString *message = error ? @"截图保存失败" : @"截图保存成功";
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [alertController dismissViewControllerAnimated:YES completion:^{}];
    }]];
    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alertController animated:YES completion:nil];
}

#pragma mark - Private

- (NSString *)playbackStateStringWithType:(PLVUniPlaybackState)type {
    NSString *state = nil;
    switch (type) {
        case PLVUniPlaybackStateStart:
            state = @"start";
            break;
        case PLVUniPlaybackStatePause:
            state = @"pause";
            break;
        case PLVUniPlaybackStateStop:
            state = @"stop";
            break;
        case PLVUniPlaybackStateComplete:
            state = @"complete";
            break;
        default:
            break;
    }
    return state;
}

- (NSString *)playErrorStringWithType:(PLVUniPlayErrorType)type {
    NSString *state = nil;
    switch (type) {
        case PLVUniPlayErrorTypeUnConfig:
            state = @"config_invalid";
            break;
        case PLVUniPlayErrorTypeIllegalVid:
            state = @"illegal_vid";
            break;
        case PLVUniPlayErrorTypePlayError:
            state = @"play_error";
            break;
        default:
            break;
    }
    return state;
}

#pragma mark - Timer Related

- (void)addTimer {
    self.positionEventTimer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(positionChangeNotify) userInfo:nil repeats:YES];
}

- (void)removeTimer {
    [_positionEventTimer invalidate];
    _positionEventTimer = nil;
}

- (void)positionChangeNotify {
    if (_positionChange) {
        if (self.videoPlayer.video) {
            [self fireEvent:kPositionChangeEvent params:@{@"detail":@{@"currentPosition":@(self.videoPlayer.currentPlaybackTime)}} domChanges:nil];
        }
    } else {
        [self removeTimer];
    }
}

@end

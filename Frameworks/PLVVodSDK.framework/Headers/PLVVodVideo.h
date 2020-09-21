//
//  PLVVodVideo.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"
#import "PLVVodAd.h"

@class PLVVodVideoKeyFrameItem;

/// 视频数据模型
@interface PLVVodVideo : NSObject

/// 视频 id
@property (nonatomic, copy, readonly) NSString *vid;

/// 视频标题
@property (nonatomic, copy) NSString *title;

// 是否包含 ppt
@property (nonatomic, assign) BOOL hasPPT;

/// viewlog 上报的频率
@property (nonatomic, assign, readonly) int reportFreq;

/// 可用清晰度数量
@property (nonatomic, assign, readonly) int qualityCount;

/// 默认播放清晰度
@property (nonatomic, assign) PLVVodQuality preferredQuality;

/// 视频时长
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/// 源文件大小
@property (nonatomic, assign, readonly) NSInteger sourcefilesize;

/// 源文件url
@property (nonatomic, copy, readonly) NSString *play_source_url;

/// 各码率视频大小
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *filesizes;

/// 视频快照URL
@property (nonatomic, copy) NSString *snapshot;

/// 源文件播放
@property (nonatomic, assign, readonly) BOOL keepSource;

/// 分类id
@property (nonatomic, copy, readonly) NSString *categoryId;

/// 分类树
@property (nonatomic, strong, readonly) NSArray *categoryTree;

/// 是否存在问答
@property (nonatomic, assign, readonly) BOOL interactive;

/// 视频字幕（srtKey: srtUrl）
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *srts;

/// 视频打点信息
@property (nonatomic, strong) NSArray<PLVVodVideoKeyFrameItem *> *videokeyframes;

/// 广告信息
@property (nonatomic, strong) NSArray<PLVVodAd *> *ads;

/// 片头URL
@property (nonatomic, copy) NSString *teaser;

/// 片头播放时长
@property (nonatomic, assign) NSTimeInterval teaserDuration;

/// 是否显示片头
@property (nonatomic, assign) BOOL teaserShow;

/// 可用线路
@property (nonatomic, strong, readonly) NSArray<NSString *> *availableRouteLines;
@property (nonatomic, strong, readonly) NSArray<NSString *> *tsCdns;

/// 可用线路，音频文件
@property (nonatomic, strong, readonly) NSArray<NSString *> *availableAudioRouteLines;

/// 若视频不合法，可以从该属性获取不合法原因，否则为空
@property (nonatomic, strong) NSError *error;

/// 音频文件链接
@property (nonatomic, copy, readonly) NSString *aac_link;

/// 音频文件大小
@property (nonatomic, assign, readonly) NSInteger aac_filesize;

/// ppt文件链接
@property (nonatomic, copy, readonly) NSString *ppt_link;

/// 视频或账号是否可用
- (BOOL)available;

/// 视频是否为非加密视频
- (BOOL)isPlain;

/// 视频是否为hls视频
- (BOOL)isHls;

/// 是否能够切换音视频模式
- (BOOL)canSwithPlaybackMode;

/**
 请求获取 PLVVodVideo 模型对象，（视频播放时使用）
 
 @param vid vid
 @param completion PLVVodVideo 模型对象
 */
+ (void)requestVideoWithVid:(NSString *)vid completion:(void (^)(PLVVodVideo *video, NSError *error))completion;

/**
 请求获取 PLVVodVideo 模型对象,优先返回本地数据,无本地数据时，发送网络请求，
 保存或更新数据到数据库 （视频下载时使用）
 
 @param vid vid
 @param completion PLVVodVideo 模型对象

 */
+ (void)requestVideoPriorityCacheWithVid:(NSString *)vid completion:(void (^)(PLVVodVideo *video, NSError *error))completion;


#pragma mark - 内部接口

/// status 视频状态
@property (nonatomic, assign) int status;

/// outflow 账户是否超流量
@property (nonatomic, assign) BOOL outflow;

/// timeoutflow 账户是否过期
@property (nonatomic, assign) BOOL timeoutflow;

/// hlsIndex 视频主索引URL
@property (nonatomic, copy) NSString *hlsIndex;

/// hls 视频子索引URL
@property (nonatomic, strong) NSArray<NSString *> *hlsVideos;

/// mp4 videolink 各码率非加密资源 URL
@property (nonatomic, strong) NSArray<NSString *> *plainVideos;

/// packageUrl ts打包
@property (nonatomic, strong) NSArray<NSString *> *tsPackages;

/// 加密常量
@property (nonatomic, copy) NSString *constKey;

/// ts host
@property (nonatomic, copy) NSString *tsHost;

/// hls version
@property (nonatomic, copy, readonly) NSString *hlsVersion;

@end

// 视频打点信息模型
@interface PLVVodVideoKeyFrameItem : NSObject

@property (nonatomic, copy) NSString *hours;   // 小时
@property (nonatomic, copy) NSString *minutes; // 分钟
@property (nonatomic, copy) NSString *seconds; // 秒
@property (nonatomic, copy) NSString *keycontext; // 关键帧描述
@property (nonatomic, copy) NSString *id;       // 记录id
@property (nonatomic, copy) NSString *keytime;  // 打点时间

@end


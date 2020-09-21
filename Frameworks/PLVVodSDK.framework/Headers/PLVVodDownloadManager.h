//
//  PLVVodDownloadManager.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/12.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodDownloadInfo.h"
#import "PLVVodVideo.h"
#import "PLVVodLocalVideo.h"
#import "PLVVodVideoParams.h"

/**
 视频下载管理单例
 */
@interface PLVVodDownloadManager : NSObject

/// 下载目录，默认为 Library/Caches/PolyvVodCache。修改下载目录后，上一个目录的离线视频将无法索引。
@property (nonatomic, copy) NSString *downloadDir;

/// 是否允许使用蜂窝移动网络进行下载，默认 YES
@property (nonatomic, assign) BOOL allowsCellularAccess;

/// 是否启用后台下载，默认 YES
@property (nonatomic, assign) BOOL enableBackgroundDownload;

/// 后台下载会话标识符
//@property (nonatomic, copy, readonly) NSString *sessionId;

/// 添加任务后是否自动启动，默认 NO
@property (nonatomic, assign) BOOL autoStart;

/// 保存的后台下载会话block
@property (nonatomic, copy) void (^backgroundCompletionHandler)(void);

/// 完成所有下载回调
@property (nonatomic, copy) void(^completeBlock)(void);

/// 单个视频下载完成回调
@property (nonatomic, copy) void(^downloadCompleteBlock)(PLVVodDownloadInfo *info);

/// 下载错误回调
@property (nonatomic, copy) void (^downloadErrorHandler)(PLVVodVideo *video, NSError *error);

/// 是否正在下载中
@property (nonatomic, assign, readonly) BOOL isDownloading; // 正在下载中

/// 允许同时下载的最大任务数,默认为1，最大为3
@property (nonatomic, assign) NSUInteger maxRuningCount;

/// 下载的文件类型，默认视频文件
@property (nonatomic, assign) PLVDownloadFileType fileType DEPRECATED_MSG_ATTRIBUTE("Use: downloadType Instead");

/// 下载模式类型，默认视频下载模式
@property (nonatomic, assign) PLVDownloadModeType downloadType;

/// 多账号体系支持,默认NO
@property (nonatomic, assign) BOOL isMultiAccount;

/// 上一个版本视频存储目录，用于升级到多账号下载后，迁移单帐号本地视频到多账号系统的第一个下载账户
@property (nonatomic, copy) NSString *previousDownloadDir;

/**
 PLVVodDownloadManager 共享的静态对象

 @return PLVVodDownloadManager 共享的静态对象
 */
+ (instancetype)sharedManager;

/**
 设置下载目录

 @param downloadDir 设置的下载目录
 @param skipBackup 是否忽略 iCloud 的备份
 @param error 错误回调
 @return 是否成功
 */
- (BOOL)setDownloadDir:(NSString *)downloadDir skipBackup:(BOOL)skipBackup error:(NSError **)error;

/**
迁移已经缓存的视频数据
 
 @param sourceDir  被迁移的视频下载目录
 @param destDir  目标视频下载目录（新目录）
 
 @return 是否迁移成功
 */
- (BOOL)moveDownloadVideoFromSourceDir:(NSString *)sourceDir toDestDir:(NSString *)destDir;

/**
 添加至下载队列
 
 添加下载器，仅当 video 错误时，才会报错，quality 错误时，只会警告，并切换到最近的质量进行下载。

 @param video PLVVodVideo 视频对象
 @param quality 视频画质
 @return 下载信息
 */
- (PLVVodDownloadInfo *)downloadVideo:(PLVVodVideo *)video quality:(PLVVodQuality)quality;

/**
 使用后台设置的默认画质添加至下载队列

 @param video PLVVodVideo 视频对象
 @return 下载信息
 */
- (PLVVodDownloadInfo *)downloadVideo:(PLVVodVideo *)video;

/**
 下载音频文件（开通视频转音频服务才有此功能）
 
 @param video PLVVodVideo 视频对象
 @return 下载信息
 */
- (PLVVodDownloadInfo *)downloadAudio:(PLVVodVideo *)video;

/**
 下载PPT 文件
 
 @param video PLVVodVideo 视频对象
 */
- (void)downloadPPTWithVideo:(PLVVodVideo *)video completion:(void(^)(PLVVodDownloadInfo *info))completion;

/**
 开始队列下载
 */
- (void)startDownload;

/**
 停止队列下载
 */
- (void)stopDownload;

/**
 从指定视频开始下载，若达到并发数限制，则停止其他下载任务，优先下载指定视频
 
 @param vid 视频vid
 
 */
- (void)startDownloadWithVid:(NSString *)vid;

/**
 开始指定vid视频下载，根据priority 参数执行不同的下载策略
 
 @param vid 视频vid
 @param priority YES 当达到并发数限制，优先下载此视频；NO，当达到并发数限制，处于Preparing 状态
 
 */
- (void)startDownloadWithVid:(NSString *)vid highPriority:(BOOL)priority;


/**
 从指定视频/音频文件开始下载
 使用场景：同时下载视频/音频文件的客户
 
 @param videoParams fileType 为音频，操作音频文件；为视频，操作视频文件

 */
- (void)startDownloadWithVideoParams:(PLVVodVideoParams *)videoParams;

/**
 停止下载指定视频
 
 @param vid 视频vid
 */
- (void)stopDownloadWithVid:(NSString *)vid;

/**
 停止下载指定视频
 
 @param vid 视频vid
 @param autoNext 是否自动开启下一个视频的下载
 */
- (void)stopDownloadWithVid:(NSString *)vid autoNext:(BOOL)autoNext;

/**
 停止下载指定视频/音频
 
 @param videoParams fileType 为音频，操作音频文件；为视频，操作视频文件

 */
- (void)stopDownloadWithVideoParams:(PLVVodVideoParams *)videoParams;

/**
 移除下载任务，并删除对应文件

 @param vid vid
 @param error 错误回调
 */
- (void)removeDownloadWithVid:(NSString *)vid error:(NSError **)error;

/**
 移除音频/视频下载任务，并删除对应文件
 
 @param videoParams fileType 为音频，操作音频文件；为视频，操作视频文件
 @param error 错误回调
 */
- (void)removeDownloadWithVideoParams:(PLVVodVideoParams *)videoParams error:(NSError **)error;

/**
 移除所有下载任务，并删除对应文件，与已完成下载的视频无关
 
 @param completion 删除任务后的回调
 */
- (void)removeAllDownloadWithComplete:(void(^)(void *result))completion;

/**
 获取所有下载任务信息(缓冲中，已缓存)

 @param completion 完成回调
 */
- (void)requestDownloadInfosWithCompletion:(void (^)(NSArray<PLVVodDownloadInfo *> *downloadInfos))completion;

/**
 
 获取所有缓存中视频信息（准备缓存，缓存中，缓存失败）
 
 @param completion 完成回调，返回视频信息数组
 
 */
- (void)requstDownloadProcessingListWithCompletion:(void(^)(NSArray<PLVVodDownloadInfo *> *downloadInfos))completion;

/**
 
 获取所有已缓存成功视频信息
 
 @return 下载完成的视频数组
 
 */
- (NSArray<PLVVodDownloadInfo *> *)requestDownloadCompleteList;

/**
 
 根据vid 获取视频下载信息
 
 @param vid 视频vid
 
 */
- (PLVVodDownloadInfo *)requestDownloadInfoWithVid:(NSString *)vid;

/**
 
 根据videoParams 获取视频下载详细信息
 
 @param videoParams 视频/音频文件信息
 
 */
- (PLVVodDownloadInfo *)requestDownloadInfoWithVideoParams:(PLVVodVideoParams *)videoParams;


#pragma mark - 工具方法

/**
 删除指定视频
 删除视频，会删除包含 vid 的所有离线资源（与下载任务无关）。

 @param vid 视频id
 @param error 错误回调
 */
+ (void)removeVideoWithVid:(NSString *)vid error:(NSError **)error;

/**
 删除本地ppt 数据 （与下载任务无关）
 
 @param vid 视频id
 @param error 错误回调
 */
+ (void)removePPTWithVid:(NSString *)vid error:(NSError **)error;

/**
 删除指定视频/音频文件
 
 删除视频/音频，会删除包含 vid 的所有离线资源（与下载任务无关）。
 
 @param videoParams fileType 为音频，操作音频文件；为视频，操作视频文件
 @param error 错误回调
 */
+ (void)removeVideoWithVideoParams:(PLVVodVideoParams *)videoParams error:(NSError **)error;

/**
 删除下载目录下所有资源
 
 删除下载目录下所有离线资源（与下载任务无关）。

 @param error 错误回调
 */
+ (void)removeAllVideoWithError:(NSError **)error;

/**
 删除下载目录下所有音频资源
 
 删除下载目录下所有音频离线资源（与下载任务无关）。
 
 @param error 错误回调
 */
+ (void)removeAllAudioWithError:(NSError **)error;

/**
 获取已下载的本地视频

 @return 一组 PLVVodLocalVideo 对象
 */
- (NSArray<PLVVodLocalVideo *> *)localVideos;

/**
 判断指定视频是否存在本地
 
 指定 vid 视频是否已下载，返回指定 vid 的清晰度，返回 0 则不存在该视频。

 @param vid vid
 @return 指定视频的画质
 */
+ (PLVVodQuality)videoExist:(NSString *)vid;

/**
 兼容 1.x.x 版本的离线视频
 
 注意：
 - 实现兼容的前提是使用相同的下载目录，必须保证与之前版本的下载目录一致；
 - 该方法调用一次即可，多次调用也不会修改文件。
 */
- (void)compatibleWithPreviousVideos;

/**
 在AppDelegate 中调用，程序即将结束时，修改并保存下载中视频的下载状态，用于
 程序下次启动后，恢复视频下载状态
 
 */
- (void)applicationWillTerminate; // 已经废弃，sdk 内部自动调用

/**
 在AppDelegate 中调用，app 回到前台模式，进行相关设置
 
 */
- (void)applicationWillEnterForeground; // 已经废弃，sdk 内部自动调用

/**
 在AppDelegate 中调用，app 退到后台模式，进行相关设置

 */
- (void)applicationDidEnterBackground; // 已经废弃，sdk 内部自动调用

/**
 
 处理后台下载完成回调的事件
 */
- (void)handleEventsForBackgroundURLSession:(NSString *)identifier
                          completionHandler:(void (^)(void))completionHandler;

#pragma mark 多账号下载支持

/**
 
 当开启多账号支持时，可以切换当前下载帐号，各个帐号具有单独的存储目录
 
 @param accountId 终端用户的唯一标志，建议传递userId
 
 */
- (void)switchDownloadAccount:(NSString *)accountId;

/**
 
 登出多账号，停止当前帐号下载中的视频，重新设置多账号下的默认帐号
 登出后，会采用默认帐号进行下载相关操作
 
 */
- (void)logoutMultiAccount;




@end

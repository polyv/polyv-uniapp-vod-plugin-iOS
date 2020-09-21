//
//  PLVVodConstans.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#ifndef PLVVodConstans_h
#define PLVVodConstans_h

/// 清晰度
typedef NS_ENUM(NSInteger, PLVVodQuality) {
	/// 自动
	PLVVodQualityAuto,
	/// 流畅
	PLVVodQualityStandard = 1,
	/// 高清
	PLVVodQualityHigh,
	/// 超清
	PLVVodQualityUltra
};
/// 清晰度描述
static inline NSString *NSStringFromPLVVodQuality(PLVVodQuality quality) {
	switch (quality) {
		case PLVVodQualityAuto:
			return @"自动";
		case PLVVodQualityStandard:
			return @"流畅";
		case PLVVodQualityHigh:
			return @"高清";
		case PLVVodQualityUltra:
			return @"超清";
		default:
			return @"未知";
	}
}

/// 播放模式
typedef NS_ENUM(NSInteger, PLVVodPlaybackMode) {
    PLVVodPlaybackModeDefault,
    PLVVodPlaybackModeVideo,
    PLVVodPlaybackModeAudio
};

/// 资源状态
typedef NS_ENUM(NSInteger, PLVVodAssetState) {
	/// 未知
	PLVVodAssetStateUnknown = 0,
	/// 加载中
	PLVVodAssetStateLoading,
	/// 播放中
	PLVVodAssetStatePlaying,
	/// 播放结束
	PLVVodAssetStateFinished
};

/// 日志等级
typedef NS_OPTIONS(NSUInteger, PLVVodLogLevel) {
	/// 禁用日志输出
	PLVVodLogLevelSilent= 0,
	/// 只输出错误日志
	PLVVodLogLevelError	= 1 << 0,
	/// 只输出警告日志
	PLVVodLogLevelWarn	= 1 << 1,
	/// 只输出信息日志
	PLVVodLogLevelInfo	= 1 << 2,
	/// 只输出调试日志
	PLVVodLogLevelDebug	= 1 << 3,
	/// 输出除了调试的日志
	PLVVodLogLevelWithoutDebug = PLVVodLogLevelError | PLVVodLogLevelWarn | PLVVodLogLevelInfo,
	/// 输出所有日志
	PLVVodLogLevelAll	= 0xFFFFFFFF,
};

/// 下载文件类型
typedef NS_ENUM(NSUInteger, PLVDownloadFileType) {
    
    PLVDownloadFileTypeVideo = 1 << 0,  // 视频文件
    PLVDownloadFileTypeAudio = 1 << 1   // 音频文件
};

/// 下载模式类型
typedef NS_ENUM(NSUInteger, PLVDownloadModeType) {
    PLVDownloadModeTypeVideo = 1 << 0,  // 视频下载模式
    PLVDownloadModeTypeAudio = 1 << 1   // 音频下载模式
};

#define PLV_VOD_RESOURCES_BUNDLE_NAME @"PolyvVodResources.bundle"
#define PLV_VOD_RESOURCES_BUNDLE_RELPATH(file) [PLV_VOD_RESOURCES_BUNDLE_NAME stringByAppendingPathComponent:file]
#define PLV_VOD_RESOURCES_BUNDLE_PATH [[NSBundle mainBundle] pathForResource:PLV_VOD_RESOURCES_BUNDLE_NAME ofType:nil]
#define PLV_VOD_RESOURCES_BUNDLE [NSBundle bundleWithPath:PLV_VOD_RESOURCES_BUNDLE_PATH]

#pragma mark - 常量

static const double PLVVodAnimationDuration = 0.25;

#pragma mark 通知

/// 片头播放状态变更通知
static NSString * const PLVVodPlayerTeaserStateDidChangeNotification = @"PLVVodPlayerTeaserStateDidChangeNotification";
/// 广告播放状态变更通知
static NSString * const PLVVodPlayerAdStateDidChangeNotification = @"PLVVodPlayerAdStateDidChangeNotification";

/// 远程控制通知
static NSString * const PLVVodRemoteControlEventDidReceiveNotification = @"PLVVodRemoteControlEventDidReceiveNotification";
static NSString * const PLVVodRemoteControlEventKey = @"event";

/// 通知定义
static NSString * const kNotificationIJKPlayerCreateKey = @"kNotificationIJKPlayerCreateKey"; // ijkplayer 创建

#pragma mark - 错误声明

static NSString * const PLVVodErrorDomain = @"net.polyv.vod.sdk.ErrorDomain";
typedef NS_ENUM(NSInteger, PLVVodErrorCode) {
	// 视频错误 ------
	/// 视频或账号不合法
	account_video_illegal = 20000,
	/// 账户套餐流量不足
	account_flow_out = 20001,
	/// 账户套餐已过期
	account_time_out = 20002,
	/// 视频与账号不匹配
	video_unmatch_account = 20003,
	/// 加密秘钥不合法
	account_encode_key_illegal = 20005,
	/// 加密向量不合法
	account_encode_iv_illegal = 20006,
	/// 视频状态不合法
	video_status_illegal = 20009,
	
	// 播放错误 ------
	/// 播放令牌请求失败
	playback_token_fetch_error = 20010,
	/// 无法获取视频
	video_not_found = 20011,
	/// 未知视频对象
	video_type_unknown = 20012,
	/// 视频时长不合法
	playback_duration_illegal = 20013,
	/// 片头格式不合法
	teaser_type_illegal = 20021,
	/// 广告类型不合法
	ad_type_illegal = 20025,
    /// 当前视频不支持音频播放模式
    video_not_support_play_audio = 20026,
    /// 本地视频播放失败
    play_local_video_error = 20027,
	
	// 下载错误 ------
	/// 下载错误
	download_error = 20040,
	/// 下载器创建失败
	downloader_create_error = 20041,
	/// 下载任务创建失败
	download_task_create_error = 20042,
	/// 下载任务不存在
	download_task_not_found = 20043,
	/// m3u8写入失败
	m3u8_write_error = 20051,
	/// 播放秘钥写入错误
	key_write_error = 20052,
	/// 切片路径修复失败
	ts_path_fix_error = 20053,
	/// 解压错误
	unzip_error = 20055,
    /// 下载完成后，ts文件不全
    download_error_lost_ts = 20056,
	
	// 检索错误 ------
	/// 参数不合法
	argument_illegal = 20061,
	/// 下载目录不存在
	download_dir_not_found = 20062,
	/// 无法检索文件，目标存在同名目录
	target_file_is_dir = 20063,
	/// 无法获取文件名
	filename_not_found = 20064,
	/// 无法获取切片
	ts_not_found = 20065,
	/// 本地资源不可达
	local_file_unaccessible = 20066,
	/// 本地视频播放秘钥不合法
	local_key_illegal = 20067,
	/// hls目录索引失败
	hls_dir_not_found = 20068,
	
	// 文件操作错误 ------
	/// 视频移除错误
	video_remove_error = 20071,
	/// 文件移动错误
	file_move_error = 20072,
	
	// 网络请求错误 ------
	/// 网络不可达
	network_unreachable = 20100,
	/// 网络错误
	network_error = 20101,
	/// 服务器错误
	server_error = 20102,
	/// 请求错误
	fetch_error = 20103,
	/// JSON解析错误
	json_read_error = 20104,
    /// vid错误
    vid_error = 20105,
	/// 播放秘钥请求失败
	key_fetch_error = 20111,
	/// m3u8请求失败
	m3u8_fetch_error = 20112,
};

NSDictionary *PLVVodErrorInfoWithCode(PLVVodErrorCode code);
static NSString * const PLVVodErrorSelectorKey = @"selector";         // 相关方法
static NSString * const PLVVodSubErrorCodeKey = @"subErrorCode";      // 业务处理错误码
static NSString * const PLVVodHttpStatusCodeKey = @"httpStatusCode";  // http 请求返回状态码
static NSString * const PLVVodNSURLErrorCodeKey = @"nsurlErrorCode";  // 系统网络错误码
static NSString * const PLVSysErrorDomainKey = @"PLVSysErrorDomainKey";  // 错误域
static NSString * const PLVSysErrorCodeKey = @"PLVSysErrorCodeKey";  // 错误码

#endif /* PLVVodConstans_h */

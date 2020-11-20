//
//  PLVVodPlayerViewController.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVVodVideo.h"
#import "PLVVodLocalVideo.h"
#import "PLVVodPlayerSkinProtocol.h"
#import "PLVVodAdPlayerViewController.h"
#import "PLVVodPlayerLogo.h"

/// 拉伸模式
typedef NS_ENUM(NSInteger, PLVVodMovieScalingMode) {
	PLVVodMovieScalingModeNone,
	PLVVodMovieScalingModeAspectFit,
	PLVVodMovieScalingModeAspectFill,
	PLVVodMovieScalingModeFill
};

/// 播放状态
typedef NS_ENUM(NSInteger, PLVVodPlaybackState) {
	PLVVodPlaybackStateStopped,
	PLVVodPlaybackStatePlaying,
	PLVVodPlaybackStatePaused,
	PLVVodPlaybackStateInterrupted,
	PLVVodPlaybackStateSeekingForward,
	PLVVodPlaybackStateSeekingBackward
};

/// 加载状态
typedef NS_OPTIONS(NSUInteger, PLVVodLoadState) {
	PLVVodLoadStateUnknown        = 0,
	PLVVodLoadStatePlayable       = 1 << 0,
	PLVVodLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
	PLVVodLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

/// seek 定位模式
typedef NS_ENUM(NSUInteger, PLVVodPlaySeekType) {
    PLVVodPlaySeekTypeDefaul = 0, // 默认模式
    PLVVodPlaySeekTypePrecise = 1 // 精确模式
};

/// 手势识别类型
typedef NS_ENUM(NSInteger, PLVVodGestureType) {
	//// 未知
	PLVVodGestureTypeUnknown,
	/// 点击
	PLVVodGestureTypeTap,
	/// 双击
	PLVVodGestureTypeDoubleTap,
	/// 左滑
	PLVVodGestureTypeLeftPan,
	/// 右滑
	PLVVodGestureTypeRightPan,
	/// 左侧上滑
	PLVVodGestureTypeLeftSideUpPan,
	/// 左侧下滑
	PLVVodGestureTypeLeftSideDownPan,
	/// 右侧上滑
	PLVVodGestureTypeRightSideUpPan,
	/// 右侧下滑
	PLVVodGestureTypeRightSideDownPan,
    /// 长按
    PLVVodGestureTypeLongPress,
    /// 长按取消
    PLVVodGestureTypeLongPressEnd
};

typedef NS_ENUM(NSInteger, PLVVodFullScreenOrientation) {
    PLVVodFullScreenOrientationAuto = 0, // 根据视频宽高比自动判断，当宽高比 >=1 时，横向全屏；当宽高比 <1 时，竖向全屏
    PLVVodFullScreenOrientationPortrait, // 竖向全屏
    PLVVodFullScreenOrientationLandscape, // 横向全屏
};

@class PLVMarquee;

/// 主视频播放器
@interface PLVVodPlayerViewController : UIViewController

/// 覆盖图层
@property (nonatomic, strong) UIView *maskView;

/// 视频渲染视图
@property (nonatomic, readonly) UIView *videoView;

/// video 模型
@property (nonatomic, strong) PLVVodVideo *video;

/// 当前清晰度
@property (nonatomic, assign, readonly) PLVVodQuality quality;

/// 用户播放时间
@property (nonatomic, assign, readonly) NSTimeInterval viewerWatchDuration;

/// 用户停留时间
@property (nonatomic, assign, readonly) NSTimeInterval viewerStayDuration;

/// 播放的视频内容时长
@property (nonatomic, assign, readonly) NSTimeInterval videoContentPlayedTime;

/// 其他 viewlog 参数，param1~param5 和 key1~key3 参数值需要 UrlSafeBase64 编码
@property (nonatomic, strong) NSDictionary<NSString *, id> *viewlogExtraParams;

/// 本地视频优先播放，默认为 YES
@property (nonatomic, assign) BOOL localPrior;

/// 是否为本地播放
@property (nonatomic, assign) BOOL localPlayback;

/// 是否允许后台播放
@property (nonatomic, assign) BOOL enableBackgroundPlayback;

/// 是否需要循环播放, 默认NO （不支持hls视频）
@property (nonatomic, assign) BOOL enablePlayRecycle;

/// 解码方式设置，默认 YES (硬解码)
@property (nonatomic, assign) BOOL isVideoToolBox;

/// seek 播放定位类型设置。0 默认，1 精确模式
@property (nonatomic, assign) PLVVodPlaySeekType seekType;

/// 是否播放片头，默认 NO
@property (nonatomic, assign) BOOL enableTeaser;
/// 片头播放状态
@property (nonatomic, assign, readonly) PLVVodAssetState teaserState;

/// 是否开启广告，默认 NO
@property (nonatomic, assign) BOOL enableAd;
/// 广告播放器
@property (nonatomic, strong, readonly) PLVVodAdPlayerViewController *adPlayer;

/// 是否开启记忆播放位置，默认 NO
@property (nonatomic, assign) BOOL rememberLastPosition;

/// 拉伸模式
@property (nonatomic, assign) PLVVodMovieScalingMode scalingMode;

/// 路由线路，仅对加密视频有效，传入 POVVodVideo 对象中 availableRouteLines 数组的元素
@property (nonatomic, copy) NSString *routeLine;

/// 播放控制
@property (nonatomic, strong) IBOutlet id<PLVVodPlayerSkinProtocol> playerControl;

/// 识别手势类型
@property (nonatomic, assign, readonly) PLVVodGestureType gestureType;
/// 手势识别回调
@property (nonatomic, copy) void (^gestureCallback)(PLVVodPlayerViewController *player, UIGestureRecognizer *recognizer, PLVVodGestureType gestureType);
/// 手势识别时忽略的视图
@property (nonatomic, strong) NSArray *doNotReceiveGestureViews;

/// 跑马灯
@property (nonatomic, strong) PLVMarquee *marquee;

/// 防录屏功能，默认NO关闭
@property (nonatomic, assign) BOOL videoCaptureProtect;

#pragma mark - 播放

/// 自动播放，默认 YES
@property (nonatomic, assign) BOOL autoplay;

/// 播放速度
@property (nonatomic, assign) double playbackRate;
/// 是否在切换码率/切换音视频播放模式/切换播放线路时，记忆播放速度，默认 YES
@property (nonatomic, assign) BOOL rememberPlaybackRate;

/// 播放音量
@property (nonatomic, assign) double playbackVolume;

/// 开始播放时间
@property (nonatomic, assign) NSTimeInterval startPlaybackTime;

/// 当前播放时间
@property (nonatomic, assign) NSTimeInterval currentPlaybackTime;

/// 媒体时长
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/// 可播放时长
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;

/// 是否就绪播放
@property (nonatomic, assign, readonly) BOOL preparedToPlay;
/// 是否就绪播放回调
@property (nonatomic, copy) void (^preparedToPlayHandler)(PLVVodPlayerViewController *player);

/// 播放状态
@property (nonatomic, assign, readonly) PLVVodPlaybackState playbackState;
/// 播放状态回调
@property (nonatomic, copy) void (^playbackStateHandler)(PLVVodPlayerViewController *player);

/// 播放模式
@property (nonatomic, assign) PLVVodPlaybackMode playbackMode;
/// 播放模式回调
@property (nonatomic, copy) void (^playbackModeHandler)(PLVVodPlayerViewController *player);
/// 更新播放模式更新成功回调
- (void)playbackModeDidChange;
- (void)updateAudioCoverAnimation:(BOOL)isPlaying;

/// 加载状态
@property (nonatomic, assign, readonly) PLVVodLoadState loadState;
/// 加载状态回调
@property (nonatomic, copy) void (^loadStateHandler)(PLVVodPlayerViewController *player);

/// 是否播放结束，只能判断播放结束，不能判断是成功结束，还是异常结束
@property (nonatomic, assign, readonly) BOOL reachEnd;

/// 是否成功播放结束
@property (nonatomic, readonly) BOOL reachEndSuccess;

/// 播放结束回调
@property (nonatomic, copy) void (^reachEndHandler)(PLVVodPlayerViewController *player);

/// 记忆播放位置
@property (nonatomic, readonly) NSTimeInterval lastPosition;

/// 是否正在载入回调
@property (nonatomic, copy) void (^loadingHandler)(BOOL isLoading);

/// 设置全屏方向
@property (nonatomic, assign) PLVVodFullScreenOrientation fullScreenOrientation;

/// 当前是否全屏
@property (nonatomic, assign) BOOL fullscreen;
/// 全屏状态变化回调
@property (nonatomic, copy) void (^didFullScreenSwitch)(BOOL fullScreen);

/// 本地视频播放，发送viewlog日志开关，默认NO
@property (nonatomic, assign) BOOL enableLocalViewLog;

/// 播放器错误回调
@property (nonatomic, copy) void (^playerErrorHandler)(PLVVodPlayerViewController *player, NSError *error);

/// 播放异常结束，手动恢复播放回调。播放异常结束后，该block每10s回调一次，在该block中可实现恢复播放逻辑。
@property (nonatomic, copy) void (^playbackRecoveryHandle)(PLVVodPlayerViewController *player);

/// 回调视频打点信息
@property (nonatomic, copy) void (^videoTipsSelectedHandler)(NSUInteger tipIndex);

/// 播放进度回调
@property (nonatomic, copy) void (^playbackProgressHandler)(PLVVodPlayerViewController *player, NSTimeInterval curPlayTime);

/// 是否启动 ppt 功能，默认为 NO，此时无论该视频有无 ppt 均不显示
@property (nonatomic, assign) BOOL enablePPT;

/// 视频加载速率
@property (nonatomic, readonly) NSString *tcpSpeed;

/// 播放器 logo 图层
@property (nonatomic, strong, readonly) PLVVodPlayerLogo *logoView;

/// 预加载缓冲大小,单位字节。sdk默认10M。10M = 10*1024*1024
@property (nonatomic, assign) NSInteger maxCacheSize;

/// 预加载缓冲时长, sdk 内部会转换为最小帧数.
/// 如果设置缓冲数据长度为10s，视频帧率为25 ，对应的minCacheFrame 值为 10*25
@property (nonatomic, assign) NSInteger maxCacheDuration;

/// 预加载视频最小帧数，缓存数据长度达到最小帧数，不再读取更多数据
@property (nonatomic, assign) NSInteger minCacheFrame;

/// 占位视图
@property (nonatomic, strong) UIView *placeholderView;
/// self.view 当前约束
@property (nonatomic, strong) NSMutableArray<NSLayoutConstraint *> *constraints;
/// 根控制器
@property (nonatomic, weak) UIViewController *rootViewController;

/// 返回当前播放视频的 pid
- (NSString *)getPlayId;

/// 返回播放器实时状态
- (NSDictionary *)getRealPlayStatus;

/**
 指定/切换 PLVVodVideo 对象，及其清晰度

 @param video PLVVodVideo 对象
 @param quality 清晰度
 */
- (void)setVideo:(PLVVodVideo *)video quality:(PLVVodQuality)quality;

/**
 切换码率，若码率不符合则自动切换到附近的清晰度

 @param quality 清晰度
 */
- (void)switchQuality:(PLVVodQuality)quality;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 离开播放器并暂停
- (void)leavePlayerWithPause;

/// 当前时刻的截图
- (UIImage *)snapshot;

/// 播放时间显示字符串，子类中重写该方法，可实现自定义播放器时间显示
- (NSString *)timeDescription;

/// 获取视频的宽高；在视频播放就绪后可获取到数值，可在preparedToPlayHandler中根据就绪状态来获取
- (CGSize)getVideoSize;

/// 检查该视频模型是否将本地播放
- (BOOL)checkVideoWillPlayLocal:(PLVVodVideo *)video;

#pragma mark - IBAction

/// 播放或暂停 Action
- (IBAction)playPauseAction:(UIButton *)sender;

/// 播放进度滑杆 TouchDown Action
- (IBAction)playbackSliderTouchDownAction:(UISlider *)sender;

/// 播放进度滑杆 ValueChange Action
- (IBAction)playbackSliderValueChangeAction:(UISlider *)sender;

/// 播放进度滑杆 TouchUpCancel Action
- (IBAction)playbackSliderTouchUpCancelAction:(UISlider *)sender;

/// 亮度滑杆调节 Action
- (IBAction)brightnessAction:(UISlider *)sender;

/// 音量滑杆调节 Action
- (IBAction)volumeAction:(UISlider *)sender;

/**
 添加播放器到占位视图上

 `placeholderView` 为竖屏时的占位视图，该视图需要先布局，播放器会参照该视图的布局而进行竖屏的布局。
 
 @param placeholderView 竖屏状态时的占位视图
 @param rootViewController 播放器所在页面的 UIViewController 对象
 */
- (void)addPlayerOnPlaceholderView:(UIView *)placeholderView rootViewController:(UIViewController *)rootViewController;

/**
 
 播放外部平台视频，保利威平台视频不能采用该方法
 
 @param videoUrl 外部视频url 地址
 
 */
- (void)setURL:(NSURL *)videoUrl;

/**
 播放外部平台视频，保利威平台视频不能采用该方法
 
 @param videoUrl 外部视频url 地址
 @param headers 请求头设置
 */
- (void)setURL:(NSURL *)videoUrl withHeaders:(NSDictionary<NSString *, NSString *> *)headers;

/**
 手动销毁播放器，单例播放等少数特别场景才需要调用此方法
 
 */
- (void)destroyPlayer;

/**
 自定义片头设置
 
 @param teaserUrl       片头url，图片支持png,jpg,gif; 视频支持mp4，flv
 @param teaserDuration  片头播放时长，片头时长大于视频时长时，以视频实际时长为准
 
 @return YES,设置成功； NO,设置失败，参数错误
 */

- (BOOL)setCustomTeaser:(NSString *)teaserUrl teaserDuration:(NSInteger )teaserDuration;

/// 为播放器增加 logo，一个播放器只能添加一个 PLVVodPlayerLogo 对象
- (void)addPlayerLogo:(PLVVodPlayerLogo *)logo;

// 设置播放器是否处于全屏模式
- (void)setPlayerFullScreen:(BOOL)full DEPRECATED_MSG_ATTRIBUTE("Please use [PLVVodSkinPlayerController playInFullscreen:] instead");

/// 旋转设备到指定方向
+ (void)rotateOrientation:(UIInterfaceOrientation)orientation DEPRECATED_MSG_ATTRIBUTE("Please use [PLVVodUtils changeDeviceOrientation:] instead");

@end

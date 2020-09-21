//
//  PLVVodPlayerSkinProtocol.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/30.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVVodConstans.h"

@class PLVVodPlayerViewController;

/// 自定义皮肤协议
@protocol PLVVodPlayerSkinProtocol <NSObject>

/// 弱引用的播放器
@property (nonatomic, weak) IBOutlet PLVVodPlayerViewController *delegatePlayer;

/// 指导页面隐藏导航栏
@property (nonatomic, assign) BOOL shouldHideNavigationBar;

/// 指导页面状态栏隐藏
@property (nonatomic, assign) BOOL shouldHideStatusBar;

/// 指导页面状态栏样式
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

/// 清晰度个数
@property (nonatomic, assign) int qualityCount;
/// 当前清晰度
@property (nonatomic, assign) PLVVodQuality quality;
/// 清晰度修改回调
@property (nonatomic, copy) void (^qualityDidChangeBlock)(PLVVodQuality quality);

/// 当前是否播放本地视频
@property (nonatomic, assign) BOOL localPlayback;

/// 当前播放速率
@property (nonatomic, assign) double playbackRate;
/// 播放速率改变回调
@property (nonatomic, copy) void (^selectedPlaybackRateDidChangeBlock)(double playbackRate);

/// 当前视频拉伸方式
@property (nonatomic, assign) NSInteger scalingMode;
/// 视频拉伸方式改变回调
@property (nonatomic, copy) void (^scalingModeDidChangeBlock)(NSInteger scalingMode);

/// 字幕名称
@property (nonatomic, strong) NSArray<NSString *> *subtitleKeys;
/// 选中的字幕名称
@property (nonatomic, copy) NSString *selectedSubtitleKey;
/// 字幕改变回调
@property (nonatomic, copy) void (^selectedSubtitleKeyDidChangeBlock)(NSString *selectedSubtitleKey);

#pragma mark 控件

/// 播放/暂停按钮
@property (nonatomic, weak) IBOutlet UIButton *playPauseButton;

/// 时间标签
@property (weak, nonatomic) IBOutlet UILabel *timeLabel;

/// 缓冲进度
@property (weak, nonatomic) IBOutlet UIProgressView *bufferProgressView;

/// 播放进度滑杆
@property (weak, nonatomic) IBOutlet UISlider *playbackSlider;

/// 全屏/半屏按钮
@property (nonatomic, weak) IBOutlet UIButton *fullShrinkscreenButton;

/// 亮度滑杆
@property (nonatomic, weak) IBOutlet UISlider *brightnessSlider;

/// 音量滑杆
@property (nonatomic, weak) IBOutlet UISlider *volumeSlider;

@end

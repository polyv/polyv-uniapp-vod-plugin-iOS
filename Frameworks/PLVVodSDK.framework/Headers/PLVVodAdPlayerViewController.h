//
//  PLVVodAdPlayerViewController.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/11/8.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVVodAd.h"
#import "PLVVodConstans.h"

typedef void(^PLVVodAdCompletionBlock)(BOOL finish);

/// 广告播放器
@interface PLVVodAdPlayerViewController : UIViewController

/// 需要播放的广告
@property (nonatomic, strong) NSArray<PLVVodAd *> *ads;

/// 当前播放广告
@property (nonatomic, strong) PLVVodAd *currentAd;

/// 当前播放广告的状态
@property (nonatomic, assign) PLVVodAssetState state;

/// 播放按钮，仅在暂停广告会出现
@property (nonatomic, strong, readonly) UIButton *playButton;

/// 剩余时间文本
@property (nonatomic, strong, readonly) UILabel *timeLabel;

/// 跳过按钮
@property (nonatomic, assign) BOOL canSkip;
@property (nonatomic, strong, readonly) UIButton *skipButton;

/// 静音按钮
@property (nonatomic, strong, readonly) UIButton *muteButton;

/// 错误回调
@property (nonatomic, copy) void (^playerErrorHandler)(PLVVodAdPlayerViewController *adPlayer, NSError *error);

/// 点击回调
@property (nonatomic, copy) void (^adDidTapBlock)(PLVVodAd *ad);

/// 上边距
@property (nonatomic, assign) CGFloat topInset;

/// 显示广告
- (void)showAdWithLocation:(PLVVodAdLocation)location completion:(PLVVodAdCompletionBlock)completion;

/// 隐藏广告
- (void)hideAd;

/// 时间标签
+ (NSAttributedString *)timeStringWithSeconds:(NSInteger)remainSeconds;

@end

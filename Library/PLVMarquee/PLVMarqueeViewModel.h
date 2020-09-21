//
//  PLVMarqueeViewModel.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/11/1.
//  Copyright © 2017年 POLYV. All rights reserved.
//
// 跑马灯私有VM

#import <UIKit/UIKit.h>
#import "PLVMarquee.h"

@interface PLVMarqueeViewModel : NSObject

/// 跑马灯图层
@property (nonatomic, strong) CALayer *marqueeLayer;

/// 初始化
+ (instancetype)viewModelWithMarquee:(PLVMarquee *)marquee;

/// 显示跑马灯
- (void)showInRect:(CGRect)rect layer:(CALayer *)layer currentPlaybackTime:(NSTimeInterval)currentPlaybackTime duration:(NSTimeInterval)videoDuration;

@end

//
//  PLVMarquee.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/11/1.
//  Copyright © 2017年 POLYV. All rights reserved.
//
// 跑马灯模型
// 随机因素：
// - 出现位置
// - 出现间隔

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PLVMarqueeType) {
	/// 闪现 （在随机位置出现）
	PLVMarqueeTypeFade,
	/// 滚动 (从右侧随机位置出现，并向左滚动)
	PLVMarqueeTypeRoll,
	/// 滚动+闪现 （在随机位置出现 + 并向左滚动）
	PLVMarqueeTypeRollFade
};

/// 配置跑马灯效果
@interface PLVMarquee : NSObject

/// 跑马灯类型
@property (nonatomic, assign) PLVMarqueeType type;

/**
 渐变动画时长
 任何跑马灯类型，都带有透明度渐变的动画
 该属性即是透明度变化过程（如：alpha 0 -> 1）的时间
 默认0.5s
 */
@property (nonatomic, assign) NSTimeInterval fadeDuration;

/**
 单次跑马灯显示时长，不包含动画时长
 实际总时长 = displayDuration + 2 * fadeDuration
 type为 PLVMarqueeTypeRoll / PLVMarqueeTypeRollFade 时，影响滚动速度
 默认8s
 */
@property (nonatomic, assign) NSTimeInterval displayDuration;

/**
 间隔时间是否为固定值，默认No
 */
@property (nonatomic, assign) BOOL timeIntervalConstant;

/**
 下一次闪现的间隔时间，
 timeIntervalConstant - NO，实际间隔时间是取 （0 ~ maxFadeInterval） 范围内随机值
 timeIntervalConstant - YES，实际间隔时间即是 maxFadeInterval
 仅type为 PLVMarqueeTypeFade / PLVMarqueeTypeRollFade 时有效
*/
@property (nonatomic, assign) NSTimeInterval maxFadeInterval;

/**
 下一次滚动出现的间隔时间，
 timeIntervalConstant - NO，实际间隔时间是取 （0 ~ maxRollInterval） 范围内随机值
 timeIntervalConstant - YES，实际间隔时间即是 maxRollInterval
 仅type为 PLVMarqueeTypeRoll / PLVMarqueeTypeRollFade 时有效
 */
@property (nonatomic, assign) NSTimeInterval maxRollInterval;

/// 跑马灯内容
@property (nonatomic, copy) NSString *content;

/// 跑马灯颜色
@property (nonatomic, strong) UIColor *color;

/// 跑马灯最大透明度
@property (nonatomic, assign) CGFloat alpha;

/// 跑马灯字体
@property (nonatomic, strong) UIFont *font;

@end

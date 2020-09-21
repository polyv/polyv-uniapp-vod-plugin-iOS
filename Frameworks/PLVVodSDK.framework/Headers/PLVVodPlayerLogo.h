//
//  PLVVodPlayerLogo.h
//  _PolyvVodSDK
//
//  Created by MissYasiky on 2020/4/13.
//  Copyright © 2020 POLYV. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// logo位置：
typedef NS_ENUM(NSInteger, PLVVodPlayerLogoPosition) {
    PLVVodPlayerLogoPositionNone = 0,   // 不显示
    PLVVodPlayerLogoPositionLeftUp,     // 左上
    PLVVodPlayerLogoPositionRightUp,    // 右上（默认值）
    PLVVodPlayerLogoPositionLeftDown,   // 左下
    PLVVodPlayerLogoPositionRightDown   // 右下
};

/// logo 配置参数类
@interface PLVVodPlayerLogoParam : NSObject

/*
 logo 宽高像素单位与百分比单位二选其一
 */
/// logo 宽与高像素（单位：pt），默认 0
@property (nonatomic, assign) CGFloat logoWidth;
@property (nonatomic, assign) CGFloat logoHeight;

/// logo 宽与高百分比（单位：%），取值范围 [0,1]，默认 0
@property (nonatomic, assign) CGFloat logoWidthScale;
@property (nonatomic, assign) CGFloat logoHeightScale;

/*
logo 水平与垂直偏移像素单位与百分比单位二选其一
*/
/// logo 水平与垂直偏移像素（单位：pt），默认 0
@property (nonatomic, assign) CGFloat xOffset;
@property (nonatomic, assign) CGFloat yOffset;

/// logo 水平与垂直偏移百分比（单位：%），取值范围 [0,1]，默认 0
@property (nonatomic, assign) CGFloat xOffsetScale;
@property (nonatomic, assign) CGFloat yOffsetScale;

/// logo 位置，默认右上角
@property (nonatomic, assign) PLVVodPlayerLogoPosition position;

///透明度，取值范围 [0,1]，默认 1
@property (nonatomic, assign) CGFloat logoAlpha;

/// logo图片的URL，必须使用 https 协议
@property (nonatomic, copy) NSString *logoUrl;


@end

@interface PLVVodPlayerLogo : UIView

/// 添加 logo，一个 PLVVodPlayerLogo 对象可同时添加最多两个 logo
- (void)insertLogoWithParam:(PLVVodPlayerLogoParam *)param;

@end

NS_ASSUME_NONNULL_END

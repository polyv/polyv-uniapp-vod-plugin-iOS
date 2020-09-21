//
//  PLVVodUtils.h
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/9/1.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodUtils : NSObject

/// 检查 param 是否为不为空字符串
+ (BOOL)isValidString:(NSString *)param;

/// 检查 vid 是否格式正确且合法
+ (BOOL)validateVid:(NSString *)vid;

/// 检查视频播放是否合法
+ (BOOL)isVideoArrowPlay:(NSString *)vid;

/// 检查是否为合法链接格式
+ (BOOL)validateUrlString:(NSString *)urlString;

/// 把 0xFFFFFF 格式的字符串转化为 UIColor
+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

/// 读取字典 NSString 类型值安全方法
+ (NSString * _Nullable)stringValueWithDictionary:(NSDictionary *)dict
                                           forKey:(NSString *)key
                                     defaultValue:(NSString * _Nullable)defaultValue;

@end

NS_ASSUME_NONNULL_END

//
//  PLVVodUtils.m
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/9/1.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodUtils.h"
#import <PLVVodSDK/PLVVodSDK.h>

@implementation PLVVodUtils

+ (BOOL)isValidString:(NSString *)param {
    return (param && [param isKindOfClass:[NSString class]] && param.length > 0);
}

+ (BOOL)validateVid:(NSString *)vid {
    if(![self isValidString:vid]) {
        return NO;
    } else {
        NSString *VID = @"^[[a-z]|[0-9]]{32}_[[a-z]|[0-9]]$";
        NSPredicate *regexVid = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",VID];
        return [regexVid evaluateWithObject:vid];
    }
}

+ (BOOL)isVideoArrowPlay:(NSString *)vid {
    NSString *userId = [PLVVodSettings sharedSettings].userid;
    return [[vid substringToIndex:10] isEqualToString:userId];
}

+ (BOOL)validateUrlString:(NSString *)urlString {
    if (urlString == nil || urlString.length <= 7) {
        return NO;
    }
    if (![urlString hasPrefix:@"http://"] && ![urlString hasPrefix:@"https://"]) {
        return NO;
    }
    return YES;
}

+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha {
    NSString *cString = [[hexString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    
    //hexString应该6到8个字符
    if ([cString length] < 6) {
        return [UIColor clearColor];
    }
    
    //如果hexString 有@"0X"前缀
    if ([cString hasPrefix:@"0X"])
        cString = [cString substringFromIndex:2];
    
    //如果hexString 有@"#""前缀
    if ([cString hasPrefix:@"#"])
        cString = [cString substringFromIndex:1];
    if ([cString length] != 6)
        return [UIColor clearColor];
    
    //RGB转换
    NSRange range;
    range.location = 0;
    range.length = 2;
    
    //R
    NSString *rString = [cString substringWithRange:range];
    
    //G
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    
    //B
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f) green:((float) g / 255.0f) blue:((float) b / 255.0f) alpha:alpha];
}

+ (NSString *)stringValueWithDictionary:(NSDictionary *)dict
                                 forKey:(NSString *)key
                           defaultValue:(NSString *)defaultValue {
    if (![defaultValue isKindOfClass:[NSString class]] || defaultValue.length == 0) {
        defaultValue = nil;
    }
    
    if (!dict || ![dict isKindOfClass:[NSDictionary class]]) {
        return defaultValue;
    }
    
    if (!key || ![key isKindOfClass:[NSString class]] || key.length == 0) {
        return defaultValue;
    }
    
    return dict[key] ?: defaultValue;
}

@end

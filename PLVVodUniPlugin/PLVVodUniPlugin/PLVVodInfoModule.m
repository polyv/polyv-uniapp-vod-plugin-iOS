//
//  PLVVodInfoModule.m
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/9/7.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodInfoModule.h"
#import "PLVVodUtils.h"
#import <PLVVodSDK/PLVVodSDK.h>

@implementation PLVVodInfoModule

WX_EXPORT_METHOD(@selector(getVideoInfo:callback:))

- (void)getVideoInfo:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils isValidString:vid]) {
        if (callback) {
           callback(@{@"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid": vid, @"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    [PLVVodVideo requestVideoWithVid:vid completion:^(PLVVodVideo *video, NSError *error) {
        if (callback) {
            if (error) {
                NSString *errMsg = error.localizedDescription ?: @"获取视频信息失败";
                NSDictionary *ret = @{@"vid": vid, @"errMsg": errMsg};
                callback(ret, NO);
            } else {
                NSDictionary *ret = @{@"vid": vid, @"duration": @(video.duration), @"levelNum":@(video.qualityCount)};
                callback(ret, NO);
            }
        }
    }];
}

WX_EXPORT_METHOD(@selector(getFileSize:callback:))

- (void)getFileSize:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *vid = [PLVVodUtils stringValueWithDictionary:options forKey:@"vid" defaultValue:nil];
    if (![PLVVodUtils isValidString:vid]) {
        if (callback) {
            callback(@{@"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    if (![PLVVodUtils validateVid:vid]) {
        if (callback) {
            callback(@{@"vid": vid, @"errMsg":@"vid无效"}, NO);
        }
        return;
    }
    
    NSInteger level = [options[@"level"] integerValue];
    if (level < 1 || level > 3) {
        if (callback) {
            NSDictionary *ret = @{@"vid": vid, @"errMsg":@"请传入正确的码率"};
            callback(ret, NO);
        }
        return;
    }
    
    [PLVVodVideo requestVideoWithVid:vid completion:^(PLVVodVideo *video, NSError *error) {
        if (callback) {
            if (error) {
                NSString *errMsg = error.localizedDescription ?: @"获取视频信息失败";
                NSDictionary *ret = @{@"vid": vid, @"errMsg": errMsg};
                callback(ret, NO);
            } else {
                NSArray *fileSizes = video.filesizes;
                if (fileSizes == nil || [fileSizes count] == 0) {
                    NSDictionary *ret = @{@"vid": vid, @"errMsg": @"获取视频信息失败"};
                    callback(ret, NO);
                } else if ([fileSizes count] < level) {
                    NSNumber *fileSize = fileSizes[0];
                    NSDictionary *ret = @{@"vid": vid, @"fileSize": fileSize};
                    callback(ret, NO);
                } else {
                    NSNumber *fileSize = fileSizes[level-1];
                    NSDictionary *ret = @{@"vid": vid, @"fileSize": fileSize};
                    callback(ret, NO);
                }
            }
        }
    }];
}

@end

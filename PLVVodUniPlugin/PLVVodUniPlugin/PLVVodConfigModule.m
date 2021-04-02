//
//  PLVVodConfigModule.m
//  PLVVodUniPlugin
//
//  Created by MissYasiky on 2020/8/27.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodConfigModule.h"
#import "PLVVodUtils.h"
#import "PLVVodConfig.h"
#import <PLVVodSDK/PLVVodSDK.h>

@implementation PLVVodConfigModule

WX_EXPORT_METHOD(@selector(setConfig:callback:))

- (void)setConfig:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *configStr = [PLVVodUtils stringValueWithDictionary:options forKey:@"config" defaultValue:nil];
    NSString *errMsg = nil;
    
    if (![PLVVodUtils isValidString:configStr]) {
        errMsg = @"加密串参数为空";
    } else {
        NSError *error;
        NSString *key = options[@"aeskey"];
        NSString *iv = options[@"iv"];
        if ([PLVVodUtils isValidString:key] && [PLVVodUtils isValidString:iv]) {
            [PLVVodSettings settingsWithConfigString:configStr key:key iv:iv error:&error];
        } else {
            [PLVVodSettings settingsWithConfigString:configStr error:&error];
        }
        
        if (error) {
            errMsg = error.localizedDescription ?: @"配置加密串出错";
        }
    }
    
    if (callback) {
        if (errMsg) {
            callback(@{@"isSuccess": @(NO), @"errMsg": errMsg}, NO);
        } else {
            callback(@{@"isSuccess": @(YES)}, NO);
        }
    }
}

WX_EXPORT_METHOD(@selector(setToken:callback:))

- (void)setToken:(NSDictionary *)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *userid = [PLVVodUtils stringValueWithDictionary:options forKey:@"userid" defaultValue:nil];
    NSString *readtoken = [PLVVodUtils stringValueWithDictionary:options forKey:@"readtoken" defaultValue:nil];
    NSString *writetoken = [PLVVodUtils stringValueWithDictionary:options forKey:@"writetoken" defaultValue:nil];
    NSString *secretkey = [PLVVodUtils stringValueWithDictionary:options forKey:@"secretkey" defaultValue:nil];
    
    NSString *errMsg = nil;
    if (![PLVVodUtils isValidString:userid] ||
        ![PLVVodUtils isValidString:readtoken] ||
        ![PLVVodUtils isValidString:writetoken] ||
        ![PLVVodUtils isValidString:secretkey]) {
        errMsg = @"配置参数不可为空";
    } else {
        [PLVVodSettings settingsWithUserid:userid readtoken:readtoken writetoken:writetoken secretkey:secretkey];
    }
    
    if (callback) {
        if (errMsg) {
            callback(@{@"isSuccess": @(NO), @"errMsg": errMsg}, NO);
        } else {
            callback(@{@"isSuccess": @(YES)}, NO);
        }
    }
}

WX_EXPORT_METHOD(@selector(setViewerId:))

- (void)setViewerId:(NSDictionary *)options {
    NSString *viewerId = [PLVVodUtils stringValueWithDictionary:options forKey:@"viewerId" defaultValue:nil];
    if (viewerId && viewerId.length > 0) {
        [PLVVodSettings sharedSettings].viewerId = viewerId;
    }
}

WX_EXPORT_METHOD(@selector(setViewerName:))

- (void)setViewerName:(NSDictionary *)options {
    NSString *viewerName = [PLVVodUtils stringValueWithDictionary:options forKey:@"viewerName" defaultValue:nil];
    if (viewerName && viewerName.length > 0) {
        [PLVVodSettings sharedSettings].viewerName = viewerName;
    }
}

WX_EXPORT_METHOD(@selector(setViewerInfo:))

- (void)setViewerInfo:(NSDictionary *)options {
    PLVVodViewerInfo *viewerInfos = [PLVVodSettings sharedSettings].viewerInfos;
    
    NSString *p3 = [PLVVodUtils stringValueWithDictionary:options forKey:@"param3" defaultValue:nil];
    if (p3 && p3.length > 0) {
        viewerInfos.viewerExtraInfo1 = p3;
    }
    NSString *p4 = [PLVVodUtils stringValueWithDictionary:options forKey:@"param4" defaultValue:nil];
    if (p4 && p4.length > 0) {
        viewerInfos.viewerExtraInfo2 = p4;
    }
    NSString *p5 = [PLVVodUtils stringValueWithDictionary:options forKey:@"param5" defaultValue:nil];
    if (p5 && p5.length > 0) {
        viewerInfos.viewerExtraInfo3 = p5;
    }
}

WX_EXPORT_METHOD(@selector(openMediaCodec:))

- (void)openMediaCodec:(NSDictionary *)options {
    NSString *mediaCodec = [PLVVodUtils stringValueWithDictionary:options forKey:@"mediaCodec" defaultValue:nil];
    BOOL isVideoToolBox = [mediaCodec boolValue];
    [PLVVodConfig sharedConfig].isVideoToolBox = isVideoToolBox;
}

@end

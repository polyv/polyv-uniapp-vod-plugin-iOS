//
//  PLVVodConfig.m
//  ModuleDemo
//
//  Created by MissYasiky on 2021/2/18.
//  Copyright © 2021 APICloud. All rights reserved.
//

#import "PLVVodConfig.h"

@implementation PLVVodConfig

+ (instancetype)sharedConfig {
    static PLVVodConfig *config = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        config = [[PLVVodConfig alloc] init];
    });
    return config;
}

@end

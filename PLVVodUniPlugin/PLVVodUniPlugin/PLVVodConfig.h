//
//  PLVVodConfig.h
//  ModuleDemo
//
//  Created by MissYasiky on 2021/2/18.
//  Copyright © 2021 APICloud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodConfig : NSObject

/// 解码方式设置，YES - 硬解码，NO  - 软解码，默认 NO
@property (nonatomic, assign) BOOL isVideoToolBox;

+ (instancetype)sharedConfig;

@end

NS_ASSUME_NONNULL_END

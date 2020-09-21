//
//  PLVVodPlayerUtil.h
//  PolyvVodSDK
//
//  Created by mac on 2018/10/30.
//  Copyright © 2018年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodVideo.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodPlayerUtil : NSObject

/**
 根据vid 返回上一次播放进度位置
 
 @param videoId 视频id
 
 @return 上一次播放进度位置，单位秒
 
 */

+ (NSTimeInterval )lastPositionWithVid:(NSString *)videoId;

/**
 根据vid 返回保存上一次播放进度的时间戳
 
 @param videoId 视频id
 
 @return 保存上一次进度的时间戳，单位毫秒
 
 */
+ (NSTimeInterval )lastPositionTimestampWithVid:(NSString *)videoId;

/**
 根据video模型，获取投屏加密视频的Key iv
 
 @param video 视频模型
 @param quality 当前所选码率
 
 */
+ (void)requestCastKeyIvWitVideo:(PLVVodVideo *)video quality:(NSInteger)quality completion:(void (^)(NSString * _Nullable key, NSString * _Nullable iv, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

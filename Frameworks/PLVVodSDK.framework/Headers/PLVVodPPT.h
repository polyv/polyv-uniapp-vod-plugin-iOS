//
//  PLVVodPPT.h
//  PLVVodSDK
//
//  Created by MissYasiky on 2019/7/24.
//  Copyright © 2019 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodPPTPage : NSObject

@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) NSInteger index;

@property (nonatomic, assign) NSInteger timing;

@property (nonatomic, copy) NSString *key;

@property (nonatomic, copy) NSString *imageUrl;

@property (nonatomic, copy) NSString *thumbImageUrl;

- (BOOL)isLocalImage;

- (UIImage *)localImage;

@end

@interface PLVVodPPT : NSObject

@property (nonatomic, copy) NSString *vid;

@property (nonatomic, copy) NSDictionary <NSString *, PLVVodPPTPage *> * _Nullable pagesDict;

@property (nonatomic, copy) NSArray <PLVVodPPTPage *>* _Nullable pages;

/// 获取在线数据
+ (void)requestPPTWithVid:(NSString *)vid completion:(void (^)(PLVVodPPT * _Nullable ppt, NSError * _Nullable error))completion;
/// 获取缓存数据
+ (void)requestCachePPTWithVid:(NSString *)vid completion:(void (^)(PLVVodPPT * _Nullable ppt, NSError * _Nullable error))completion;
/// 已缓存
+ (BOOL)isExistWithVid:(NSString *)vid;

@end

NS_ASSUME_NONNULL_END

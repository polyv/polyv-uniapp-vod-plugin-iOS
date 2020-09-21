//
//  PLVVodAd.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 广告类型
typedef NS_ENUM(NSInteger, PLVVodAdType) {
	/// 未知
	PLVVodAdTypeUnknown,
	/// 图片
	PLVVodAdTypeImage = 1,
	/// 视频
	PLVVodAdTypeVideo,
	/// SWF
	PLVVodAdTypeSwf
};
/// PLVVodAdType 描述
NSString *NSStringFromPLVVodAdType(PLVVodAdType adType);

/// 广告位置
typedef NS_ENUM(NSInteger, PLVVodAdLocation) {
	/// 未知
	PLVVodAdLocationUnknown,
	/// 片头
	PLVVodAdLocationHead = 1,
	/// 暂停
	PLVVodAdLocationPause,
	/// 片尾
	PLVVodAdLocationTail
};
/// PLVVodAdLocation 描述
NSString *NSStringFromPLVVodAdLocation(PLVVodAdLocation adLocation);

/// 广告数据模型
@interface PLVVodAd : NSObject

/// addrurl 跳转地址
@property (nonatomic, copy) NSString *address;

/// adtype 广告类型
@property (nonatomic, assign) PLVVodAdType type;

/// cataid 广告分类id
@property (nonatomic, copy) NSString *categoryId;

/// location 位置
@property (nonatomic, assign) PLVVodAdLocation location;

/// matterurl 广告资源URL
@property (nonatomic, copy) NSString *adUrl;

/// timesize 广告时长，小于等于0则为无穷大
@property (nonatomic, assign) NSTimeInterval duration;

/// 已播放，广告只播放一次
@property (nonatomic, assign) BOOL played;

/// 初始化
+ (instancetype)adWithDic:(NSDictionary *)dic;

@end

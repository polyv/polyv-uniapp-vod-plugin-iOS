//
//  PLVVodDownloadManager+Database.h
//  PolyvVodSDK
//
//  Created by mac on 2018/10/13.
//  Copyright © 2018年 POLYV. All rights reserved.
//

#import <PLVVodSDK/PLVVodSDK.h>
#import <WCDB/WCDB.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodDownloadManager (Database)

/// 创建扩展表
+ (BOOL)createExtendTableWithClass:(Class)classObj;

/// 插入或更新一条记录
+ (BOOL)insertOrUpdateWithExtendInfo:(WCTObject *)extendInfo;

/// 根据条件查询记录
+ (NSArray /* <WCTObject *> */ *)getExtendInfoWithClass:(Class)classObj condition:(const WCTCondition &)condition;

/// 查询所有记录
+ (NSArray /* <WCTObject *> */ *)getAllExtendInfoWithClass:(Class)classObj;

/// 根据条件删除一条记录
+ (BOOL)deleteExtendInfoWithClass:(Class)classObj condition:(const WCTCondition &)condition;

/// 删除所有记录
+ (BOOL)deleteAllExtendInfoWithClass:(Class)classObj;

/// 更新指定字段的数据
+ (BOOL)updateExtendInfo:(WCTObject *)extendInfo propertys:(const WCTPropertyList &)propertyList condition:(const WCTCondition &)condition;

@end

NS_ASSUME_NONNULL_END

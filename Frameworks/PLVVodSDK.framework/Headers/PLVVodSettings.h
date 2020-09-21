//
//  PLVVodSettings.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"

/// SDK 版本
extern NSString * const PLVVodSdkVersion;

/// viewlog 参数设置
@interface PLVVodViewerInfo : NSObject

/// 终端用户id
@property (nonatomic, copy) NSString *viewerId;

/// 终端用户昵称
@property (nonatomic, copy) NSString *viewerName;

/// 终端用户头像
@property (nonatomic, copy) NSString *viewerAvatar;

/// viewlog 自定义参数，param1 ,param2 对用户不可见
@property (nonatomic, copy) NSString *viewerExtraInfo1; // 对应 viewlog param3
@property (nonatomic, copy) NSString *viewerExtraInfo2; // 对应 viewlog param4
@property (nonatomic, copy) NSString *viewerExtraInfo3; // 对应 viewlog param5

@end

@interface PLVVodSettings : NSObject

/// userid
@property (nonatomic, copy, readonly) NSString *userid;

/// readtoken
@property (nonatomic, copy, readonly) NSString *readtoken;

/// writetoken
@property (nonatomic, copy, readonly) NSString *writetoken;

/// secretkey
@property (nonatomic, copy, readonly) NSString *secretkey;

/// 子账号appid
@property (nonatomic, copy, readonly) NSString *appid;

/// 终端用户id
@property (nonatomic, copy) NSString *viewerId;

/// 终端用户昵称
@property (nonatomic, copy) NSString *viewerName;

/// 终端用户头像
@property (nonatomic, copy) NSString *viewerAvatar;

/// viewlog 参数设置
@property (nonatomic, strong) PLVVodViewerInfo *viewerInfos;

/// 终端用户播放令牌额外参数
@property (nonatomic, copy) NSString *viewerTokenExtraParam;

/// 是否启用多账户，默认 NO。开启后可播放、下载除了配置的账号以外的其他账号的非加密视频。
@property (nonatomic, assign, getter=isMutilAccount) BOOL mutilAccount;

/// 日志输出等级，默认 PLVVodLogLevelWithoutDebug
@property (nonatomic, assign) PLVVodLogLevel logLevel;

/// 是否启动 HTTPDNS，默认 YES.
@property (nonatomic, assign) BOOL enableHttpDNS;
/// 延迟启动 HttpDNS，enableHttpDNS 为 YES 时生效，默认 NO
@property (class, nonatomic, assign) BOOL delayHttpDNS;
/// 延迟启动 HttpDNS 的时间，delayHttpDNS 为 YES 时生效，默认 2（单位：秒）
@property (class, nonatomic, assign) NSInteger delayHttpDNSTime;

/// 错误回调
@property (nonatomic, copy) void (^settingErrorHandler)(NSError *error);

/**
 获取 PLVVodSettings 静态对象

 @return PLVVodSettings 静态对象
 */
+ (instancetype)sharedSettings;

/**
 通过 userid、readtoken、writetoken、secretkey 配置账号

 @param userid userid
 @param readtoken readtoken
 @param writetoken writetoken
 @param secretkey secretkey
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithUserid:(NSString *)userid readtoken:(NSString *)readtoken writetoken:(NSString *)writetoken secretkey:(NSString *)secretkey;

/**
 使用加密串配置账号

 @param configString 加密串
 @param error 解密、配置过程的错误
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithConfigString:(NSString *)configString error:(NSError **)error ;

/**
 使用加密串、加密秘钥、加密向量配置账号

 @param configString 加密串
 @param key 加密秘钥
 @param iv 加密向量
 @param error 解密、配置过程的错误
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithConfigString:(NSString *)configString key:(NSString *)key iv:(NSString *)iv error:(NSError **)error;

/**
 
 通过appid，secretkey，总帐号userid 配置子帐号
 
 @param appId       子帐号appid
 @param secretKey   子帐号加密key
 @param userId      总帐号userid
 
 */
+ (instancetype)settingsWithAppId:(NSString *)appId secretKey:(NSString *)secretKey userId:(NSString *)userId;

@end

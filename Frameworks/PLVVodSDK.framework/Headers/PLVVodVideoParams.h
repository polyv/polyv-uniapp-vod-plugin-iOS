//
//  PLVVodVideoParams.h
//  PolyvVodSDK
//
//  Created by mac on 2019/3/26.
//  Copyright © 2019 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVVodVideoParams : NSObject

@property (nonatomic, copy) NSString *vid;  // 视频vid
@property (nonatomic, assign) PLVDownloadFileType fileType; //文件类型

// 创建对象
+ (PLVVodVideoParams *)videoParamsWithVid:(NSString *)vid fileType:(PLVDownloadFileType )fileType;

@end

NS_ASSUME_NONNULL_END

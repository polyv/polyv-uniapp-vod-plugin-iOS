//
//  PLVVodDownloadInfo.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/12.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"
#import "PLVVodVideo.h"
/**
 下载状态
 */
typedef NS_ENUM(NSInteger, PLVVodDownloadState) {
	/// 默认准备
	PLVVodDownloadStatePreparing = 0,	// 准备
    /// 准备中
    PLVVodDownloadStatePreparingStart = 7, // 准备中，正在创建任务(新增状态，兼容低版本)
	/// 下载器准备就绪，下载任务已创建
	PLVVodDownloadStateReady = 1,		// 就绪，下载任务已创建
	/// 正在下载
	PLVVodDownloadStateRunning = 2,		// 正在下载
	/// 停止下载中
	PLVVodDownloadStateStopping = 3,	// 正在停止
	/// 下载已停止
	PLVVodDownloadStateStopped = 4,		// 停止下载
	/// 下载成功
	PLVVodDownloadStateSuccess = 5,		// 下载成功
	/// 下载失败，失败错误信息可从 `error` 属性获取
	PLVVodDownloadStateFailed = 6		// 下载失败
};
/**
 PLVVodDownloadState 本地字符串

 @param state 下载状态
 @return 描述字符串
 */
NS_INLINE NSString *NSStringFromPLVVodDownloadState(PLVVodDownloadState state) {
	NSString *string = nil;
	switch (state) {
		case PLVVodDownloadStatePreparing:{
			string = @"准备";
		}break;
        case PLVVodDownloadStatePreparingStart:
        {
            string = @"准备中";
        }break;
		case PLVVodDownloadStateReady:{
			string = @"就绪";
		}break;
		case PLVVodDownloadStateRunning:{
			string = @"下载中";
		}break;
		case PLVVodDownloadStateStopping:{
			string = @"停止中";
		}break;
		case PLVVodDownloadStateStopped:{
			string = @"停止";
		}break;
		case PLVVodDownloadStateSuccess:{
			string = @"成功";
		}break;
		case PLVVodDownloadStateFailed:{
			string = @"失败";
		}break;
		default:{}break;
	}
	return string;
}

@interface PLVVodDownloadInfo : NSObject

/// 唯一标识
@property (nonatomic, copy, readonly) NSString *identifier;

/// PLVVodVideo 对象
@property (nonatomic, strong, readonly) PLVVodVideo *video;

/// vid 便捷属性
@property (nonatomic, copy, readonly) NSString *vid;

/// 清晰度
@property (nonatomic, assign, readonly) PLVVodQuality quality;

/// 下载状态
@property (nonatomic, assign, readonly) PLVVodDownloadState state;
@property (nonatomic, copy) void (^stateDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载速率（单位：byte/s）
@property (nonatomic, assign, readonly) double bytesPerSeconds;
@property (nonatomic, copy) void (^bytesPerSecondsDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载进度（0-1）
@property (nonatomic, assign, readonly) double progress;
@property (nonatomic, copy) void (^progressDidChangeBlock)(PLVVodDownloadInfo *info);

/// 解压进度（0-1）
@property (nonatomic, assign, readonly) double unzipProgress;
@property (nonatomic, copy) void (^unzipProgressDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载错误
@property (nonatomic, strong, readonly) NSError *error;

/// 队列ID
@property (nonatomic, assign, readonly) NSInteger downloadId;

/// 文件类型,默认为视频
@property (nonatomic, assign, readonly) PLVDownloadFileType fileType;

/// 请求cdn资源时的唯一标志
@property (nonatomic, copy, readonly) NSString *did;

/// UI展示
@property (nonatomic, copy, readonly) NSString *snapshot; // 封面
@property (nonatomic, copy, readonly) NSString *title;    // 视频名称
@property (nonatomic, assign, readonly) NSUInteger filesize; // 文件大小
@property (nonatomic, assign, readonly) NSUInteger duration; // 视频时长

@end

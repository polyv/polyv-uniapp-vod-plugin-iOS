//
//  PLVVodPluginProxy.m
//  PLVVodPlugin
//
//  Created by XHY on 2020/5/19.
//  Copyright © 2020 DCloud. All rights reserved.
//

#import "PLVVodPluginProxy.h"
#import <PLVVodSDK/PLVVodSDK.h>

@implementation PLVVodPluginProxy

- (void)onCreateUniPlugin {
    NSLog(@"UniPluginProtocol Func: %@,%s",self,__func__);
}

- (BOOL)application:(UIApplication *_Nullable)application didFinishLaunchingWithOptions:(NSDictionary *_Nullable)launchOptions {
    NSLog(@"UniPluginProtocol Func: %@,%s",self,__func__);
    [self downloadSetting];
    return YES;
}

- (void)application:(UIApplication *_Nullable)application handleEventsForBackgroundURLSession:(NSString *_Nonnull)identifier completionHandler:(void (^_Nullable)(void))completionHandler {
    [[PLVVodDownloadManager sharedManager] handleEventsForBackgroundURLSession:identifier completionHandler:completionHandler];
}

#pragma mark - Private

- (void)downloadSetting {
//    [PLVVodDownloadManager sharedManager].autoStart = YES; // 添加下载任务后，自动开始下载，默认为 NO
    [PLVVodDownloadManager sharedManager].maxRuningCount = 3; // 最大下载并发数，默认为 1，最大为 3
    NSString *downloadDir = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/plvideo"];
    [PLVVodDownloadManager sharedManager].downloadDir = downloadDir;
}

@end

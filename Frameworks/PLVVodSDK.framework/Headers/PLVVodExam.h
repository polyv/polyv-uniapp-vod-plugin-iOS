//
//  PLVVodExam.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/10.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 问答数据模型
@interface PLVVodExam : NSObject

/// examId 问答题目id
@property (nonatomic, copy, readonly) NSString *examId;

/// userid 用户id
@property (nonatomic, copy, readonly) NSString *userId;

/// videoPoolId 视频的id
@property (nonatomic, copy, readonly) NSString *vid;

/// showTime 问答题目开始显示的时间
@property (nonatomic, assign, readonly) NSTimeInterval showTime;

/// question 问题
@property (nonatomic, copy, readonly) NSString *question;

/// choices 选项
@property (nonatomic, strong, readonly) NSArray<NSString *> *options;

/// 正确选项
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *correctIndex;

/// answer 正确注解
@property (nonatomic, copy, readonly) NSString *correctExplanation;

/// wrongAnswer 错误注解
@property (nonatomic, copy, readonly) NSString *wrongExplanation;

/// skip 能否跳过问答
@property (nonatomic, assign, readonly) BOOL skippable;

/// wrongTime 回答错误后跳回到第几秒
@property (nonatomic, assign, readonly) NSTimeInterval backTime;

/// wrongShow 回答错误是否提示答案
@property (nonatomic, assign, readonly) BOOL wrongShow;

/// createdTime 创建问答题目的时间
@property (nonatomic, assign, readonly) NSDate *createdTime;

/// 回答是否正确
@property (nonatomic, assign) BOOL correct;

/// illustration 插图
@property (nonatomic, copy, readonly) NSString *illustration;

/// 请求获取 PLVVodExam 模型对象
+ (void)requestVideoWithVid:(NSString *)vid completion:(void (^)(NSArray<PLVVodExam *> *exams, NSError *error))completion;

/// 将问答信息字典转为 PLVVodExam 模型对象
+ (PLVVodExam *)createExamWithDic:(NSDictionary *)dic;

/// 将问答信息字典数组 转为 PLVVodExam 模型对象数组
+ (NSArray <PLVVodExam *> *)createExamArrayWithDicArray:(NSArray <NSDictionary *> *)dicArray;

/// 根据回答正误获取注解
- (NSString *)explanation;

/// 根据vid 获取本地问答数据
+ (NSArray <PLVVodExam *> *)localExamsWithVid:(NSString *)vid downloadDir:(NSString *)downloadDir;


@end

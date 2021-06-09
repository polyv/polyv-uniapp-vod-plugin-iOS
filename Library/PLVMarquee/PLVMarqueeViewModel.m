//
//  PLVMarqueeViewModel.m
//  PolyvVodSDK
//
//  Created by BqLin on 2017/11/1.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import "PLVMarqueeViewModel.h"

@interface PLVMarqueeViewModel ()

@property (nonatomic, strong) PLVMarquee *marquee;
@property (nonatomic, assign) CGSize contentSize;

@property (nonatomic, strong) NSDate *lastFadeDate;
@property (nonatomic, strong) NSDate *lastRollDate;
@property (nonatomic, assign) CGRect lastShowRect;

@end

@implementation PLVMarqueeViewModel

/// 初始化
+ (instancetype)viewModelWithMarquee:(PLVMarquee *)marquee {
	if (!marquee) {
		return nil;
	}
	PLVMarqueeViewModel *viewModel = [[self alloc] init];
	viewModel.marquee = marquee;
	[viewModel setupLayer];
	return viewModel;
}

- (void)setupLayer {
	NSMutableDictionary *contentAttr = [NSMutableDictionary dictionary];
	contentAttr[NSForegroundColorAttributeName] = self.marquee.color;
	contentAttr[NSFontAttributeName] = self.marquee.font;
	
	NSMutableAttributedString *content = [[NSMutableAttributedString alloc] initWithString:self.marquee.content attributes:contentAttr];
	CATextLayer *textLayer = [CATextLayer layer];
	textLayer.string = content;
	CGSize textSize = [self.marquee.content sizeWithAttributes:contentAttr];
	self.contentSize = textSize;
	textLayer.contentsScale = [UIScreen mainScreen].scale;
	textLayer.opacity = 0;
	self.marqueeLayer = textLayer;
    self.marqueeLayer.masksToBounds = YES;
}

- (void)setMarqueeFrame:(CGRect)frame {
	[CATransaction begin];
	[CATransaction setDisableActions:YES];
	self.marqueeLayer.frame = frame;
	[CATransaction commit];
}

- (CAAnimation *)fadeAnimationWithDisplayDuration:(NSTimeInterval)displayDuration {
	PLVMarquee *marquee = self.marquee;
	if (displayDuration <= 0) displayDuration = marquee.displayDuration;
	NSTimeInterval duration = marquee.fadeDuration * 2 + displayDuration;
	CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"opacity"];
	animation.duration = duration;
	animation.removedOnCompletion = YES;
	
	animation.values = @[@0, @(marquee.alpha), @(marquee.alpha), @0];
	animation.keyTimes = @[@0, @(marquee.fadeDuration/duration), @(1-marquee.fadeDuration/duration), @1];
	
	return animation;
}

- (CAAnimation *)rollAnimationInRect:(CGRect)rect {
	PLVMarquee *marquee = self.marquee;
	CGFloat y = self.marqueeLayer.frame.origin.y;
	CGPoint endPoint = CGPointMake(0, y);
	NSTimeInterval duration = marquee.fadeDuration * 2 + marquee.displayDuration;
	
	CABasicAnimation *animation=[CABasicAnimation animationWithKeyPath:@"position"];
	animation.toValue = [NSValue valueWithCGPoint:endPoint];
	animation.duration = duration;
	animation.removedOnCompletion = YES;
	
	return animation;
}

- (void)showInRect:(CGRect)rect layer:(CALayer *)layer currentPlaybackTime:(NSTimeInterval)currentPlaybackTime duration:(NSTimeInterval)videoDuration {
	// 随机位置出现
	CGFloat randomX = [self.class randomDoubleFrom:0 to:rect.size.width - self.contentSize.width accuracy:2];
	CGFloat randomY = [self.class randomDoubleFrom:20 to:rect.size.height - self.contentSize.height accuracy:2];
	
	PLVMarquee *marquee = self.marquee;
	NSTimeInterval marqueeDuration = marquee.fadeDuration * 2 + marquee.displayDuration;
	if (videoDuration - currentPlaybackTime <= marqueeDuration) {
		return;
	}
	//NSTimeInterval availableDuration = videoDuration - marqueeDuration;
	
	switch (marquee.type) {
		case PLVMarqueeTypeFade:{
			NSTimeInterval marqueeInterval = marquee.maxFadeInterval;
            if (!self.marquee.timeIntervalConstant) {
                marqueeInterval = [self.class randomDoubleFrom:marqueeDuration to:marqueeDuration + marqueeInterval accuracy:2];
            }else{
                marqueeInterval = marqueeDuration + marqueeInterval;
            }
            NSTimeInterval currentInterval = [[NSDate date] timeIntervalSinceDate:self.lastFadeDate];
            BOOL isSwitch = (rect.size.width != self.lastShowRect.size.width && self.lastShowRect.size.width > 0) ? YES: NO;

			if (!self.lastFadeDate || currentInterval > marqueeInterval || isSwitch) {
				self.lastFadeDate = [NSDate date];
                self.lastShowRect = rect;
                
                [self.marqueeLayer removeAllAnimations];
				[self setMarqueeFrame:CGRectMake(randomX, randomY, self.contentSize.width, self.contentSize.height)];
				[self.marqueeLayer addAnimation:[self fadeAnimationWithDisplayDuration:-1] forKey:@"fade"];
			}
		}break;
		case PLVMarqueeTypeRoll:{
			NSTimeInterval marqueeInterval = marquee.maxRollInterval;
            if (!self.marquee.timeIntervalConstant) {
                marqueeInterval = [self.class randomDoubleFrom:marqueeDuration to:marqueeDuration + marqueeInterval accuracy:2];
            }else{
                marqueeInterval = marqueeDuration + marqueeInterval;
            }
			NSTimeInterval currentInterval = [[NSDate date] timeIntervalSinceDate:self.lastRollDate];
            BOOL isSwitch = (rect.size.width != self.lastShowRect.size.width && self.lastShowRect.size.width > 0) ? YES: NO;
            
			if (!self.lastRollDate || currentInterval > marqueeInterval || isSwitch) {
				self.lastRollDate = [NSDate date];
                self.lastShowRect = rect;
                
                [self.marqueeLayer removeAllAnimations];
                [self setMarqueeFrame:CGRectMake(rect.size.width, randomY, self.contentSize.width, self.contentSize.height)];
                [self.marqueeLayer addAnimation:[self fadeAnimationWithDisplayDuration:-1] forKey:@"fade"];
                [self.marqueeLayer addAnimation:[self rollAnimationInRect:rect] forKey:@"role"];
			}
		}break;
		case PLVMarqueeTypeRollFade:{
			// 滚动间隔
			NSTimeInterval marqueeInterval = marquee.maxRollInterval;
            if (!self.marquee.timeIntervalConstant) {
                marqueeInterval = [self.class randomDoubleFrom:marqueeDuration to:marqueeDuration + marqueeInterval accuracy:2];
            }else{
                marqueeInterval = marqueeDuration + marqueeInterval;
            }
			NSTimeInterval currentInterval = [[NSDate date] timeIntervalSinceDate:self.lastRollDate];
            BOOL isSwitch = (rect.size.width != self.lastShowRect.size.width && self.lastShowRect.size.width > 0) ? YES: NO;

			if (!self.lastRollDate || currentInterval > marqueeInterval || isSwitch) {
				self.lastRollDate = [NSDate date];
                self.lastShowRect = rect;
                
                [self.marqueeLayer removeAnimationForKey:@"role"];
				[self setMarqueeFrame:CGRectMake(rect.size.width, randomY, self.contentSize.width, self.contentSize.height)];
				//[self.marqueeLayer addAnimation:[self fadeAnimationWithDisplayDuration:-1] forKey:nil];
				[self.marqueeLayer addAnimation:[self rollAnimationInRect:rect] forKey:@"roll"];
			}
			
			// 闪现时长
			NSTimeInterval fadeDisplayDuration = marquee.maxFadeInterval;
			NSTimeInterval fadeMarqueeDuration = marquee.fadeDuration * 2 + fadeDisplayDuration;
			// 闪现间隔
			NSTimeInterval fadeMarqueeInterval = fadeDisplayDuration;
			fadeMarqueeInterval = fadeMarqueeDuration + marquee.maxFadeInterval;
			NSTimeInterval currentFadeInterval = [[NSDate date] timeIntervalSinceDate:self.lastFadeDate];
			if (!self.lastFadeDate || currentFadeInterval > fadeMarqueeInterval) {
				self.lastFadeDate = [NSDate date];
				[self.marqueeLayer addAnimation:[self fadeAnimationWithDisplayDuration:fadeDisplayDuration] forKey:@"fade"];
			}
		}break;
		default:{}break;
	}
	
//	if (currentPlaybackTime > self.nextShowTime) {
//		self.nextShowTime = [self.class randomDoubleFrom:beginTime to:endTime accuracy:2];
//		NSLog(@"show from: %f to: %f - %f", beginTime, endTime, self.nextShowTime);
//	}
}

#pragma mark - tool

+ (double)randomDoubleFrom:(double)fromValue to:(double)toValue accuracy:(NSInteger)accuracy {
	accuracy = (NSInteger)pow(10, accuracy);
	fromValue = fromValue * accuracy;
	toValue = toValue * accuracy;
	double randomValue = 1.0 * (arc4random() % (NSInteger)(toValue - fromValue + 1) + fromValue) / accuracy;
	return randomValue;
}

@end

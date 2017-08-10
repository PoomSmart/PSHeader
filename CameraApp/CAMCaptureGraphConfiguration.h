#if FROM_IOS(10_0)

#import "CAMCaptureConfiguration.h"

@interface CAMCaptureGraphConfiguration : NSObject <NSCoding>
+ (instancetype)captureGraphConfigurationUsingConfiguration:(CAMCaptureConfiguration *)configuration;
- (NSInteger)flashMode;
- (NSInteger)torchMode;
- (NSInteger)HDRMode;
- (NSInteger)timerDuration;
- (NSInteger)irisMode;
- (NSInteger)photoModeEffectFilterType;
- (NSInteger)squareModeEffectFilterType;
- (NSInteger)mode;
- (NSInteger)device;
@end

#endif

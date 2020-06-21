#import "CAMCaptureEngine.h"

NS_CLASS_AVAILABLE_IOS(9_0)
@interface CUCaptureController : NSObject
- (BOOL)isCapturingVideo;
- (BOOL)isCapturingBurst;
- (BOOL)isCapturingTimelapse;
- (CAMCaptureEngine *)_captureEngine;
@end

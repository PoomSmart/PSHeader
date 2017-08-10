#if FROM_IOS(9_0)

#import "CAMCaptureEngine.h"

@interface CUCaptureController : NSObject
- (BOOL)isCapturingVideo;
- (BOOL)isCapturingBurst;
- (BOOL)isCapturingTimelapse;
- (CAMCaptureEngine *)_captureEngine;
@end

#endif

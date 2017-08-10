#if FROM_IOS(9_0)

#import <AVFoundation/AVFoundation.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface CAMCaptureStillImageOutput : AVCaptureStillImageOutput
@end
#pragma clang diagnostic pop

#endif

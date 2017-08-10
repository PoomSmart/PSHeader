#if FROM_IOS(9_0)

#import <AVFoundation/AVFoundation.h>
#import "../Celestial/FigCaptureStillImageSettings.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@interface AVCaptureIrisStillImageOutput : AVCaptureOutput
- (AVCaptureStillImageOutput *)_sanitizedSettingsForSettings:(FigCaptureStillImageSettings *)settings;
@end

#pragma clang diagnostic pop

#endif

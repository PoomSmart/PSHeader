#import <AVFoundation/AVFoundation.h>
#import "../Celestial/FigCaptureStillImageSettings.h"

NS_CLASS_AVAILABLE_IOS(9_0)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface AVCaptureIrisStillImageOutput : AVCaptureOutput

- (AVCaptureStillImageOutput *)_sanitizedSettingsForSettings:(FigCaptureStillImageSettings *)settings;

@end
#pragma clang diagnostic pop

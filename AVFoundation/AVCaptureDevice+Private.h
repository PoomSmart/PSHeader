#import <AVFoundation/AVFoundation.h>

@interface AVCaptureDevice (Private)
- (AVCaptureSession *)session;
- (BOOL)isFaceDetectionSupported PS_AVAILABLE_IOS(5_0);
@end

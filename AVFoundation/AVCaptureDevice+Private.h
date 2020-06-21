#import <AVFoundation/AVFoundation.h>

@interface AVCaptureDevice (Private)

- (AVCaptureSession *)session;

- (BOOL)isFaceDetectionSupported NS_AVAILABLE_IOS(5_0);

@end

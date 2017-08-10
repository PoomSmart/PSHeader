#if FROM_IOS(9_0)

#import "CAMCaptureMovieFileOutput.h"
#import <AVFoundation/AVFoundation.h>

@interface CAMCaptureEngine : NSObject
- (CAMCaptureMovieFileOutput *)movieFileOutput;
@property(retain, nonatomic) AVCaptureDevice *cameraDevice;
@property(retain, nonatomic) AVCaptureSession *_captureSession;
- (AVCaptureDeviceInput *)audioCaptureDeviceInput;
- (void)_handleSessionDidStartRunning:(id)arg1;
@end

#endif

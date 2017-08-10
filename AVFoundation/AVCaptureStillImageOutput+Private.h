#import <AVFoundation/AVFoundation.h>

@interface AVCaptureStillImageOutput (Private)
@property BOOL squareCropEnabled PS_AVAILABLE_IOS(7_0);
@property CGSize previewImageSize;
- (AVCaptureConnection *)firstActiveConnection;
@end

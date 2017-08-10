#if FROM_IOS(7_0)

#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

@interface AVCaptureDeviceFormat (Private)
- (CMVideoDimensions)sensorDimensions;
@end

#endif

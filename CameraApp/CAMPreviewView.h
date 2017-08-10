#if FROM_IOS(8_0)

#import <AVFoundation/AVFoundation.h>

@interface CAMPreviewView : UIView
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property CGFloat dimmingStrength;
- (void)setDimmingStrength:(CGFloat)strength duration:(NSTimeInterval)duration;
@end

#endif

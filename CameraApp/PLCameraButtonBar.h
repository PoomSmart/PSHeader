#if TO_IOS(6_1)

#import "PLCameraButton.h"

@interface PLCameraButtonBar : UIToolbar
@property(retain, nonatomic) PLCameraButton *cameraButton;
- (UIView *)_backgroundView;
- (void)_setVisibility:(BOOL)visible;
@end

#endif

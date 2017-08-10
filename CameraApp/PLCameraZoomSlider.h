#if TO_IOS(7_1)

#import <UIKit/UISlider.h>

@interface PLCameraZoomSlider : UISlider
- (void)makeInvisible;
- (void)makeVisible;
- (void)makeVisibleAnimated:(BOOL)animated;
@end

#endif

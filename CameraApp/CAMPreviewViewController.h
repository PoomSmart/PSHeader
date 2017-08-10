#if FROM_IOS(8_0)

#import "CAMEffectsRenderer.h"

@interface CAMPreviewViewController : UIViewController
- (CAMEffectsRenderer *)effectsRenderer;
- (BOOL)_userLockedFocusAndExposure;
- (void)updateIndicatorVisibilityAnimated:(BOOL)animated;
@end

#endif

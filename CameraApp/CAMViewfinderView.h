#import "CAMPreviewView.h"

@interface CAMViewfinderView : UIView
- (CAMPreviewView *)previewView;
- (CAMTopBar *)topBar;
- (CAMBottomBar *)bottomBar;
- (CAMZoomSlider *)zoomSlider;
- (CGFloat)_interpolatedTopBarHeight;
- (CGSize)_topBarSizeForTraitCollection:(UITraitCollection *)traitCollection PS_DEPRECATED_IOS(9_0, 9_3);
- (CGSize)_topBarSizeForLayoutStyle:(NSInteger)layoutStyle PS_AVAILABLE_IOS(10_0);
@end

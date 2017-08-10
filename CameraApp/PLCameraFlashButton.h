#if TO_IOS(6_1)

#import "PLReorientingButton.h"

@interface PLCameraFlashButton : PLReorientingButton
@property(assign, nonatomic, getter = isAutoHidden) BOOL autoHidden;
@property NSInteger flashMode;
- (void)_expandAnimated:(BOOL)animated;
- (void)_collapseAndSetMode:(NSInteger)mode animated:(BOOL)animated;
- (UIView *)delegate;
@end

#endif

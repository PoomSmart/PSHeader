#if FROM_IOS(9_0)

#import "CAMShutterButtonSpec.h"

@interface CUShutterButton : UIButton
+ (instancetype)shutterButton;
+ (instancetype)smallShutterButton;
+ (instancetype)tinyShutterButton;
+ (instancetype)tinyShutterButtonWithLayoutStyle:(NSInteger)style NS_AVAILABLE_IOS(10_0);
@property(getter = isPulsing) BOOL pulsing;
@property(getter = isSpinning) BOOL spinning;
@property NSInteger mode;
- (UIColor *)_colorForMode:(NSInteger)mode;
- (UIView *)_innerView;
- (UIView *)_outerView;
- (void)_updateOuterAndInnerLayers;
- (void)_setSpec:(CAMShutterButtonSpec)spec;
@end

#endif

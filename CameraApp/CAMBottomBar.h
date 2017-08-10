#if FROM_IOS(7_0)

#import "CAMFilterButton.h"
#import "CAMFlashButton.h"
#import "CAMFlipButton.h"
#import "CAMHDRButton.h"
#import "CAMTimerButton.h"
#import "CAMShutterButton.h"
#import "CAMImageWell.h"
#import "CAMModeDial.h"
#import "CAMSlalomIndicatorView.h"

@class UITraitCollection, CAMTimerButton;

@interface CAMBottomBar : UIView
@property(readonly, assign, nonatomic) UIView *backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMFlashButton *flashButton;
@property(retain, nonatomic) CAMFlipButton *flipButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMTimerButton *timerButton PS_AVAILABLE_IOS(8_0);
@property(retain, nonatomic) CAMShutterButton *shutterButton;
@property(retain, nonatomic) CAMShutterButton *stillDuringVideoButton;
@property(retain, nonatomic) CAMImageWell *imageWell;
@property(retain, nonatomic) CAMModeDial *modeDial;
@property(retain, nonatomic) CAMSlalomIndicatorView *slalomIndicatorView;
@property(assign) NSInteger layoutStyle;
+ (BOOL)wantsVerticalBarForTraitCollection:(UITraitCollection *)traitCollection PS_AVAILABLE_IOS(8_0);
+ (BOOL)wantsVerticalBarForLayoutStyle:(NSInteger)style PS_AVAILABLE_IOS(10_0);
- (UIButton *)_expandedMenuButton;
- (NSObject *)delegate;
- (UIView *)backgroundView;
- (CGRect)alignmentRectForFrame:(CGRect)frame;
- (UIView *)_shutterButtomBottomLayoutSpacer;
- (BOOL)_isTimerButtonExpanded PS_AVAILABLE_IOS(8_0);
- (UIView *)_filterButtonBottomLayoutSpacer;
- (void)_setupHorizontalFilterButtonConstraints;
- (void)_setupVerticalFilterButtonConstraints;
- (BOOL)shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)shouldHideFlipButtonForMode:(NSInteger)mode device:(NSInteger)device;
@end

#endif

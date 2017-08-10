#if FROM_IOS(7_0)

#import "CAMFilterButton.h"
#import "CAMHDRButton.h"
#import "CAMFlashButton.h"
#import "CAMTimerButton.h"
#import "CAMFlipButton.h"
#import "CAMElapsedTimeView.h"
#import "CAMCaptureGraphConfiguration.h"

@class CAMCaptureGraphConfiguration;

@interface CAMTopBar : UIView
@property(readonly, assign, nonatomic) UIView *_backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMFlashButton *flashButton;
@property(retain, nonatomic) CAMTimerButton *timerButton PS_AVAILABLE_IOS(8_0);
@property(retain, nonatomic) CAMFlipButton *flipButton;
@property(retain, nonatomic) CAMElapsedTimeView *elapsedTimeView;
@property(readonly, assign, nonatomic, getter = isFloating) BOOL floating;
@property(assign, nonatomic) NSInteger orientation;
@property(assign, nonatomic) NSInteger style;
@property(assign, nonatomic) NSInteger backgroundStyle;
- (UIButton *)_expandedMenuButton PS_AVAILABLE_IOS(8_0);
- (NSObject *)delegate;
- (NSMutableArray __OF(NSNumber *) *)_allowedControlsForVideoMode PS_AVAILABLE_IOS(8_0);
- (NSMutableArray __OF(NSNumber *) *)_allowedControlsForStillImageMode PS_AVAILABLE_IOS(8_0);
- (NSMutableArray __OF(NSNumber *) *)_allowedControlsForPanoramaMode PS_AVAILABLE_IOS(8_0);
- (NSMutableArray __OF(NSNumber *) *)_allowedControlsForTimelapseMode PS_AVAILABLE_IOS(8_0);
- (BOOL)_isFlashButtonExpanded;
- (BOOL)_shouldHideFlashButton;
- (BOOL)shouldHideFlipButtonForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)shouldHideFlashButtonForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration PS_AVAILABLE_IOS(10_0);
- (void)setBackgroundStyle:(NSInteger)style animated:(BOOL)animated;
- (void)setStyle:(NSInteger)style animated:(BOOL)animated;
- (void)expandMenuButton:(UIButton *)button animated:(BOOL)animated;
- (void)collapseMenuButton:(UIButton *)button animated:(BOOL)animated;
@end

#endif

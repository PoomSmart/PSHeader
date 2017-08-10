#if FROM_IOS(9_0)

#import "CAMTopBar.h"
#import "CAMBottomBar.h"
#import "CAMViewfinderView.h"
#import "CAMZoomSlider.h"
#import "CAMElapsedTimeView.h"
#import "CAMFramerateIndicatorView.h"
#import "CAMFlashButton.h"
#import "CUShutterButton.h"
#import "CAMPreviewViewController.h"
#import "CUCaptureController.h"
#import "CAMCaptureGraphConfiguration.h"

@interface CAMViewfinderViewController : UIViewController
@property NSInteger _desiredFlashMode;
@property NSInteger _flashMode;
@property NSInteger _desiredTorchMode;
@property NSInteger _torchMode;
@property NSInteger _currentMode;
@property NSInteger _currentDevice;
@property NSInteger _desiredCaptureDevice;
@property(nonatomic, strong) CAMViewfinderView *view;
@property(retain, nonatomic) CAMFramerateIndicatorView *_framerateIndicatorView;
- (BOOL)_shouldHideTopBarForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration PS_AVAILABLE_IOS(10_0);
- (BOOL)_shouldHideFlashButtonForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration PS_AVAILABLE_IOS(10_0);
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_isCapturingTimelapse;
- (BOOL)isEmulatingImagePicker;
- (CAMTopBar *)_topBar;
- (CAMBottomBar *)_bottomBar;
- (CAMViewfinderView *)viewfinderView;
- (CAMZoomSlider *)_zoomSlider;
- (CAMElapsedTimeView *)_elapsedTimeView;
- (CAMFlashButton *)_flashButton;
- (CAMPreviewViewController *)_previewViewController;
- (CUShutterButton *)_shutterButton;
- (CUCaptureController *)_captureController;
- (CAMCaptureGraphConfiguration *)_currentGraphConfiguration;
- (NSInteger)timerDuration;
- (NSInteger)_timerDuration;
- (NSInteger)_resolvedTimerDuration;
- (NSInteger)_remainingCaptureTimerTicks;
- (NSMutableArray __OF(NSNumber *) *)modesForModeDial:(id)arg;
- (void)_stopCapturingVideo;
- (void)_handleShutterButtonPressed:(id)arg1;
- (void)_handleShutterButtonReleased:(id)arg1;
- (void)_captureStillImageWithCurrentSettings;
- (NSInteger)_numFilterSelectionsBeforeCapture;
- (void)_setNumFilterSelectionsBeforeCapture:(NSInteger)arg1;
- (void)_handleUserChangedFromDevice:(NSInteger)from toDevice:(NSInteger)to;
- (void)_collapseExpandedButtonsAnimated:(BOOL)animated;
- (NSInteger)_effectFilterTypeForMode:(NSInteger)mode;
- (BOOL)_isCapturingFromTimer;
- (void)captureController:(id)arg1 didChangeToMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (void)_flashButtonDidChangeFlashMode:(CAMFlashButton *)flashButton;
- (void)_setCurrentMode:(NSInteger)mode PS_DEPRECATED_IOS(9_0, 9_3);
@end

#endif

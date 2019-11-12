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
@property NSInteger flashMode;
@property NSInteger _flashMode;
@property NSInteger _desiredTorchMode;
@property NSInteger torchMode PS_AVAILABLE_IOS(10_0);;
@property NSInteger _torchMode PS_DEPRECATED_IOS(9_0, 9_3);;
@property NSInteger _currentMode;
@property NSInteger _currentDevice;
@property NSInteger _desiredCaptureDevice;
@property(nonatomic, strong) CAMViewfinderView *view;
@property(retain, nonatomic) CAMFramerateIndicatorView *_framerateIndicatorView;
@property(readonly, assign, nonatomic) CAMModeDial *_modeDial;
@property(readonly, assign, nonatomic) CAMTopBar *_topBar;
@property(readonly, assign, nonatomic) CAMBottomBar *_bottomBar;
@property(readonly, assign, nonatomic) CAMFlashButton *_flashButton;
@property(readonly, assign, nonatomic) CAMFlipButton *_flipButton;
@property(readonly, assign, nonatomic) CAMTimerButton *_timerButton;
@property(readonly, assign, nonatomic) CAMFilterButton *_filterButton;
@property(readonly, assign, nonatomic) CAMZoomSlider *_zoomSlider;
@property(readonly, assign, nonatomic) CAMHDRButton *_HDRButton;
@property(readonly, assign, nonatomic) CUShutterButton *_shutterButton;
@property(readonly, assign, nonatomic) CUShutterButton *_stillDuringVideoButton;
@property(readonly, assign, nonatomic) CAMElapsedTimeView *_elapsedTimeView;
@property(getter = _numFilterSelectionsBeforeCapture, setter = _setNumFilterSelectionsBeforeCapture:) NSUInteger _numFilterSelectionsBeforeCapture;
- (BOOL)_shouldHideTopBarForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration PS_AVAILABLE_IOS(10_0);
- (BOOL)_shouldHideFlashButtonForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration PS_AVAILABLE_IOS(10_0);
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (BOOL)_shouldEnableFlashButton;
- (BOOL)_isCapturingTimelapse;
- (BOOL)isEmulatingImagePicker;
- (CAMPreviewViewController *)_previewViewController;
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
- (void)_handleUserChangedFromDevice:(NSInteger)from toDevice:(NSInteger)to;
- (void)_collapseExpandedButtonsAnimated:(BOOL)animated;
- (NSInteger)_effectFilterTypeForMode:(NSInteger)mode;
- (BOOL)_isCapturingFromTimer;
- (void)captureController:(id)arg1 didChangeToMode:(NSInteger)mode device:(NSInteger)device PS_DEPRECATED_IOS(9_0, 9_3);
- (void)_flashButtonDidChangeFlashMode:(CAMFlashButton *)flashButton;
- (void)_setCurrentMode:(NSInteger)mode PS_DEPRECATED_IOS(9_0, 9_3);
- (void)_writeUserPreferences;
- (void)_readUserPreferencesAndHandleChanges PS_DEPRECATED_IOS(9_0, 12_4);
- (void)readUserPreferencesAndHandleChangesWithOverrides:(id)arg1 PS_AVAILABLE_IOS(13_0);
@end

#endif

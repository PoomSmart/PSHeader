#if FROM_IOS(8_0)

#import "CAMModeDial.h"
#import "CAMTopBar.h"
#import "CAMBottomBar.h"
#import "CAMFlashButton.h"
#import "CAMFlipButton.h"
#import "CAMTimerButton.h"
#import "CAMFilterButton.h"
#import "CAMHDRButton.h"
#import "CAMElapsedTimeView.h"
#import "CAMHDRBadge.h"
#import "CAMAvalancheSession.h"
#import "CAMApplicationSpec.h"
#import "CAMTorchPatternController.h"
#import "CAMPreviewView.h"
#import "CAMZoomSlider.h"

@interface CAMCameraView : UIView
@property(assign, nonatomic) NSInteger videoFlashMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(assign, nonatomic) NSInteger lastSelectedPhotoFlashMode;
@property(readonly, assign, nonatomic) CAMModeDial *_modeDial;
@property(readonly, assign, nonatomic) CAMTopBar *_topBar;
@property(readonly, assign, nonatomic) CAMBottomBar *_bottomBar;
@property(readonly, assign, nonatomic) CAMFlashButton *_flashButton;
@property(readonly, assign, nonatomic) CAMFlipButton *_flipButton;
@property(readonly, assign, nonatomic) CAMTimerButton *_timerButton;
@property(readonly, assign, nonatomic) CAMFilterButton *_filterButton;
@property(readonly, assign, nonatomic) CAMHDRButton *_HDRButton;
@property(readonly, assign, nonatomic) CAMShutterButton *_shutterButton;
@property(readonly, assign, nonatomic) CAMShutterButton *_stillDuringVideoButton;
@property(readonly, assign, nonatomic) CAMElapsedTimeView *_elapsedTimeView;
@property(assign, nonatomic, getter = isTallScreen) BOOL tallScreen;
@property(readonly, assign, nonatomic) BOOL isCameraReady;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(readonly, assign, nonatomic) CAMAvalancheSession *_avalancheSession;
@property(assign, nonatomic) BOOL HDRIsOn;
@property(readonly, assign, nonatomic) CGRect unzoomedPreviewFrame;
@property(getter = _isFlipping, setter = _setFlipping:) BOOL _flipping;
@property(getter = _numFilterSelectionsBeforeCapture, setter = _setNumFilterSelectionsBeforeCapture:) NSUInteger _numFilterSelectionsBeforeCapture;
- (CAMHDRBadge *)_HDRBadge;
- (BOOL)HDRIsOn;
- (BOOL)_performingDelayedCapture;
- (BOOL)_shouldHideHDRBadgeForMode:(NSInteger)mode;
- (void)_createHDRBadgeIfNecessary;
- (void)_updateHDRBadge;
- (void)cameraShutterReleased:(id)arg1;
- (void)takePicture;
- (NSInteger)_photoFlashMode;
- (NSInteger)_currentFlashMode;
- (BOOL)_isCapturing;
- (void)_updateTopBarStyleForDeviceOrientation:(NSInteger)orientation;
- (void)flashButtonDidChangeFlashMode:(id)arg1;
- (BOOL)_performingTimedCapture;
- (BOOL)hasInFlightCaptures;
- (void)_shutterButtonClicked;
- (void)pausePreview;
- (void)resumePreview;
- (void)_setShouldShowFocus:(BOOL)focus;
- (void)hideStaticClosedIris;
- (void)_updatePreviewWellImage:(UIImage *)image;
- (void)_setOverlayControlsEnabled:(BOOL)enabled;
- (void)_setFlashMode:(NSInteger)mode;
- (void)_clearFocusViews;
- (void)_setBottomBarEnabled:(BOOL)enabled;
- (void)setCameraButtonsEnabled:(BOOL)enabled;
- (void)takePictureOpenIrisAnimationFinished;
- (NSString *)modeDial:(CAMModeDial *)modeDial titleForItemAtIndex:(NSUInteger)index;
- (void)_switchFromCameraModeAtIndex:(NSUInteger)fromIndex toCameraModeAtIndex:(NSUInteger)toIndex;
- (void)_rotateCameraControlsAndInterface;
- (CGRect)_bottomBarFrame;
- (BOOL)bottomBarShouldHideFilterButton:(id)arg1;
- (BOOL)_shouldHideFilterButtonForMode:(NSInteger)mode;
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode;
- (BOOL)_shouldEnableFlashButton;
- (BOOL)_didEverMoveToWindow;
- (BOOL)_shouldEnableModeDial;
- (void)_handleVolumeUpEvents:(NSUInteger)events;
- (void)showZoomSlider;
- (void)_beginZooming;
- (void)_addZoomAnimationDisplayLinkWithSelector:(SEL)selector;
- (void)_setZoomFactor:(CGFloat)factor;
- (void)_endZooming;
- (void)_createZoomSliderIfNecessary;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode;
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (BOOL)_isVideoMode:(NSInteger)mode;
- (BOOL)_isHidingBadgesForFilterUI;
- (void)_layoutTopBarForOrientation:(NSInteger)orientation;
- (void)flashButtonModeDidChange:(NSInteger)mode;
- (void)_captureStillDuringVideo;
- (void)_setSwipeToModeSwitchEnabled:(BOOL)enabled;
- (NSInteger)_glyphOrientationForCameraOrientation:(NSInteger)cameraOrientation;
- (CAMApplicationSpec *)spec;
- (CAMTorchPatternController *)_torchPatternController;
- (NSInteger)_HDRMode;
- (NSInteger)_currentTimerDuration;
- (NSInteger)_remainingDelayedCaptureTicks;
- (CAMPreviewView *)previewView;
- (CAMZoomSlider *)_zoomSlider;
- (BOOL)_shouldUseAvalancheForDelayedCapture;
- (BOOL)_avalancheCaptureInProgress;
- (void)_teardownAvalancheCaptureTimer;
- (void)_startDelayedCapture;
- (void)_updateForFocusCapabilities;
- (void)_collapseExpandedButtonsAnimated:(BOOL)animated;
@end

#endif

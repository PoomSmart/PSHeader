#if TO_IOS(7_1)

#import "PLVideoPreviewView.h"
#import "CAMModeDial.h"
#import "CAMTopBar.h"
#import "CAMBottomBar.h"
#import "CAMFlashButton.h"
#import "CAMFlipButton.h"
#import "CAMFilterButton.h"
#import "CAMHDRButton.h"
#import "CAMElapsedTimeView.h"
#import "CAMHDRBadge.h"
#import "CAMAvalancheSession.h"
#import "CAMApplicationSpec.h"
#import "CAMPreviewView.h"

@class CAMModeDial, CAMTopBar, CAMBottomBar, CAMFlashButton, CAMFlipButton, CAMFilterButton, CAMHDRButton, CAMShutterButton, CAMElapsedTimeView, CAMHDRBadge, CAMAvalancheSession, CAMApplicationSpec;

@interface PLCameraView : UIView
@property(retain, nonatomic) UIToolbar *bottomButtonBar;
@property NSInteger photoFlashMode;
@property(assign, nonatomic) NSInteger videoFlashMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(assign, nonatomic) NSInteger lastSelectedPhotoFlashMode;
@property(readonly, assign, nonatomic) CAMModeDial *_modeDial PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMTopBar *_topBar PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMBottomBar *_bottomBar PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMFlashButton *_flashButton PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMFlipButton *_flipButton PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMFilterButton *_filterButton;
@property(readonly, assign, nonatomic) CAMHDRButton *_HDRButton PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMShutterButton *_shutterButton PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMShutterButton *_stillDuringVideoButton PS_AVAILABLE_IOS(7_0);
@property(readonly, assign, nonatomic) CAMElapsedTimeView *_elapsedTimeView PS_AVAILABLE_IOS(7_0);
@property(assign, nonatomic, getter = isTallScreen) BOOL tallScreen;
@property(readonly, assign, nonatomic) BOOL isCameraReady;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(readonly, assign, nonatomic) CAMAvalancheSession *_avalancheSession PS_AVAILABLE_IOS(7_0);
@property(assign, nonatomic) BOOL HDRIsOn;
@property(readonly, assign, nonatomic) CGRect unzoomedPreviewFrame;
- (CAMHDRBadge *)_HDRBadge PS_AVAILABLE_IOS(7_0);
- (BOOL)HDRIsOn;
- (BOOL)_shouldHideHDRBadgeForMode:(NSInteger)mode;
- (void)_createHDRBadgeIfNecessary;
- (void)_updateHDRBadge;
- (void)cameraShutterReleased:(id)arg1;
- (void)takePicture;
- (NSInteger)_photoFlashMode;
- (NSInteger)_currentFlashMode;
- (BOOL)_isCapturing;
- (void)_updateTopBarStyleForDeviceOrientation:(NSInteger)orientation PS_AVAILABLE_IOS(7_0);
- (void)flashButtonDidChangeFlashMode:(id)arg1;
- (BOOL)_performingTimedCapture PS_AVAILABLE_IOS(7_0);
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
- (NSString *)modeDial:(CAMModeDial *)modeDial titleForItemAtIndex:(NSUInteger)index PS_AVAILABLE_IOS(7_0);
- (void)_switchFromCameraModeAtIndex:(NSUInteger)fromIndex toCameraModeAtIndex:(NSUInteger)toIndex;
- (void)_rotateCameraControlsAndInterface;
- (CGRect)_bottomBarFrame;
- (BOOL)bottomBarShouldHideFilterButton:(id)arg1 PS_AVAILABLE_IOS(7_0);
- (BOOL)_shouldHideFilterButtonForMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_shouldEnableFlashButton;
- (BOOL)_didEverMoveToWindow;
- (BOOL)_shouldEnableModeDial PS_AVAILABLE_IOS(7_0);
- (void)_handleVolumeUpEvents:(NSUInteger)events;
- (void)showZoomSlider;
- (void)_beginZooming;
- (void)_addZoomAnimationDisplayLinkWithSelector:(SEL)selector;
- (void)_setZoomFactor:(CGFloat)factor;
- (void)_endZooming;
- (void)_createZoomSliderIfNecessary;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_isStillImageMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_isVideoMode:(NSInteger)mode PS_AVAILABLE_IOS(7_0);
- (BOOL)_isHidingBadgesForFilterUI;
- (void)_layoutTopBarForOrientation:(NSInteger)orientation PS_AVAILABLE_IOS(7_0);
- (void)flashButtonModeDidChange:(NSInteger)mode;
- (void)_captureStillDuringVideo;
- (void)_setSwipeToModeSwitchEnabled:(BOOL)enabled;
- (NSInteger)_glyphOrientationForCameraOrientation:(NSInteger)cameraOrientation;
- (CAMApplicationSpec *)spec PS_AVAILABLE_IOS(7_0);
- (PLVideoPreviewView *)videoPreviewView;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (void)_setSettingsButtonAlpha:(CGFloat)alpha duration:(NSTimeInterval)duration PS_TO_IOS(6_1);
- (void)_disableBottomBarForContinuousCapture;
- (void)_setBottomBarEnabled:(BOOL)enabled;
- (void)_setShouldShowFocus:(BOOL)show;
- (void)_checkDiskSpaceAfterCapture;
- (void)openIrisWithDidFinishSelector:(SEL)openIrisWith withDuration:(NSTimeInterval)duration;
- (void)closeIrisWithDidFinishSelector:(SEL)closeIrisWith withDuration:(NSTimeInterval)duration;
- (void)_loadZoomSliderResources;
@end

#endif

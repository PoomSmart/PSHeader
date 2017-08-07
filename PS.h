#import "iOSVersions.h"
#import "CameraMacros.h"
#import "Misc.h"
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/CAFilter.h>

#define FOR_IOS8_UP __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
#define FOR_IOS7_UP __IPHONE_OS_VERSION_MAX_ALLOWED >= 70000

//#define PS_DONATE_URL @"https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=GBQGZL8EFMM86"
#define PS_DONATE_URL @"https://poomsmart.github.io/repo/"
#define PS_TWITTER_URL @"https://twitter.com/PoomSmart"

@interface CAMCameraSpec : NSObject
+ (instancetype)specForCurrentPlatform;
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@end

@interface CAMApplicationSpec : CAMCameraSpec
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@property(readonly) NSInteger modeDialOrientation;
@property(readonly) NSInteger bottomBarOrientation;
@end

@interface CAMPhoneApplicationSpec : CAMApplicationSpec
@end

@interface CAMPadApplicationSpec : CAMApplicationSpec
@end

@interface AVCaptureDevice (Addition)
- (BOOL)isFaceDetectionSupported;
@end

@interface AVCaptureFigVideoDevice : AVCaptureDevice
@end

@interface PLCameraButton : UIButton
@end

@protocol zoomSliderDelegate
- (void)makeInvisible;
- (void)makeVisible;
- (void)makeVisibleAnimated:(BOOL)animated;
@end

@interface PLCameraZoomSlider : UISlider <zoomSliderDelegate>
@end

@interface PLCropOverlayBottomBar : UIToolbar
- (void)_setVisibility:(BOOL)visible;
@end

@interface PLCameraButtonBar : UIToolbar
@property(retain, nonatomic) PLCameraButton *cameraButton;
- (UIView *)_backgroundView;
- (void)_setVisibility:(BOOL)visible;
@end

@interface CAMImageWell : UIView
@end

@interface CAMZoomSlider : UISlider <zoomSliderDelegate>
@property(getter = isMinimumAutozooming) BOOL minimumAutozooming;
@property(getter = isMaximumAutozooming) BOOL maximumAutozooming;
@property(readonly) NSTimer *_visibilityTimer;
@property(getter = _isAutozooming, setter = _setAutozooming :) BOOL _autozooming;
@property(readonly) UIImageView *_thumbImageView;
@property(readonly) UIView *_minTrackMaskView;
@property(readonly) UIView *_maxTrackMaskView;
@property(assign, nonatomic) UIView *delegate;
- (void)_commonCAMZoomSliderInitialization;
- (void)stopVisibilityTimer;
- (void)startVisibilityTimer;
- (void)_endAutozooming;
- (void)_beginAutozooming;
- (void)_updateAutozooming;
- (void)_hideZoomSlider:(id)arg1;
- (void)_postHideZoomSliderAnimation;
- (BOOL)visibilityTimerIsValid;
@end

@protocol flashButtonDelegate
@property(assign, nonatomic, getter = isAutoHidden) BOOL autoHidden;
@property NSInteger flashMode;
- (void)_expandAnimated:(BOOL)animated;
- (void)_collapseAndSetMode:(NSInteger)mode animated:(BOOL)animated;
@end

@interface CAMExpandableMenuButton : UIView
@property NSUInteger selectedIndex;
+ (double)expansionDuration;
- (NSArray *)_menuItems;
- (void)setHighlighted:(BOOL)highlighted forIndex:(NSUInteger)index;
@end

@interface CAMButtonLabel : UILabel
@property BOOL useLegibilityView;
@property BOOL wantsLegibilityShadow;
@end

@interface PLCameraLevelView : UIView
@end

@interface CAMPanoramaLevelView : UIView
@end

@interface PLCameraPanoramaBrokenArrowView : UIView
@end

@interface CAMPanoramaArrowView : UIView
@end

@interface PLCameraPanoramaTextLabel : UILabel
@end

@interface CAMPanoramaLabel : UILabel
@end

@interface PLIOSurfaceData : NSData
@end

@interface PLReorientingButton : UIButton
@property(assign, nonatomic) CGFloat endCapRadius;
- (id)initWithFrame:(CGRect)frame;
- (void)setButtonOrientation:(NSInteger)orientation animated:(BOOL)animated;
@end

@protocol panoramaViewDelegate
- (void)setCaptureDirection:(NSInteger)direction;
- (void)_arrowWasTapped:(id)arg1;
@end

@interface CAMPanoramaView : UIView <panoramaViewDelegate>
@end

@interface PLCameraPanoramaView : UIView <panoramaViewDelegate>
@end

@interface CAMPanoramaViewController : UIViewController
- (void)_handleDirectionChange:(id)arg1;
@end

@interface CAMTriStateButton : UIControl
@property(assign, nonatomic) NSInteger flashMode;
@end

@interface CAMFlashButton : UIButton <flashButtonDelegate>
@property(assign, nonatomic) NSInteger orientation;
@property(readonly) UIImageView *_glyphView;
@property(readonly, assign, nonatomic) UIImageView *_flashIconView;
@property(readonly, assign, nonatomic) UIImageView *_iconView;
@property(readonly, assign, nonatomic) CAMButtonLabel *_offLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_onLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_autoLabel;
@property(assign, nonatomic) NSUInteger selectedIndex;
@property(getter = isUnavailable) BOOL unavailable;
@property BOOL allowsAutomaticFlash;
- (UIView *)delegate;
- (BOOL)isExpanded;
- (void)collapseMenuAnimated:(BOOL)animated;
- (void)expandMenuAnimated:(BOOL)animated;
- (void)collapseMenuAnimated:(BOOL)animated;
- (NSUInteger)indexForMode:(NSInteger)mode;
@end

@interface CAMTorchPattern : NSObject
- (id)initWithType:(NSInteger)type;
@end

@interface CAMTorchPatternController : NSObject
- (void)blink;
- (void)doubleBlink; // type 3
@end

@interface CAMFilterButton : UIButton
@property(readonly) UIImageView *_circlesImageView;
@property(getter = isOn) BOOL on;
@property UIEdgeInsets tappableEdgeInsets;
+ (CAMFilterButton *)filterButton;
- (void)_commonCAMFilterButtonInitialization;
- (UIImage *)_filterImage;
- (UIImage *)_filterOnImage;
- (float)_selectedIndicatorAlpha;
- (UIEdgeInsets)alignmentRectInsets;
- (id)initWithCoder:(id)coder;
- (id)initWithFrame:(CGRect)frame;
- (CGSize)intrinsicContentSize;
@end

@interface CAMHDRButton : UIButton
@property(readonly, nonatomic) CAMButtonLabel *_onLabel; // @synthesize _onLabel=__onLabel;
@property(readonly, nonatomic) CAMButtonLabel *_offLabel; // @synthesize _offLabel=__offLabel;
@property(readonly, nonatomic) CAMButtonLabel *_hdrLabel; // @synthesize _hdrLabel=__hdrLabel;
@property(nonatomic) NSInteger orientation; // @synthesize orientation=_orientation;
@property(nonatomic, getter = isOn) BOOL on; // @synthesize on=_on;
- (void)_updateFromOrientationChangeAnimated:(BOOL)arg1;
- (void)_updateFrameFromOrientation;
- (CGAffineTransform)_transformForOrientation:(NSInteger)arg1;
- (void)_updateLabelsFromOrientation;
- (void)_updateFromOnState;
- (void)setOrientation:(NSInteger)arg1 animated:(BOOL)arg2;
- (void)layoutSubviews;
- (void)_layoutForLandscapeOrientation;
- (void)_layoutForPortraitOrientation;
- (CGSize)sizeThatFits:(CGSize)arg1;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(CGRect)arg1;
- (void)_commonCAMHDRButtonInitialization;
@end

@interface CAMTimerButton : CAMExpandableMenuButton
@property NSInteger duration;
- (NSString *)titleForMenuItemAtIndex:(NSUInteger)index;
- (NSInteger)numberOfMenuItems;
@end

/*typedef struct CAMShutterButtonSpec {
        double outerRingDiameter;
        double outerRingStrokeWidth;
        double stopSquareSideLength;
        double stopSquareCornerRadius;
   } _spec;*/

@interface CAMShutterButton : UIButton {
}
+ (CAMShutterButton *)shutterButton;
+ (CAMShutterButton *)tinyShutterButton;
+ (CAMShutterButton *)smallShutterButton;
@property(getter = isPulsing, setter = setPulsing:) BOOL pulsing;
@property BOOL spinning;
@property NSInteger mode;
- (CGSize)intrinsicContentSize;
- (UIColor *)_colorForMode:(NSInteger)mode;
- (UIView *)_innerView;
- (UIView *)_outerView;
- (void)_updateOuterAndInnerLayers;
//- (void)_setSpec:(CAMShutterButtonSpec)spec;
@end

@interface CAMFlipButton : UIButton
- (UIImage *)_flipImage;
@end

@interface PLCameraFlashButton : PLReorientingButton <flashButtonDelegate>
- (UIView *)delegate;
@end

@interface CAMModeDialItem : UIView
@property(retain, nonatomic) NSString *title;
- (BOOL)isSelected;
- (CAShapeLayer *)_scalableTextLayer;
@end

@interface CAMModeDial : UIView
@property(retain, nonatomic) NSMutableArray *_items;
@property(retain, nonatomic) UIView *_itemsContainerView;
@property NSUInteger selectedIndex;
@property NSInteger orientation;
#if FOR_IOS8_UP
+ (BOOL)wantsVerticalModeDialForTraitCollection:(UITraitCollection *)traitCollection;
#endif
+ (BOOL)wantsVerticalModeDialForLayoutStyle:(NSInteger)style;
@end

@interface CAMElapsedTimeView : UIView
@property(readonly) UILabel *_timeLabel;
@property(readonly) UIImageView *_recordingImageView;
@property(readonly) NSTimer *_updateTimer;
@property(readonly) NSDate *_startTime;
- (void)_beginRecordingAnimation;
- (void)_endRecordingAnimation;
- (void)startTimer;
- (void)endTimer;
- (void)resetTimer;
- (void)_update:(NSTimer *)timer;
@end

@protocol slalomIndicatorViewDelegate

@end

@interface CAMSlalomIndicatorView : UIView <slalomIndicatorViewDelegate>
- (void)setFramesPerSecond:(NSInteger)sec;
@end

@interface CAMFramerateIndicatorView : UIView <slalomIndicatorViewDelegate>
@property NSInteger style;
- (NSInteger)_framesPerSecond;
- (NSString *)_labelText;
- (void)_updateLabels;
- (UILabel *)_topLabel;
- (UILabel *)_bottomLabel;
- (UIImageView *)_borderImageView;
@end

@class CAMCaptureGraphConfiguration;

@interface CAMTopBar : UIView
@property(readonly, assign, nonatomic) UIView *_backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMFlashButton *flashButton;
@property(retain, nonatomic) CAMTimerButton *timerButton;
@property(retain, nonatomic) CAMFlipButton *flipButton;
@property(retain, nonatomic) CAMElapsedTimeView *elapsedTimeView;
@property(readonly, assign, nonatomic, getter = isFloating) BOOL floating;
@property(assign, nonatomic) NSInteger orientation;
@property(assign, nonatomic) NSInteger style;
@property(assign, nonatomic) NSInteger backgroundStyle;
- (UIButton *)_expandedMenuButton;
- (NSObject /*<cameraViewDelegate>*/ *)delegate;
- (NSMutableArray *)_allowedControlsForVideoMode;
- (BOOL)_isFlashButtonExpanded;
- (BOOL)_shouldHideFlashButton;
- (BOOL)shouldHideFlipButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)shouldHideFlashButtonForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration;
- (void)setBackgroundStyle:(NSInteger)style animated:(BOOL)animated;
- (void)setStyle:(NSInteger)style animated:(BOOL)animated;
- (void)expandMenuButton:(UIButton *)button animated:(BOOL)animated;
- (void)collapseMenuButton:(UIButton *)button animated:(BOOL)animated;
@end

@interface CAMBottomBar : UIView
@property(readonly, assign, nonatomic) UIView *backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMFlashButton *flashButton;
@property(retain, nonatomic) CAMFlipButton *flipButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMTimerButton *timerButton;
@property(retain, nonatomic) CAMShutterButton *shutterButton;
@property(retain, nonatomic) CAMShutterButton *stillDuringVideoButton;
@property(retain, nonatomic) CAMImageWell *imageWell;
@property(retain, nonatomic) CAMModeDial *modeDial;
@property(retain, nonatomic) CAMSlalomIndicatorView *slalomIndicatorView;
@property(assign) NSInteger layoutStyle;
#if FOR_IOS8_UP
+ (BOOL)wantsVerticalBarForTraitCollection:(UITraitCollection *)traitCollection;
#endif
+ (BOOL)wantsVerticalBarForLayoutStyle:(NSInteger)style;
- (UIButton *)_expandedMenuButton;
- (NSObject /*<cameraViewDelegate>*/ *)delegate;
- (UIView *)backgroundView;
- (CGSize)sizeThatFits:(CGSize)fits;
- (CGSize)intrinsicContentSize;
- (CGRect)alignmentRectForFrame:(CGRect)frame;
- (UIView *)_shutterButtomBottomLayoutSpacer;
- (BOOL)_isTimerButtonExpanded;
- (UIView *)_filterButtonBottomLayoutSpacer;
- (void)_setupHorizontalFilterButtonConstraints;
- (void)_setupVerticalFilterButtonConstraints;
- (BOOL)shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)shouldHideFlipButtonForMode:(NSInteger)mode device:(NSInteger)device;
@end

@interface CAMAvalancheSession : NSObject
@property(readonly, assign, nonatomic) NSUInteger numberOfPhotos;
@end

@interface CAMAvalancheCaptureService : NSObject
- (CAMAvalancheSession *)_activeAvalancheSession;
@end

@protocol cameraPreviewViewDelegate
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property float dimmingStrength;
- (void)setDimmingStrength:(float)strength duration:(double)duration;
@end

@interface CAMPreviewView : UIView <cameraPreviewViewDelegate>
@end

@interface PLCameraPreviewView : UIView <cameraPreviewViewDelegate>
@end

@interface PLPreviewOverlayView : UIView
@end

@interface PLCameraVideoStillCaptureButton : PLReorientingButton
@end

@interface PLCameraOptionsButton : PLReorientingButton
@end

@interface PLCameraSettingsView
@end

@interface PLCameraSettingsGroupView : UIView
@property(retain, nonatomic) UIView *accessorySwitch;
- (void)setType:(NSInteger)type;
- (void)setTitle:(NSString *)title;
@end

@interface PUAvalancheReviewControllerPhoneSpec : NSObject
@end

@interface PUPhotoEditViewController : NSObject
- (UIViewController *)delegate;
- (void)_handleDoneButton:(id)arg1;
@end

@protocol effectFilterManagerDelegate
+ (NSObject <effectFilterManagerDelegate> *)sharedInstance;
- (NSUInteger)blackAndWhiteFilterStartIndex;
- (NSUInteger)filterCount;
- (CIFilter *)filterForIndex:(NSUInteger)index;
- (void)_addEffectNamed:(NSString *)name aggdName:(NSString *)aggdName filter:(CIFilter *)filter;
@end

@interface PLEffectFilterManager : NSObject <effectFilterManagerDelegate>
@end

@interface CAMEffectFilterManager : NSObject <effectFilterManagerDelegate>
+ (NSString *)displayNameForType:(NSInteger)type;
@end

@protocol cameraGLViewDelegate
@property CGSize fixedSize;
- (CGFloat)drawableHeight;
- (CGFloat)drawableWidth;
@end

@interface PLGLView : UIView <cameraGLViewDelegate>
@end

@interface CAMGLView : UIView <cameraGLViewDelegate>
@end

@protocol effectsGridViewDelegate
- (NSUInteger)_cellCount;
- (NSUInteger)_filterIndexForGridIndex:(NSUInteger)index;
- (BOOL)isBlackAndWhite;
- (BOOL)isSquare;
- (CGRect)rectForFilterIndex:(NSUInteger)index;
- (CGRect)_squareCropFromRect:(CGRect)rect;
@end

@interface PLEffectsGridView : UIView <effectsGridViewDelegate, cameraGLViewDelegate>
@end

@interface CAMEffectsGridView : UIView <effectsGridViewDelegate, cameraGLViewDelegate>
- (CGRect)rectForFilterType:(NSInteger)type;
@end

@interface PLEffectsFullsizeView : PLGLView
@end

@interface CAMEffectsFullsizeView : CAMGLView
@property NSInteger filterType;
@end

@interface PLEffectSelectionViewController : UIViewController
- (void)_setSelectedIndexPath:(NSIndexPath *)indexPath;
@end

@interface CAMEffectSelectionViewController : UIViewController
- (void)_setSelectedIndexPath:(NSIndexPath *)indexPath;
@end

@interface PLImageAdjustmentView : UIView
@property(retain) UIImage *editedImage;
- (void)setEditedImage:(UIImage *)image;
@end

@interface _PLManagedAsset : NSObject
- (NSInteger)orientationValue;
@end

@interface PLManagedAsset : _PLManagedAsset
@property(readonly, nonatomic) NSString *pathForImageFile;
@property(readonly, nonatomic) NSString *pathForOriginalFile;
@property(readonly, nonatomic) NSString *pathForAdjustmentFile;
@property short kindSubtype;
@property short savedAssetType;
@property BOOL hasAdjustments;
- (BOOL)isMogul;
- (BOOL)isVideo;
@end

@interface PLVideoView : UIView
@property(readonly) PLManagedAsset *videoCameraImage;
- (BOOL)isPlaying;
- (BOOL)canEdit;
- (BOOL)_canAccessVideo;
- (BOOL)_mediaIsPlayable;
- (BOOL)_mediaIsVideo;
- (BOOL)_shouldShowSlalomEditor;
@end

@protocol photoBrowserDelegate
@property(assign, nonatomic) BOOL isCameraApp;
@property(readonly, assign, nonatomic) PLVideoView *currentVideoView;
- (PLManagedAsset *)currentAsset;
- (BOOL)isEditingVideo;
- (UINavigationBar *)navigationBar;
@end

@interface PUPhotoBrowserController : UIViewController <photoBrowserDelegate, UIActionSheetDelegate>
- (id)_toolbarButtonForIdentifier:(NSString *)ident;
- (void)photoEditController:(PUPhotoEditViewController *)controller didFinishWithSavedChanges:(BOOL)change;
@end

@interface PLPublishingAgent : NSObject
@property BOOL enableHDUpload;
@property BOOL mediaIsHDVideo;
@property NSInteger remakerMode;
@property NSInteger selectedOption;
+ (PLPublishingAgent *)publishingAgentForBundleNamed:(NSString *)name toPublishMedia:(PLManagedAsset *)media;
- (NSInteger)_remakerModeForSelectedOption;
- (void)_transcodeVideo:(PLManagedAsset *)asset;
@end

@interface PLPhotoBrowserController : UIViewController <photoBrowserDelegate, UIActionSheetDelegate>
@property(assign, nonatomic) BOOL isCameraApp;
@end

@interface FigCaptureSourceFormat : NSObject
- (id)initWithFigCaptureStreamFormatDictionary:(id)dictionary;
- (id)AVCaptureSessionPresets;
- (BOOL)isPhotoFormat;
- (BOOL)isHighResPhotoFormat;
@end

@interface PFVideoAdjustments : NSObject
+ (CMTimeRange)defaultSlowMotionTimeRangeForDuration:(CMTime)duration;
+ (float)defaultSlowMotionRateForNominalFrameRate:(float)framerate;
@property CMTimeRange slowMotionTimeRange;
- (id)initWithURL:(NSURL *)url;
- (id)initWithSlowMotionTimeRange:(CMTimeRange)range rate:(float)rate;
- (BOOL)isRecognizedFormat;
@end

@interface AVCaptureDeviceFormat_FigRecorder : NSObject
- (id)initWithDictionary:(NSDictionary *)dictionary;
@end

@interface AVAssetExportSession (Addition)
- (void)setMinVideoFrameDuration:(CMTime)duration;
@end

@interface PLCIFilterUtilties : NSObject
+ (CIImage *)outputImageFromFilters:(NSArray *)filters inputImage:(CIImage *)inputImage orientation:(UIImageOrientation)orientation copyFiltersFirst:(BOOL)copyFirst;
@end

@interface PLEditPhotoController : UIViewController <UIActionSheetDelegate>
@property(readonly) CGRect normalizedCropRect;
- (UINavigationItem *)navigationItem;
- (CIImage *)_newCIImageFromUIImage:(UIImage *)image;
- (NSArray *)_currentNonGeometryFiltersWithEffectFilters:(NSArray *)filters;
- (NSArray *)_cropAndStraightenFiltersForImageSize:(CGSize)size forceSquareCrop:(BOOL)crop forceUseGeometry:(BOOL)geometry;
- (void)_setControlsEnabled:(BOOL)enabled animated:(BOOL)animated;
- (void)_presentSavingHUD;
- (void)_dismissSavingHUD;
- (void)save:(UIBarButtonItem *)item;
- (void)cancel:(UIBarButtonItem *)item;
- (void)saveAdjustments;
@end

@interface CAMHDRBadge : UIButton
@end

@protocol cameraViewDelegate
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
- (CAMHDRBadge *)_HDRBadge;
- (BOOL)HDRIsOn;
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
@end

@interface PLCameraView : UIView <cameraViewDelegate>
@property(retain, nonatomic) UIToolbar *bottomButtonBar;
@property NSInteger photoFlashMode;
//- (PLVideoPreviewView *)videoPreviewView;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (void)_setSettingsButtonAlpha:(CGFloat)alpha duration:(double)duration;
- (void)_disableBottomBarForContinuousCapture;
- (void)_setBottomBarEnabled:(BOOL)enabled;
- (void)_setShouldShowFocus:(BOOL)show;
- (void)_checkDiskSpaceAfterCapture;
- (void)openIrisWithDidFinishSelector:(SEL)openIrisWith withDuration:(float)duration;
- (void)closeIrisWithDidFinishSelector:(SEL)closeIrisWith withDuration:(float)duration;
- (void)_loadZoomSliderResources;
@end

@interface PLUICameraViewController : UIViewController
- (PLCameraView *)_cameraView;
@end

@interface CAMCameraView : UIView <cameraViewDelegate>
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
@end

@protocol cameraEffectsRendererDelegate
@property(assign, nonatomic, getter = isShowingGrid) BOOL showGrid;
- (void)setShowGrid:(BOOL)show animated:(BOOL)animated;
@end

@interface PLCameraEffectsRenderer : NSObject <cameraEffectsRendererDelegate>
@end

@interface CAMEffectsRenderer : NSObject <cameraEffectsRendererDelegate>
- (void)_previewStarted:(id)arg1;
- (void)_deviceStarted:(id)arg1;
- (void)_setPreviewStartedNotificationNeeded:(BOOL)arg1;
@end

@interface CAMClosedViewfinderController : NSObject
- (void)addClosedViewfinderReason:(NSInteger)reason;
- (void)removeClosedViewfinderReason:(NSInteger)reason;
@end

@protocol cameraControllerDelegate
@property(assign, nonatomic) AVCaptureDevice *currentDevice;
@property(assign, nonatomic) AVCaptureOutput *currentOutput;
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *previewLayer;
@property(readonly, assign, nonatomic) AVCaptureSession *currentSession;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(readonly, assign, nonatomic) NSInteger cameraOrientation;
@property(assign, nonatomic, getter = isHDREnabled) BOOL HDREnabled;
@property(retain) NSObject <cameraEffectsRendererDelegate> *effectsRenderer;
@property(assign, nonatomic) CGFloat videoZoomFactor;
@property(getter = _isPreviewPaused, setter = _setPreviewPaused :) BOOL _previewPaused;
+ (BOOL)isStillImageMode:(NSInteger)mode;
- (BOOL)_isSessionReady;
- (BOOL)isCameraApp;
- (BOOL)canCaptureVideo;
- (BOOL)isChangingModes;
- (BOOL)isReady;
- (NSMutableArray *)supportedCameraModes;
- (UIView <cameraViewDelegate> *)delegate;
- (BOOL)isCapturingVideo;
- (void)_setFlashMode:(NSInteger)mode force:(BOOL)force;
- (void)_suggestedHDRChanged;
- (BOOL)isFocusLockSupported;
- (BOOL)flashWillFire;
- (void)pausePreview;
- (void)resumePreview;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
- (void)setFocusDisabled:(BOOL)disabled;
- (void)_lockFocus:(BOOL)focus lockExposure:(BOOL)exposure lockWhiteBalance:(BOOL)whiteBalance;
- (NSUInteger)_activeFilterIndex;
- (double)mogulFrameRate;
- (CGFloat)maximumZoomFactorForDevice:(AVCaptureDevice *)device;
- (BOOL)_lockCurrentDeviceForConfiguration;
- (void)_unlockCurrentDeviceForConfiguration;
- (void)setFocusDisabled:(BOOL)disabled;
@end

@interface PLCameraController : NSObject <cameraControllerDelegate>
@property BOOL performingTimedCapture;
- (PLCameraView *)delegate;
- (BOOL)_isVideoMode:(NSInteger)mode;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
@end

@interface CAMCaptureController : NSObject <cameraControllerDelegate>
@property BOOL performingAvalancheCapture;
+ (BOOL)isStillImageMode:(NSInteger)mode;
+ (BOOL)isVideoMode:(NSInteger)mode;
- (CAMCameraView *)delegate;
- (BOOL)isCapturingPanorama;
- (BOOL)isCapturingTimelapse;
- (CAMAvalancheCaptureService *)_avalancheCaptureService;
- (void)setFaceDetectionEnabled:(BOOL)enabled forceDisableImageProcessing:(BOOL)disableIP;
@end

@interface PLCameraController (CamRotate)
- (BOOL)isSyncOrientation;
@end

@interface CAMCaptureController (CamRotate)
- (BOOL)isSyncOrientation;
@end

@interface CAMLegibilityViewHelper : NSObject
+ (UIImage *)_imageFromLabel:(UILabel *)label sizeToFit:(BOOL)fit;
@end

@interface CAMCameraViewController : UIViewController
@end

@interface CAMApplicationViewController : CAMCameraViewController
@end

@interface DeferredPUCameraApplicationViewController : CAMApplicationViewController <UIActionSheetDelegate>
@end

@interface PUAbstractAlbumListViewController : UIViewController
- (UIBarButtonItem *)_internalButtonItem;
@end

@interface PUAlbumListViewController : UIViewController
- (UIBarButtonItem *)_internalButtonItem;
@end

@interface PURootSettings : NSObject
+ (void)presentSettingsController;
@end

@interface PUPhotoEditProtoSettings : NSObject
@property BOOL useOldPhotosEditor2;
@end

@interface PLPhotoEffect : NSObject
+ (NSArray *)allEffects;
+ (PLPhotoEffect *)_effectWithIdentifier:(NSString *)identifier CIFilterName:(NSString *)filterName displayName:(NSString *)displayName;
+ (PLPhotoEffect *)_effectWithIdentifier:(NSString *)identifier;
+ (PLPhotoEffect *)_effectWithCIFilterName:(NSString *)identifier;
+ (NSUInteger)indexOfEffectWithIdentifier:(NSString *)identifier;
- (NSString *)displayName;
- (NSString *)filterIdentifier;
- (NSString *)CIFilterName;
@end

@interface PLProgressHUD : UIView
- (void)done;
- (void)showInView:(UIView *)view;
- (void)hide;
- (void)setText:(NSString *)text;
@end

@interface PBFilter : CIFilter
@end

@interface CIColorPosterize : CIFilter
@property(retain, nonatomic) NSNumber *inputLevels;
@end

@interface CIColorMonochrome : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) CIColor *inputColor;
@end

@interface CIFalseColor : CIFilter
@property(retain, nonatomic) CIColor *inputColor0;
@property(retain, nonatomic) CIColor *inputColor1;
@end

@interface CISepiaTone : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@end

@interface CIVibrance : CIFilter
@property(retain, nonatomic) NSNumber *inputAmount;
@end

@interface CIBloom : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIGloom : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIGaussianBlur : CIFilter
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIThermal : CIFilter
@end

@interface CIXRay : CIFilter
@end

@interface CIPixellate : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputScale;
@end

@interface CIStretch : CIFilter
@property(retain, nonatomic) CIVector *inputPoint;
@property(retain, nonatomic) CIVector *inputSize;
@end

@interface CITwirlDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@property(retain, nonatomic) NSNumber *inputAngle;
@end

@interface CIHoleDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIPinchDistortion : CIFilter
@property(retain, nonatomic) NSNumber *inputScale;
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIMirror : CIFilter
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) CIVector *inputPoint;
@end

@interface CIWrapMirror : CIFilter
@end

@interface CISharpenLuminance : CIFilter
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

@interface CITriangleKaleidoscope : CIFilter
@property(retain, nonatomic) NSNumber *inputDecay;
@property(retain, nonatomic) NSNumber *inputSize;
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) CIVector *inputPoint;
@end

@interface CILightTunnel : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRotation;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CICircleSplashDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CICircularScreen : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputWidth;
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

@interface CILineScreen : CIFilter
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) NSNumber *inputWidth;
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

/*@interface PSViewController (Addition)
   - (void)setView:(id)view;
   - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
   - (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
   - (void)viewDidLoad;
   @end

   @interface UITableViewCell (Addition)
   - (id)initWithFrame:(CGRect)frame reuseIdentifier:(NSString *)identifier;
   @end

   @interface PSTableCell (Addition)
   @property(retain, nonatomic) UIView *accessoryView;
   - (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier specifier:(PSSpecifier *)specifier;
   @end

   @interface PSSwitchTableCell : PSControlTableCell
   - (id)initWithStyle:(NSInteger)arg1 reuseIdentifier:(id)identifier specifier:(id)spec;
   @end*/

@interface SBSRestartRenderServerAction : NSObject
+ (SBSRestartRenderServerAction *)restartActionWithTargetRelaunchURL:(NSURL *)url;
@end

@interface FBSSystemService : NSObject
+ (FBSSystemService *)sharedService;
- (void)sendActions:(NSSet *)actions withResult:(id)result;
@end

@interface FigCaptureStillImageSettings : NSObject
@property NSUInteger outputWidth;
@property NSUInteger outputHeight;
@property NSUInteger thumbnailWidth;
@property NSUInteger thumbnailHeight;
@property BOOL outputMirroring;
@property NSInteger outputOrientation;
@property BOOL thumbnailEnabled;
@property BOOL thumbnailMirroring;
@property NSInteger thumbnailOrientation;
@property NSInteger flashMode;
@property NSInteger HDRMode;
@property CGFloat scaleFactor;
@end

typedef struct {
    NSInteger mode;
    NSInteger videoConfiguration;
    NSInteger previewConfiguration;
    NSInteger audioConfiguration;
} CAMCaptureModeWithOptions;

@interface NSValue (CameraUI)
+ (NSValue *)valueWithModeWithOptions:(CAMCaptureModeWithOptions)options;
@end

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface CAMCaptureStillImageOutput : AVCaptureStillImageOutput
@end
#pragma clang diagnostic pop

@interface CAMCaptureCapabilities : NSObject
+ (CAMCaptureCapabilities *)capabilities;
- (BOOL)isFlashSupportedForDevice:(NSInteger)device;
- (BOOL)isTorchPatternSupportedForDevice:(NSInteger)device;
- (BOOL)isBackCameraSupported;
- (BOOL)isFrontCameraSupported;
@end

@interface CAMVideoPreviewView : UIView
@end

@interface CAMViewfinderView : UIView
- (CAMPreviewView *)previewView;
- (CAMTopBar *)topBar;
- (CAMBottomBar *)bottomBar;
- (CAMZoomSlider *)zoomSlider;
- (CGFloat)_interpolatedTopBarHeight;
#if FOR_IOS8_UP
- (CGSize)_topBarSizeForTraitCollection:(UITraitCollection *)traitCollection;
#endif
@end

@interface CUShutterButton : CAMShutterButton
+ (CUShutterButton *)tinyShutterButtonWithLayoutStyle:(NSInteger)style;
@end

@interface CAMCaptureMovieFileOutput : AVCaptureMovieFileOutput
@end

@interface CAMCaptureEngine : NSObject
- (CAMCaptureMovieFileOutput *)movieFileOutput;
@property(retain, nonatomic) AVCaptureDevice *cameraDevice;
@property(retain, nonatomic) AVCaptureSession *_captureSession;
- (AVCaptureDeviceInput *)audioCaptureDeviceInput;
- (void)_handleSessionDidStartRunning:(id)arg1;
@end

@interface CUCaptureController : NSObject
- (BOOL)isCapturingVideo;
- (BOOL)isCapturingBurst;
- (BOOL)isCapturingTimelapse;
- (CAMCaptureEngine *)_captureEngine;
@end

@interface CAMPreviewViewController : UIViewController
- (CAMEffectsRenderer *)effectsRenderer;
- (BOOL)_userLockedFocusAndExposure;
- (void)updateIndicatorVisibilityAnimated:(BOOL)animated;
@end

@interface CAMViewfinderViewController : UIViewController <cameraViewDelegate>
@property NSInteger _desiredFlashMode;
@property NSInteger _flashMode;
@property NSInteger _desiredTorchMode;
@property NSInteger _torchMode;
@property NSInteger _currentMode;
@property NSInteger _currentDevice;
@property NSInteger _desiredCaptureDevice;
@property(nonatomic, strong) CAMViewfinderView *view;
@property(retain, nonatomic) CAMFramerateIndicatorView *_framerateIndicatorView;
- (BOOL)_shouldHideTopBarForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration;
- (BOOL)_shouldHideFlashButtonForGraphConfiguration:(CAMCaptureGraphConfiguration *)configuration;
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode device:(NSInteger)device;
- (BOOL)_isCapturingTimelapse;
- (BOOL)isEmulatingImagePicker;
#if FOR_IOS8_UP
- (UITraitCollection *)traitCollection;
#endif
- (CAMTopBar *)_topBar;
- (CAMBottomBar *)_bottomBar;
- (CAMViewfinderView *)viewfinderView;
- (CAMZoomSlider *)_zoomSlider;
- (CAMElapsedTimeView *)_elapsedTimeView;
- (CAMFlashButton *)_flashButton;
- (CAMPreviewViewController *)_previewViewController;
- (CUCaptureController *)_captureController;
- (CAMCaptureGraphConfiguration *)_currentGraphConfiguration;
- (NSInteger)timerDuration;
- (NSInteger)_timerDuration;
- (NSInteger)_resolvedTimerDuration;
- (NSInteger)_remainingCaptureTimerTicks;
- (NSMutableArray *)modesForModeDial:(id)arg;
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
- (void)captureController:(id)arg1 didChangeToMode:(NSInteger)mode device:(NSInteger)device;
- (void)_flashButtonDidChangeFlashMode:(CAMFlashButton *)flashButton;
- (void)_setCurrentMode:(NSInteger)mode; // iOS < 10
@end

@interface AVCaptureDevice (Private)
- (AVCaptureSession *)session;
@end

@interface AVCaptureConnection (Private)
- (AVCaptureDevice *)sourceDevice;
@end

@interface AVCaptureSession (Private)
- (NSMutableDictionary *)captureOptions;
@end

@interface AVCaptureSession (CAMCaptureEngine)
- (void)cam_ensureInputs:(NSArray *)inputs;
- (void)cam_removeInputs:(NSArray *)inputs;
@end

@interface AVCaptureStillImageOutput (Private)
@property BOOL squareCropEnabled;
@property CGSize previewImageSize;
- (BOOL)isSquareCropEnabled; // hacky
- (AVCaptureConnection *)firstActiveConnection;
@end

@interface FigCaptureIrisStillImageSettings : FigCaptureStillImageSettings
@end

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface AVCaptureIrisStillImageOutput : AVCaptureOutput
- (AVCaptureStillImageOutput *)_sanitizedSettingsForSettings:(FigCaptureStillImageSettings *)settings;
@end

@interface AVCaptureStillImageSettings : NSObject
@end

@interface AVCaptureIrisStillImageSettings : AVCaptureStillImageSettings
@property NSInteger irisMovieMode;
@end
#pragma clang diagnostic pop

#if FOR_IOS7_UP

@interface AVCaptureDeviceFormat (Private)
- (CMVideoDimensions)sensorDimensions;
@end

@interface AVCaptureDeviceFormatInternal : NSObject
@end

#endif

@interface AVCaptureStillImageRequest : NSObject
@property CGSize previewImageSize;
@end

@interface DCIMImageWellUtilities : NSObject
+ (UIImage *)cameraPreviewWellImage;
@end

@interface CAMStillImageCaptureResponse : NSObject
- (UIImage *)thumbnailImage;
@end

@interface FigCaptureConnectionConfiguration : NSObject
@end

@interface FigVideoCaptureConnectionConfiguration : FigCaptureConnectionConfiguration
@end

@interface CAMCaptureConfiguration : NSObject
- (NSInteger)videoConfiguration;
- (NSInteger)audioConfiguration;
- (NSInteger)previewConfiguration;
- (NSInteger)mode;
- (NSInteger)device;
@end

@interface CAMCaptureGraphConfiguration : NSObject
+ (CAMCaptureGraphConfiguration *)captureGraphConfigurationUsingConfiguration:(CAMCaptureConfiguration *)configuration;
- (NSInteger)mode;
- (NSInteger)device;
- (NSInteger)flashMode;
- (NSInteger)torchMode;
- (NSInteger)HDRMode;
- (NSInteger)timerDuration;
- (NSInteger)irisMode;
- (NSInteger)photoModeEffectFilterType;
- (NSInteger)squareModeEffectFilterType;
@end

#ifdef CHECK_TARGET

typedef enum {
    TargetTypeGUI,
    TargetTypeGUINoExtension,
    TargetTypeNonGUI,
    TargetTypeKeyboardExtension
} TargetType;

static BOOL _isTarget(TargetType type, NSArray <NSString *> *filters) {
    NSProcessInfo *processInfo = [NSClassFromString(@"NSProcessInfo") processInfo];
    NSArray *args = processInfo.arguments;
    HBLogDebug(@"Process arguments: %@", args);
    if (args.count) {
        NSString *executablePath = [args objectAtIndex:0];
        if (executablePath) {
            HBLogDebug(@"Executable path: %@", executablePath);
            NSString *processName = [executablePath lastPathComponent];
            BOOL isSpringBoard = [processName isEqualToString:@"SpringBoard"];
            BOOL isExtensionOrApp = [executablePath rangeOfString:@"/Application"].location != NSNotFound;
            BOOL isUILike = isSpringBoard || isExtensionOrApp;
            #ifdef CHECK_EXCEPTIONS
            if (filters) {
                if (filters.count == 0)
                    return YES;
                BOOL allow = NO;
                #ifdef CHECK_PROCESS_NAME
                allow = [filters containsObject:processName];
                #else
                allow = [filters containsObject:NSBundle.mainBundle.bundleIdentifier];
                #endif
                if (allow)
                    return allow;
            }
            #endif
            if (type == TargetTypeGUI)
                return isUILike;
            BOOL isExtension = [executablePath rangeOfString:@"appex"].location != NSNotFound;
            #ifdef CHECK_KEYBOARD_EXTENSION
            if (type == TargetTypeKeyboardExtension && isExtension) {
                id val = NSBundle.mainBundle.infoDictionary[@"NSExtension"][@"NSExtensionPointIdentifier"];
                BOOL isKeyboardExtension = val ? [val isEqualToString:@"com.apple.keyboard-service"] : NO;
                // Here, TargetTypeKeyboardExtension
                return isKeyboardExtension;
            }
            #endif
            if (type == TargetTypeGUINoExtension)
                return isUILike && !isExtension;
            if (type == TargetTypeNonGUI)
                return !isUILike && !isExtension;
        }
    }
    return NO;
}

#define isTarget(type) _isTarget(type, nil)

#endif

#ifdef KILL_PROCESS

#include <spawn.h>

void killProcess(const char *name) {
    pid_t pid;
    int status;
    const char *args[] = {
        "killall", "-9", name, NULL
    };
    posix_spawn(&pid, "/usr/bin/killall", NULL, NULL, (char *const *)args, NULL);
    waitpid(pid, &status, WEXITED);
}

#endif

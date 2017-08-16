#if FROM_IOS(8_0)

#import "CAMCameraView.h"
#import "CAMAvalancheCaptureService.h"
#import "CAMEffectsRenderer.h"
#import <AVFoundation/AVFoundation.h>

@interface CAMCaptureController : NSObject
@property(assign, nonatomic)AVCaptureDevice *currentDevice;
@property(assign, nonatomic) AVCaptureOutput *currentOutput;
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *previewLayer;
@property(readonly, assign, nonatomic) AVCaptureSession *currentSession;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(readonly, assign, nonatomic) NSInteger cameraOrientation;
@property(assign, nonatomic, getter = isHDREnabled) BOOL HDREnabled;
@property(retain, nonatomic) CAMEffectsRenderer *effectsRenderer;
@property(assign, nonatomic) CGFloat videoZoomFactor;
@property(getter = _isPreviewPaused, setter = _setPreviewPaused:) BOOL _previewPaused;
@property BOOL performingAvalancheCapture;
+ (BOOL)isStillImageMode:(NSInteger)mode;
- (BOOL)_isSessionReady;
- (BOOL)isCameraApp;
- (BOOL)hasFrontCamera;
- (BOOL)hasRearCamera;
- (BOOL)canCaptureVideo;
- (BOOL)isChangingModes;
- (BOOL)isReady;
- (NSMutableArray __OF(NSNumber *) *)supportedCameraModes;
- (CAMCameraView *)delegate;
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
- (BOOL)_isVideoMode:(NSInteger)mode;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
+ (BOOL)isStillImageMode:(NSInteger)mode;
+ (BOOL)isVideoMode:(NSInteger)mode;
- (BOOL)isCapturingPanorama;
- (BOOL)isCapturingTimelapse;
- (CAMAvalancheCaptureService *)_avalancheCaptureService;
- (void)setFaceDetectionEnabled:(BOOL)enabled forceDisableImageProcessing:(BOOL)disableIP;
- (NSUInteger)effectFilterIndexForMode:(NSInteger)mode;
@end

#endif

#if TO_IOS(7_1)

#import "PLCameraView.h"
#import "PLCameraEffectsRenderer.h"
#import <AVFoundation/AVFoundation.h>

@class PLCameraEffectsRenderer;

@interface PLCameraController : NSObject
@property(assign, nonatomic) AVCaptureDevice *currentDevice;
@property(assign, nonatomic) AVCaptureOutput *currentOutput;
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *previewLayer;
@property(readonly, assign, nonatomic) AVCaptureSession *currentSession;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(readonly, assign, nonatomic) NSInteger cameraOrientation;
@property(assign, nonatomic, getter = isHDREnabled) BOOL HDREnabled;
@property(retain, nonatomic) PLCameraEffectsRenderer *effectsRenderer PS_AVAILABLE_IOS(7_0);
@property(assign, nonatomic) CGFloat videoZoomFactor;
@property(getter = _isPreviewPaused, setter = _setPreviewPaused :) BOOL _previewPaused;
@property BOOL performingTimedCapture PS_AVAILABLE_IOS(7_0);
+ (BOOL)isStillImageMode:(NSInteger)mode;
- (BOOL)_isSessionReady;
- (BOOL)isCameraApp;
- (BOOL)canCaptureVideo;
- (BOOL)isChangingModes;
- (BOOL)isReady;
- (NSMutableArray __OF(NSNumber *) *)supportedCameraModes;
- (PLCameraView *)delegate;
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
@end

#endif

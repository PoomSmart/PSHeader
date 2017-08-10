#if FROM_IOS(9_0)

@interface CAMCaptureCapabilities : NSObject
+ (instancetype)capabilities;
- (BOOL)isFlashSupportedForDevice:(NSInteger)device;
- (BOOL)isTorchPatternSupportedForDevice:(NSInteger)device;
- (BOOL)isBackCameraSupported;
- (BOOL)isFrontCameraSupported;
@end

#endif

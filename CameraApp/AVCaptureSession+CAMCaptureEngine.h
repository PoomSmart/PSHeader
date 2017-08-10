#if FROM_IOS(9_0)

@interface AVCaptureSession (CAMCaptureEngine)
- (void)cam_ensureInputs:(NSArray *)inputs;
- (void)cam_removeInputs:(NSArray *)inputs;
@end

#endif

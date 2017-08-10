#if FROM_IOS(8_0)

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

#endif

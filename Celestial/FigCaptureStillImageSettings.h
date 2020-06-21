NS_CLASS_AVAILABLE_IOS(8_0)
@interface FigCaptureStillImageSettings : NSObject

@property BOOL outputMirroring;
@property BOOL thumbnailEnabled;
@property BOOL thumbnailMirroring;

@property CGFloat scaleFactor;

@property NSInteger flashMode;
@property NSInteger HDRMode;
@property NSInteger outputOrientation;
@property NSInteger thumbnailOrientation;

@property NSUInteger outputHeight;
@property NSUInteger outputWidth;
@property NSUInteger thumbnailHeight;
@property NSUInteger thumbnailWidth;

@end

#if FROM_IOS(9_0)

#import "CAMCaptureModeWithOptions.h"

@interface NSValue (CameraUI)
+ (NSValue *)valueWithModeWithOptions:(CAMCaptureModeWithOptions)options;
@end

#endif

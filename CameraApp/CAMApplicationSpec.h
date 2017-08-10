#if FROM_IOS(7_0)

#import "CAMCameraSpec.h"

@interface CAMApplicationSpec : CAMCameraSpec
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@property(readonly) NSInteger modeDialOrientation;
@property(readonly) NSInteger bottomBarOrientation;
@end

#endif

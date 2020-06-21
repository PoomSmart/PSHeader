#if FOR_IOS_BETWEEN(7_0, 8_4)

#import "CAMAvalancheSession.h"

NS_CLASS_AVAILABLE_IOS(8_0)
@interface CAMAvalancheCaptureService : NSObject

- (CAMAvalancheSession *)_activeAvalancheSession;

@end

#endif
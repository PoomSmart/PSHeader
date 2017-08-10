#if FROM_IOS(8_0)

#import "CAMAvalancheSession.h"

@class CAMAvalancheSession;

@interface CAMAvalancheCaptureService : NSObject
- (CAMAvalancheSession *)_activeAvalancheSession;
@end

#endif

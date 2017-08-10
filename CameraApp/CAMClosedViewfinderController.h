#if FROM_IOS(9_0)

@interface CAMClosedViewfinderController : NSObject
- (void)addClosedViewfinderReason:(NSInteger)reason;
- (void)removeClosedViewfinderReason:(NSInteger)reason;
@end

#endif

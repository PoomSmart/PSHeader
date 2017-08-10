#if FOR_IOS_BETWEEN(7_0, 7_1)

#import <CoreImage/CoreImage.h>

@interface PLEffectFilterManager : NSObject
+ (instancetype)sharedInstance;
- (NSUInteger)blackAndWhiteFilterStartIndex;
- (NSUInteger)filterCount;
- (CIFilter *)filterForIndex:(NSUInteger)index;
- (void)_addEffectNamed:(NSString *)name aggdName:(NSString *)aggdName filter:(CIFilter *)filter;
@end

#endif

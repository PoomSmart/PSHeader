#if FROM_IOS(8_0)

#import <CoreImage/CoreImage.h>

@interface CAMEffectFilterManager : NSObject
+ (instancetype)sharedInstance;
+ (NSString *)displayNameForType:(NSInteger)type;
- (NSUInteger)blackAndWhiteFilterStartIndex;
- (NSUInteger)filterCount;
- (CIFilter *)filterForIndex:(NSUInteger)index;
- (void)_addEffectNamed:(NSString *)name aggdName:(NSString *)aggdName filter:(CIFilter *)filter;
@end

#endif

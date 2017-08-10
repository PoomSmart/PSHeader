#if FROM_IOS(8_0)

@interface PLPhotoEffect : NSObject
+ (NSArray __OF(PLPhotoEffect *) *)allEffects;
+ (instancetype)_effectWithIdentifier:(NSString *)identifier CIFilterName:(NSString *)filterName displayName:(NSString *)displayName;
+ (instancetype)_effectWithIdentifier:(NSString *)identifier;
+ (instancetype)_effectWithCIFilterName:(NSString *)identifier;
+ (NSUInteger)indexOfEffectWithIdentifier:(NSString *)identifier;
- (NSString *)displayName;
- (NSString *)filterIdentifier;
- (NSString *)CIFilterName;
@end

#endif

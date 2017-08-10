#if FROM_IOS(10_0)

@interface CAMCaptureConfiguration : NSObject
- (NSInteger)videoConfiguration;
- (NSInteger)audioConfiguration;
- (NSInteger)previewConfiguration;
- (NSInteger)mode;
- (NSInteger)device;
@end

#endif

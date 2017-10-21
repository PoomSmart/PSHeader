#if FROM_IOS(8_0)

@interface UIView (CameraUI)
- (void)cam_setHidden:(BOOL)hidden animated:(BOOL)animated;
@end

#endif

@interface UIView (PhotoLibrary)
- (void)pl_setHidden:(BOOL)hidden animated:(BOOL)animated;
@end
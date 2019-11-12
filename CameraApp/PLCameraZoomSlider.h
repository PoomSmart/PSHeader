#if TO_IOS(7_1)

@interface PLCameraZoomSlider : UISlider
- (void)makeInvisible;
- (void)makeVisible;
- (void)makeVisibleAnimated:(BOOL)animated;
@end

#endif

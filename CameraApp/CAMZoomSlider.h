#if FROM_IOS(8_0)

@interface CAMZoomSlider : UISlider
@property(getter = isMinimumAutozooming) BOOL minimumAutozooming;
@property(getter = isMaximumAutozooming) BOOL maximumAutozooming;
@property(readonly) NSTimer *_visibilityTimer;
@property(getter = _isAutozooming, setter = _setAutozooming :) BOOL _autozooming;
@property(readonly) UIImageView *_thumbImageView;
@property(readonly) UIView *_minTrackMaskView;
@property(readonly) UIView *_maxTrackMaskView;
@property(assign, nonatomic) UIView *delegate;
- (void)_commonCAMZoomSliderInitialization;
- (void)stopVisibilityTimer;
- (void)startVisibilityTimer;
- (void)_endAutozooming;
- (void)_beginAutozooming;
- (void)_updateAutozooming;
- (void)_hideZoomSlider:(id)arg1;
- (void)_postHideZoomSliderAnimation;
- (BOOL)visibilityTimerIsValid;
- (void)makeInvisible;
- (void)makeVisible;
- (void)makeVisibleAnimated:(BOOL)animated;
@end

#endif

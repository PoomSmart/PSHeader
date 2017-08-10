#if FROM_IOS(7_0)

@interface CAMModeDialItem : UIView
@property(retain, nonatomic) NSString *title;
- (BOOL)isSelected;
- (CAShapeLayer *)_scalableTextLayer;
@end

#endif

#if TO_IOS(6_1)

@interface PLReorientingButton : UIButton
@property(assign, nonatomic) CGFloat endCapRadius;
- (void)setButtonOrientation:(NSInteger)orientation animated:(BOOL)animated;
@end

#endif

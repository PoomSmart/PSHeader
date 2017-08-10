#if FOR_IOS_BETWEEN(7_0, 7_1)

@interface PLGLView : UIView
@property CGSize fixedSize;
- (CGFloat)drawableHeight;
- (CGFloat)drawableWidth;
@end

#endif

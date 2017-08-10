#if FROM_IOS(8_0)

@interface CAMGLView : UIView
@property CGSize fixedSize;
- (CGFloat)drawableHeight;
- (CGFloat)drawableWidth;
@end

#endif

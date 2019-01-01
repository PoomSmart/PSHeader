#if FROM_IOS(9_0)

@interface CAMFramerateIndicatorView : UIView
@property NSInteger style;
- (NSInteger)_framesPerSecond;
- (NSString *)_labelText;
- (void)_updateLabels;
- (UILabel *)_topLabel;
- (UILabel *)_bottomLabel;
- (UIImageView *)_borderImageView;
- (void)_updateForAppearanceChange;
@end

#endif

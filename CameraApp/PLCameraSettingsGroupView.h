#if TO_IOS(6_1)

@interface PLCameraSettingsGroupView : UIView
@property(retain, nonatomic) UIView *accessorySwitch;
- (void)setType:(NSInteger)type;
- (void)setTitle:(NSString *)title;
@end

#endif

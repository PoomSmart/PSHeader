#if FROM_IOS(8_0)

@interface CAMExpandableMenuButton : UIView
@property NSUInteger selectedIndex;
+ (double)expansionDuration;
- (NSArray *)_menuItems;
- (void)setHighlighted:(BOOL)highlighted forIndex:(NSUInteger)index;
@end

#endif

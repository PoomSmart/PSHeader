#if FROM_IOS(7_0)

#import "CAMModeDialItem.h"

@class UITraitCollection;

@interface CAMModeDial : UIView
@property(retain, nonatomic) NSMutableArray __OF(CAMModeDialItem *) * _items;
@property(retain, nonatomic) UIView *_itemsContainerView;
@property NSUInteger selectedIndex;
@property NSInteger orientation;
+ (BOOL)wantsVerticalModeDialForTraitCollection:(UITraitCollection *)traitCollection PS_DEPRECATED_IOS(8_0, 9_3);
+ (BOOL)wantsVerticalModeDialForLayoutStyle:(NSInteger)style PS_AVAILABLE_IOS(10_0);
@end

#endif

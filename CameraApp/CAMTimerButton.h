#if FROM_IOS(8_0)

#import "CAMExpandableMenuButton.h"

@interface CAMTimerButton : CAMExpandableMenuButton
@property NSInteger duration;
- (NSString *)titleForMenuItemAtIndex:(NSUInteger)index;
- (NSInteger)numberOfMenuItems;
@end

#endif

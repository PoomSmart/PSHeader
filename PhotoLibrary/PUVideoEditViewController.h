#if FROM_IOS(8_0)

#import "PHAsset.h"

@interface PUVideoEditViewController : UIViewController <UIActionSheetDelegate>
- (PHAsset *)_videoAsset;
- (void)_handleMainActionButton:(id)arg1;
- (void)_handleSaveButton:(id)arg1;
@end

#endif

#if FROM_IOS(8_0)

#import "PUPhotoEditViewController.h"
#import "PLVideoView.h"
#import "PLManagedAsset.h"

@interface PUPhotoBrowserController : UIViewController <UIActionSheetDelegate>
@property(assign, nonatomic) BOOL isCameraApp;
@property(readonly, assign, nonatomic) PLVideoView *currentVideoView;
- (PLManagedAsset *)currentAsset;
- (BOOL)isEditingVideo;
- (id)_toolbarButtonForIdentifier:(NSString *)identifier;
- (void)photoEditController:(PUPhotoEditViewController *)controller didFinishWithSavedChanges:(BOOL)change;
@end

#endif

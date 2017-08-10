#if FROM_IOS(5_0)

#import "PLVideoView.h"
#import "PLManagedAsset.h"

@interface PLPhotoBrowserController : UIViewController <UIActionSheetDelegate>
@property(assign, nonatomic) BOOL isCameraApp;
@property(readonly, assign, nonatomic) PLVideoView *currentVideoView;
- (PLManagedAsset *)currentAsset;
- (UINavigationBar *)navigationBar;
- (BOOL)isEditingVideo;
- (id)_toolbarButtonForIdentifier:(NSString *)identifier;
@end

#endif

#if FROM_IOS(8_0)

#import "CAMGLView.h"

@interface CAMEffectsGridView : CAMGLView
- (NSUInteger)_cellCount;
- (NSUInteger)_filterIndexForGridIndex:(NSUInteger)index;
- (BOOL)isBlackAndWhite;
- (BOOL)isSquare;
- (CGRect)rectForFilterType:(NSInteger)type;
- (CGRect)_squareCropFromRect:(CGRect)rect;
@end

#endif

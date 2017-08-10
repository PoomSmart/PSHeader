#if FOR_IOS_BETWEEN(7_0, 7_1)

#import "PLGLView.h"

@interface PLEffectsGridView : PLGLView
- (NSUInteger)_cellCount;
- (NSUInteger)_filterIndexForGridIndex:(NSUInteger)index;
- (BOOL)isBlackAndWhite;
- (BOOL)isSquare;
- (CGRect)rectForFilterIndex:(NSUInteger)index;
- (CGRect)_squareCropFromRect:(CGRect)rect;
@end

#endif

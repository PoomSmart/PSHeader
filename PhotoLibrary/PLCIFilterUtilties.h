#import <CoreImage/CoreImage.h>

@interface PLCIFilterUtilties : NSObject
+ (CIImage *)outputImageFromFilters:(NSArray *)filters inputImage:(CIImage *)inputImage orientation:(UIImageOrientation)orientation copyFiltersFirst:(BOOL)copyFirst;
@end

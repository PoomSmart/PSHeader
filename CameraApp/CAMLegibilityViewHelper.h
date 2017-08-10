#if FROM_IOS(8_0)

@interface CAMLegibilityViewHelper : NSObject
+ (UIImage *)_imageFromLabel:(UILabel *)label sizeToFit:(BOOL)fit;
@end

#endif

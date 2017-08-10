#if FROM_IOS(8_0)

@interface FigCaptureSourceFormat : NSObject
- (id)initWithFigCaptureStreamFormatDictionary:(id)dictionary;
- (id)AVCaptureSessionPresets;
- (BOOL)isPhotoFormat;
- (BOOL)isHighResPhotoFormat;
@end

#endif

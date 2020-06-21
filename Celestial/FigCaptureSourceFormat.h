NS_CLASS_AVAILABLE_IOS(8_0)
@interface FigCaptureSourceFormat : NSObject

- (id)initWithFigCaptureStreamFormatDictionary:(id)dictionary;
- (id)AVCaptureSessionPresets;

- (BOOL)isPhotoFormat;
- (BOOL)isHighResPhotoFormat;

@end

// All capability keys with "?" as a commet prefix requires use with MGGetBoolAnswer(key)
// Otherwise, use MGGetSInt32Answer(key, defaultValue)

// ? has front-facing or rear-facing camera
#define kBackCameraSupportedKey "rear-facing-camera"
#define kFrontCameraSupportedKey "front-facing-camera"

// ? supports flash on front/rear camera
#define kBackFlashSupportedKey "camera-flash"
#define kFrontFlashSupportedKey "fJZs6N8SqTS4RuQVh3szxA"

// ? supports video recording
#define kVideoSupportedKey "video-camera"
// ? supports taking stills during video recording
#define kStillDuringVideoSupportedKey "video-stills"

// ? supports HDR on front/rear camera
#define kBackHDRSupportedKey "RearFacingCameraHDRCapability"
#define kFrontHDRSupportedKey "FrontFacingCameraHDRCapability"

// ? supports setting HDR mode as on on front/rear camera
#define kBackHDROnSupportedKey "LkWb+FyA1+ef2UD1Fx+kAw"
#define kFrontHDROnSupportedKey "HnHX0gXt8RvhMQzIVMM7hw"

// ? supports auto HDR mode on front/rear camera
#define kBackAutoHDRSupportedKey "RearFacingCameraAutoHDRCapability"
#define kFrontAutoHDRSupportedKey "FrontFacingCameraAutoHDRCapability"

// ? supports live camera effect
#define kLiveFilterSupportedKey "CameraLiveEffectsCapability"

// ? supports burst mode on front/rear camera
#define kBackBurstSupportedKey "RearFacingCameraBurstCapability"
#define kFrontBurstSupportedKey "FrontFacingCameraBurstCapability"

// interval value for each burst photo captured on front/rear camera
#define kBackCaptureIntervalKey "gq0j1GmcIcaD4DjJoo9pfg"
#define kFrontCaptureIntervalKey "TDM8SEI14n2KE9PGHO0a4A"

// ? supports iris mode on rear camera (including the internal used with apple-internal-install)
#define kIrisSupportedKey "pLzf7OiX5nWAPUMj7BfI4Q"
#define kIrisInternalSupportedKey "euampscYbKXqj/bSaHD0QA"

// ? supports slo-mo capture on front/rear camera
#define kBackSlomoSupportedKey "RearFacingCameraHFRCapability"
#define kFrontSlomoSupportedKey "FrontFacingCameraHFRCapability"

// ? supports 1080p60 on rear camera
#define kBack60FPSVideoSupportedKey "RearFacingCamera60fpsVideoCaptureCapability"

// maximum 4k FPS supported on front/rear camera
#define kBack4kMaxFPSKey "po7g0ATDzGoVI1DO8ISmuw"
#define kFront4KMaxFPSKey "cux58RcuSiBhpxWnT3pE4A" // iOS 10+

// maximum 1080p FPS supported on front/rear camera
#define kBack1080pMaxFPSKey "jBGZJ71pRJrqD8VZ6Tk2VQ" // iOS 10+
#define kFront1080pMaxFPSKey "3yzXj0lJhQi+r3kgQlwiOg" // iOS 10+

// maximum 720p FPS supported on front/rear camera
#define kBack720pMaxFPSKey "0/7QNywWU4IqDcyvTv9UYQ"
#define kFront720pMaxFPSKey "0AFeHRmliNJ4pSlVb8ltZA" // iOS 10+

// maximum slo-mo 720p FPS supported on rear camera
#define kBackSlomo720pMaxFPSKey "XellXEQUbOIgUPoTrIj5nA"

// maximum slo-mo 1080p FPS supported on rear camera
#define kBackSlomo1080pMaxFPSKey "jKFTzVOYcfTfNBh+yDrprw"

// ? supports HEVC encoding
#define kHEVCEncodingSupportedKey "g/MkWm2Ac6+TLNBgtBGxsg" // iOS 11+

// maximum video zoom factor on front/rear camera
#define kBackVideoMaximumZoomFactorKey "RearFacingCameraMaxVideoZoomFactor"
#define kFrontVideoMaximumZoomFactorKey "FrontFacingCameraMaxVideoZoomFactor"

// ? supports telephoto on rear camera
#define kBackTelephotoSupportedKey "YzrS+WPEMqyh/FBv/n/jvA" // iOS 11+
// ? supports dual on rear camera
// is used for portrait mode
#define kBackDualSupportedKey "0/VAyl58TL5U/mAQEJNRQw" // iOS 11+

// maximum len zoom factor for photo/video on dual rear camera
#define kBackDualPhotoMaximumZoomFactorKey "JLP/IinyzetEPztvoNUNKg" // iOS 11+
#define kBackDualVideoMaximumZoomFactorKey "IweaHIDpz+rknAcb3+xg9g" // iOS 11+

// ? has front pearl camera (might require use with MGIsQuestionValid())
// is used for portrait mode
#define kFrontPearlSupportedKey "8S7ydMJ4DlCUF38/hI/fJA" // iOS 11+

// ? supports portrait effects
#define kPortraitEffectsSupportedKey "hewg+QX1h57eGJGphdCong" // iOS 11+

// ? supports forcing shutter sound on
#define kShutterSoundRequiredKey "RegionalBehaviorShutterClick"

// ? supports using lock button as shutter button
#define kLockButtonAppropriateForShutterKey "euampscYbKXqj/bSaHD0QA" // iOS 11+

// ? supports pipelined still image processing
#define kPipelinedStillImageProcessingSupportedKey "XIcF5FOyQlt/H79oFw9ciA" // iOS 11+

// ? supports modern HDR mode†
// suspected to be the key to check if the device is introduced as of 2017
#define kModernHDRSupportedKey "cWWKdUn+rIclZ60ZGAVhBw" // iOS 12+

// ? supports auto low light video capture
#define kAutoLowLightVideoSupportedKey "DeviceSupportsAutoLowLightVideo" // iOS 12+

// ? supports recording stereo audio
#define kStereoAudioRecordingSupportedKey "DeviceSupportsStereoAudioRecording" // iOS 12+

// ? supports studio light portrait preview
#define kStudioLightPortraitPreviewKey "DeviceSupportsStudioLightPortraitPreview" // iOS 12+

// ? supports capturing on finger touch down
#define kCameraCaptureOnTouchDownSupportedKey "DeviceSupportsCameraCaptureOnTouchDown" // iOS 12+
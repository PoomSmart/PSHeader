#import <dlfcn.h>

#define CAMERAUI "/System/Library/PrivateFrameworks/CameraUI.framework/CameraUI"
#define openCamera10() dlopen(CAMERAUI, RTLD_LAZY)
#define openCamera9() openCamera10()
#define CAMERAKIT "/System/Library/PrivateFrameworks/CameraKit.framework/CameraKit"
#define openCamera8() dlopen(CAMERAKIT, RTLD_LAZY)
#define PHOTOLIBRARY "/System/Library/PrivateFrameworks/PhotoLibrary.framework/PhotoLibrary"
#define openCamera7() dlopen(PHOTOLIBRARY, RTLD_LAZY)
#define openCamera6() openCamera7()
#define openCamera5() openCamera7()

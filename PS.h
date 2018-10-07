#import "iOSVersions.h"
#import "CameraMacros.h"
#import "Misc.h"
#import "Availability.h"

#import "Generics.h"
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import "CoreImage/CoreImage.h"
#import "AVFoundation/AVFoundation.h"
#import "Celestial/Celestial.h"
#import "PhotoLibrary/PhotoLibrary.h"
#import "CameraApp/CameraApp.h"

#define PS_DONATE_URL @"https://poomsmart.github.io/repo/"
#define PS_TWITTER_URL @"https://twitter.com/PoomSmart"

#ifdef CHECK_TARGET

typedef enum {
    TargetTypeGUI,
    TargetTypeGUINoExtension,
    TargetTypeNonGUI,
    TargetTypeKeyboardExtension
} TargetType;

static BOOL _isTarget(TargetType type, NSArray <NSString *> *filters) {
    NSArray <NSString *> *args = [NSClassFromString(@"NSProcessInfo") processInfo].arguments;
    HBLogDebug(@"Process arguments: %@", args);
    if (args.count) {
        NSString *executablePath = [args objectAtIndex:0];
        if (executablePath) {
            HBLogDebug(@"Executable path: %@", executablePath);
            NSString *processName = [executablePath lastPathComponent];
            BOOL isSpringBoard = [processName isEqualToString:@"SpringBoard"];
            BOOL isExtensionOrApp = [executablePath rangeOfString:@"/Application"].location != NSNotFound;
            BOOL isUILike = isSpringBoard || isExtensionOrApp;
#ifdef CHECK_EXCEPTIONS
            if (filters) {
                if (filters.count == 0)
                    return YES;
                BOOL allow = NO;
    #ifdef CHECK_PROCESS_NAME
                allow = [filters containsObject:processName];
    #else
                allow = [filters containsObject:NSBundle.mainBundle.bundleIdentifier];
    #endif
                if (allow)
                    return allow;
            }
#endif
            if (type == TargetTypeGUI)
                return isUILike;
            BOOL isExtension = [executablePath rangeOfString:@"appex"].location != NSNotFound;
#ifdef CHECK_KEYBOARD_EXTENSION
            if (type == TargetTypeKeyboardExtension && isExtension) {
                id val = NSBundle.mainBundle.infoDictionary[@"NSExtension"][@"NSExtensionPointIdentifier"];
                BOOL isKeyboardExtension = val ? [val isEqualToString:@"com.apple.keyboard-service"] : NO;
                // Here, TargetTypeKeyboardExtension
                return isKeyboardExtension;
            }
#endif
            if (type == TargetTypeGUINoExtension)
                return isUILike && !isExtension;
            if (type == TargetTypeNonGUI)
                return !isUILike && !isExtension;
        }
    }
    return NO;
}

#define isTarget(type) _isTarget(type, nil)

#endif

#ifdef KILL_PROCESS

#include <spawn.h>

void killProcess(const char *name) {
    pid_t pid;
    int status;
    const char *args[] = {
        "killall", "-9", name, NULL
    };
    posix_spawn(&pid, "/usr/bin/killall", NULL, NULL, (char *const *)args, NULL);
    waitpid(pid, &status, WEXITED);
}

#endif

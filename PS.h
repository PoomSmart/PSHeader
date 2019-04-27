#import "iOSVersions.h"
#import "CameraMacros.h"
#import "Misc.h"
#import "Availability.h"

#import "Generics.h"
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIFunctions.h>

#import "CoreImage/CoreImage.h"
#import "AVFoundation/AVFoundation.h"
#import "Celestial/Celestial.h"
#import "PhotoLibrary/PhotoLibrary.h"
#import "CameraApp/CameraApp.h"
#import "CameraGestaltKeys.h"

#define PS_DONATE_URL @"https://poomsmart.github.io/repo/"
#define PS_TWITTER_URL @"https://twitter.com/PoomSmart"

#ifdef CHECK_TARGET

typedef NS_ENUM (NSUInteger, TargetType) {
    TargetTypeApps = 1 << 0,
    TargetTypeGenericExtensions = 1 << 1,
    TargetTypeKeyboardExtensions = 1 << 2
};

static BOOL _isTarget(TargetType type, NSArray <NSString *> *filters) {
    NSArray <NSString *> *args = [NSClassFromString(@"NSProcessInfo") processInfo].arguments;
    HBLogDebug(@"Process arguments: %@", args);
    if (args.count) {
        NSString *executablePath = [args objectAtIndex:0];
        if (executablePath) {
            HBLogDebug(@"Executable path: %@", executablePath);
            BOOL isExtension = [executablePath rangeOfString:@"appex"].location != NSNotFound;
            if (type & TargetTypeGenericExtensions && isExtension)
                return YES;
            NSString *processName = [executablePath lastPathComponent];
#ifdef CHECK_EXCEPTIONS
            if (filters) {
                if (filters.count == 0)
                    return YES;
                BOOL allow = [filters containsObject:processName];
                NSString *bundleIdentifier = NSBundle.mainBundle.bundleIdentifier;
                if (!allow && bundleIdentifier)
                    allow = [filters containsObject:bundleIdentifier];
                if (allow)
                    return YES;
            }
#endif
            BOOL isSpringBoard = [processName isEqualToString:@"SpringBoard"];
            BOOL isExtensionOrApp = [executablePath rangeOfString:@"/Application"].location != NSNotFound;
            BOOL isUILike = isSpringBoard || isExtensionOrApp;
            if (type & TargetTypeApps && isUILike && !isExtension)
                return YES;
            if (type & TargetTypeKeyboardExtensions && isExtension) {
                id val = NSBundle.mainBundle.infoDictionary[@"NSExtension"][@"NSExtensionPointIdentifier"];
                BOOL isKeyboardExtension = val ? [val isEqualToString:@"com.apple.keyboard-service"] : NO;
                return isKeyboardExtension;
            }
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

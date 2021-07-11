#ifndef _PS
#define _PS

#import "iOSVersions.h"
#import "Misc.h"
#import "Availability.h"

#define PS_DONATE_URL @"https://poomsmart.github.io/repo/"
#define PS_TWITTER_URL @"https://twitter.com/PoomSmart"

#ifdef __DEBUG__
#import <HBLog.h>
#endif

#ifdef CHECK_TARGET

typedef NS_ENUM (NSUInteger, TargetType) {
    TargetTypeApps = 1 << 0,
    TargetTypeGenericExtensions = 1 << 1,
    TargetTypeKeyboardExtensions = 1 << 2
};

FOUNDATION_EXPORT char ***_NSGetArgv();

static BOOL _isTarget(NSUInteger type, NSArray <NSString *> *filters) {
    char *executablePathC = **_NSGetArgv();
    NSString *executablePath = [NSString stringWithUTF8String:executablePathC];
    if (executablePath) {
#ifdef __DEBUG__
        HBLogDebug(@"Executable path: %@", executablePath);
#endif
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
        BOOL isSpringBoard = NSStringEqual(processName, @"SpringBoard");
        BOOL isExtensionOrApp = [executablePath rangeOfString:@"/Application"].location != NSNotFound;
        BOOL isUILike = isSpringBoard || isExtensionOrApp;
        if (type & TargetTypeApps && isUILike && !isExtension)
            return YES;
        if (type & TargetTypeKeyboardExtensions && isExtension) {
            id val = NSBundle.mainBundle.infoDictionary[@"NSExtension"][@"NSExtensionPointIdentifier"];
            BOOL isKeyboardExtension = val ? NSStringEqual(val, @"com.apple.keyboard-service") : NO;
            return isKeyboardExtension;
        }
    }
    return NO;
}

#define isTarget(type) _isTarget(type, nil)

#ifdef CHECK_TARGET_GUI

static void *observer = NULL;
static void lateLoad(void);

static void appLoaded(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo) {
    lateLoad();
}

static void appLoadedCallback() {
    CFNotificationCenterAddObserver(CFNotificationCenterGetLocalCenter(), &observer, appLoaded, (CFStringRef)UIApplicationDidFinishLaunchingNotification, NULL, CFNotificationSuspensionBehaviorCoalesce);
}

#endif

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

#endif

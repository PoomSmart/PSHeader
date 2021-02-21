#ifndef _PS_IOSVER
#define _PS_IOSVER

#import <CoreFoundation/CoreFoundation.h>
#import <version.h>

#ifndef kCFCoreFoundationVersionNumber_iOS_14_5
#define kCFCoreFoundationVersionNumber_iOS_14_5 1775.113
#endif

#define IS_IOS_BETWEEN_EEX(start, end) (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_ ## start && kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_ ## end)

#endif

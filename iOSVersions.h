#ifndef _PS_IOSVER
#define _PS_IOSVER

#import <CoreFoundation/CoreFoundation.h>
#import <version.h>

#ifndef kCFCoreFoundationVersionNumber_iOS_15_0
#define kCFCoreFoundationVersionNumber_iOS_15_0 1835.100
#endif

#define IS_IOS_BETWEEN_EEX(start, end) (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_ ## start && kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_ ## end)

#endif

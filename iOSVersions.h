#import <CoreFoundation/CoreFoundation.h>
#import <version.h>

#ifndef kCFCoreFoundationVersionNumber_iOS_12_0
#define kCFCoreFoundationVersionNumber_iOS_12_0 1556.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_12_1
#define kCFCoreFoundationVersionNumber_iOS_12_1 1560.00
#endif

#ifndef kCFCoreFoundationVersionNumber_iOS_12_2
#define kCFCoreFoundationVersionNumber_iOS_12_2 1570.15
#endif

#define IS_IOS_BETWEEN_EEX(start, end) (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_ ## start && kCFCoreFoundationVersionNumber < kCFCoreFoundationVersionNumber_ ## end)

#define isiOS4 IS_IOS_OR_OLDER(iOS_4_3)
#define isiOS50 IS_IOS_BETWEEN_EEX(iOS_5_0, iOS_5_1)
#define isiOS51 IS_IOS_BETWEEN_EEX(iOS_5_1, iOS_6_0)
#define isiOS5 IS_IOS_BETWEEN_EEX(iOS_5_0, iOS_6_0)
#define isiOS6 (kCFCoreFoundationVersionNumber == kCFCoreFoundationVersionNumber_iOS_6_0)
#define isiOS61 (NSFoundationVersionNumber == NSFoundationVersionNumber_iOS_6_1)
#define isiOS70 IS_IOS_BETWEEN_EEX(iOS_7_0, iOS_7_1)
#define isiOS71 IS_IOS_BETWEEN_EEX(iOS_7_1, iOS_8_0)
#define isiOS7 IS_IOS_BETWEEN_EEX(iOS_7_0, iOS_8_0)
#define isiOS8 IS_IOS_BETWEEN_EEX(iOS_8_0, iOS_9_0)
#define isiOS82 IS_IOS_BETWEEN_EEX(iOS_8_2, iOS_8_3)
#define isiOS83 IS_IOS_BETWEEN_EEX(iOS_8_3, iOS_9_0)
#define isiOS9 IS_IOS_BETWEEN_EEX(iOS_9_0, iOS_10_0)
#define isiOS10 IS_IOS_OR_NEWER(iOS_10_0)

#define isiOS4Up (kCFCoreFoundationVersionNumber >= 550.32)
#define isiOS5Up IS_IOS_OR_NEWER(iOS_5_0)
#define isiOS6Up IS_IOS_OR_NEWER(iOS_6_0)
#define isiOS61Up (NSFoundationVersionNumber >= NSFoundationVersionNumber_iOS_6_1)
#define isiOS7Up IS_IOS_OR_NEWER(iOS_7_0)
#define isiOS71Up IS_IOS_OR_NEWER(iOS_7_1)
#define isiOS8Up IS_IOS_OR_NEWER(iOS_8_0)
#define isiOS82Up IS_IOS_OR_NEWER(iOS_8_2)
#define isiOS83Up IS_IOS_OR_NEWER(iOS_8_3)
#define isiOS84Up IS_IOS_OR_NEWER(iOS_8_4)
#define isiOS9Up IS_IOS_OR_NEWER(iOS_9_0)
#define isiOS91Up IS_IOS_OR_NEWER(iOS_9_1)
#define isiOS92Up IS_IOS_OR_NEWER(iOS_9_2)
#define isiOS93Up IS_IOS_OR_NEWER(iOS_9_3)
#define isiOS10Up IS_IOS_OR_NEWER(iOS_10_0)
#define isiOS10_2Up IS_IOS_OR_NEWER(iOS_10_2)
#define isiOS10_3Up IS_IOS_OR_NEWER(iOS_10_3)
#define isiOS11Up IS_IOS_OR_NEWER(iOS_11_0)
#define isiOS12Up IS_IOS_OR_NEWER(iOS_12_0)
#define isiOS12_1Up IS_IOS_OR_NEWER(iOS_12_1)
#define isiOS12_2Up IS_IOS_OR_NEWER(iOS_12_2)

#define isiOS45 (isiOS4Up && kCFCoreFoundationVersionNumber < 793.00)
#define isiOS56 IS_IOS_BETWEEN_EEX(iOS_5_0, iOS_7_0)
#define isiOS67 IS_IOS_BETWEEN_EEX(iOS_6_0, iOS_8_0)
#define isiOS78 IS_IOS_BETWEEN_EEX(iOS_7_0, iOS_9_0)
#define isiOS89 IS_IOS_BETWEEN_EEX(iOS_8_0, iOS_10_0)

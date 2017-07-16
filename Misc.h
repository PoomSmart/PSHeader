#import <Foundation/Foundation.h>

#ifdef UIFUNCTIONS_NOT_C
extern NSString *UISystemRootDirectory();
#else
#import <UIKit/UIFunctions.h>
#endif

#if TARGET_OS_SIMULATOR
#define realPath(path) [UISystemRootDirectory() stringByAppendingPathComponent: path]
#define realPath2(path) [realPath(path) UTF8String]
#define realPrefPath(domain) [NSString stringWithFormat:@"%@/Library/Preferences/%@.plist", @(getenv("SIMULATOR_SHARED_RESOURCES_DIRECTORY")), domain]
#else
#define realPath(path) (path)
#define realPath2(path) ([path UTF8String])
#define realPrefPath(domain) [NSString stringWithFormat:@"/User/Library/Preferences/%@.plist", domain]
#endif

#define fileExist(path) [[NSFileManager defaultManager] fileExistsAtPath:path]
#define k(akey) (CFStringCompare(key, CFSTR(akey), kCFCompareCaseInsensitive) == kCFCompareEqualTo)
#define stringEqual(str1, str2) ([str1 isEqualToString:str2])

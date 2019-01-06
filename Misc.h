#import <Foundation/Foundation.h>

#if TARGET_OS_SIMULATOR
#import <UIKit/UIFunctions.h>
#define realPath(path) [UISystemRootDirectory() stringByAppendingPathComponent:path]
#define realPath2(path) [realPath(path) UTF8String]
#define realPrefPath(domain) [NSString stringWithFormat:@"%@/Library/Preferences/%@.plist", @(getenv("SIMULATOR_SHARED_RESOURCES_DIRECTORY")), domain]
#else
#define realPath(path) (path)
#define realPath2(path) ([path UTF8String])
#define realPrefPath(domain) [NSString stringWithFormat:@"/User/Library/Preferences/%@.plist", domain]
#endif

#define fileExist(path) [[NSFileManager defaultManager] fileExistsAtPath:path]
#define CFStringEqual(s1, s2) (CFStringCompare(s1, s2, kCFCompareCaseInsensitive) == kCFCompareEqualTo)
#define stringEqual(str1, str2) ([str1 isEqualToString:str2])

#define __NSi_4_0 introduced = 4.0
#define __NSi_4_1 introduced = 4.1
#define __NSi_4_2 introduced = 4.2
#define __NSi_4_3 introduced = 4.3
#define __NSi_5_0 introduced = 5.0
#define __NSi_5_1 introduced = 5.1
#define __NSi_6_0 introduced = 6.0
#define __NSi_6_1 introduced = 6.1
#define __NSi_7_0 introduced = 7.0
#define __NSi_7_1 introduced = 7.1
#define __NSi_8_0 introduced = 8.0
#define __NSi_8_1 introduced = 8.1
#define __NSi_8_2 introduced = 8.2
#define __NSi_8_3 introduced = 8.3
#define __NSi_8_4 introduced = 8.4
#define __NSi_9_0 introduced = 9.0
#define __NSi_9_1 introduced = 9.1
#define __NSi_9_2 introduced = 9.2
#define __NSi_9_3 introduced = 9.3
#define __NSi_10_0 introduced = 10.0
#define __NSi_10_1 introduced = 10.1
#define __NSi_10_2 introduced = 10.2
#define __NSi_10_3 introduced = 10.3
#define __NSi_11_0 introduced = 11.0

#define __IPHONE_4_0 40000
#define __IPHONE_4_1 40100
#define __IPHONE_4_2 40200
#define __IPHONE_4_3 40300
#define __IPHONE_5_0 50000
#define __IPHONE_5_1 50100
#define __IPHONE_6_0 60000
#define __IPHONE_6_1 60100
#define __IPHONE_7_0 70000
#define __IPHONE_7_1 70100
#define __IPHONE_8_0 80000
#define __IPHONE_8_2 80200
#define __IPHONE_8_3 80300
#define __IPHONE_8_4 80400
#define __IPHONE_9_0 90000
#define __IPHONE_9_1 90100
#define __IPHONE_9_2 90200
#define __IPHONE_9_3 90300
#define __IPHONE_10_0 100000
#define __IPHONE_10_1 100100
#define __IPHONE_10_2 100200
#define __IPHONE_10_3 100300
#define __IPHONE_11_0 110000

#ifndef UNRESTRICTED_AVAILABILITY

#define FROM_IOS(VER) __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_ ## VER
#define TO_IOS(VER) __IPHONE_OS_VERSION_MAX_ALLOWED <= __IPHONE_ ## VER
#define FOR_IOS_BETWEEN(LO, HI) FROM_IOS(LO) && TO_IOS(HI)

#define PS_AVAILABLE_IOS(VER) NS_AVAILABLE_IOS(VER)
#define PS_DEPRECATED_IOS(LO, HI) NS_DEPRECATED_IOS(LO, HI)
#define PS_TO_IOS(VER) PS_DEPRECATED_IOS(__IPHONE_5_0, VER)

#else

#define FROM_IOS(VER) true
#define TO_IOS(VER) true
#define FOR_IOS_BETWEEN(LO, HI) true

#define PS_AVAILABLE_IOS(VER)
#define PS_DEPRECATED_IOS(LO, HI)
#define PS_TO_IOS(VER)

#endif

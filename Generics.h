#if FROM_IOS(9_0) && __has_feature(objc_generics)
#define __OF(x) < x >
#define __OF2(x, y) < x, y >
#else
#define __OF(x)
#define __OF2(x, y)
#endif

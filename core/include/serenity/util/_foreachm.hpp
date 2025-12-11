#define __FE_0(WHAT)
#define __FE_1(WHAT, X) WHAT(X)
#define __FE_2(WHAT, X, ...) WHAT(X),__FE_1(WHAT, __VA_ARGS__)
#define __FE_3(WHAT, X, ...) WHAT(X),__FE_2(WHAT, __VA_ARGS__)
#define __FE_4(WHAT, X, ...) WHAT(X),__FE_3(WHAT, __VA_ARGS__)
#define __FE_5(WHAT, X, ...) WHAT(X),__FE_4(WHAT, __VA_ARGS__)
//... repeat as needed

#define __GET_MACRO(_0,_1,_2,_3,_4,_5,NAME,...) NAME
#define __FOR_EACH__(action,...) __GET_MACRO(_0,__VA_ARGS__,__FE_5,__FE_4,__FE_3,__FE_2,__FE_1,__FE_0)(action, __VA_ARGS__)
#include "_foreachm.hpp"
#define __VEC_ARG__(f) T f
#define __VEC_INIT__(f) (void)0; res[math::f] = f; (void)0
#define __VEC_CTOR__(n, ...) template <typename T> inline Vec##n<T> vec##n(__FOR_EACH__(__VEC_ARG__,__VA_ARGS__)) { \
	Vec##n<T> res; (void)\
	__FOR_EACH__(__VEC_INIT__, __VA_ARGS__) \
	;return res; \
	}

#define __DEFINE_VEC_TYPES__(n, ...) template <typename T> using Vec##n = Vec<n, T>; \
	using Vec##n##i = Vec##n<int>; \
	using Vec##n##f = Vec##n<float>; \
	using Vec##n##d = Vec##n<double>; \
	using Vec##n##u = Vec##n<unsigned int>; \
	__VEC_CTOR__(n, __VA_ARGS__)

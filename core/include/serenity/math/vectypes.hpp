#pragma once
#include "../util/_vecdef.hpp"

namespace serenity { namespace math {
__DEFINE_VEC_TYPES__(2, x, y)
__DEFINE_VEC_TYPES__(3, x, y, z)
__DEFINE_VEC_TYPES__(4, x, y, z, t)

template <typename T>
inline Vec4<T> vec4(Vec2<T> v1, Vec2<T> v2) {
	Vec4<T> res;
	res[x] = v1[x];
	res[y] = v1[y];
	res[z] = v2[x];
	res[t] = v2[y];
	return res;
}

}}

#include "../util/_vecdef.un.hpp"
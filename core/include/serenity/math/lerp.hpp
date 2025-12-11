#pragma once
namespace serenity {
namespace math {
template <typename T>
inline auto lerp(T a, T b, float t) -> T {
    return a + t * (b - a);
}
}
}
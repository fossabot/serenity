#pragma once

namespace serenity {
namespace math {

template <typename T>
inline auto lerp(T a, T b, double t) -> T {
    return a + t * (b - a);
};

}
}
#pragma once
namespace serenity {
namespace math {
namespace collision {

template <typename T>
inline auto leftEdge(Vec4<T> box) -> T {
	return box[x];
}

template <typename T>
inline auto topEdge(Vec4<T> box) -> T {
	return box[y];
}

template <typename T>
inline auto rightEdge(Vec4<T> box) -> T {
	return box[x] + box[z];
}

template <typename T>
inline auto bottomEdge(Vec4<T> box) -> T {
	return box[y] + box[t];
}

template <typename T>
inline auto overlaps(Vec4<T> box1, Vec4<T> box2) -> bool {
	return !(  topEdge(box1) > bottomEdge(box2)
		|| topEdge(box2) > bottomEdge(box1)
		|| leftEdge(box1) > rightEdge(box2)
		|| leftEdge(box2) > rightEdge(box1));
}

}
}
}
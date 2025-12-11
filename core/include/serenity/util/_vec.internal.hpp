#define VEC_CMPOP(op, check) bool operator op(Vec<len, T> other) const { \
		bool res; \
		for(unsigned int i = 0; i < len; i++) { \
			res = res check components[i] op other[i]; \
		} \
		return res; \
	}

#define VEC_BINOP_V(op) Vec<len, T> operator op(Vec<len, T> other) const { \
		Vec<len, T> res; \
		for(unsigned int i = 0; i < len; i++) { \
			res[i] = components[i] op other[i]; \
		} \
		return res; \
	}

#define VEC_BINOP_N(op) Vec<len, T> operator op(T other) const { \
		Vec<len, T> res; \
		for(unsigned int i = 0; i < len; i++) { \
			res[i] = components[i] op other; \
		} \
		return res; \
	}

#define VEC_BINOP_S_SIMPLE(op) template <unsigned int len, typename E> \
inline Vec<len, E> operator op(E other, Vec<len, E> self) { \
	return self op other; \
}

#define VEC_BINOP_S_ELWISE(op) template <unsigned int len, typename E> \
inline Vec<len, E> operator op(E other, Vec<len, E> self) { \
	Vec<len, E> res; \
	for(unsigned int i = 0; i < len; i++) { \
		res[i] = other op self[i]; \
	} \
	return res; \
}


#define VEC_UNOP(op) Vec<len, T> operator op() const { \
		Vec<len, T> res; \
		for(unsigned int i = 0; i < len; i++) { \
			res[i] = op components[i]; \
		} \
		return res; \
	}

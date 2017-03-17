template<typename T, T VALUE>
struct static_parameter {
};

template<typename T, T VALUE>
struct static_value : static_parameter<T, VALUE> {
    static const T value = VALUE;

    operator T() const {
        return VALUE;
    }

    static_value(int = 0) {
    }
};

enum algorithm_tag_t {
    NAIVE,
    PRECISE
};

inline static_value<algorithm_tag_t, NAIVE> naive_algorithm_tag() {
    return 0; // dummy function body: calls static_value<...>(int)
}

inline static_value<algorithm_tag_t, PRECISE> precise_algorithm_tag() {
    return 0; // dummy function body: calls static_value<...>(int)
}

typedef static_value<algorithm_tag_t, NAIVE> (*naive_algorithm_tag_t)();

typedef static_value<algorithm_tag_t, PRECISE> (*precise_algorithm_tag_t)();

template<typename T>
inline T log1p(T x, naive_algorithm_tag_t);

// later
// line 4: pass a function as a tag
double y = log1p(3.14, naive_algorithm_tag);
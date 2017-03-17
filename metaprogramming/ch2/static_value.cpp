template<typename T, T VALUE>
struct static_parameter {
};

// requires that T is an integral type

// template<typename T, T VALUE>
// struct static_value : static_parameter<T, VALUE> {
//     static const T value = VALUE;
// };

// the cast operator allows switching from a static
// constant to a runtime integer
template<typename T, T VALUE>
struct static_value : static_parameter<T, VALUE> {
    static const T value = VALUE;

    operator T() const {
        return VALUE;
    }

    static_value(int = 0) {
    }
};

template<typename T, T VALUE>
inline T static_value_cast(static_value<T, VALUE>) {
    return VALUE;
};

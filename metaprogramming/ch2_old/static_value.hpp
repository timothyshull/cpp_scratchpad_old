#ifndef METAPROGRAMMING_STATIC_VALUE_H
#define METAPROGRAMMING_STATIC_VALUE_H

template<typename T, T VALUE>
struct static_parameter {
};

template<typename T, T VALUE>
struct static_value : static_parameter<T, VALUE> {
    static const T value = VALUE;

    // add a cast operator to allow switching from a
    // static constant to a runtime integer
    operator T() const {
        return VALUE;
    }
};

// this is usually safer than the cast operator
template<typename T, T VALUE>
inline T static_value_cast(static_value<T, VALUE>) {
    return VALUE;
};

#endif //METAPROGRAMMING_STATIC_VALUE_H

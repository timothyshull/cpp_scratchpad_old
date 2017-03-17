
// Integer literals
// sizeof and other operators with an integer result (__alignof__)
// non-type template parameters
// static constants of integer type
// some standard macros
// use static_assert
// use integral_constant
// use is_integral -> wraps a static constant of a specified type
// use bool_constant
// use is_same
// use decltype


template<typename T, T v>
struct simple_integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = simple_integral_constant;

    constexpr operator value_type() const noexcept { return value; }

    constexpr value_type operator()() const noexcept { return value; } //since c++14
};
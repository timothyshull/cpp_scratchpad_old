#include <cstddef>

// can see template parameters as a tuple of of parameters (of types and constants)
template<typename T, int N>
struct F {
    typedef T *pointer_type;
    typedef T &reference_type;
    static const size_t value = sizeof(T) * N;
};

template<typename T>
struct largest_precision_type;
template<>
struct largest_precision_type<float> {
    typedef double type;
};
template<>
struct largest_precision_type<double> {
    typedef double type;
};
template<>
struct largest_precision_type<int> {
    typedef long type;
};

// Similarly:
template<unsigned int N>
struct two_to {
    static const unsigned int value = static_cast<const unsigned int>(1 << N);
};

template<unsigned int N>
struct another_two_to {
    enum {
        value = (1 << N)
    };
};

//unsigned int i = two_to<5>::value; // invocation
//largest_precision<int>::type j = i + 100; // invocation

// older metafunctions were written using enums

template<size_t A>
struct is_prime {
    enum {
        value = 0
    };
};

template<>
struct is_prime<2> {
    enum {
        value = 1
    };
};

template<>
struct is_prime<3> {
    enum {
        value = 1
    };
};
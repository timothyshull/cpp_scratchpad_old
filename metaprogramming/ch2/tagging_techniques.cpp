#include <cmath>

// use an unnamed parameter of a static type
struct unsafe {
};

template<typename T>
class X {
public:
    void swap(T &that);

    void swap(T &that, unsafe);
};

// select a function
struct naive_algorithm_tag {
};
struct precise_algorithm_tag {
};

template<typename T>
inline T log1p(T x, naive_algorithm_tag) {
    return log(x + 1);
}

template<typename T>
inline T log1p(T x, precise_algorithm_tag) {
    const T xp1 = x + 1;
    return xp1 == 1 ? x : x * log(xp1) / (xp1 - 1);
}

// later...
double t1 = log1p(3.14, naive_algorithm_tag());
double t2 = log1p(0.00000000314, precise_algorithm_tag());

// use over an if statement to reduce code generation by not compiling
// the unused selection
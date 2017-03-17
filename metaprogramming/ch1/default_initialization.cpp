#include <string>

// T x; // implies nothing about initialization of the object iteself
// depends heavily on the type T

// for fundamental or POD -> undefined
// class -> some members may still be undefined

class A {
    std::string s_;
    int i_;
public:
    A() {}  // this will default-construct s_ but leave i_ uninitialized
};

// T x = T(); -> initializes T to 0 for fundamental types but crash if T is A

T a();
// error:
// a is a function taking no argument and returning T
// equivalent to T (*a)()

T b;
// ok only if T is a class with default constructor
// otherwise T is uninitialized

T c(T());
// error: c is a function taking a function and returning T
// equivalent to T (*c)(T (*)())

T d = {};
// ok only if T is a simple aggregate44 (e.g. a struct // without user-defined constructors)

T e = T();
// requires a non-explicit copy constructor
// and may yield undefined behaviour at runtime
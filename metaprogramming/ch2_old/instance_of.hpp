#ifndef METAPROGRAMMING_INSTANCE_OF_H
#define METAPROGRAMMING_INSTANCE_OF_H

template<typename T>
struct instance_of {
//    typedef T type;
    using type = T;

    instance_of(int = 0) {}
};

// use:
// const instance_of<int> I_INT = instance_of<int>(); // ok but cumbersome
// const instance_of<double> I_DOUBLE = 0;            // also fine.

// NOTE:
// const objects either need to be explicitly initialized or have a user
// defined default constructor

// use this construct to suppress the warning
// struct empty {
//     empty(int = 0) {}
// };

#endif //METAPROGRAMMING_INSTANCE_OF_H

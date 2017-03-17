#ifndef METAPROGRAMMING_SIZE_OF_H
#define METAPROGRAMMING_SIZE_OF_H

#include <cstdlib>

template<typename T>
class larger_than {
    T body_[2];   // private, not meant to be used
};

//sizeof(T) < 2*sizeof(T) < sizeof(larger_than<T>)
//1 = sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long)

template<size_t N>
struct fixed_size {
    typedef char type[N];
};

//sizeof(fixed_size<N>::type) == N

#endif //METAPROGRAMMING_SIZE_OF_H

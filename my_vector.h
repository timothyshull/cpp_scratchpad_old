//
// Created by Timothy Shull on 12/6/15.
//

#ifndef CPPLANGUAGE_MY_VECTOR_H
#define CPPLANGUAGE_MY_VECTOR_H

#include <memory>

template<class T, class A = std::allocator<T>>
class my_vector {
private:
    T* elem;
    T* space;
    T* last;
    A alloc;

public:
    using size_type = unsigned int;
    explicit my_vector(size_type n, const T& val = T(), const A& = A());

    my_vector(const my_vector& a); // copy constructor
    my_vector& operator=(my_vector&& a); // copy assignment


};


#endif //CPPLANGUAGE_MY_VECTOR_H

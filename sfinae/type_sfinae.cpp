#include <iostream>

template<int I>
struct X {
};

template<template<typename T> class>
struct Z {
};

template<typename T>
void f(typename T::Y *) {
    std::cout << "calling f(typename T::Y *)\n";
}

template<typename T>
void f(...) {
    std::cout << "calling f(...)\n";
}

template<typename T>
void g(X<T::N> *) {
    std::cout << "calling g(X<T::N> *)\n";
}

template<typename T>
void g(...) {
    std::cout << "calling g(...)\n";
}

template<typename T>
void h(Z<T::template TT> *) {
    std::cout << "calling h(Z<T::template TT> *)\n";
}

template<typename T>
void h(...) {
    std::cout << "calling h(...)\n";
}

struct A {
};

struct B {
    int Y;
};

struct C {
    typedef int N;
};

struct D {
    typedef int TT;
};

struct B1 {
    typedef int Y;
};

struct C1 {
    static const int N = 0;
};

struct D1 {
    template<typename T>
    struct TT {
    };
};

int main() {
    // Deduction fails in each of these cases:
    f<A>(0); // A does not contain a member Y
    f<B>(0); // The Y member of B is not a type
    g<C>(0); // The N member of C is not a non-type
    h<D>(0); // The TT member of D is not a template

    // Deduction succeeds in each of these cases:
    f<B1>(0);
    g<C1>(0);
    h<D1>(0);

    return 0;
}
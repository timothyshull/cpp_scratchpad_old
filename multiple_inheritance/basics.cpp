//
// Created by Tim Shull on 10/19/16.
//

#include <cstddef>
#include <iostream>

struct Base {
    int a{0};
    int b{0};
    int c{0};
    Base() = default;
    Base(int a1, int b1, int c1) : a{a1}, b{b1}, c{c1} {};
};
// every object of type Derived includes Base as a subobject
struct Derived : public Base {
    int b{1};
    Derived() = default;
    Derived(int b1) : b{b1} {
        std::cout << "in d(int) ctor\n";
    };
};
// every object of type Derived2 includes Derived and Base as subobjects
struct Derived2 : public Derived {
    int c{2};
    Derived2() : Derived(7) {
        std::cout << "in d2 default ctor\n";
    };
    Derived2(int g) : c{g} {
        Base::b = 14;
    };
};

int main() {
    Base base;
    Derived derived;
    Derived2 derived2{};

    derived.a = 1;
    derived.b = 1;
    derived.c = 1;

    derived2.a = 2;
//    derived2.b = 2;
    derived2.c = 2;

    size_t int_size = sizeof(int);
    size_t base_size = sizeof(base);
    size_t derived_size = sizeof(derived);
    size_t derived2_size = sizeof(derived2);

    return 0;
}
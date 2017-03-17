#include <iostream>

struct X {
};

//X operator+(X&rhs, X&lhs) {
//    std::cout << "operator + for X's\n";
//    return X{};
//}

struct Y {
    Y(X) {}
}; // X is convertible to Y

template<class T>
auto f(T t1, T t2) -> decltype(t1 + t2) {
    std::cout << "in f\n";
    return t1 + t2;
}; // overload #1


int main() {
    std::cout << "in main\n";
//    X f(Y, Y);  // overload #2
    X x1, x2;
    X x3 = f(x1, x2);  // deduction fails on #1 (expression x1+x2 is ill-formed)
    // only #2 is in the overload set, and is called
    return 0;
}
#include <iostream>
#include <utility>
#include <type_traits>

struct A {
};

struct B {
    bool operator==(B const &);
};

struct C {
    short operator==(C const &);
};


// Could require custom positive and negative classes if for some reason std::false_type was returned from ==
template<typename T>
class Has_operator_equal {
    static std::false_type test(...);

    template<typename X>
    static auto test(X) -> decltype(std::declval<X>() == std::declval<X>());

public:
    static const bool value = !std::is_same<decltype(test(std::declval<T>())), std::false_type>::value;
};

//void test(...) {
//    std::cout << "in false test\n";
//};
//
//template<typename X>
//auto test(X &) -> decltype(static_cast<void>(std::declval<X>() == std::declval<X>())) {
//    std::cout << "in true test\n";
//};

template <typename T>
constexpr bool has_operator_equal() {
    return Has_operator_equal<T>::value;
}


int main() {
//    A a{};
//    B b{};
//    C c{};
//    test(a);
//    test(b);
//    test(c);
//    auto c = has_operator_equal<B>::test(b);
    std::cout << "has_operator_equal<A>() = " << std::boolalpha << has_operator_equal<A>() << std::endl;
    std::cout << "has_operator_equal<B>() = " << std::boolalpha << has_operator_equal<B>() << std::endl;
    std::cout << "has_operator_equal<C>() = " << std::boolalpha << has_operator_equal<C>() << std::endl;
    std::cout << "false_type is same as false " << std::boolalpha << std::is_same<std::false_type, decltype(false)>::value << "\n";
    return 0;
}
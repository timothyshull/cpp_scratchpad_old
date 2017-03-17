#include <iostream>
#include <utility>

//#include <boost/type_traits>

template<int n>
struct Obj_of_size {
    char data_[n];
};

using Pos_type = Obj_of_size<2>;
using Neg_type = Obj_of_size<1>;


struct A {
};

bool operator==(A &lhs, A &rhs) {
    std::cout << "has ===\n";
    return true;
}

struct B {
};

template<typename T>
T &get_type();

template<typename T>
struct has_equal {
    template<typename U>
    static const Pos_type test(bool);

    static const Neg_type test(...);

//    template<class U, class L, class R>
//    static auto test(int) -> decltype(std::declval<U>()(std::declval<L>(), std::declval<R>()),
//            void(), std::true_type());
//
//    template<class U, class L, class R>
//    static auto test(...) -> std::false_type;
//
//    using type = decltype(test<Op, X, Y>(0));

//    static const bool value = sizeof(test(std::declval<decltype(get_type<T>() == get_type<T>())>())) != sizeof(Neg_type);
};


int main() {
    std::cout << std::boolalpha << (std::declval<A&>() == std::declval<A&>()) << "\n";
//    std::cout << std::boolalpha << has_equal<B>::value << "\n";
    return 0;
}
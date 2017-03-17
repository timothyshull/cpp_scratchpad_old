#include<iostream>
#include<memory>

struct A {};

int main() {
    A *a1{new A};
    std::shared_ptr<A>a2{std::make_shared<A>()};
    std::unique_ptr<A>a3{std::make_unique<A>()};

    std::pointer_traits<A *>pt1;
    std::pointer_traits<std::shared_ptr<A>>pt2;
    std::pointer_traits<std::unique_ptr<A>>pt3;

    std::cout << std::boolalpha << std::is_pointer<A *>::value << '\n';
    std::cout << std::boolalpha << std::is_pointer<std::shared_ptr<A>>::value << '\n';
    std::cout << std::boolalpha << std::is_pointer<std::unique_ptr<A>>::value << '\n';

    std::cout << "a1: " << std::addressof(a1) << "\n";
    decltype(a1) a1_2{std::move(a1)};
    std::cout << "a1_2: " << std::addressof(a1_2) << "\n";

    // NOTE: the address of the pointer is offset from the address of the container
    std::cout << "a2: " << std::addressof(a2) << "\n";
    auto a2_get{a2.get()};
    std::cout << "a2.get(): " << std::addressof(a2_get) << "\n";
    // NOTE: creates a new unique_ptr instance with a different address and a different contained pointer address
    decltype(a2) a2_2{std::move(a2)};
    std::cout << "a2_2: " << std::addressof(a2_2) << "\n";
    auto a2_2_get = a2_2.get();
    std::cout << "a2_2.get(): " << a2_2_get << "\n";
    auto a2_3_get = a2_2.get();
    std::cout << "a2_3: " << a2_3_get << "\n";
    return 0;
}
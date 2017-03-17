//
// Created by Tim Shull on 10/8/16.
//

#include <memory>

template<typename T>
class TestClass {
public:
    std::unique_ptr<TestClass> ptr;
    T value;
};


int main() {
    TestClass<int> *pp1 = new TestClass<int>;
    pp1->value = 1;
    TestClass<int> *pp2 = new TestClass<int>;
    pp1->value = 2;

    auto u1 = std::make_unique<TestClass<int>>(11);
    auto u2 = std::make_unique<TestClass<int>>(12);

    return 0;
}

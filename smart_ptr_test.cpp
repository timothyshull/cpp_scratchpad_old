#include <iostream>

struct Foo {
    Foo() { std::cout << "Foo ..." << std::endl; }

    ~Foo() { std::cout << "~Foo ..." << std::endl; }
};

struct D {
    void operator()(Foo *pp) const {
        std::cout << "Call delete for Foo object ..." << std::endl;
    }
};

int main() {
    {
        std::cout << "constructor with no managed object\n";
        std::shared_ptr<Foo> sh1;
    }

    {
        std::cout << "constructor with object\n";
        std::shared_ptr<Foo> sh2(new Foo);
        std::shared_ptr<Foo> sh3(sh2);
        std::cout << sh2.use_count() << '\n';
        std::cout << sh3.use_count() << '\n';
    }

    {
        std::cout << "constructor with object and deleter\n";
        std::shared_ptr<Foo> sh4(new Foo, D());
    }
    return 0;
}
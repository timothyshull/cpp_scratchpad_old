#include <iostream>
#include <thread>

struct Base {
    Base() { std::cout << "  Base::Base()\n"; }

    virtual ~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base {
    Derived() { std::cout << "  Derived::Derived()\n"; }

    ~Derived() { std::cout << "  Derived::~Derived()\n"; }

    void random() { std::cout << "  random\n"; }
};

int main() {
    std::unique_ptr<Derived> udp;
    {
        Base b;
        Derived d;
        Base *bp{&d};
        Derived *dp{&d};
        if (udp) std::cout << "udp above\n";
        if (!udp) std::cout << "not udp above\n";
        udp.reset(new Derived);
        if (udp) std::cout << "udp below\n";
        if (!udp) std::cout << "not udp below\n";
        d.random();
        dp->random();
        udp->random();
    }

    return 0;
}
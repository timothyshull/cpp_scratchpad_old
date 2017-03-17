#include <iostream>

struct T {
    T() {
        std::cout << "T()\n";
    }

    virtual ~T() {
        std::cout << "~T()\n";
    }
};

struct U : public T {
    U() {
        std::cout << "U()\n";
    }

    virtual ~U() {
        std::cout << "~U()\n";
    }
};

int main() {
    {
        std::cout << "start block\n";
        T tmp{};
        U tmp2{};
        std::cout << "end block\n";
    }
    std::cout << "after block\n";
    T *tmp = new T{};
    delete tmp;
    U *tmp2 = new U{};
    delete tmp2;
    return 0;
}
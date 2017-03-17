#include <iostream>

using namespace std;

void mod_ref(int &);

int mod_stupid(int);

int main() {
    int x{3};
    int y;
    std::cout << x << std::endl;
    mod_ref(x);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    y = mod_stupid(y);
    std::cout << y << std::endl;
    return 0;
}

void mod_ref(int &a) {
    a = 10;
}

int mod_stupid(int a) {
    std::cout << a << std::endl;
    a = 11;
    return a;
}
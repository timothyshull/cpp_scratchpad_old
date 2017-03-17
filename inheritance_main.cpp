#include <iostream>
#include <memory>

using namespace std;

int main() {
    int a{1};
    int *b{&a};
    cout << *b << endl;
    *b = 3;
    cout << *b << endl;
    cout << b << endl;

    int c{4};
    std::unique_ptr<int> d{std::make_unique<int>(c)};
    cout << *d << endl;
    return 0;
}
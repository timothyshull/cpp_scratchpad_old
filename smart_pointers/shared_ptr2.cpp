#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> test{1, 2, 3, 4};

    for (auto i : test) {
        std::cout << i << std::endl;
    }

    for (auto i = test.begin(); i < test.end(); i++) {
        std::cout << *i << std::endl;
    }

    std::shared_ptr<std::vector<int>> test_ptr{std::make_shared<std::vector<int>>(test)};

    for (auto i : *test_ptr) {
        std::cout << i << std::endl;
    }

    cout << "Hello, World!" << endl;
    return 0;
}
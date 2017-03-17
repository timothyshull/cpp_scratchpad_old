#include <iostream>
#include <thread>

void hello() {
    std::cout << "1\n";
    std::cout << "2\n";
    std::cout << "3\n";
    std::cout << "4\n";
    std::cout << "5\n";
    std::cout << "6\n";
    std::cout << "7\n";
    std::cout << "8\n";
    std::cout << "9\n";
    std::cout << "10\n";
    std::cout << "11\n";
}

int main() {
    std::thread t{hello};
    t.join();

    return 0;
}
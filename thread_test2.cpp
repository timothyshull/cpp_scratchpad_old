#include <iostream>
#include <thread>

class background_task {
public:
    void operator()() const {
        std::cout << "1\n";
        std::cout << "2\n";
        std::cout << "3\n";
        std::cout << "4\n";
        std::cout << "5\n";
    }
};

int main() {
    background_task bt;
    std::thread t{bt};
    t.join();

    return 0;
}
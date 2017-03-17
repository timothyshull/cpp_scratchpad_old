#include "1_1.h"
#include <iostream>
#include <thread>

int main() {
    hello newHello;
    hello&& std::move(newHello);
    std::thread newThread (newHello);
    newThread.join();
    return 0;
}
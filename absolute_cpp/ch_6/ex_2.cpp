#include "CounterType.h"
#include <iostream>

int main() {
    CounterType counter;
    std::cout << counter.getCount();
    counter.print();
}

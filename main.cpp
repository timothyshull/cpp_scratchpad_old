#include <iostream>
#include "tape_equil.h"

int main() {
    std::vector<int> v1{1, 2, 3, 4, 5, 6};
    std::vector<int> v2{1, -2, 3, -4, 5, -6};
    std::vector<int> v3{5, 4, -10};
    std::vector<int> v4{3, 3, 3};
    std::vector<int> v5{-1000, 1000};

//    std::cout << tape_equilibrium(v1) << '\n' << std::endl;
//    std::cout << tape_equilibrium(v2) << '\n' << std::endl;
//    std::cout << tape_equilibrium(v3) << '\n' << std::endl;
//    std::cout << tape_equilibrium(v4) << '\n' << std::endl;
    std::cout << tape_equilibrium(v5) << '\n' << std::endl;
    return 0;
}
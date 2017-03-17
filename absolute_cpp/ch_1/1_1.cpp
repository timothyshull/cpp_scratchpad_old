//
// Created by Timothy Shull on 12/25/15.
//

#include "1_1.h"
#include <iostream>

double convertToTons(double d) {
    return d / 35273.92;
}

int getNumBoxes(double boxWeight) {
    return static_cast<int> (1.0 / convertToTons(boxWeight));
}

void readPackageWeight() {
    double pkg;
    std::cout << "Input the weight, in ounces, of a single box of breakfast cereal: \n";
    std::cin >> pkg;
    std::cout << "The weight in metric tons of a single package is: " << convertToTons(pkg) << "\n";
    std::cout << "The the number of boxes required to produce one metric ton is: " << getNumBoxes(pkg) << std::endl;
}

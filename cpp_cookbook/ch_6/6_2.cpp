//
// Created by Timothy Shull on 12/20/15.
//

#include "6_2.h"
#include <iostream>
#include <vector>

void efficientVectors() {
    // Set aside size on construction
    std::vector<std::string> vec1(500);

    // Always pass by reference or const reference
    /*void f(std::vector<std::string> &vec) {
       // ...
    }*/

    std::vector<std::string> vec2;

    // Use the reserve method after the vector has been constructed
    vec2.reserve(500);

    // Vectors store copies using the copy or assignment operator
    // Resizing vectors is not a cheap operation so over-allocate if necessary
    // Reserve does not initialize the space with anything whereas specifying the size at construction does
}

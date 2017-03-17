#include "square.h"

namespace experiments4 {
    double Square::get_area() {
        return side * side;
    }

    double Square::get_perimeter() {
        return side * 4;
    }

    Square::Square(double t_side) : side{t_side} { }

    Square::Square(int t_side) : side{static_cast<double>(t_side)} { }
}

//
// Created by Timothy Shull on 12/12/15.
//

#include "Point.h"

Point::Point(double val) : x{val}, y{0.0} { };

Point::Point(int val) : x{static_cast<double> (val)}, y{0.0} { };

Point::Point(double valX, double valY) : x{valX}, y{valY} { };

Point::Point(int valX, int valY) : x{static_cast<double> (valX)}, y{static_cast<double> (valY)} { };

void Point::setX(double val) {
    x = val;
};

void Point::setX(int val) {
    x = static_cast<double> (val);
};

void Point::setY(double val) {
    y = val;
};

void Point::setY(int val) {
    y = static_cast<double> (val);
};

double Point::getX() {
    return x;
};

double Point::getY() {
    return y;
};
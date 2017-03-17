//
// Created by Timothy Shull on 12/12/15.
//

#ifndef ABSTRACTFACTORY_POINT_H
#define ABSTRACTFACTORY_POINT_H

class Point {
private:
    double x;
    double y;

public:
    explicit Point(double);

    explicit Point(int);

    Point(double, double);

    Point(int, int);

    void setX(double);

    void setX(int);

    void setY(double);

    void setY(int);

    double getX();

    double getY();
};

#endif //ABSTRACTFACTORY_POINT_H

//
// Created by Timothy Shull on 12/12/15.
//

#ifndef ABSTRACTFACTORY_SHAPE_H
#define ABSTRACTFACTORY_SHAPE_H

class Shape {
public:
    virtual double computeArea() const = 0;

    virtual double computePerimeter() const = 0;
};

#endif //ABSTRACTFACTORY_SHAPE_H

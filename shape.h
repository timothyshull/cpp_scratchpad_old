#ifndef EXPERIMENTS4_SHAPE_H
#define EXPERIMENTS4_SHAPE_H

namespace experiments4 {
    class Shape {
    public:
        virtual double get_perimeter() = 0;

        virtual double get_area() = 0;

        virtual ~Shape() { };
    };
}

#endif //EXPERIMENTS4_SHAPE_H
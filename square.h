#ifndef EXPERIMENTS4_SQUARE_H
#define EXPERIMENTS4_SQUARE_H

#import "shape.h"

namespace experiments4 {
    class Square : public Shape {
    private:
        double side{0};
    public:
        double get_area() override;
        double get_perimeter() override;
        explicit Square(double);
        explicit Square(int);
    };
}

#endif //EXPERIMENTS4_SQUARE_H

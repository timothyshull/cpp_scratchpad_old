//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_14_H
#define CPP_COOKBOOK_8_14_H

class Balance {
    friend const Balance operator+(const Balance& lhs, const Balance& rhs);

    friend const Balance operator+(double lhs, const Balance& rhs);

    friend const Balance operator+(const Balance& lhs, double rhs);

public:
    Balance() : val_{0.0} { }

    Balance(double val) : val_(val) { }

    ~Balance() { }

    Balance& operator+=(const Balance&);

    Balance& operator+=(double);

    double getVal() const;

private:
    double val_;
};

void testArithmeticOperators();

#endif //CPP_COOKBOOK_8_14_H

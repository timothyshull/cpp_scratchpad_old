//
// Created by Timothy Shull on 12/25/15.
//

#include "8_14.h"
#include <iostream>

Balance& Balance::operator+=(const Balance& other) {
    val_ += other.val;
    return *this;
}

Balance& Balance::operator+=(double other) {
    val_ += other;
    return *this;
}

double Balance::getVal() const {
    return val_;
}

const Balance operator+(const Balance& lhs, const Balance& rhs) {
    return Balance(lhs.val_ + rhs.val_);
}

const Balance operator+(double lhs, const Balance& rhs) {
    return Balance(lhs + rhs.val_);
}


const Balance operator+(const Balance& lhs, double rhs) {
    return Balance(lhs.val_ + rhs);
}

void testArithmeticOperators() {
    Balance checking{500.00}, savings{23.91};

    checking += 50;
    Balance total = checking + savings;
    std::cout << "Checking balance: " << checking.getVal() << std::endl;
    std::cout << "Savings balance: " << savings.getVal() << std::endl;
}

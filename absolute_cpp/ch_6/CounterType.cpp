#include <iostream>
#include "CounterType.h"

CounterType::CounterType() : count_{0} { }

void CounterType::setCount(int newCount) {
    if (newCount > 0)
        this->count_ = newCount;
}

CounterType& CounterType::operator++() {
    this->count_ += 1;
    return *this;
}

CounterType CounterType::operator++(int) {
    CounterType tmp(*this); // copy
    operator++(); // pre-increment
    return tmp;   // return old value
}

CounterType& CounterType::operator--() {
    if (this->count_ > 0)
        this->count_ -= 1;
    else
        this->count_ = 0;
    return *this;
}

CounterType CounterType::operator--(int) {
    CounterType tmp(*this); // copy
    operator--(); // pre-increment
    return tmp;   // return old value
}

int CounterType::getCount() const {
    return this->count_;
}

void CounterType::print() {
    std::cout << this->count_;
}




//std::ostream& operator<<(std::ostream& out, const CounterType& f) {
//    out << f.getCount();
//    return out;
//}
//std::ostream& operator<<(std::ostream& out, CounterType& ctr) {
////    out << ctr.count_;
//    return out << 1;
//}

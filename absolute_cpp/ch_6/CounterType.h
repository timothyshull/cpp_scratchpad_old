//
// Created by Timothy Shull on 2/29/16.
//

#ifndef ABSOLUTE_CPP_COUNTERTYPE_H
#define ABSOLUTE_CPP_COUNTERTYPE_H

#include <iosfwd>
#include <MacTypes.h>

class CounterType {
private:
    int count_;
public:
    CounterType();

    CounterType& operator++();

    CounterType operator++(int);

    CounterType& operator--();

    CounterType operator--(int);

    void setCount(int newCount);

    int getCount() const;

    void print();
};



#endif //ABSOLUTE_CPP_COUNTERTYPE_H

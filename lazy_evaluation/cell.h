#ifndef LAZY_EVALUATION_CELL_H
#define LAZY_EVALUATION_CELL_H

#include "stream.h"

template<class T>
class Cell {
public:
    Cell() { } // need default constructor for memoization
    Cell(T v, Stream<T> const& tail)
            : _v(v), _tail(tail) { }

    explicit Cell(T v) : _v(v) { }

    T val() const {
        return _v;
    }

    Stream<T> pop_front() const {
        return _tail;
    }

private:
    T _v;
    Stream<T> _tail;
};

#endif //LAZY_EVALUATION_CELL_H

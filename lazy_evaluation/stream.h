#ifndef LAZY_EVALUATION_STREAM_H
#define LAZY_EVALUATION_STREAM_H

#include <algorithm>
#include "susp.h"

class Cell;

template<class T>
class Stream {
private:
    std::shared_ptr<Susp<Cell<T>>>
            _lazyCell;
public:
    Stream() { }

    Stream(std::function<Cell<T>()> f)
            : _lazyCell(std::make_shared<Susp<Cell<T >>>(f)) { }

    Stream(Stream&& stm)
            : _lazyCell(std::move(stm._lazyCell)) { }

    Stream& operator=(Stream&& stm) {
        _lazyCell = std::move(stm._lazyCell);
        return *this;
    }

    bool isEmpty() const {
        return !_lazyCell;
    }

    T get() const {
        return _lazyCell->get().val();
    }

    Stream<T> pop_front() const {
        return _lazyCell->get().pop_front();
    }
};

#endif //LAZY_EVALUATION_STREAM_H

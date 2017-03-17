#ifndef LAZY_EVALUATION_SIMPLE_SUSPENSION_H
#define LAZY_EVALUATION_SIMPLE_SUSPENSION_H

#include <functional>

template<class T>
class Susp {
    explicit Susp(std::function<T()> f) : _f(f) { }

    T get() { return _f(); }

private:
    std::function<T()> _f;
};

#endif //LAZY_EVALUATION_SIMPLE_SUSPENSION_H

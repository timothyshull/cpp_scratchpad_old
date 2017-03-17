#ifndef LAZY_EVALUATION_SUSP_H
#define LAZY_EVALUATION_SUSP_H

#include <functional>

template<class T>
class Susp {
    // thunk
    static T const& thunkForce(Susp* susp) {
        return susp->setMemo();
    }

    // thunk
    static T const& thunkGet(Susp* susp) {
        return susp->getMemo();
    }

    T const& getMemo() {
        return _memo;
    }

    T const& setMemo() {
        _memo = _f();
        _thunk = &thunkGet;
        return getMemo();
    }

public:
    explicit Susp(std::function<T()> f)
            : _f(f), _thunk(&thunkForce), _memo(T()) { }

    T const& get() {
        return _thunk(this);
    }

private:
    T const& (* _thunk)(Susp*);

    mutable T _memo;

    std::function<T()> _f;
};

#endif //LAZY_EVALUATION_SUSP_H

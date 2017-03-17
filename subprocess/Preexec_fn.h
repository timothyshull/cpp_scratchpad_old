//
// Created by Tim Shull on 10/22/16.
//

#ifndef SUBPROCESS_PREEXEC_FN_H
#define SUBPROCESS_PREEXEC_FN_H

#include <functional>

namespace subprocess {
    template<typename Return, typename... Args>
    class Preexec_fn {
        std::function<Return(Args...)> _pf;
    public:
        Preexec_fn(std::function<Return(Args...)> f) : _pf(f) {}

        Return operator()(Args... args) const { return _pf(args...); }
    };
}

#endif //SUBPROCESS_PREEXEC_FN_H

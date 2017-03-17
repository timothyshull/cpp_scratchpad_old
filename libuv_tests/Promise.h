#ifndef LIBUV_TESTS_PROMISE_H
#define LIBUV_TESTS_PROMISE_H

#include<functional>
#include<type_traits>
#include<tuple>

#include"utility.h"

// working from https://github.com/then/promise
// to ultimately hook these promises into libuv

void noop(...) {}

enum class Promise_state : int {
    pending = 0,
    fulfilled = 1, // with value
    rejected = 2, // with value
    merged = 3 // took on the state of another promise
};

template<typename T, typename Enable = void>
class Promise {};

template<typename Function_type, typename ...Args, typename Return, typename ...Deferreds>
class Promise<Function_type, typename std::enable_if<is_callable<Function_type>::value>::type> {
    // int deferred_state_;
    Promise_state state_;
    Return value_;
    std::tuple<Deferreds...> deferreds_;
    void (*_noop)(...) = noop;

public:
    Promise(Function_type fn) : state_{Promise_state::pending} {
        std::function<Function_type> wrapped_func{fn};

        if (!wrapped_func || std::is_same<Function_type, decltype(noop)>::value) {
            return;
        }
        do_resolution(wrapped_func);
    }


};

#endif //LIBUV_TESTS_PROMISE_H

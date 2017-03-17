#ifndef JS_PROMISES_PROMISE_H
#define JS_PROMISES_PROMISE_H

#include<functional>
#include<type_traits>
#include <string>

#include"utility.h"

enum class Promise_states {
    no_state = 0,
};

template<class Return_type, class ...Arg_types>
class Promise<Return_type(Arg_types...)> {
    void _check(std::function<Return_type(Arg_types...)> executor) {
        // static_assert(std::is_callable) -> can check if callable here but this should be handled by std::function
        // no need to check that type is a promise here
    }

    int _bit_field;
    void (*_fulfillment_handler)(); // TODO: add a way to set the types here
    void (*_rejection_handler)(); // TODO: add a way to set the types here
    Return_type (*_promise)(Arg_types...); // this should be the std::function
    void (*_receiver)(Arg_types...);

public:
    explicit Promise(std::function<Return_type(Arg_types...)> executor) : _bit_field{static_cast<int>(Promise_states::no_state)} {
        if (!std::is_same<decltype(executor), Noop>::value) {
            _check(executor);
            _resolve_from_executor(executor);
        }
        _promise_created();
        _fire_event();
    }

    inline std::string to_string() { return "[object Promise]"; }

    // TODO: should handle separate args here to get len
    void catch_error(std::function<Return_type(Arg_types...)> fn) {
        constexpr int len = sizeof...(Arg_types);
        if (len > 1) {

        }
        then([]{}, fn);

    }
};

#endif //JS_PROMISES_PROMISE_H

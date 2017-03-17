#ifndef LIBUV_TESTS_UTILITY_H
#define LIBUV_TESTS_UTILITY_H

#include <utility>

// uses result_of from the docs and libcxx is_callable components
namespace utility {
    struct None {
        None() = delete;

        None(const None &) = delete;

        None &operator=(const None &) = delete;

        ~None() = delete;
    };

    template<class F, class... Args>
    inline auto invoke(F &&f, Args &&... args) -> decltype(std::forward<F>(f)(std::forward<Args>(args)...)) {
        return std::forward<F>(f)(std::forward<Args>(args)...);
    }

    template<class Base, class T, class Derived>
    inline auto invoke(T Base::*pmd, Derived &&ref) -> decltype(std::forward<Derived>(ref).*pmd) {
        return std::forward<Derived>(ref).*pmd;
    }

    template<class PMD, class Pointer>
    inline auto invoke(PMD &&pmd, Pointer &&ptr) -> decltype((*std::forward<Pointer>(ptr)).*std::forward<PMD>(pmd)) {
        return (*std::forward<Pointer>(ptr)).*std::forward<PMD>(pmd);
    }

    template<class Base, class T, class Derived, class... Args>
    inline auto invoke(T Base::*pmf, Derived &&ref, Args &&... args) -> decltype((std::forward<Derived>(ref).*pmf)(std::forward<Args>(args)...)) {
        return (std::forward<Derived>(ref).*pmf)(std::forward<Args>(args)...);
    }

    template<class PMF, class Pointer, class... Args>
    inline auto invoke(PMF &&pmf, Pointer &&ptr, Args &&... args) -> decltype(((*std::forward<Pointer>(ptr)).*std::forward<PMF>(pmf))(std::forward<Args>(args)...)) {
        return ((*std::forward<Pointer>(ptr)).*std::forward<PMF>(pmf))(std::forward<Args>(args)...);
    }

    // invokable
    template<class Return, class Function_ptr, class ...Args>
    struct invokable_r {
        using Result = decltype(invoke(std::declval<Function_ptr>(), std::declval<Args>()...));

        static const bool value = std::conditional<!std::is_same<Result, None>::value, typename std::conditional<std::is_void<Return>::value, std::true_type, std::is_convertible<Result, Return>>::type, std::false_type>::type::value;
    };
}; // namespace utility

template<class Function, class Return = void>
struct is_callable {};

template<class Function, class ...Args, class Return>
struct is_callable<Function(Args...), Return>
        : std::integral_constant<bool, utility::invokable_r<Return, Function, Args...>::value> {
};

template<class Function, class Return = void>
constexpr bool is_callable_v = is_callable<Function, Return>::value;

#endif //LIBUV_TESTS_UTILITY_H

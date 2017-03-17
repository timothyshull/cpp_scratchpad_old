#ifndef JS_PROMISES_TMP_H
#define JS_PROMISES_TMP_H

#include <__config>
#include <system_error>
#include <memory>
#include <chrono>
#include <exception>
#include <mutex>
#include <thread>
#include <cstdlib>

void lassert(bool x, const char *m) {
    if (!x) {
        std::fprintf(stderr, "%s\n", m);
        std::abort();
    }
}

enum class future_errc {
    future_already_retrieved = 1,
    promise_already_satisfied,
    no_state,
    broken_promise
};
template<>
struct is_error_code_enum<future_errc> : public std::true_type {};

enum class launch {
    async = 1,
    deferred = 2,
    any = 1 | 2 // async | deferred
};

//    using __launch_underlying_type = std::underlying_type<launch>::type;

using __launch_underlying_type = int;

inline
constexpr
launch
operator&(launch __x, launch __y) {
    return static_cast<launch>(static_cast<__launch_underlying_type>(__x) &
                               static_cast<__launch_underlying_type>(__y));
}

inline
constexpr
launch
operator|(launch __x, launch __y) {
    return static_cast<launch>(static_cast<__launch_underlying_type>(__x) |
                               static_cast<__launch_underlying_type>(__y));
}

inline
constexpr
launch
operator^(launch __x, launch __y) {
    return static_cast<launch>(static_cast<__launch_underlying_type>(__x) ^
                               static_cast<__launch_underlying_type>(__y));
}

inline
constexpr
launch
operator~(launch __x) {
    return static_cast<launch>(~static_cast<__launch_underlying_type>(__x) & 3);
}

inline
launch &
operator&=(launch &__x, launch __y) {
    __x = __x & __y;
    return __x;
}

inline
launch &
operator|=(launch &__x, launch __y) {
    __x = __x | __y;
    return __x;
}

inline
launch &
operator^=(launch &__x, launch __y) {
    __x = __x ^ __y;
    return __x;
}

//enum class future_status
enum class future_status {
    ready,
    timeout,
    deferred
};

const std::error_category &future_category() noexcept;

inline std::error_code make_error_code(future_errc __e) noexcept {
    return error_code(static_cast<int>(__e), future_category());
}

inline
std::error_condition
make_error_condition(future_errc __e) noexcept {
    return error_condition(static_cast<int>(__e), future_category());
}

class future_error : public std::logic_error {
    std::error_code __ec_;
public:
    future_error(std::error_code __ec);

    const std::error_code &code() const noexcept { return __ec_; }

    virtual ~future_error() noexcept;
};

[[noreturn]] inline
void __throw_future_error(future_errc _Ev) {
    throw future_error(make_error_code(_Ev));
}

class __assoc_sub_state
        : public std::__shared_count {
protected:
    std::exception_ptr __exception_;
    mutable std::mutex __mut_;
    mutable std::condition_variable __cv_;
    unsigned __state_;

    virtual void __on_zero_shared() noexcept;

    void __sub_wait(std::unique_lock<std::mutex> &__lk);

public:
    enum {
        __constructed = 1,
        __future_attached = 2,
        ready = 4,
        deferred = 8
    };

    __assoc_sub_state() : __state_(0) {}

    bool __has_value() const { return (__state_ & __constructed) || (__exception_ != nullptr); }

    void __set_future_attached() {
        std::lock_guard<std::mutex> __lk(__mut_);
        __state_ |= __future_attached;
    }

    bool __has_future_attached() const { return (__state_ & __future_attached) != 0; }

    void __set_deferred() { __state_ |= deferred; }

    void __make_ready();

    bool __is_ready() const { return (__state_ & ready) != 0; }

    void set_value();

    void set_value_at_thread_exit();

    void set_exception(std::exception_ptr __p);

    void set_exception_at_thread_exit(std::exception_ptr __p);

    void copy();

    void wait();

    template<class _Rep, class _Period>
    future_status

    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const;

    template<class _Clock, class _Duration>
    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const;

    virtual void __execute();
};

template<class _Clock, class _Duration>
future_status
__assoc_sub_state::wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const {
    std::unique_lock<std::mutex> __lk(__mut_);
    if (__state_ & deferred) {
        return future_status::deferred;
    }
    while (!(__state_ & ready) && _Clock::now() < __abs_time) {
        __cv_.wait_until(__lk, __abs_time);
    }
    if (__state_ & ready) {
        return future_status::ready;
    }
    return future_status::timeout;
}

template<class _Rep, class _Period>
inline
future_status
__assoc_sub_state::wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const {
    return wait_until(std::chrono::steady_clock::now() + __rel_time);
}

template<class _Rp>
class __assoc_state
        : public __assoc_sub_state {
    typedef __assoc_sub_state base;
    typedef typename std::aligned_storage<sizeof(_Rp), std::alignment_of<_Rp>::value>::type _Up;
protected:
    _Up __value_;

    virtual void __on_zero_shared() noexcept;

public:

    template<class _Arg>
    void set_value(_Arg &&__arg);

    template<class _Arg>
    void set_value_at_thread_exit(_Arg &&__arg);

    _Rp move();

    typename std::add_lvalue_reference<_Rp>::type copy();
};

template<class _Rp>
void
__assoc_state<_Rp>::__on_zero_shared() noexcept {
    if (this->__state_ & base::__constructed) {
        reinterpret_cast<_Rp *>(&__value_)->~_Rp();
    }
    delete this;
}

template<class _Rp>
template<class _Arg>
void
__assoc_state<_Rp>::set_value(_Arg &&__arg) {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    if (this->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    ::new(&__value_) _Rp(std::forward<_Arg>(__arg));
    this->__state_ |= base::__constructed | base::ready;
    __cv_.notify_all();
}

template<class _Rp>
template<class _Arg>
void
__assoc_state<_Rp>::set_value_at_thread_exit(_Arg &&__arg) {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    if (this->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    ::new(&__value_) _Rp(std::forward<_Arg>(__arg));
    this->__state_ |= base::__constructed;
    std::__thread_local_data()->__make_ready_at_thread_exit(this);
}

template<class _Rp>
_Rp
__assoc_state<_Rp>::move() {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    this->__sub_wait(__lk);
    if (this->__exception_ != nullptr) {
        rethrow_exception(this->__exception_);
    }
    return std::move(*reinterpret_cast<_Rp *>(&__value_));
}

template<class _Rp>
typename std::add_lvalue_reference<_Rp>::type
__assoc_state<_Rp>::copy() {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    this->__sub_wait(__lk);
    if (this->__exception_ != nullptr) {
        rethrow_exception(this->__exception_);
    }
    return *reinterpret_cast<_Rp *>(&__value_);
}

template<class _Rp>
class __assoc_state<_Rp &>
        : public __assoc_sub_state {
    typedef __assoc_sub_state base;
    typedef _Rp *_Up;
protected:
    _Up __value_;

    virtual void __on_zero_shared() noexcept;

public:

    void set_value(_Rp &__arg);

    void set_value_at_thread_exit(_Rp &__arg);

    _Rp &copy();
};

template<class _Rp>
void
__assoc_state<_Rp &>::__on_zero_shared() noexcept {
    delete this;
}

template<class _Rp>
void
__assoc_state<_Rp &>::set_value(_Rp &__arg) {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    if (this->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    __value_ = std::addressof(__arg);
    this->__state_ |= base::__constructed | base::ready;
    __cv_.notify_all();
}

template<class _Rp>
void
__assoc_state<_Rp &>::set_value_at_thread_exit(_Rp &__arg) {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    if (this->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    __value_ = std::addressof(__arg);
    this->__state_ |= base::__constructed;
    std::__thread_local_data()->__make_ready_at_thread_exit(this);
}

template<class _Rp>
_Rp &
__assoc_state<_Rp &>::copy() {
    std::unique_lock<std::mutex> __lk(this->__mut_);
    this->__sub_wait(__lk);
    if (this->__exception_ != nullptr) {
        rethrow_exception(this->__exception_);
    }
    return *__value_;
}

template<class _Rp, class _Alloc>
class __assoc_state_alloc
        : public __assoc_state<_Rp> {
    typedef __assoc_state<_Rp> base;
    _Alloc __alloc_;

    virtual void __on_zero_shared() noexcept;

public:

    explicit __assoc_state_alloc(const _Alloc &__a)
            : __alloc_(__a) {}
};

template<class _Rp, class _Alloc>
void
__assoc_state_alloc<_Rp, _Alloc>::__on_zero_shared() noexcept {
    if (this->__state_ & base::__constructed) {
        reinterpret_cast<_Rp *>(std::addressof(this->__value_))->~_Rp();
    }
    typedef typename std::__allocator_traits_rebind<_Alloc, __assoc_state_alloc>::type _Al;
    typedef std::allocator_traits<_Al> _ATraits;
    typedef std::pointer_traits<typename _ATraits::pointer> _PTraits;
    _Al __a(__alloc_);
    this->~__assoc_state_alloc();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

template<class _Rp, class _Alloc>
class __assoc_state_alloc<_Rp &, _Alloc>
        : public __assoc_state<_Rp &> {
    typedef __assoc_state<_Rp &> base;
    _Alloc __alloc_;

    virtual void __on_zero_shared() noexcept;

public:

    explicit __assoc_state_alloc(const _Alloc &__a)
            : __alloc_(__a) {}
};

template<class _Rp, class _Alloc>
void
__assoc_state_alloc<_Rp &, _Alloc>::__on_zero_shared() noexcept {
    typedef typename std::__allocator_traits_rebind<_Alloc, __assoc_state_alloc>::type _Al;
    typedef std::allocator_traits<_Al> _ATraits;
    typedef std::pointer_traits<typename _ATraits::pointer> _PTraits;
    _Al __a(__alloc_);
    this->~__assoc_state_alloc();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

template<class _Alloc>
class __assoc_sub_state_alloc
        : public __assoc_sub_state {
    typedef __assoc_sub_state base;
    _Alloc __alloc_;

    virtual void __on_zero_shared() noexcept;

public:

    explicit __assoc_sub_state_alloc(const _Alloc &__a)
            : __alloc_(__a) {}
};

template<class _Alloc>
void
__assoc_sub_state_alloc<_Alloc>::__on_zero_shared() noexcept {
    typedef typename std::__allocator_traits_rebind<_Alloc, __assoc_sub_state_alloc>::type _Al;
    typedef std::allocator_traits<_Al> _ATraits;
    typedef std::pointer_traits<typename _ATraits::pointer> _PTraits;
    _Al __a(__alloc_);
    this->~__assoc_sub_state_alloc();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

template<class _Rp, class _Fp>
class __deferred_assoc_state
        : public __assoc_state<_Rp> {
    typedef __assoc_state<_Rp> base;

    _Fp __func_;

public:
    explicit __deferred_assoc_state(_Fp &&__f);

    virtual void __execute();
};

template<class _Rp, class _Fp>
inline
__deferred_assoc_state<_Rp, _Fp>::__deferred_assoc_state(_Fp &&__f)
        : __func_(std::forward<_Fp>(__f)) {
    this->__set_deferred();
}

template<class _Rp, class _Fp>
void
__deferred_assoc_state<_Rp, _Fp>::__execute() {
    try {
        this->set_value(__func_());
    }
    catch (...) {
        this->set_exception(std::current_exception());
    }
}

template<class _Fp>
class __deferred_assoc_state<void, _Fp>
        : public __assoc_sub_state {
    typedef __assoc_sub_state base;

    _Fp __func_;

public:
    explicit __deferred_assoc_state(_Fp &&__f);

    virtual void __execute();
};

template<class _Fp>
inline
__deferred_assoc_state<void, _Fp>::__deferred_assoc_state(_Fp &&__f)
        : __func_(std::forward<_Fp>(__f)) {
    this->__set_deferred();
}

template<class _Fp>
void
__deferred_assoc_state<void, _Fp>::__execute() {
    try {
        __func_();
        this->set_value();
    } catch (...) {
        this->set_exception(std::current_exception());
    }
}

template<class _Rp, class _Fp>
class __async_assoc_state
        : public __assoc_state<_Rp> {
    typedef __assoc_state<_Rp> base;

    _Fp __func_;

    virtual void __on_zero_shared() noexcept;

public:
    explicit __async_assoc_state(_Fp &&__f);

    virtual void __execute();
};

template<class _Rp, class _Fp>
inline
__async_assoc_state<_Rp, _Fp>::__async_assoc_state(_Fp &&__f)
        : __func_(std::forward<_Fp>(__f)) {
}

template<class _Rp, class _Fp>
void
__async_assoc_state<_Rp, _Fp>::__execute() {
    try {
        this->set_value(__func_());
    } catch (...) {
        this->set_exception(std::current_exception());
    }
}

template<class _Rp, class _Fp>
void
__async_assoc_state<_Rp, _Fp>::__on_zero_shared() noexcept {
    this->wait();
    base::__on_zero_shared();
}

template<class _Fp>
class __async_assoc_state<void, _Fp>
        : public __assoc_sub_state {
    typedef __assoc_sub_state base;

    _Fp __func_;

    virtual void __on_zero_shared() noexcept;

public:
    explicit __async_assoc_state(_Fp &&__f);

    virtual void __execute();
};

template<class _Fp>
inline
__async_assoc_state<void, _Fp>::__async_assoc_state(_Fp &&__f)
        : __func_(std::forward<_Fp>(__f)) {
}

template<class _Fp>
void
__async_assoc_state<void, _Fp>::__execute() {
    try {
        __func_();
        this->set_value();
    } catch (...) {
        this->set_exception(std::current_exception());
    }
}

template<class _Fp>
void
__async_assoc_state<void, _Fp>::__on_zero_shared() noexcept {
    this->wait();
    base::__on_zero_shared();
}

template<class _Rp> class promise;

template<class _Rp> class shared_future;

// future

template<class _Rp> class future;

template<class _Rp, class _Fp>
future<_Rp>
__make_deferred_assoc_state(_Fp &&__f);

template<class _Rp, class _Fp>
future<_Rp>
__make_async_assoc_state(_Fp &&__f);

template<class _Rp>
class future {
    __assoc_state<_Rp> *__state_;

    explicit future(__assoc_state<_Rp> *__state);

    template<class> friend class promise;

    template<class> friend class shared_future;

    template<class _R1, class _Fp>
    friend future<_R1> __make_deferred_assoc_state(_Fp &&__f);

    template<class _R1, class _Fp>
    friend future<_R1> __make_async_assoc_state(_Fp &&__f);

public:

    future() noexcept : __state_(nullptr) {}

    future(future &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    future(const future &) = delete;

    future &operator=(const future &) = delete;

    future &operator=(future &&__rhs) noexcept {
        future(std::move(__rhs)).swap(*this);
        return *this;
    }

    ~future();

    shared_future<_Rp> share();

    // retrieving the value
    _Rp get();

    void swap(future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
future<_Rp>::future(__assoc_state<_Rp> *__state)
        : __state_(__state) {
    if (__state_->__has_future_attached()) {
        __throw_future_error(future_errc::future_already_retrieved);
    }
    __state_->__add_shared();
    __state_->__set_future_attached();
}

struct __release_shared_count {
    void operator()(std::__shared_count *p) { p->__release_shared(); }
};

template<class _Rp>
future<_Rp>::~future() {
    if (__state_) {
        __state_->__release_shared();
    }
}

template<class _Rp>
_Rp
future<_Rp>::get() {
    std::unique_ptr<std::__shared_count, __release_shared_count> __(__state_);
    __assoc_state<_Rp> *__s = __state_;
    __state_ = nullptr;
    return __s->move();
}

template<class _Rp>
class future<_Rp &> {
    __assoc_state<_Rp &> *__state_;

    explicit future(__assoc_state<_Rp &> *__state);

    template<class> friend class promise;

    template<class> friend class shared_future;

    template<class _R1, class _Fp>
    friend future<_R1> __make_deferred_assoc_state(_Fp &&__f);

    template<class _R1, class _Fp>
    friend future<_R1> __make_async_assoc_state(_Fp &&__f);

public:

    future() noexcept : __state_(nullptr) {}

    future(future &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    future(const future &) = delete;

    future &operator=(const future &) = delete;

    future &operator=(future &&__rhs) noexcept {
        future(std::move(__rhs)).swap(*this);
        return *this;
    }

    ~future();

    shared_future<_Rp &> share();

    // retrieving the value
    _Rp &get();

    void swap(future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
future<_Rp &>::future(__assoc_state<_Rp &> *__state)
        : __state_(__state) {
    if (__state_->__has_future_attached()) {
        __throw_future_error(future_errc::future_already_retrieved);
    }
    __state_->__add_shared();
    __state_->__set_future_attached();
}

template<class _Rp>
future<_Rp &>::~future() {
    if (__state_) {
        __state_->__release_shared();
    }
}

template<class _Rp>
_Rp &
future<_Rp &>::get() {
    std::unique_ptr<std::__shared_count, __release_shared_count> __(__state_);
    __assoc_state<_Rp &> *__s = __state_;
    __state_ = nullptr;
    return __s->copy();
}

template<>
class future<void> {
    __assoc_sub_state *__state_;

    explicit future(__assoc_sub_state *__state);

    template<class> friend class promise;

    template<class> friend class shared_future;

    template<class _R1, class _Fp>
    friend future<_R1> __make_deferred_assoc_state(_Fp &&__f);

    template<class _R1, class _Fp>
    friend future<_R1> __make_async_assoc_state(_Fp &&__f);

public:

    future() noexcept : __state_(nullptr) {}

    future(future &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    future(const future &) = delete;

    future &operator=(const future &) = delete;

    future &operator=(future &&__rhs) noexcept {
        future(std::move(__rhs)).swap(*this);
        return *this;
    }

    ~future();

    shared_future<void> share();

    // retrieving the value
    void get();

    void swap(future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
inline
void
swap(future<_Rp> &__x, future<_Rp> &__y) noexcept {
    __x.swap(__y);
}

// promise<R>

template<class _Callable> class packaged_task;

template<class _Rp>
class promise {
    __assoc_state<_Rp> *__state_;

    explicit promise(std::nullptr_t) noexcept : __state_(nullptr) {}

    template<class> friend class packaged_task;

public:
    promise();

    template<class _Alloc>
    promise(std::allocator_arg_t, const _Alloc &__a);

    promise(promise &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    promise(const promise &__rhs) = delete;

    ~promise();

    // assignment
    promise &operator=(promise &&__rhs) noexcept {
        promise(std::move(__rhs)).swap(*this);
        return *this;
    }

    promise &operator=(const promise &__rhs) = delete;

    void swap(promise &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // retrieving the result
    future<_Rp> get_future();

    // setting the result
    void set_value(const _Rp &__r);

    void set_value(_Rp &&__r);

    void set_exception(std::exception_ptr __p);

    // setting the result with deferred notification
    void set_value_at_thread_exit(const _Rp &__r);

    void set_value_at_thread_exit(_Rp &&__r);

    void set_exception_at_thread_exit(std::exception_ptr __p);
};

template<class _Rp>
promise<_Rp>::promise()
        : __state_(new __assoc_state<_Rp>) {
}

template<class _Rp>
template<class _Alloc>
promise<_Rp>::promise(std::allocator_arg_t, const _Alloc &__a0) {
    typedef __assoc_state_alloc<_Rp, _Alloc> _State;
    typedef typename std::__allocator_traits_rebind<_Alloc, _State>::type _A2;
    typedef std::__allocator_destructor<_A2> _D2;
    _A2 __a(__a0);
    std::unique_ptr<_State, _D2> __hold(__a.allocate(1), _D2(__a, 1));
    ::new(static_cast<void *>(std::addressof(*__hold.get()))) _State(__a0);
    __state_ = std::addressof(*__hold.release());
}

template<class _Rp>
promise<_Rp>::~promise() {
    if (__state_) {
        if (!__state_->__has_value() && __state_->use_count() > 1) {
            __state_->set_exception(make_exception_ptr(
                    future_error(make_error_code(future_errc::broken_promise))
            ));
        }
        __state_->__release_shared();
    }
}

template<class _Rp>
future<_Rp>
promise<_Rp>::get_future() {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    return future<_Rp>(__state_);
}

template<class _Rp>
void
promise<_Rp>::set_value(const _Rp &__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value(__r);
}

template<class _Rp>
void
promise<_Rp>::set_value(_Rp &&__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value(std::move(__r));
}

template<class _Rp>
void
promise<_Rp>::set_exception(std::exception_ptr __p) {
    lassert(__p != nullptr, "promise::set_exception: received nullptr"); // may be a runtime assertion
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_exception(__p);
}

template<class _Rp>
void
promise<_Rp>::set_value_at_thread_exit(const _Rp &__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value_at_thread_exit(__r);
}

template<class _Rp>
void
promise<_Rp>::set_value_at_thread_exit(_Rp &&__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value_at_thread_exit(std::move(__r));
}

template<class _Rp>
void
promise<_Rp>::set_exception_at_thread_exit(std::exception_ptr __p) {
    lassert(__p != nullptr, "promise::set_exception_at_thread_exit: received nullptr");
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_exception_at_thread_exit(__p);
}

// promise<R&>

template<class _Rp>
class promise<_Rp &> {
    __assoc_state<_Rp &> *__state_;

    explicit promise(std::nullptr_t) noexcept : __state_(nullptr) {}

    template<class> friend class packaged_task;

public:
    promise();

    template<class _Allocator>
    promise(std::allocator_arg_t, const _Allocator &__a);

    promise(promise &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    promise(const promise &__rhs) = delete;

    ~promise();

    // assignment
    promise &operator=(promise &&__rhs) noexcept {
        promise(std::move(__rhs)).swap(*this);
        return *this;
    }

    promise &operator=(const promise &__rhs) = delete;

    void swap(promise &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // retrieving the result
    future<_Rp &> get_future();

    // setting the result
    void set_value(_Rp &__r);

    void set_exception(std::exception_ptr __p);

    // setting the result with deferred notification
    void set_value_at_thread_exit(_Rp &);

    void set_exception_at_thread_exit(std::exception_ptr __p);
};

template<class _Rp>
promise<_Rp &>::promise()
        : __state_(new __assoc_state<_Rp &>) {
}

template<class _Rp>
template<class _Alloc>
promise<_Rp &>::promise(std::allocator_arg_t, const _Alloc &__a0) {
    typedef __assoc_state_alloc<_Rp &, _Alloc> _State;
    typedef typename std::__allocator_traits_rebind<_Alloc, _State>::type _A2;
    typedef std::__allocator_destructor<_A2> _D2;
    _A2 __a(__a0);
    std::unique_ptr<_State, _D2> __hold(__a.allocate(1), _D2(__a, 1));
    ::new(static_cast<void *>(std::addressof(*__hold.get()))) _State(__a0);
    __state_ = std::addressof(*__hold.release());
}

template<class _Rp>
promise<_Rp &>::~promise() {
    if (__state_) {
        if (!__state_->__has_value() && __state_->use_count() > 1) {
            __state_->set_exception(make_exception_ptr(
                    future_error(make_error_code(future_errc::broken_promise))
            ));
        }
        __state_->__release_shared();
    }
}

template<class _Rp>
future<_Rp &>
promise<_Rp &>::get_future() {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    return future<_Rp &>(__state_);
}

template<class _Rp>
void
promise<_Rp &>::set_value(_Rp &__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value(__r);
}

template<class _Rp>
void
promise<_Rp &>::set_exception(std::exception_ptr __p) {
    lassert(__p != nullptr, "promise::set_exception: received nullptr");
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_exception(__p);
}

template<class _Rp>
void
promise<_Rp &>::set_value_at_thread_exit(_Rp &__r) {
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_value_at_thread_exit(__r);
}

template<class _Rp>
void
promise<_Rp &>::set_exception_at_thread_exit(std::exception_ptr __p) {
    lassert(__p != nullptr, "promise::set_exception_at_thread_exit: received nullptr");
    if (__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    __state_->set_exception_at_thread_exit(__p);
}

// promise<void>

template<>
class promise<void> {
    __assoc_sub_state *__state_;

    explicit promise(std::nullptr_t) noexcept : __state_(nullptr) {}

    template<class> friend class packaged_task;

public:
    promise();

    template<class _Allocator>
    promise(std::allocator_arg_t, const _Allocator &__a);

    promise(promise &&__rhs) noexcept
            : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    promise(const promise &__rhs) = delete;

    ~promise();

    promise &operator=(promise &&__rhs) noexcept {
        promise(std::move(__rhs)).swap(*this);
        return *this;
    }

    promise &operator=(const promise &__rhs) = delete;

    void swap(promise &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // retrieving the result
    future<void> get_future();

    // setting the result
    void set_value();

    void set_exception(std::exception_ptr __p);

    // setting the result with deferred notification
    void set_value_at_thread_exit();

    void set_exception_at_thread_exit(std::exception_ptr __p);
};

template<class _Alloc>
promise<void>::promise(std::allocator_arg_t, const _Alloc &__a0) {
    typedef __assoc_sub_state_alloc<_Alloc> _State;
    typedef typename std::__allocator_traits_rebind<_Alloc, _State>::type _A2;
    typedef std::__allocator_destructor<_A2> _D2;
    _A2 __a(__a0);
    std::unique_ptr<_State, _D2> __hold(__a.allocate(1), _D2(__a, 1));
    ::new(static_cast<void *>(std::addressof(*__hold.get()))) _State(__a0);
    __state_ = std::addressof(*__hold.release());
}

template<class _Rp>
inline
void
swap(promise<_Rp> &__x, promise<_Rp> &__y) noexcept {
    __x.swap(__y);
}

template<class _Rp, class _Alloc>
struct uses_allocator<promise<_Rp>, _Alloc> : public std::true_type {
};

// packaged_task

template<class _Fp> class __packaged_task_base;

template<class _Rp, class ..._ArgTypes>
class __packaged_task_base<_Rp(_ArgTypes...)> {
    __packaged_task_base(const __packaged_task_base &);

    __packaged_task_base &operator=(const __packaged_task_base &);

public:

    __packaged_task_base() {}

    virtual ~__packaged_task_base() {}

    virtual void __move_to(__packaged_task_base *) noexcept = 0;

    virtual void destroy() = 0;

    virtual void destroy_deallocate() = 0;

    virtual _Rp operator()(_ArgTypes &&...) = 0;
};

template<class _FD, class _Alloc, class _FB> class __packaged_task_func;

template<class _Fp, class _Alloc, class _Rp, class ..._ArgTypes>
class __packaged_task_func<_Fp, _Alloc, _Rp(_ArgTypes...)>
        : public __packaged_task_base<_Rp(_ArgTypes...)> {
    std::__compressed_pair<_Fp, _Alloc> __f_;
public:

    explicit __packaged_task_func(const _Fp &__f) : __f_(__f) {}

    explicit __packaged_task_func(_Fp &&__f) : __f_(std::move(__f)) {}

    __packaged_task_func(const _Fp &__f, const _Alloc &__a)
            : __f_(__f, __a) {}

    __packaged_task_func(_Fp &&__f, const _Alloc &__a)
            : __f_(std::move(__f), __a) {}

    virtual void __move_to(__packaged_task_base<_Rp(_ArgTypes...)> *) noexcept;

    virtual void destroy();

    virtual void destroy_deallocate();

    virtual _Rp operator()(_ArgTypes &&... __args);
};

template<class _Fp, class _Alloc, class _Rp, class ..._ArgTypes>
void
__packaged_task_func<_Fp, _Alloc, _Rp(_ArgTypes...)>::__move_to(
        __packaged_task_base<_Rp(_ArgTypes...)> *__p) noexcept {
    ::new(__p) __packaged_task_func(std::move(__f_.first()), std::move(__f_.second()));
}

template<class _Fp, class _Alloc, class _Rp, class ..._ArgTypes>
void
__packaged_task_func<_Fp, _Alloc, _Rp(_ArgTypes...)>::destroy() {
    __f_.~__compressed_pair<_Fp, _Alloc>();
}

template<class _Fp, class _Alloc, class _Rp, class ..._ArgTypes>
void
__packaged_task_func<_Fp, _Alloc, _Rp(_ArgTypes...)>::destroy_deallocate() {
    typedef typename std::__allocator_traits_rebind<_Alloc, __packaged_task_func>::type _Ap;
    typedef std::allocator_traits<_Ap> _ATraits;
    typedef std::pointer_traits<typename _ATraits::pointer> _PTraits;
    _Ap __a(__f_.second());
    __f_.~__compressed_pair<_Fp, _Alloc>();
    __a.deallocate(_PTraits::pointer_to(*this), 1);
}

template<class _Fp, class _Alloc, class _Rp, class ..._ArgTypes>
_Rp
__packaged_task_func<_Fp, _Alloc, _Rp(_ArgTypes...)>::operator()(_ArgTypes &&... __arg) {
    return std::__invoke(__f_.first(), std::forward<_ArgTypes>(__arg)...);
}

template<class _Callable> class __packaged_task_function;

template<class _Rp, class ..._ArgTypes>
class __packaged_task_function<_Rp(_ArgTypes...)> {
    typedef __packaged_task_base<_Rp(_ArgTypes...)> __base;
    typename std::aligned_storage<3 * sizeof(void *)>::type __buf_;
    __base *__f_;

public:
    typedef _Rp result_type;

    // construct/copy/destroy:

    __packaged_task_function() noexcept : __f_(nullptr) {}

    template<class _Fp>
    __packaged_task_function(_Fp &&__f);

    template<class _Fp, class _Alloc>
    __packaged_task_function(std::allocator_arg_t, const _Alloc &__a, _Fp &&__f);

    __packaged_task_function(__packaged_task_function &&) noexcept;

    __packaged_task_function &operator=(__packaged_task_function &&) noexcept;

    __packaged_task_function(const __packaged_task_function &) = delete;

    __packaged_task_function &operator=(const __packaged_task_function &) = delete;

    ~__packaged_task_function();

    void swap(__packaged_task_function &) noexcept;

    _Rp operator()(_ArgTypes...) const;
};

template<class _Rp, class ..._ArgTypes>
__packaged_task_function<_Rp(_ArgTypes...)>::__packaged_task_function(__packaged_task_function &&__f) noexcept {
    if (__f.__f_ == nullptr) {
        __f_ = nullptr;
    } else if (__f.__f_ == (__base *) &__f.__buf_) {
        __f_ = (__base *) &__buf_;
        __f.__f_->__move_to(__f_);
    } else {
        __f_ = __f.__f_;
        __f.__f_ = nullptr;
    }
}

template<class _Rp, class ..._ArgTypes>
template<class _Fp>
__packaged_task_function<_Rp(_ArgTypes...)>::__packaged_task_function(_Fp &&__f)
        : __f_(nullptr) {
    typedef typename std::remove_reference<typename std::decay<_Fp>::type>::type _FR;
    typedef __packaged_task_func<_FR, std::allocator<_FR>, _Rp(_ArgTypes...)> _FF;
    if (sizeof(_FF) <= sizeof(__buf_)) {
        __f_ = (__base *) &__buf_;
        ::new(__f_) _FF(std::forward<_Fp>(__f));
    } else {
        typedef std::allocator<_FF> _Ap;
        _Ap __a;
        typedef std::__allocator_destructor<_Ap> _Dp;
        std::unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
        ::new(__hold.get()) _FF(std::forward<_Fp>(__f), allocator<_FR>(__a));
        __f_ = __hold.release();
    }
}

template<class _Rp, class ..._ArgTypes>
template<class _Fp, class _Alloc>
__packaged_task_function<_Rp(_ArgTypes...)>::__packaged_task_function(std::allocator_arg_t, const _Alloc &__a0, _Fp &&__f)
        : __f_(nullptr) {
    typedef typename std::remove_reference<typename std::decay<_Fp>::type>::type _FR;
    typedef __packaged_task_func<_FR, _Alloc, _Rp(_ArgTypes...)> _FF;
    if (sizeof(_FF) <= sizeof(__buf_)) {
        __f_ = (__base *) &__buf_;
        ::new(__f_) _FF(std::forward<_Fp>(__f));
    } else {
        typedef typename std::__allocator_traits_rebind<_Alloc, _FF>::type _Ap;
        _Ap __a(__a0);
        typedef std::__allocator_destructor<_Ap> _Dp;
        std::unique_ptr<__base, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
        ::new(static_cast<void *>(std::addressof(*__hold.get())))
                _FF(std::forward<_Fp>(__f), _Alloc(__a));
        __f_ = std::addressof(*__hold.release());
    }
}

template<class _Rp, class ..._ArgTypes>
__packaged_task_function<_Rp(_ArgTypes...)> &
__packaged_task_function<_Rp(_ArgTypes...)>::operator=(__packaged_task_function &&__f) noexcept {
    if (__f_ == (__base *) &__buf_) {
        __f_->destroy();
    } else if (__f_) {
        __f_->destroy_deallocate();
    }
    __f_ = nullptr;
    if (__f.__f_ == nullptr) {
        __f_ = nullptr;
    } else if (__f.__f_ == (__base *) &__f.__buf_) {
        __f_ = (__base *) &__buf_;
        __f.__f_->__move_to(__f_);
    } else {
        __f_ = __f.__f_;
        __f.__f_ = nullptr;
    }
    return *this;
}

template<class _Rp, class ..._ArgTypes>
__packaged_task_function<_Rp(_ArgTypes...)>::~__packaged_task_function() {
    if (__f_ == (__base *) &__buf_) {
        __f_->destroy();
    } else if (__f_) {
        __f_->destroy_deallocate();
    }
}

template<class _Rp, class ..._ArgTypes>
void
__packaged_task_function<_Rp(_ArgTypes...)>::swap(__packaged_task_function &__f) noexcept {
    if (__f_ == (__base *) &__buf_ && __f.__f_ == (__base *) &__f.__buf_) {
        typename std::aligned_storage<sizeof(__buf_)>::type __tempbuf;
        __base *__t = (__base *) &__tempbuf;
        __f_->__move_to(__t);
        __f_->destroy();
        __f_ = nullptr;
        __f.__f_->__move_to((__base *) &__buf_);
        __f.__f_->destroy();
        __f.__f_ = nullptr;
        __f_ = (__base *) &__buf_;
        __t->__move_to((__base *) &__f.__buf_);
        __t->destroy();
        __f.__f_ = (__base *) &__f.__buf_;
    } else if (__f_ == (__base *) &__buf_) {
        __f_->__move_to((__base *) &__f.__buf_);
        __f_->destroy();
        __f_ = __f.__f_;
        __f.__f_ = (__base *) &__f.__buf_;
    } else if (__f.__f_ == (__base *) &__f.__buf_) {
        __f.__f_->__move_to((__base *) &__buf_);
        __f.__f_->destroy();
        __f.__f_ = __f_;
        __f_ = (__base *) &__buf_;
    } else {
        std::swap(__f_, __f.__f_);
    }
}

template<class _Rp, class ..._ArgTypes>
inline
_Rp
__packaged_task_function<_Rp(_ArgTypes...)>::operator()(_ArgTypes... __arg) const {
    return (*__f_)(std::forward<_ArgTypes>(__arg)...);
}

template<class _Rp, class ..._ArgTypes>
class packaged_task<_Rp(_ArgTypes...)> {
public:
    typedef _Rp result_type; // extension

private:
    __packaged_task_function<result_type(_ArgTypes...)> __f_;
    promise<result_type> __p_;

public:
    // construction and destruction

    packaged_task() noexcept : __p_(nullptr) {}

    template<class _Fp,
            class = typename std::enable_if
                    <
                            !std::is_same<
                                    typename std::decay<_Fp>::type,
                                    packaged_task
                            >::value
                    >::type
    >

    explicit packaged_task(_Fp &&__f) : __f_(std::forward<_Fp>(__f)) {}

    template<class _Fp, class _Allocator,
            class = typename std::enable_if
                    <
                            !std::is_same<
                                    typename std::decay<_Fp>::type,
                                    packaged_task
                            >::value
                    >::type
    >

    packaged_task(std::allocator_arg_t, const _Allocator &__a, _Fp &&__f)
            : __f_(std::allocator_arg, __a, std::forward<_Fp>(__f)),
              __p_(std::allocator_arg, __a) {}
    // ~packaged_task() = default;

    // no copy
    packaged_task(const packaged_task &) = delete;

    packaged_task &operator=(const packaged_task &) = delete;

    // move support

    packaged_task(packaged_task &&__other) noexcept
            : __f_(std::move(__other.__f_)), __p_(std::move(__other.__p_)) {}

    packaged_task &operator=(packaged_task &&__other) noexcept {
        __f_ = std::move(__other.__f_);
        __p_ = std::move(__other.__p_);
        return *this;
    }

    void swap(packaged_task &__other) noexcept {
        __f_.swap(__other.__f_);
        __p_.swap(__other.__p_);
    }

    bool valid() const noexcept { return __p_.__state_ != nullptr; }

    // result retrieval

    future<result_type> get_future() { return __p_.get_future(); }

    // execution
    void operator()(_ArgTypes... __args);

    void make_ready_at_thread_exit(_ArgTypes... __args);

    void reset();
};

template<class _Rp, class ..._ArgTypes>
void
packaged_task<_Rp(_ArgTypes...)>::operator()(_ArgTypes... __args) {
    if (__p_.__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    if (__p_.__state_->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    try {
        __p_.set_value(__f_(std::forward<_ArgTypes>(__args)...));
    } catch (...) {
        __p_.set_exception(std::current_exception());
    }
}

template<class _Rp, class ..._ArgTypes>
void
packaged_task<_Rp(_ArgTypes...)>::make_ready_at_thread_exit(_ArgTypes... __args) {
    if (__p_.__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    if (__p_.__state_->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    try {
        __p_.set_value_at_thread_exit(__f_(std::forward<_ArgTypes>(__args)...));
    } catch (...) {
        __p_.set_exception_at_thread_exit(std::current_exception());
    }
}

template<class _Rp, class ..._ArgTypes>
void
packaged_task<_Rp(_ArgTypes...)>::reset() {
    if (!valid()) {
        __throw_future_error(future_errc::no_state);
    }
    __p_ = promise<result_type>();
}

template<class ..._ArgTypes>
class packaged_task<void(_ArgTypes...)> {
public:
    typedef void result_type; // extension

private:
    __packaged_task_function<result_type(_ArgTypes...)> __f_;
    promise<result_type> __p_;

public:
    // construction and destruction

    packaged_task() noexcept : __p_(nullptr) {}

    template<class _Fp,
            class = typename std::enable_if
                    <
                            !std::is_same<
                                    typename std::decay<_Fp>::type,
                                    packaged_task
                            >::value
                    >::type
    >

    explicit packaged_task(_Fp &&__f) : __f_(std::forward<_Fp>(__f)) {}

    template<class _Fp, class _Allocator,
            class = typename std::enable_if
                    <
                            !std::is_same<
                                    typename std::decay<_Fp>::type,
                                    packaged_task
                            >::value
                    >::type
    >

    packaged_task(std::allocator_arg_t, const _Allocator &__a, _Fp &&__f)
            : __f_(std::allocator_arg, __a, std::forward<_Fp>(__f)),
              __p_(std::allocator_arg, __a) {}
    // ~packaged_task() = default;

    // no copy
    packaged_task(const packaged_task &) = delete;

    packaged_task &operator=(const packaged_task &) = delete;

    // move support

    packaged_task(packaged_task &&__other) noexcept
            : __f_(std::move(__other.__f_)), __p_(std::move(__other.__p_)) {}

    packaged_task &operator=(packaged_task &&__other) noexcept {
        __f_ = std::move(__other.__f_);
        __p_ = std::move(__other.__p_);
        return *this;
    }

    void swap(packaged_task &__other) noexcept {
        __f_.swap(__other.__f_);
        __p_.swap(__other.__p_);
    }

    bool valid() const noexcept { return __p_.__state_ != nullptr; }

    // result retrieval

    future<result_type> get_future() { return __p_.get_future(); }

    // execution
    void operator()(_ArgTypes... __args);

    void make_ready_at_thread_exit(_ArgTypes... __args);

    void reset();
};

template<class ..._ArgTypes>
void
packaged_task<void(_ArgTypes...)>::operator()(_ArgTypes... __args) {
    if (__p_.__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    if (__p_.__state_->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    try {
        __f_(std::forward<_ArgTypes>(__args)...);
        __p_.set_value();
    } catch (...) {
        __p_.set_exception(std::current_exception());
    }
}

template<class ..._ArgTypes>
void
packaged_task<void(_ArgTypes...)>::make_ready_at_thread_exit(_ArgTypes... __args) {
    if (__p_.__state_ == nullptr) {
        __throw_future_error(future_errc::no_state);
    }
    if (__p_.__state_->__has_value()) {
        __throw_future_error(future_errc::promise_already_satisfied);
    }
    try {
        __f_(std::forward<_ArgTypes>(__args)...);
        __p_.set_value_at_thread_exit();
    } catch (...) {
        __p_.set_exception_at_thread_exit(std::current_exception());
    }
}

template<class ..._ArgTypes>
void
packaged_task<void(_ArgTypes...)>::reset() {
    if (!valid()) {
        __throw_future_error(future_errc::no_state);
    }
    __p_ = promise<result_type>();
}

template<class _Callable>
inline
void
swap(packaged_task<_Callable> &__x, packaged_task<_Callable> &__y) noexcept {
    __x.swap(__y);
}

template<class _Callable, class _Alloc>
struct uses_allocator<packaged_task<_Callable>, _Alloc>
        : public std::true_type {
};

template<class _Rp, class _Fp>
future<_Rp>
__make_deferred_assoc_state(_Fp &&__f) {
    std::unique_ptr<__deferred_assoc_state<_Rp, _Fp>, __release_shared_count>
            __h(new __deferred_assoc_state<_Rp, _Fp>(std::forward<_Fp>(__f)));
    return future<_Rp>(__h.get());
}

template<class _Rp, class _Fp>
future<_Rp>
__make_async_assoc_state(_Fp &&__f) {
    std::unique_ptr<__async_assoc_state<_Rp, _Fp>, __release_shared_count>
            __h(new __async_assoc_state<_Rp, _Fp>(std::forward<_Fp>(__f)));
    std::thread(&__async_assoc_state<_Rp, _Fp>::__execute, __h.get()).detach();
    return future<_Rp>(__h.get());
}

template<class _Fp, class... _Args>
class __async_func {
    std::tuple<_Fp, _Args...> __f_;

public:
    typedef typename std::__invoke_of<_Fp, _Args...>::type _Rp;

    explicit __async_func(_Fp &&__f, _Args &&... __args)
            : __f_(std::move(__f), std::move(__args)...) {}

    __async_func(__async_func &&__f) : __f_(std::move(__f.__f_)) {}

    _Rp operator()() {
        typedef typename std::__make_tuple_indices<1 + sizeof...(_Args), 1>::type _Index;
        return __execute(_Index());
    }

private:
    template<size_t ..._Indices>
    _Rp
    __execute(std::__tuple_indices<_Indices...>) {
        return std::__invoke(std::move(std::get<0>(__f_)), std::move(std::get<_Indices>(__f_))...);
    }
};

inline bool __does_policy_contain(launch __policy, launch __value) { return (int(__policy) & int(__value)) != 0; }

template<class _Fp, class... _Args>
future<typename std::__invoke_of<typename std::decay<_Fp>::type, typename std::decay<_Args>::type...>::type>
async(launch __policy, _Fp &&__f, _Args &&... __args) {
    typedef __async_func<typename std::decay<_Fp>::type, typename std::decay<_Args>::type...> _BF;
    typedef typename _BF::_Rp _Rp;

    try {
        if (__does_policy_contain(__policy, launch::async)) {
            return std::__make_async_assoc_state<_Rp>(_BF(std::__decay_copy(std::forward<_Fp>(__f)),
                                                          std::__decay_copy(std::forward<_Args>(__args))...));
        }
    } catch (...) { if (__policy == launch::async) { throw; }}

    if (__does_policy_contain(__policy, launch::deferred)) {
        return std::__make_deferred_assoc_state<_Rp>(_BF(std::__decay_copy(std::forward<_Fp>(__f)),
                                                         std::__decay_copy(std::forward<_Args>(__args))...));
    }
    return future<_Rp>{};
}

template<class _Fp, class... _Args>
inline
future<typename std::__invoke_of<typename std::decay<_Fp>::type, typename std::decay<_Args>::type...>::type>
async(_Fp &&__f, _Args &&... __args) {
    return std::async(launch::any, std::forward<_Fp>(__f),
                      std::forward<_Args>(__args)...);
}

// shared_future

template<class _Rp>
class shared_future {
    __assoc_state<_Rp> *__state_;

public:

    shared_future() noexcept : __state_(nullptr) {}

    shared_future(const shared_future &__rhs) : __state_(__rhs.__state_) { if (__state_) { __state_->__add_shared(); }}

    shared_future(future<_Rp> &&__f) noexcept : __state_(__f.__state_) { __f.__state_ = nullptr; }

    shared_future(shared_future &&__rhs) noexcept : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    ~shared_future();

    shared_future &operator=(const shared_future &__rhs);

    shared_future &operator=(shared_future &&__rhs) noexcept {
        shared_future(std::move(__rhs)).swap(*this);
        return *this;
    }

    // retrieving the value

    const _Rp &get() const { return __state_->copy(); }

    void swap(shared_future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
shared_future<_Rp>::~shared_future() {
    if (__state_) {
        __state_->__release_shared();
    }
}

template<class _Rp>
shared_future<_Rp> &
shared_future<_Rp>::operator=(const shared_future &__rhs) {
    if (__rhs.__state_) {
        __rhs.__state_->__add_shared();
    }
    if (__state_) {
        __state_->__release_shared();
    }
    __state_ = __rhs.__state_;
    return *this;
}

template<class _Rp>
class shared_future<_Rp &> {
    __assoc_state<_Rp &> *__state_;

public:

    shared_future() noexcept : __state_(nullptr) {}

    shared_future(const shared_future &__rhs) : __state_(__rhs.__state_) { if (__state_) { __state_->__add_shared(); }}

    shared_future(future<_Rp &> &&__f) noexcept : __state_(__f.__state_) { __f.__state_ = nullptr; }

    shared_future(shared_future &&__rhs) noexcept : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    ~shared_future();

    shared_future &operator=(const shared_future &__rhs);

    shared_future &operator=(shared_future &&__rhs) noexcept {
        shared_future(std::move(__rhs)).swap(*this);
        return *this;
    }

    // retrieving the value

    _Rp &get() const { return __state_->copy(); }

    void swap(shared_future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
shared_future<_Rp &>::~shared_future() {
    if (__state_) {
        __state_->__release_shared();
    }
}

template<class _Rp>
shared_future<_Rp &> &
shared_future<_Rp &>::operator=(const shared_future &__rhs) {
    if (__rhs.__state_) {
        __rhs.__state_->__add_shared();
    }
    if (__state_) {
        __state_->__release_shared();
    }
    __state_ = __rhs.__state_;
    return *this;
}

template<>
class shared_future<void> {
    __assoc_sub_state *__state_;

public:

    shared_future() noexcept : __state_(nullptr) {}

    shared_future(const shared_future &__rhs) : __state_(__rhs.__state_) { if (__state_) { __state_->__add_shared(); }}

    shared_future(future<void> &&__f) noexcept : __state_(__f.__state_) { __f.__state_ = nullptr; }

    shared_future(shared_future &&__rhs) noexcept : __state_(__rhs.__state_) { __rhs.__state_ = nullptr; }

    ~shared_future();

    shared_future &operator=(const shared_future &__rhs);

    shared_future &operator=(shared_future &&__rhs) noexcept {
        shared_future(std::move(__rhs)).swap(*this);
        return *this;
    }

    // retrieving the value

    void get() const { __state_->copy(); }

    void swap(shared_future &__rhs) noexcept { std::swap(__state_, __rhs.__state_); }

    // functions to check state

    bool valid() const noexcept { return __state_ != nullptr; }

    void wait() const { __state_->wait(); }

    template<class _Rep, class _Period>

    future_status
    wait_for(const std::chrono::duration<_Rep, _Period> &__rel_time) const { return __state_->wait_for(__rel_time); }

    template<class _Clock, class _Duration>

    future_status
    wait_until(const std::chrono::time_point<_Clock, _Duration> &__abs_time) const { return __state_->wait_until(__abs_time); }
};

template<class _Rp>
inline
void
swap(shared_future<_Rp> &__x, shared_future<_Rp> &__y) noexcept {
    __x.swap(__y);
}

template<class _Rp>
inline
shared_future<_Rp>
future<_Rp>::share() {
    return shared_future<_Rp>(std::move(*this));
}

template<class _Rp>
inline
shared_future<_Rp &>
future<_Rp &>::share() {
    return shared_future<_Rp &>(std::move(*this));
}

inline
shared_future<void>
future<void>::share() {
    return shared_future<void>(std::move(*this));
}

#endif //JS_PROMISES_TMP_H

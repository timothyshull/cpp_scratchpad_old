#ifndef JS_PROMISES_TMP2_H
#define JS_PROMISES_TMP2_H

#include <folly/Portability.h>
#include <folly/Try.h>
#include <functional>

#include <folly/futures/Future.h>
#include <folly/futures/Promise-inl.h>

#include <atomic>
#include <thread>

#include <folly/futures/FutureException.h>
#include <folly/futures/detail/Core.h>

namespace folly {

// forward declaration
    template<class T> class Future;

    template<class T>
    class Promise {
    public:
        Promise();

        ~Promise();

        // not copyable
        Promise(Promise const &) = delete;

        Promise &operator=(Promise const &) = delete;

        // movable
        Promise(Promise<T> &&) noexcept;

        Promise &operator=(Promise<T> &&) noexcept;

        /** Return a Future tied to the shared core state. This can be called only
          once, thereafter Future already retrieved exception will be raised. */
        Future<T> getFuture();

        /** Fulfill the Promise with an exception_wrapper */
        void setException(exception_wrapper ew);

        /** Fulfill the Promise with an exception_ptr, e.g.
          try {
            ...
          } catch (...) {
            p.setException(std::current_exception());
          }
          */
        FOLLY_DEPRECATED("use setException(exception_wrapper)")
        void setException(std::exception_ptr const &);

        /** Fulfill the Promise with an exception type E, which can be passed to
          std::make_exception_ptr(). Useful for originating exceptions. If you
          caught an exception the exception_wrapper form is more appropriate.
          */
        template<class E>
        typename std::enable_if<std::is_base_of<std::exception, E>::value>::type
        setException(E const &);

        /// Set an interrupt handler to handle interrupts. See the documentation for
        /// Future::raise(). Your handler can do whatever it wants, but if you
        /// bother to set one then you probably will want to fulfill the promise with
        /// an exception (or special value) indicating how the interrupt was
        /// handled.
        void setInterruptHandler(std::function<void(exception_wrapper const &)>);

        /// Sugar to fulfill this Promise<Unit>
        template<class B = T>
        typename std::enable_if<std::is_same<Unit, B>::value, void>::type
        setValue() {
            setTry(Try<T>(T()));
        }

        /** Set the value (use perfect forwarding for both move and copy) */
        template<class M>
        void setValue(M &&value);

        void setTry(Try<T> &&t);

        /** Fulfill this Promise with the result of a function that takes no
          arguments and returns something implicitly convertible to T.
          Captures exceptions. e.g.

          p.setWith([] { do something that may throw; return a T; });
        */
        template<class F>
        void setWith(F &&func);

        bool isFulfilled();

    private:
        typedef typename Future<T>::corePtr corePtr;

        template<class> friend class Future;

        // Whether the Future has been retrieved (a one-time operation).
        bool retrieved_;

        // shared core state object
        corePtr core_;

        void throwIfFulfilled();

        void throwIfRetrieved();

        void detach();
    };

}

namespace folly {

    template<class T>
    Promise<T>::Promise() : retrieved_(false), core_(new detail::Core<T>()) {}

    template<class T>
    Promise<T>::Promise(Promise<T> &&other) noexcept
            : retrieved_(other.retrieved_), core_(other.core_) {
        other.core_ = nullptr;
        other.retrieved_ = false;
    }

    template<class T>
    Promise<T> &Promise<T>::operator=(Promise<T> &&other) noexcept {
        std::swap(core_, other.core_);
        std::swap(retrieved_, other.retrieved_);
        return *this;
    }

    template<class T>
    void Promise<T>::throwIfFulfilled() {
        if (UNLIKELY(!core_)) {
            throw NoState();
        }
        if (UNLIKELY(core_->ready())) {
            throw PromiseAlreadySatisfied();
        }
    }

    template<class T>
    void Promise<T>::throwIfRetrieved() {
        if (UNLIKELY(retrieved_)) {
            throw FutureAlreadyRetrieved();
        }
    }

    template<class T>
    Promise<T>::~Promise() {
        detach();
    }

    template<class T>
    void Promise<T>::detach() {
        if (core_) {
            if (!retrieved_) {
                core_->detachFuture();
            }
            core_->detachPromise();
            core_ = nullptr;
        }
    }

    template<class T>
    Future<T> Promise<T>::getFuture() {
        throwIfRetrieved();
        retrieved_ = true;
        return Future<T>(core_);
    }

    template<class T>
    template<class E>
    typename std::enable_if<std::is_base_of<std::exception, E>::value>::type
    Promise<T>::setException(E const &e) {
        setException(make_exception_wrapper<E>(e));
    }

    template<class T>
    void Promise<T>::setException(std::exception_ptr const &ep) {
        try {
            std::rethrow_exception(ep);
        } catch (const std::exception &e) {
            setException(exception_wrapper(std::current_exception(), e));
        } catch (...) {
            setException(exception_wrapper(std::current_exception()));
        }
    }

    template<class T>
    void Promise<T>::setException(exception_wrapper ew) {
        throwIfFulfilled();
        core_->setResult(Try<T>(std::move(ew)));
    }

    template<class T>
    void Promise<T>::setInterruptHandler(
            std::function<void(exception_wrapper const &)> fn) {
        core_->setInterruptHandler(std::move(fn));
    }

    template<class T>
    void Promise<T>::setTry(Try<T> &&t) {
        throwIfFulfilled();
        core_->setResult(std::move(t));
    }

    template<class T>
    template<class M>
    void Promise<T>::setValue(M &&v) {
        static_assert(!std::is_same<T, void>::value,
                      "Use setValue() instead");

        setTry(Try<T>(std::forward<M>(v)));
    }

    template<class T>
    template<class F>
    void Promise<T>::setWith(F &&func) {
        throwIfFulfilled();
        setTry(makeTryWith(std::forward<F>(func)));
    }

    template<class T>
    bool Promise<T>::isFulfilled() {
        if (core_) {
            return core_->hasResult();
        }
        return true;
    }

}

#endif //JS_PROMISES_TMP2_H

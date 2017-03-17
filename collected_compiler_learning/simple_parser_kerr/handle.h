#pragma once

#include <windows.h>

#ifdef _DEBUG
#include <crtdbg.h>
#ifndef ASSERT
#define ASSERT _ASSERTE
#endif
#ifndef VERIFY
#define VERIFY ASSERT
#endif
#else
#ifndef ASSERT
#define ASSERT __noop
#endif
#ifndef VERIFY
#define VERIFY(expression) (expression)
#endif
#endif

namespace KennyKerr {
    template<typename Traits>
    class unique_handle {
        using pointer = typename Traits::pointer;

        pointer m_value;

        void close() noexcept {
            if (*this) {
                Traits::close(m_value);
            }
        }

    public:

        unique_handle(unique_handle const &) = delete;

        unique_handle &operator=(unique_handle const &) = delete;

        explicit unique_handle(pointer value = Traits::invalid()) noexcept :
                m_value(value) {}

        unique_handle(unique_handle &&other) noexcept :
                m_value(other.release()) {}

        unique_handle &operator=(unique_handle &&other) noexcept {
            if (this != &other) {
                reset(other.release());
            }

            return *this;
        }

        ~unique_handle() noexcept {
            close();
        }

        explicit operator bool() const noexcept {
            return m_value != Traits::invalid();
        }

        pointer get() const noexcept {
            return m_value;
        }

        pointer *get_address_of() noexcept {
            ASSERT(!*this);
            return &m_value;
        }

        pointer release() noexcept {
            pointer value = m_value;
            m_value = Traits::invalid();
            return value;
        }

        bool reset(pointer value = Traits::invalid()) noexcept {
            if (m_value != value) {
                close();
                m_value = value;
            }

            return static_cast<bool>(*this);
        }

        void swap(unique_handle<Traits> &other) noexcept {
            pointer p = m_value;
            m_value = other.m_value;
            other.m_value = p;
        }
    };

    template<typename Traits>
    void swap(unique_handle<Traits> &left,
              unique_handle<Traits> &right) noexcept {
        left.swap(right);
    }

    template<typename Traits>
    bool operator==(unique_handle<Traits> const &left,
                    unique_handle<Traits> const &right) noexcept {
        return left.get() == right.get();
    }

    template<typename Traits>
    bool operator!=(unique_handle<Traits> const &left,
                    unique_handle<Traits> const &right) noexcept {
        return left.get() != right.get();
    }

    template<typename Traits>
    bool operator<(unique_handle<Traits> const &left,
                   unique_handle<Traits> const &right) noexcept {
        return left.get() < right.get();
    }

    template<typename Traits>
    bool operator>=(unique_handle<Traits> const &left,
                    unique_handle<Traits> const &right) noexcept {
        return left.get() >= right.get();
    }

    template<typename Traits>
    bool operator>(unique_handle<Traits> const &left,
                   unique_handle<Traits> const &right) noexcept {
        return left.get() > right.get();
    }

    template<typename Traits>
    bool operator<=(unique_handle<Traits> const &left,
                    unique_handle<Traits> const &right) noexcept {
        return left.get() <= right.get();
    }

    struct null_handle_traits {
        using pointer = HANDLE;

        static pointer invalid() noexcept {
            return nullptr;
        }

        static void close(pointer value) noexcept {
            VERIFY(CloseHandle(value));
        }
    };

    struct invalid_handle_traits {
        using pointer = HANDLE;

        static pointer invalid() noexcept {
            return INVALID_HANDLE_VALUE;
        }

        static void close(pointer value) noexcept {
            VERIFY(CloseHandle(value));
        }
    };

    using null_handle = unique_handle<null_handle_traits>;
    using invalid_handle = unique_handle<invalid_handle_traits>;
}

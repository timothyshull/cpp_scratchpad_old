#ifndef DW_ALGOS_ALLOCATOR
#define DW_ALGOS_ALLOCATOR 1

#include <new>
#include <bits/functexcept.h>

#include <limits>

using std::size_t;
using std::ptrdiff_t;

template<typename T>
class base_allocator {
public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    template<typename T1>
    struct rebind {
        typedef base_allocator <T1> other;
    };

    base_allocator() throw() { }

    base_allocator(const base_allocator&) throw() { }

    template<typename T1>
    base_allocator(const base_allocator <T1>&) throw() { }

    ~base_allocator() throw() { }

    pointer address(reference x) const { return &x; }

    const_pointer address(const_reference x) const { return &x; }

    pointer allocate(size_type n, const void* = 0) {
//        if (__builtin_expect(n > this->max_size(), false))
        if (n > this->max_size())
            throw std::bad_alloc();

        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(pointer p, size_type) { ::operator delete(p); }

    size_type max_size() const throw() {
        return size_t(-1) / sizeof(T);
//        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    void construct(pointer p, const_reference val) { ::new(p) T(val); }

    void destroy(pointer p) { p->~T(); }
};

template<typename T>
inline bool operator==(const base_allocator<T>&, const base_allocator<T>&) { return true; }

template<typename T>
inline bool operator!=(const base_allocator<T>&, const base_allocator<T>&) { return false; }


template<typename T>
class allocator;

/// allocator<void> specialization.
template<>
class allocator<void> {
public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = void*;
    using const_pointer = const void*;
    using value_type = void;

    template<typename T1>
    struct rebind {
        typedef allocator<T1> other;
    };
};

template<typename T>
class allocator : public base_allocator<T> {
public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    template<typename T1>
    struct rebind {
        typedef allocator<T1> other;
    };

    allocator() throw() { }

    allocator(const allocator& a) throw() : base_allocator<T>(a) { }

    template<typename T1>
    allocator(const allocator<T1>&) throw() { }

    ~allocator() throw() { }

    // Inherit everything else.
};

template<typename T1, typename T2>
inline bool operator==(const allocator<T1>&, const allocator<T2>&) { return true; }

template<typename T1, typename T2>
inline bool operator!=(const allocator<T1>&, const allocator<T2>&) { return false; }

// To implement Option 3 of DR 431.
template<typename Alloc, bool = std::is_empty<Alloc>::value>
struct Alloc_swap
{ static void _S_do_it(Alloc&, Alloc&) { } };

template<typename Alloc>
struct Alloc_swap<Alloc, false>
{
    static void
    _S_do_it(Alloc& __one, Alloc& __two)
    {
        // Precondition: swappable allocators.
        if (__one != __two)
            swap(__one, __two);
    }
};

#endif // DW_ALGOS_ALLOCATOR

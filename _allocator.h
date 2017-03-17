#ifndef CPP_DSS_ALLOCATOR_H
#define CPP_DSS_ALLOCATOR_H

#include <cstddef>
#include <limits>
#include <new>

namespace cpp_dss {
    template<typename Tp>
    class _allocator {
    public:
        using const_pointer = const Tp*;
        using const_reference = const Tp&;
        using pointer = Tp*;
        using reference = Tp&;
        using difference_type = ptrdiff_t;
        using size_type = size_t;
        using value_type = Tp;

        template<typename _Tp>
        struct rebind {
            using other = _allocator<_Tp>;
        };

        _allocator() throw() { }

        _allocator(const _allocator&) throw() { }

        template<typename _Tp>
        _allocator(const _allocator<_Tp>&) throw() { }

        ~_allocator()() throw() { }

        inline size_type max_size() const {
            return size_type(-1) / sizeof(value_type);
//            return std::numeric_limits<size_type>::max() / sizeof(value_type);
        }

        inline const_pointer address(const_reference _x) const {
            return &_x;
        }

        inline pointer address(reference _x) const {
            return &_x;
        }

        inline pointer allocate(size_type _n, const void* = 0) const {
            if (_n > this->max_size())
                std::__throw_bad_alloc();

            return static_cast<pointer>(::operator new(_n * sizeof(value_type)));
        }

//        inline void deallocate(pointer _p, size_type) const {
        inline void deallocate(pointer _p) const {
            ::operator delete(_p);
        }

        inline void construct(pointer _p, const_reference _val) const {
            ::new(_p) Tp(_val);
        }

        inline void destroy(pointer p) const {
            p->~Tp();
        }
    };

    template<typename Tp>
    inline bool
    operator==(const _allocator<Tp>&, const _allocator<Tp>&) { return true; }

    template<typename Tp>
    inline bool
    operator!=(const _allocator<Tp>&, const _allocator<Tp>&) { return false; }
}

#endif // CPP_DSS_ALLOCATOR_H

#ifndef CPP_DSS_VECTOR1_H
#define CPP_DSS_VECTOR1_H

#include "_allocator.h"

namespace cpp_dss {
    template<typename Tp>
    class _vector {
    public:
        using const_iterator = const Tp*;
        using const_pointer = const Tp*;
        using const_reference = const Tp&;
        using iterator = Tp*;
        using pointer = Tp*;
        using reference = Tp&;
        using difference_type = ptrdiff_t;
        using size_type = size_t;
        using value_type = Tp;

        _vector() : _block{nullptr}, _size{0}, _capacity(0) { }

        ~_vector() {
            _destroy_all_elements();
            _alloc.deallocate(_block);
        }

        bool empty() const {
            return _size == 0;
        }

        size_type size() const {
            return _size;
        }

        size_type capacity() const {
            return _capacity;
        }

//        const_iterator begin() const {
//            return _block;
//        }

        iterator begin() const {
            return _block;
        }

//        const_iterator end() const {
//            return _block + size();
//        }

        iterator end() const {
            return _block + size();
        }

//        const_reference front() const {
//            return *_block;
//        }

        reference front() const {
            return *_block;
        }

//        const_reference back() const {
//            return *(_block + size() - 1);
//        }

        reference back() const {
            return *(_block + size() - 1);
        }

        const_reference operator[](size_type _nx) const {
            return _block[_nx];
        }

        reference operator[](size_type _nx) {
            return _block[_nx];
        }

        void push_back(const_reference _src) {
            if (size() == capacity())
                _reallocate(static_cast<size_type>(1.5 * (capacity() + 2)));

            _alloc.construct(end(), _src);
            _size += 1;
        }

        void clear() {
            _destroy_all_elements();
            _size = 0;
        }

    private:
        void _reallocate(size_type _n) {
            pointer new_block = _alloc.allocate(_n);

            for (size_type i = 0; i != size(); ++i) {
                _alloc.construct(new_block + i, _block[i]);
                _alloc.destroy(_block + i);
            }

            _alloc.deallocate(_block);
            _block = new_block;
            _capacity = _n;
        }

        void _destroy_all_elements() {
            for (size_type i = 0; i != size(); ++i) {
                _alloc.destroy(_block + i);
            }
        }

        pointer _block;
        size_type _size;
        size_type _capacity;
        _allocator<value_type> _alloc;
    };
}

#endif //CPP_DSS_VECTOR1_H

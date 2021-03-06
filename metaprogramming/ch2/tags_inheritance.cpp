#include <cstddef>
#include <new>

template<typename T, T VALUE>
struct static_parameter {
};

template<typename T, T VALUE>
struct static_value : static_parameter<T, VALUE> {
    static const T value = VALUE;

    operator T() const {
        return VALUE;
    }

    static_value(int = 0) {
    }
};


template<size_t SIZE>
struct fixed_size_allocator {
    void *get_block();
};

template<size_t SIZE>
class compound_pool;

template<>
class compound_pool<0> {
protected:
    template<size_t N>
    void *pick(static_value<size_t, N>) {
        return ::operator new(N);
    }
};

template<size_t SIZE>
class compound_pool : compound_pool<SIZE / 2> {
    fixed_size_allocator<SIZE> p_;
protected:
    using compound_pool<SIZE / 2>::pick;

    fixed_size_allocator<SIZE> &pick(static_value<size_t, SIZE>) {
        return p_;
    }

public:
    template<typename object_t>
    object_t *allocate() {
        typedef static_value<size_t, sizeof(object_t)> selector_t;
        return static_cast<object_t *>(get_pointer(this->pick(selector_t())));
    }

private:
    template<size_t N>
    void *get_pointer(fixed_size_allocator<N> &p) {
        return p.get_block();
    }

    void *get_pointer(void *p) {
        return p;
    }
};
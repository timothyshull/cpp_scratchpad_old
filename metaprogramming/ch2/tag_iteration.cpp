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

template<typename T, int N>
void zeroize_helper(T *const data, static_value<int, N>) {
    zeroize_helper(data, static_value<int, N - 1>());
    data[N - 1] = T();
}

template<typename T>
void zeroize_helper(T *const data, static_value<int, 1>) {
    data[0] = T();
}

template<typename T, int N>
void zeroize(T (&data)[N]) {
    zeroize_helper(data, static_value<int, N>());
}

// iterate backwards
template<typename T, int N>
void zeroize_helper(T *const data, static_value<int, N>) {
    data[N - 1] = T();
    zeroize_helper(data, static_value<int, N - 1>());
}

// exponential unrolling
template<int N, int M>
struct index {
};

template<typename T, int N, int M>
void zeroize_helper(T *const data, index<N, M>) {
    zeroize_helper(data, index<N / 2, M>());
    zeroize_helper(data, index<N / 2, M + N / 2>());
}

template<typename T, int M>
void zeroize_helper(T *const data, index<1, M>) {
    data[M] = T();
}

template<typename T, int N>
void zeroize(T (&data)[N]) {
    zeroize_helper(data, index<N, 0>());
}

double test[8];
zeroize(test);
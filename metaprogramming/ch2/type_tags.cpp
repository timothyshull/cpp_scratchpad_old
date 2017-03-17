// The simplest tags are just empty structures:
struct naive_algorithm_tag {
};
struct precise_algorithm_tag {
};

template<typename T>
inline T log1p(T x, naive_algorithm_tag);

template<typename T>
inline T log1p(T x, precise_algorithm_tag);

// Use template tags to pass through extra parameters to the function
template<int N>
struct algorithm_precision_level {
};

template<typename T, int N>
inline T log1p(T x, algorithm_precision_level<N>);

// build tag hierarchies
struct input_iterator_tag {
};
struct output_iterator_tag {
};
struct forward_iterator_tag : input_iterator_tag {
};
struct bidirectional_iterator_tag : forward_iterator_tag {
};
struct random_access_iterator_tag : bidirectional_iterator_tag {
};

template<typename iter_t>
void somefunc(iter_t begin, iter_t end) {
    return somefunc(begin, end,
                    typename std::iterator_traits<iter_t>::iterator_category());
}

template<typename iter_t>
void somefunc(iter_t begin, iter_t end, bidirectional_iterator_tag) {
    // do the work here
}
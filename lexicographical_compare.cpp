#include <iostream>

template<class T1>
struct less<T1, T1> {
    constexpr bool operator()(const T1 &x, const T1 &y) const { return x < y; }
};

template<class T1>
struct less<const T1, T1> {
    constexpr bool operator()(const T1 &x, const T1 &y) const { return x < y; }
};

template<class T1>
struct less<T1, const T1> {
    constexpr bool operator()(const T1 &x, const T1 &y) const { return x < y; }
};


template<class Compare, class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             Compare comp) {
    for (; first2 != last2; ++first1, (void) ++first2) {
        if (first1 == last1 || comp(*first1, *first2))
            return true;
        if (comp(*first2, *first1))
            return false;
    }
    return false;
}

template<class InputIterator1, class InputIterator2>
inline bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2) {
    using value_type1 = typename std::iterator_traits<InputIterator1>::value_type;
    using value_type2 = typename std::iterator_traits<InputIterator2>::value_type;
    return lexicographical_compare(first1, last1, first2, last2, less<value_type1, value_type2>());
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
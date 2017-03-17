#ifndef METAPROGRAMMING_STATIC_ASSERTIONS_H
#define METAPROGRAMMING_STATIC_ASSERTIONS_H

// used to induce a compiler error when a template parameter does
// not meet a specification

template<typename T>
void myfunc() {
    typedef typename T::type ERROR_T_DOES_NOT_CONTAIN_type;
    const int ASSERT_T_MUST_HAVE_STATIC_CONSTANT_value(T::value);
};

#endif //METAPROGRAMMING_STATIC_ASSERTIONS_H

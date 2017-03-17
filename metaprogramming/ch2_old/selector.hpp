#ifndef METAPROGRAMMING_SELECTOR_H
#define METAPROGRAMMING_SELECTOR_H

template<bool PARAMETER>
struct selector {
};

typedef selector<true> true_type;
typedef selector<false> false_type;

#endif //METAPROGRAMMING_SELECTOR_H

#include <cstddef>

// only weak ordering is granted -> 1=sizeof(char) sizeof(short) sizeof(int) sizeof(long)

template<typename T>
class larger_than {
    T body_[2];   // private, not meant to be used
};

using no_type = char;
using yes_type = larger_than<no_type>;

template<size_t N>
struct fixed_size {
    typedef char type[N];
};

// results in -> sizeof(fixed_size<N>::type) == N

int main() {
    fixed_size<3>::type f(); // error: illegal
    int three = sizeof(f());
    fixed_size<3>::type &f(); // ok
    int three = sizeof(f()); // ok, three == 3
}
// can pass function pointers
template<typename T, int (*fptr)(T)>
class X {
};

template<typename T, T val>
class Y {
};

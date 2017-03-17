// passing a function and function pointer have different
// syntax but they are mostly equivalent
// have to be careful about the subtle differences
// when returning a functor
template<double F(int)>
struct A {
};
template<double (*F)(int)>
struct B {
};

double f(int) {
    return 3.14;
}

A<f> t1;   // ok
B<f> t2;   // ok
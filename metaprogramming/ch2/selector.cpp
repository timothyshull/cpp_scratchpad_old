// a template that can be instantiated in two ways
template<bool PARAMETER>
struct selector {
};

using true_type = selector<true>;
using false_type = selector<false>;

// used to replace specific parameter invocation

template<bool B, typename T>
void f(const T &x) {
}

template<typename T, bool B>
void f(const T &x, selector<B>) {
}

int main() {
    double d = 3.14;
    f<true, double>(d); // force B=true and deduce T=double

    double d_o = 3.14;
    f(d_o, selector<true>()); // deduce B=true and T=double
};

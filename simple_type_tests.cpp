#include <iostream>
#include <type_traits>

template<typename I, typename R>
class Functor {
public:
    R operator()(I i) {
        return static_cast<R>(i); // bs
    }
};


int main() {
    Functor<int, double> mf;
    double test_var = mf(10);
    std::cout << "test_var is: " << test_var << std::endl;
    std::cout << typeid(test_var).name() << std::endl;
    bool test_type = std::is_same<decltype(test_var), double>::value;
    std::cout <<  test_type << std::endl;
    std::cout << std::noboolalpha << test_type << " == " << std::boolalpha << test_type << std::endl;
    return 0;
}
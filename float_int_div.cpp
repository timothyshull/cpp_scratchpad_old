#include <iostream>

int main()
{
    int num1 = 1;
    float div1 = 1.0;
    auto res1 = num1 / div1;
    std::cout << std::boolalpha << std::is_same<float, decltype(res1)>::value << "\n";
    std::cout << std::boolalpha << std::is_same<int, decltype(res1)>::value << "\n";

    float num2 = 1.0;
    int div2 = 1;
    auto res2 = num2 / div2;
    std::cout << std::boolalpha << std::is_same<float, decltype(res2)>::value << "\n";
    std::cout << std::boolalpha << std::is_same<int, decltype(res2)>::value << "\n";

    return 0;
}
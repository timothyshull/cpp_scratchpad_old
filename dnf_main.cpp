#include <iostream>
#include <vector>


int main()
{
    std::vector<int> tmp;
    tmp.reserve(10);

    for (int i{0}; i < 10; ++i) {
        tmp[i] = i;
    }

    int id_4{tmp[4]};
    int id_5{tmp[5]};
    std::initializer_list<int> init_list{1, 2, 3, 4, 5};

    std::cout << std::boolalpha << (id_4 == id_5) << "\n";
    std::cout << typeid(id_4).name() << "\n";
    std::cout << typeid(init_list).name() << "\n";
    std::cout << std::boolalpha << std::is_same<decltype(id_4), int>::value << "\n";
    return 0;
}
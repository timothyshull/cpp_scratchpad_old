#include <vector>
#include <iostream>

//void permute(std::vector<int>& v, int i)
//{
//    if (i == v.size() - 1) {
//        std::cout << v[i];
//        return;
//    }
//    for (int j{0}; j < v.size(); ++j) {
//        std::swap(v[i], v[j]);
//        permute(v, i + 1);
//        std::swap(v[i], v[j]);
//    }
//    std::cout << "\n";
//}

void permute(std::vector<int>& v)
{
    for (int i{0}; i < v.size(); ++i) {
        for (auto e : v) { std::cout << e; }
        std::cout << "\n";
        int j;
        for (j = v.size() - 1; j > i; --j) {
            std::swap(v[j], v[j - 1]);
            for (auto e : v) { std::cout << e; }
            std::cout << "\n";
        }
        std::swap(v[j], v[v.size() - 1]);
    }
}

int main() {
    std::vector<int> a{1, 2, 3, 4, 5, 6};
    permute(a);
    return 0;
}
#include <vector>
#include <iostream>

void dnf(std::vector<int>& v, int pivot_idx)
{
    int pivot{v[pivot_idx]};
    std::cout << "pivot is: " << pivot << "\n";
//    int lo{0};
//
//    for (int i{0}; i < v.size(); ++i) {
//        if (v[i] < pivot) {
//            int tmp = v[i];
//            v[i] = v[lo];
//            v[lo] = tmp;
//            ++lo;
//        }
//    }
//
//    int hi{static_cast<int>(v.size() - 1)};
//    for (int i{hi}; i >= 0 && v[i] >= pivot; --i) {
//        if (v[i] > pivot) {
//            int tmp = v[i];
//            v[i] = v[hi];
//            v[hi] = tmp;
//            --hi;
//        }
//    }
    int lo{0};
    int mid{0};
    int hi{static_cast<int>(v.size() - 1)};
    for (int i{0}; i < v.size(); ++i) {
        if (v[mid] < pivot) {
            int tmp = v[mid];
            v[mid] = v[lo];
            v[lo] = tmp;
            ++mid;
            ++lo;
        } else if (v[mid] > pivot) {
            int tmp = v[mid];
            v[mid] = v[hi];
            v[hi] = tmp;
            --hi;
        } else {
            ++mid;
        }
    }
}

int main(int argc, char* argv[])
{
    std::vector<int> v{5, 6, 9, 3, 4, 1, 3, 2, 5, 6, 7, 7, 7, 8, 9, 10};
    dnf(v, 0);
    for (auto i : v) {
        std::cout << i << "\n";
    }
    return 0;
}
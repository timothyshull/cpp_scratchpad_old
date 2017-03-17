#include <vector>
#include <cassert>

//static long findMissing(std::vector<long> list){
//    auto diff = list[1] - list[0] < list[2] - list[1] ? list[1] - list[0] : list[2] - list[1];
//    long missing = 0;
//    for (auto i = 1; i < list.size(); ++i) {
//        if (list[i] - list[i - 1] > diff) { missing = list[i] - diff; }
//    }
////    for (auto it0 = list.begin(), it1 = ++list.begin(); it1 != list.end(); ++it0, (void) ++it0) {
////        if (*it1 - *it0 > diff) { missing = (*it1 - *it0) / 2;}
////    }
//    return missing;
//}

// use binary search
static long findMissing(std::vector<long> list){
    auto diff = list[1] - list[0] < list[2] - list[1] ? list[1] - list[0] : list[2] - list[1];
    auto l = 0;
    int h = list.size() - 1;

    while (true) {
        auto m = (l + h) / 2;
        if (list[m] - list[m - 1] > diff) { return list[m] - diff; }
        if (list[h] - list[l] == (h - l) * diff) { h = m - 1; }
        else { l = m + 1; }
    }
}

int main() {
    assert(7 == findMissing({1, 3, 5, 9, 11}));
    assert(-7 == findMissing({-11, -9, -5, -3, -1}));
    return 0;
}
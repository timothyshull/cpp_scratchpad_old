//
// Created by Tim Shull on 10/29/16.
//

#include<vector>
#include<iostream>
#include<array>

template <typename T>
void pprint_vector(const std::vector<T> &in) {
    if (in.empty()) {
        std::cout << "[]\n";
    } else {
        std::cout << "[\n";
        for (auto e : in) {
            std::cout << "    " << e << "\n";
        }
        std::cout << "];\n";
    }
}

template<typename T, typename S>
void compress(std::vector<T> &target, const std::vector<T> &data, const std::vector<S> &selectors) {
    target.clear();
    target.reserve(std::max(data.size(), selectors.size()));
    auto it1 = data.begin();
    auto it2 = selectors.begin();
    auto end1 = data.end();
    auto end2 = selectors.end();
    for (; it1 != end1 && it2 != end2; ++it1, ++it2) {
        if (static_cast<bool>(*it2)) {
            target.emplace_back(*it1);
        }
    }
};

int main() {
    std::vector<int> list{1, 4, -5, 10, -7, 2, 3, -1};
    auto list_sz = list.size();

    std::vector<int> pos;
    pos.reserve(list_sz);
    for (auto e : list) {
        if (e > 0) {
            pos.emplace_back(e);
        }
    }
    pprint_vector(pos);

    std::vector<int> neg;
    neg.reserve(list_sz);
    for (auto e : list) {
        if (e < 0) {
            neg.emplace_back(e);
        }
    }
    pprint_vector(neg);

    std::vector<int> neg_clip;
    neg_clip.reserve(list_sz);
    for (auto e : list) {
        if (e < 0) {
            neg_clip.emplace_back(e);
        } else {
            neg_clip.emplace_back(0);
        }
    }
    pprint_vector(neg_clip);

    std::vector<int> pos_clip;
    pos_clip.reserve(list_sz);
    for (auto e : list) {
        if (e > 0) {
            pos_clip.emplace_back(e);
        } else {
            pos_clip.emplace_back(0);
        }
    }
    pprint_vector(pos_clip);

    std::array<int, 8> counts {0, 3, 10, 4, 1, 7, 6, 1};

    std::vector<int> more5;
    more5.reserve(counts.size());
    for (auto e : counts) {
        more5.emplace_back(static_cast<int>(e > 5));
    }

    std::vector<std::string> addresses {
            "5412 N CLARK",
            "5148 N CLARK",
            "5800 E 58TH",
            "2122 N CLARK",
            "5645 N RAVENSWOOD",
            "1060 W ADDISON",
            "4801 N BROADWAY",
            "1039 W GRANVILLE"
    };

    std::vector<std::string> a;
    compress(a, addresses, more5);
    pprint_vector(a);
    return 0;
}
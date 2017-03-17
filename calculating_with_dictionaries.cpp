//
// Created by Tim Shull on 10/27/16.
//
#include<map>
#include<string>
#include<iostream>

using Map_type = std::map<std::string, double>;
using Map_iterator_type = std::map<std::string, double>::const_iterator;

struct Comp_min {
    inline bool operator()(const std::pair<std::string, double> &rhs, const std::pair<std::string, double> &lhs) {
        return std::get<1>(rhs) < std::get<1>(lhs);
    }
};

struct Comp_max {
    inline bool operator()(const std::pair<std::string, double> &rhs, const std::pair<std::string, double> &lhs) {
        return std::get<1>(lhs) < std::get<1>(rhs);
    }
};

double min(Map_type &m) {
    auto tmp = std::min_element<Map_iterator_type, Comp_min>(m.cbegin(), m.cend(), Comp_min{});
    return tmp->second;
}

double max(Map_type &m) {
    auto tmp = std::min_element<Map_iterator_type, Comp_max>(m.cbegin(), m.cend(), Comp_max{});
    return tmp->second;
}


int main() {
    Map_type prices{
            {"ACME", 45.23},
            {"AAPL", 612.78},
            {"IBM",  205.55},
            {"HPQ",  37.20},
            {"FB",   10.75}
    };

    auto min_price = min(prices);
    auto max_price = max(prices);
    std::cout << "min price: " << min_price << "\n";
    std::cout << "max price: " << max_price << "\n";

    std::cout << "sorted prices:\n";
    // map sorted by default
    for (auto p : prices) {
        std::cout << "name: " << p.first << ", prices: " << p.second << "\n";
    }

    std::multimap<double, std::string> p_rev;
    for (auto p : prices) {
        p_rev.emplace(std::pair<double, std::string>{p.second, p.first});
    }
    // sorted by default
    for (auto p : p_rev) {
        std::cout << "name: " << p.second << ", prices: " << p.first << "\n";
    }
    return 0;
}

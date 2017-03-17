//
// Created by Tim Shull on 10/29/16.
//

#include<map>
#include<string>
#include<iostream>
#include<set>

void pprint_map(const std::map<std::string, double> &in) {
    for (auto p : in) {
        std::cout << "{" << p.first << " , " << p.second << " }\n";
    }
    std::cout << "\n";
}

int main() {
    std::map<std::string, double> prices{
            {"ACME", 45.23},
            {"AAPL", 612.78},
            {"IBM",  205.55},
            {"HPQ",  37.20},
            {"FB",   10.75}
    };
    std::map<std::string, double> p1;
    for (auto p : prices) {
        if (p.second > 200) {
            p1.emplace(p);
        }
    }
    std::cout << "Stocks priced over $200.00:\n";
    pprint_map(p1);
    std::set<std::string> tech_names{"AAPL", "IBM", "HPQ", "MSFT"};
    std::map<std::string, double> p2;
    auto end = tech_names.end();
    for (auto p : prices) {
        if (tech_names.find(p.first) != end) {
            p2.emplace(p);
        }
    }
    std::cout << "All technology stocks:\n";
    pprint_map(p2);
    return 0;
}
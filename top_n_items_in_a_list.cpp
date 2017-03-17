//
// Created by Tim Shull on 10/28/16.
//

#include<array>
#include<string>
#include<map>
#include<iostream>

// TODO: duplicate the python counter class
template<typename T, size_t sz>
void increment_or_add(const std::array<T, sz> &words, std::map<T, int> &count_map) {
    for (auto w : words) {
        auto search = count_map.find(w);
        if (search != count_map.end()) {
            count_map[w] += 1;
        } else {
            count_map.emplace(std::pair<std::string, int>{w, 1});
        }
    }
}

void reverse_map(const std::map<std::string, int> &in, std::multimap<int, std::string> &out) {
    for (auto p : in) {
        out.emplace(std::pair<int, std::string>{p.second, p.first});
    }
}

void print_top_three(const std::multimap<int, std::string> in) {
    int i{0};
    for (auto it = in.rbegin(), end = in.rend(); it != end; ++it, ++i) {
        if (i == 3) break;
        std::cout << "( " << it->second << " , " << it->first << " ) " << "\n";
    }
}

// Doesn't account for duplicates in top value counts
int main() {
    std::array<std::string, 29> words{
            "look", "into", "my", "eyes", "look", "into", "my", "eyes",
            "the", "eyes", "the", "eyes", "the", "eyes", "not", "around", "the",
            "eyes", "don't", "look", "around", "the", "eyes", "look", "into",
            "my", "eyes", "you're", "under"
    };
    std::map<std::string, int> word_count{};
    increment_or_add(words, word_count);
    std::multimap<int, std::string> wc_inverted{};
    reverse_map(word_count, wc_inverted);
    print_top_three(wc_inverted);
    std::array<std::string, 8> more_words{
            "why", "are", "you", "not", "looking", "in", "my", "eyes"
    };
    increment_or_add(more_words, word_count);
    wc_inverted.clear();
    reverse_map(word_count, wc_inverted);
    print_top_three(wc_inverted);

    return 0;
}
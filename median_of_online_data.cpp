// p. 180
#include <queue>
#include <iostream>

void median_of_online_data(std::istream& is)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;

    int x;
    while (is >> x) {
        if (min_heap.empty()) { min_heap.emplace(x); }
        else if (x >= min_heap.top()) { min_heap.emplace(x); }
        else { max_heap.emplace(x); }
    }

    if (max_heap.size() < min_heap.size() - 1) {
        while (max_heap.size() < min_heap.size() - 1) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
    } else if (min_heap.size() < max_heap.size()) {
        while (min_heap.size() <= max_heap.size()) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
    }

    if (min_heap.size() == max_heap.size()) {
        std::cout << (0.5 * (min_heap.top() + max_heap.top())) << "\n";
    } else { std::cout << min_heap.top() << "\n"; }
}

int main()
{
    median_of_online_data(std::cin);
    return 0;
}
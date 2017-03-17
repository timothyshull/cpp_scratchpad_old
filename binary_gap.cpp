#include <bitset>
#include <iostream>
#include <cmath>

const size_t INT_BITS = sizeof(int) * 8;
using int_repr = std::bitset<INT_BITS>;

// Can skip construction of bitset and just use binary operations
int binary_gap(int_repr repr) {
    int max_gap = 0;
    int current_gap = 0;
    // need to traverse bitset backwards due to endianness
    int index = static_cast<int>(repr.size() - 1);
    // skip all leading 0s
    while (!repr[index]) {
        index -= 1;
    }
    for (; index < INT_BITS; index -= 1) {
        if (!repr[index]) {
            current_gap += 1;
        } else {
            current_gap = 0;
        }
        if (current_gap > max_gap) {
            max_gap = current_gap;
        }
    }
    return max_gap;
}

int solution(int val) {
    int_repr repr = int_repr(static_cast<unsigned long long>(val));
    return binary_gap(repr);
}

int main() {
//    auto binary = get_binary_repr(20);
    std::cout << solution(1041) << "\n";
    return 0;
}
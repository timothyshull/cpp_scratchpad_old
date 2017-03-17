#include <vector>
#include <iostream>

// the problem with this solution is that it does not operate on A
std::vector<int> solution(std::vector<int> &A, int K) {
    std::vector<int> result;
    result.assign(A.size(), 0);
    int i = 0;
    for (auto it = A.begin(); it != A.end(); ++it) {
        int new_index = (i + K) % static_cast<int>(A.size());
        result[new_index] = *it;
        i += 1;
    }
    return result;
}

int main() {
    std::vector<int> input = {3, 8, 9, 7, 6};
    auto result = solution(input, 3);

    for (auto i : result) {
        std::cout << i << "\n";
    }
    return 0;
}


static inline void swap_elems(std::vector<int> &A, int start, int end) {
    int tmp = 0;
    while (start < end) {
        tmp = A[start];
        A[start++] = A[end];
        A[end--] = tmp;
    }
}

std::vector<int> solution_cyclic_rotation(std::vector<int> &A, int K) {
    int len = static_cast<int>(A.size());
    if (0 == len || 0 == K)
        return A;
    K = K % len;
    swap_elems(A, len - K, len - 1);
    swap_elems(A, 0, len - K - 1);
    swap_elems(A, 0, len - 1);
    return A;
}

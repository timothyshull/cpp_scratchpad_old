#include <iostream>

// redo with int solution(vector<int> &A);
// one flaw is that there is no checking for malformed input
int solution(int A[], int N) {
    int result = 0;
    for (int i = 0; i < N; ++i) {
        result ^= A[i];
    }
    return result;
}

int main() {
    int test_arr[] = {9, 3, 9, 3, 9, 7, 9};
    int unpaired = solution(test_arr, sizeof(test_arr) / sizeof(int));
    std::cout << unpaired << "\n";
    return 0;
}

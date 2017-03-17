#include <cstddef>

#include "find_failed_build.h"

std::deque<bool> dq1{true, false};

template<typename Comparator_type>
long find_failed_build(long uuid_array[], std::size_t size)
{
    Comparator_type comp;

    if (size == 2) { return 1; }

    //long ret;
    std::size_t lo{0};
    std::size_t hi{size - 1};
    std::size_t mid{hi / 2};
    long ret = mid;

    while (true) {
        if (!comp(uuid_array[mid]) && comp(uuid_array[mid - 1])) {
            break;
        }

        if (!comp(uuid_array[mid])) {
            hi = mid;
        } else {
            lo = mid;
        }

        if (hi - lo == 2 && mid == lo) {
            ++mid;
        } else if (hi - lo == 2 && mid != lo) {
            mid = hi;
        } else {
            mid = (hi - lo) / 2 + lo;
        }
    }

    return static_cast<long>(mid);
}

bool Find_failed_build_comparator::operator()(std::deque<bool>& input_ctr, std::size_t index)
{
    return dq1[index % 2];
}

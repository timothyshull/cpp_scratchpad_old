#ifndef TMP4_FIND_FAILED_BUILD_H
#define TMP4_FIND_FAILED_BUILD_H

#include <deque>

template<typename Comparator_type>
long find_failed_build(long uuid_array[], std::size_t size);

struct Find_failed_build_comparator {
    bool operator()(std::deque<bool>& input_ctr, std::size_t index);
};

#endif // TMP4_FIND_FAILED_BUILD_H

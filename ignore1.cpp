#include <istream>

template<typename charT, typename traits>
inline
std::basic_istream<charT, traits>&
ignore_line(std::basic_istream<charT, traits>& strm) {
    strm.ignore(std::numeric_limits<std::streamsize>::max(), strm.widen('\n'));
    return strm;
};
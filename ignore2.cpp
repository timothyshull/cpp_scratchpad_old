#include <istream>

class ignore_line {
private:
    int num;
public:
    explicit ignore_line(int n = 1) : num{n} { }

    template<typename charT, typename traits>
    friend std::basic_istream<charT, traits>&
    operator>>(std::basic_istream<charT, traits>& strm, const ignore_line& ign) {
        for (int i = 0; i < ign.num; ++i) {
            strm.ignore(std::numeric_limits<std::streamsize>::max(), strm.widen('\n'));
        }
        return strm;
    };
};
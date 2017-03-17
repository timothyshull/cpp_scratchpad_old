#include <string>
#include <cassert>

class Printer {
public:
    static std::string printerError(const std::string& s)
    {
        int errors{0};
        for (auto c : s) { if (c > 'm') { ++errors; }}
        return std::to_string(errors) + "/" + std::to_string(s.size());
    }
};

int main()
{
    std::string s = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
    assert(Printer::printerError(s) == "3/56");
    s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
    assert(Printer::printerError(s) == "6/60");
    s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyzuuuuu";
    assert(Printer::printerError(s) == "11/65");
    return 0;
}
#include <string>
#include <cassert>

std::string to_camel_case(std::string text)
{
    const static std::string delims{"-_"};
    auto w = text.begin();
    auto r = text.begin();
    auto e = text.end();
    while (r != e) {
        auto c = *r;
        if (std::find(delims.begin(), delims.end(), c) != delims.end()) {
            ++r;
            if (r != e) { *r = static_cast<std::string::value_type>(std::toupper(*r)); }
        }
        if (r != e) { *w = *r; }
        ++r;
        ++w;
    }
    text.erase(w, e);
    return text;
}

int main() {
    assert("theStealthWarrior" == to_camel_case("the-stealth-warrior"));
    assert("TheStealthWarrior" == to_camel_case("The_Stealth_Warrior"));
    return 0;
}
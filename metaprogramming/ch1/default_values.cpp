template<typename char_t = char>
class basic_string {
    // this code compiles only when char_t is either 'char' or 'wchar_t'
// ...
};

class my_string : public basic_string<> {
    // empty or minimal body
    // note: no virtual destructor!
};

using local_string = basic_string<wchar_t>;
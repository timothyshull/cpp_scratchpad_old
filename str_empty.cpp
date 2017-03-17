#include <iostream>
#include <vector>
#include <algorithm>

bool is_empty1()
{
    std::string str;
    try {
        std::istream::sentry sentry(std::cin, true);
        if (sentry) {
            std::ios_base::iostate err = std::ios_base::goodbit;
            std::streamsize extracted = 0;
            while (true) {
                std::istream::traits_type::int_type i = std::cin.rdbuf()->sbumpc();
                if (std::istream::traits_type::eq_int_type(i, std::istream::traits_type::eof())) {
                    err |= std::ios_base::eofbit;
                    break;
                }
                ++extracted;
                std::istream::char_type ch = std::istream::traits_type::to_char_type(i);
                str += ch;
                if (std::istream::traits_type::eq(ch, '\n')) {
                    break;
                }
                if (str.size() == str.max_size()) {
                    err |= std::ios_base::failbit;
                    break;
                }
            }
            if (extracted == 0) {
                err |= std::ios_base::failbit;
            }
            std::cin.setstate(err);
        }
    } catch (...) {
        std::ios_base::iostate rdstate = std::cin.rdstate();
        rdstate |= std::ios_base::badbit;
        if (std::cin.exceptions() & std::ios_base::badbit) {
            throw;
        }
    }
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        std::cin.putback(*it);
    }
    return str.size() <= 1;
}


bool is_empty()
{
    using Traits_type = std::istream::traits_type;
    std::string str;
    std::cin >> std::noskipws;
    Traits_type::int_type i;
    Traits_type::char_type ch;
    while (true) {
        i = std::cin.get(); // sentry setup and EOF handled in get, no need to handle again here
        ch = Traits_type::to_char_type(i);
        str += ch;
        if (Traits_type::eq(ch, '\n')) {
            break;
        }
        if (str.size() == str.max_size()) {
            auto err = std::cin.rdstate();
            err |= std::ios_base::failbit;
            std::cin.setstate(err);
            break;
        }
    }
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        std::cin.putback(*it);
    }
    return str.size() <= 1;
}


int main()
{
//    std::cout << "Hello, World!" << std::endl;
//    std::string line;
//    while (std::cin >> line) {
//        if (line == "") {
//            break;
//        }
//        std::cout << "the line was: " << line << "\n";
//    }
//    std::cout << "empty line...exiting\n";
    std::string tmp;
    // essential to reextract from cin inside of while loop
    while (!is_empty()) {
//        std::getline(std::cin, tmp);
//        std::cout << tmp << "\n";
        std::cout << "got a line!\n";
    }
//    char c1 = std::cin.get(); // reads 'H'
//    std::cout << "after reading " << c1 << '\n';
//    char c;
//    while ((std::cout << "Looping: \n") && std::cin >> c) {
//        std::cout << "Char was " << c << "\n";
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), std::cin.eof());
//    }

    return 0;
}


//bool Std_in::is_empty()
//{
////    using Traits_type = typename std::istream::traits_type;
////    _save_state();
////    int to_extract = 0;
////    while (true) {
////        int i = std_in.get();
////        if (Traits_type::eq_int_type(i, Traits_type::eof())) {
////            break;
////        }
////        char ch = Traits_type::to_char_type(i);
////        if (Traits_type::eq(ch, '\n')) {
////            break;
////        }
////        ++to_extract;
////    }
////    _revert_state();
////    return to_extract == 0;
//    try {
//        using Traits_type = typename std::istream::traits_type;
//
//        using Int_type = typename std::istream::traits_type::int_type;
//        using Char_type = typename std::istream::traits_type::char_type;
//
//        if (__sentry) {
//            std::streamsize to_extract = 0;
////            _save_state();
//            while (true) {
//                Int_type i = std_in.rdbuf()->sbumpc();
////                if (Traits_type::eq_int_type(i, Traits_type::eof())) {
////                    break;
////                }
//                ++to_extract;
//                Char_type ch = Traits_type::to_char_type(i);
//                if (Traits_type::eq(ch, '\n')) {
//                    break;
//                }
//            }
////            _revert_state();
//            for (int i = 0; i < to_extract; ++i) {
//                std_in.rdbuf()->sungetc();
//            }
//            return to_extract == 1;
//        }
//    } catch (...) {
//        std_in.setstate(std::ios_base::failbit);
//        return true;
//    }
//}
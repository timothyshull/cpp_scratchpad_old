#ifndef MORE_STRING_MANIPULATION_UTILITY_H
#define MORE_STRING_MANIPULATION_UTILITY_H

#include<string>
#include<vector>

bool shortened_read_string(const char filename[], std::string &result);

void split_lines(std::string &s, std::vector<std::string> &v);

// from cookbook
template<typename T>
void pad(std::basic_string<T> &s, typename std::basic_string<T>::size_type n, T c) {
    if (n > s.length()) {
        s.append(n - s.length(), c);
    }
}

void rtrim(std::string &s, char c);

template<typename T, typename F>
void rtrimws(std::basic_string<T> &s, F f) {
    if (s.empty()) {
        return;
    }
    typename std::basic_string<T>::iterator p;
    for (p = s.end(); p != s.begin() && f(*--p);) {}
    if (!f(*p)) {
        p++;
    }
    s.erase(p, s.end());
}

// Overloads to make cleaner calling for client code
void rtrimws(std::string &s);

void rtrimws(std::wstring &ws);

#endif //MORE_STRING_MANIPULATION_UTILITY_H

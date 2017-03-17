#include<string>
#include<iostream>
#include"utility.h"

int main() {
    std::string s = "zing ";
    std::wstring ws = L"zong ";
    rtrimws(s);
    rtrimws(ws);
    std::cout << s << "|\n";
    std::wcout << ws << L"|\n";

    return 0;
}

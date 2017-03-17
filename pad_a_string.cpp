#include<string>
#include<iostream>
#include"utility.h"

int main() {
    std::string s{"Appendix A"};
    std::wstring ws{L"Acknowledgements"};

    pad(s, 20, '*');
    pad(ws, 20, L'*');

    std::cout << s << "\n";
    std::wcout << ws << L"\n";

    return 0;
}

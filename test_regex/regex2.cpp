
#include <string>
#include <regex>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string data = "XML tag: <tag-name>the value</tag-name>.";
    cout << "data: " << data << "\n\n";
    smatch m; // for returned details of the match
    bool found = regex_search(data, m, regex("<(.*)>(.*)</(\\1)>"));
    // print match details:
    cout << "m.empty(): " << boolalpha << m.empty() << "\n";
    cout << "m.size(): " << m.size() << "\n";
    if (found) {
        cout << "m.str(): " << m.str() << "\n";
        cout << "m.length(): " << m.length() << "\n";
        cout << "m.position(): " << m.position() << "\n";
        cout << "m.prefix().str(): " << m.prefix().str() << "\n";
        cout << "m.suffix().str(): " << m.suffix().str() << "\n";
        cout << "\n";

        // iterating over all matches (using the match index):
        for (int i = 0; i < m.size(); ++i) {
            cout << "m[" << i << "].str(): " << m[i].str() << "\n";
            cout << "m.str(" << i << "): " << m.str(i) << "\n";
            cout << "m.position(" << i << "): " << m.position(i) << "\n";
            cout << "\n";
            // iterating over all matches (using iterators):
        }
        cout << "matches:" << "\n";
        for (auto pos = m.begin(); pos != m.end(); ++pos) {
            cout << " " << *pos << " ";
            cout << "(length: " << pos->length() << ")" << "\n";
        }
    }

    return 0;
}
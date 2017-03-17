#include <regex>
#include <iostream>

using namespace std;

void out(bool b) {
    cout << (b ? "found" : "not found") << endl;
}

int main() {
    // find XML/HTML-tagged value (using default syntax):
    regex reg1("<.*>.*</.*>");
    bool found = regex_match("<tag>value</tag>", reg1);
    out(found);
    // find XML/HTML-tagged value (tags before and after the value must match):
    regex reg2("<(.*)>.*</\\1>");
    found = regex_match("<tag>value</tag>", reg2); // regular expression
    out(found);
    // find XML/HTML-tagged value (using grep syntax):
    regex reg3("<\\(.*\\)>.*</\\1>", regex_constants::grep);
    found = regex_match("<tag>value</tag>", reg3); // regular expression
    out(found);
    // use C-string as regular expression (needs explicit cast to regex):
    found = regex_match ("<tag>value</tag>", regex("<(.*)>.*</\\1>")); // regular expression
    out(found);
    cout << "\n";
    // regex_match() versus regex_search():
    found = regex_match("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>"));
    out(found);
    found = regex_match("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*"));
    out(found);
    found = regex_search("XML tag: <tag>value</tag>", regex("<(.*)>.*</\\1>"));
    out(found);
    found = regex_search("XML tag: <tag>value</tag>", regex(".*<(.*)>.*</\\1>.*"));
    out(found);

    return 0;
}
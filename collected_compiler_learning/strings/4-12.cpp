#include <string>
#include <iostream>

using namespace std;

// String tokenizer class.
class StringTokenizer {

public:

    StringTokenizer(const string &s, const char *delim = NULL) :
            str_(s), count_(-1), begin_(0), end_(0) {

        if (!delim)
            delim_ = " \f\n\r\t\v";  //default to whitespace
        else
            delim_ = delim;

        // Point to the first token
        begin_ = static_cast<int>(str_.find_first_not_of(delim_));
        end_ = static_cast<int>(str_.find_first_of(delim_, static_cast<unsigned long>(begin_)));
    }

    size_t countTokens() {
        if (count_ >= 0) // return if we've already counted
            return static_cast<size_t>(count_);

        string::size_type n = 0;
        string::size_type i = 0;

        for (;;) {
            // advance to the first token
            if ((i = str_.find_first_not_of(delim_, i)) == string::npos)
                break;
            // advance to the next delimiter
            i = str_.find_first_of(delim_, i + 1);
            n++;
            if (i == string::npos)
                break;
        }
        count_ = static_cast<int>(n);
        return static_cast<size_t>(count_);
    }

    bool hasMoreTokens() { return (begin_ != end_); }

    void nextToken(string &s) {
        if (begin_ != string::npos && end_ != string::npos) {
            s = str_.substr(static_cast<unsigned long>(begin_), static_cast<unsigned long>(end_ - begin_));
            begin_ = static_cast<int>(str_.find_first_not_of(delim_, static_cast<unsigned long>(end_)));
            end_ = static_cast<int>(str_.find_first_of(delim_, static_cast<unsigned long>(begin_)));
        }
        else if (begin_ != string::npos && end_ == string::npos) {
            s = str_.substr(static_cast<unsigned long>(begin_), str_.length() - begin_);
            begin_ = static_cast<int>(str_.find_first_not_of(delim_, static_cast<unsigned long>(end_)));
        }

    }

private:
    StringTokenizer() {};
    string delim_;
    string str_;
    int count_;
    int begin_;
    int end_;
};

int main() {
    string s = " razzle dazzle giddyup ";
    string tmp;

    StringTokenizer st(s);

    cout << "there are " << st.countTokens() << " tokens.\n";
    while (st.hasMoreTokens()) {
        st.nextToken(tmp);
        cout << "token = " << tmp << '\n';
    }
}

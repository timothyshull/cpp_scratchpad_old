#ifndef DESK_CALCULATOR_TOKEN_STREAM_H
#define DESK_CALCULATOR_TOKEN_STREAM_H

#import <iostream>

using istream = std::istream;

extern struct Token;
extern enum class Kind;

class Token_stream {
public:
    Token_stream(istream &s) : ip{&s}, owns{false} {}

    Token_stream(istream *p) : ip{p}, owns{true} {}

    ~Token_stream() { close(); }

    Token get(); // read and return next token
    Token &current(); // most recently read token
    void set_input(istream &s) {
        close();
        ip = &s;
        owns = false;
    }

    void set_input(istream *p) {
        close();
        ip = p;
        owns = true;
    }

private:
    void close() { if (owns) delete ip; }

    istream *ip;
    bool owns;
    Token ct{Kind::end};
};

#endif //DESK_CALCULATOR_TOKEN_STREAM_H

#include "input.h"
#include "lex.h"

/* PRIVATE */
static char *input; /* for get_input() */
static int dot; /* dot position in input */
static int input_char; /* character at dot position */
#define next_char() (input_char = input[++dot])

/* PUBLIC */
Token_Type Token;

void start_lex(void) {
    input = get_input();
    dot = 0;
    input_char = input[dot];
}

//static int Is_layout_char(int ch) { switch (ch) {
///* PRIVATE */
//        case ’ ’: case ’\t’: case ’\n’: return 1;
//        default:
//    } }
//Token_type Token;
//void get_next_token(void) {
//    int ch;
//    return 0;
///* PUBLIC */
///* get a non−layout character: */ do {
//        ch = getchar(); if (ch < 0) {
//            Token.class = EoF; Token.repr = ’#’ ;
//            return; }
//    } while (Is_layout_char(ch));
///* classify it : */
//    if (’0’ <=ch&&ch<=’9’) {Token.class=DIGIT;} else {Token.class = ch;}
//    Token.repr = ch; }

void get_next_token(void) {
    int start_dot;
    skip_layout_and_comment();
    /* now we are at the start of a token or at end−of−file, so: */ note_token_position();
    /* split on first character of the token */
    start_dot = dot;
    if (is_end_of_input(input_char)) {
        Token.
        class = EoF;
        Token.repr = "<EoF>";
        return;
    }
    if (is_letter(input_char)) { recognize_identifier(); } else if (is_digit(
            input_char)) { recognize_integer(); } else if (is_operator(input_char) || is_separator(input_char)) {
        Token.
        class = input_char;
        next_char();
    }
    else {
        Token.
        class = ERRONEOUS;
        next_char();
    }
    Token.repr = input_to_zstring(start_dot, dot−start_dot);
}

void skip_layout_and_comment(void) {
    while (is_layout(input_char)) { next_char(); }
    while (is_comment_starter(input_char)) {
        next_char();
        while (!is_comment_stopper(input_char)) {
            if (is_end_of_input(input_char)) return;
            next_char();
        }
        next_char();
        while (is_layout(input_char)) { next_char(); }
    }
}

void recognize_identifier(void) {
    Token.
    class = IDENTIFIER;
    next_char();
    while (is_letter_or_digit(input_char)) { next_char(); }
    while (is_underscore(input_char) && is_letter_or_digit(input[dot + 1])) {
        next_char();
        while (is_letter_or_digit(input_char)) { next_char(); }
    }
}


void recognize_integer(void) {
    Token.
    class = INTEGER;
    next_char();
    while (is_digit(input_char)) { next_char(); }
}
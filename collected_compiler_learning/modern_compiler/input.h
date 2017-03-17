#ifndef SIMPLE_LEXER_INPUT_H
#define SIMPLE_LEXER_INPUT_H

#include <string>

std::string get_input();

#define is_end_of_input(ch) ((ch) == '\0')
#define is_layout(ch) (!is_end_of_input(ch)&&(ch) <= ' ')
#define is_comment_starter(ch) ((ch) == '#')
#define is_comment_stopper(ch) ((ch) == '#' || ( ch) == '\n')
#define is_uc_letter(ch) ('A' <= (ch) && (ch) <= 'Z')
#define is_lc_letter (ch) ('a' <= (ch) && (ch) <= 'z')
#define is_letter (ch) (is_uc_letter(ch) || is_lc_letter(ch))
#define is_digit(ch) ('0' <= (ch) && (ch) <= '9')
#define is_letter_or_digit (ch) (is_letter(ch) || is_digit(ch))
#define is_underscore(ch) ((ch) == '_')
#define is_operator(ch) (strchr("+−*/", (ch)) != 0)
#define is_separator(ch) (strchr(" ;,(){} ", (ch)) != 0)

#endif //SIMPLE_LEXER_INPUT_H

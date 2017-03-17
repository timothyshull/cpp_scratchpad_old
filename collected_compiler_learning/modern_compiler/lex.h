#ifndef SIMPLE_LEXER_LEX_H
#define SIMPLE_LEXER_LEX_H

/* Define class constants; 0−255 reserved for ASCII characters: */
#define EoF 256
#define DIGIT 257
#define IDENTIFIER 257
#define INTEGER 258
#define ERRONEOUS 259

typedef struct {
    char *file_name;
    int line_number;
    int char_number;
} Position_in_File;

typedef struct {
    int class;
    char repr;
} Token_type;

typedef struct {
    int class;
    char *repr;
    Position_in_File pos;
} Token_Type;

extern Token_Type Token;

extern void start_lex(void);

extern void get_next_token(void);

#endif //SIMPLE_LEXER_LEX_H

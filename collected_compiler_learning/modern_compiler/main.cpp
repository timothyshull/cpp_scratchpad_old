#include <printf.h>
#include "lex.h" /* for start_lex (), get_next_token() */

int main(void) {
    start_lex();
    do {
        get_next_token();

        switch (Token.class) {
            case IDENTIFIER:
                printf(" Identifier ");
            break;
            case INTEGER:
                printf("Integer");
            break;
            case ERRONEOUS:
                printf("Erroneous token");
            break;
            case EoF:
                printf("End−of−file pseudo−token");
            break;
            default:
                printf("Operator or separator");
            break;
        }
        printf(": %s\n", Token.repr);
    } while (Token.
    class != EoF);
    return 0;
}
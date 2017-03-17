#include "parser.h" /* for types AST_node and Expression */ #include "backend.h" /* for self check */

/* PRIVATE */
static void Code_gen_expression(Expression *expr) {
    switch (expr−>type) {
        case 'D':
            printf("PUSH %d\n", expr−>value);
        break;
        case 'P':
            Code_gen_expression(expr−>left);
        Code_gen_expression(expr−>right);
        switch (expr−>oper) {
            case '+':
                case '* ' :
        }
        break;
    }
}

printf ("ADD\n"); break; printf ( "MULT\n"); break;

/* PUBLIC */
void Process(AST_node *icode) {
    Code_gen_expression(icode);
    printf("PRINT\n");
}


// interpretation

#include #include

"parser.h" "backend.h"
/* for types AST_node and Expression */ /* for self check */
/* PRIVATE */
static int Interpret_expression(Expression *expr) {
    switch (expr−>type) {
        case 'D':
            return expr−>value;
        break;
        case 'P': {
            int e_left = Interpret_expression(expr−>left);
            int e_right = Interpret_expression(expr−>right);
            switch (expr−>oper) {
                case '+':
                    return e_left + e_right;
                case '* ' :
                    return e_left * e_right;
            }
        }
        break;
    }
}

/* PUBLIC */
void Process(AST_node *icode) {
    printf("%d\n", Interpret_expression(icode));
}

extern void Process(AST_node *);
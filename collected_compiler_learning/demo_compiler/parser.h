#ifndef DEMO_COMPILER_PARSER_H
#define DEMO_COMPILER_PARSER_H

typedef int Operator;
typedef struct _expression {
    char type;
    int value;
    struct_expression *left, *right;
    Operator oper;
} Expression;

typedef Expression AST_node;

extern int Parse_program(AST_node **);

static int Parse_operator(Operator *oper);

static int Parse_expression(Expression **expr_p);

#endif // DEMO_COMPILER_PARSER_H
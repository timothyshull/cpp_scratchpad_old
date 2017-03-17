#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::string> split_str(const std::string& input, const char delim);

class Expression;

class Expression {
public:
    virtual int interpret(const std::map<std::string, Expression*>& variables) = 0;
};

class Number : public Expression {
public:
    Number(const int number) : _number{number} {}

    int interpret(const std::map<std::string, Expression*>& variables) { return _number; }

private:
    int _number;
};

class Plus : public Expression {

public:
    Plus(Expression* left, Expression* right) : _left_operand{left}, _right_operand{right} {}

    int interpret(const std::map<std::string, Expression*>& variables)
    {
        return _left_operand->interpret(variables) + _right_operand->interpret(variables);
    }

private:
    Expression* _left_operand;
    Expression* _right_operand;
};

class Minus : public Expression {

public:
    Minus(Expression* left, Expression* right) : _left_operand{left}, _right_operand{right} {}

    int interpret(const std::map<std::string, Expression*>& variables)
    {
        return _left_operand->interpret(variables) - _right_operand->interpret(variables);
    }

private:
    Expression* _left_operand;
    Expression* _right_operand;
};

class Variable : public Expression {
public:
    Variable(const std::string& name) : name{name} {}

    int interpret(const std::map<std::string, Expression*>& variables)
    {
        std::map<std::string, Expression*>::const_iterator it = variables.find(name);
        if (it == variables.end()) { return 0; }
        return it->second->interpret(variables);
    }

private:
    std::string name;
};

class Evaluator : public Expression {
public:
    Evaluator(const std::string& expression)
    {
        std::stack<Expression*> expression_stack;
        for (auto token : split_str(expression, ' ')) {
            if (token == "+") {
                Expression* t1 = expression_stack.top();
                expression_stack.pop();
                Expression* t2 = expression_stack.top();
                expression_stack.pop();
                Expression* sub_expression = new Plus{t1, t2};
                expression_stack.push(sub_expression);
            } else if (token == "-") {
                // it's necessary remove first the right operand from the stack
                Expression* right = expression_stack.top();
                expression_stack.pop();
                // ..and after the left one
                Expression* left = expression_stack.top();
                expression_stack.pop();
                Expression* sub_expression = new Minus(left, right);
                expression_stack.push(sub_expression);
            } else {
                expression_stack.push(new Variable(token));
            }
        }
        _syntax_tree = expression_stack.top();
        expression_stack.pop();
    }

    int interpret(const std::map<std::string, Expression*>& context)
    {
        return _syntax_tree->interpret(context);
    }

private:
    Expression* _syntax_tree;
};

std::vector<std::string> split_str(const std::string& input, const char delim)
{
    std::vector<std::string> out;
    auto end = input.find(delim);
    decltype(end) begin{0};

    do {
        out.emplace_back(input.substr(begin, end - begin));
        begin = ++end;
        end = input.find(delim, end);
    } while (end != std::string::npos);

    return std::move(out);
}

int main(int argc, char* argv[])
{
    const std::string expression{"w x z - +"};
    Evaluator* sentence = new Evaluator(expression);
    std::map<std::string, Expression*> variables;
    variables.emplace("w", new Number(5));
    variables.emplace("x", new Number(10));
    variables.emplace("z", new Number(42));
    const int result = sentence->interpret(variables);
    std::cout << result << "\n";
    return 0;
}
#include "Precompiled.h"
#include "Scanner.h"
#include "FileMap.h"

using namespace KennyKerr;

enum class SyntaxError {
    InvalidToken,
    PrimaryExpected,
    DivideByZero,
    RightParenthesisExpected,
    UnexpectedToken,
};

static char const *ErrorMessages[] =
        {
                "InvalidToken",
                "PrimaryExpected",
                "DivideByZero",
                "RightParenthesisExpected",
                "UnexpectedToken",
        };

struct SyntaxException {
    SyntaxError Error;
    unsigned Line;

    SyntaxException(SyntaxError const error,
                    unsigned const line) :
            Error(error),
            Line(line) {}
};

float ScanExpression(Scanner &scanner);

float ScanTerm(Scanner &scanner);

float ScanPrimary(Scanner &scanner);

void PrintTokens(FileMap const &file);

int main() {
    FileMap file(L"C:\\temp\\Sample.b");

    if (!file) {
        printf("Error: failed to open file\n");
        return 1;
    }

    try {
        Scanner scanner(file.Begin(), file.End());
        scanner.Next();
        float const value = ScanExpression(scanner);

        if (Token::EndOfFile != scanner.GetToken()) {
            throw SyntaxException(SyntaxError::UnexpectedToken,
                                  scanner.GetLine());
        }

        printf("Result: %.2f\n", value);
    }
    catch (SyntaxException const &e) {
        printf("Error: %s (line %d)\n",
               ErrorMessages[static_cast<unsigned>(e.Error)],
               e.Line);
    }
}

float ScanExpression(Scanner &scanner) {
    float value = ScanTerm(scanner);

    for (;;) {
        Token const token = scanner.GetToken();

        if (Token::Add == token) {
            scanner.Next();
            value += ScanTerm(scanner);
        }
        else if (Token::Subtract == token) {
            scanner.Next();
            value -= ScanTerm(scanner);
        }
        else if (Token::Invalid == token) {
            throw SyntaxException(SyntaxError::InvalidToken,
                                  scanner.GetLine());
        }
        else {
            break;
        }
    }

    return value;
}

float ScanTerm(Scanner &scanner) {
    float value = ScanPrimary(scanner);

    for (;;) {
        Token const token = scanner.GetToken();

        if (Token::Multiply == token) {
            scanner.Next();
            value *= ScanPrimary(scanner);
        }
        else if (Token::Divide == token) {
            scanner.Next();
            float const other = ScanPrimary(scanner);

            if (0 == other) {
                throw SyntaxException(SyntaxError::DivideByZero,
                                      scanner.GetLine());
            }

            value /= other;
        }
        else {
            break;
        }
    }

    return value;
}

float ScanPrimary(Scanner &scanner) {
    Token const token = scanner.GetToken();

    if (Token::Number == token) {
        float const value = scanner.GetNumber();

        scanner.Next();
        return value;
    }

    if (Token::LeftParenthesis == token) {
        scanner.Next();
        float const value = ScanExpression(scanner);

        if (Token::RightParenthesis != scanner.GetToken()) {
            throw SyntaxException(SyntaxError::RightParenthesisExpected,
                                  scanner.GetLine());
        }

        scanner.Next();
        return value;
    }

    throw SyntaxException(SyntaxError::PrimaryExpected,
                          scanner.GetLine());
}

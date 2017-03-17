#pragma once

namespace KennyKerr {
    enum class Token {
        Invalid,
        EndOfFile,
        Number,
        Add,
        Subtract,
        Multiply,
        Divide,
        LeftParenthesis,
        RightParenthesis,
    };

    class Scanner {
        char const *const m_end = nullptr;
        char const *m_next = nullptr;
        float m_number = 0.0f;
        Token m_token = Token::Invalid;
        unsigned m_line = 1;

        void SkipWhitespace() noexcept {
            while (m_next != m_end) {
                if ('\n' == *m_next) {
                    ++m_next;
                    ++m_line;
                }
                else if (isspace(*m_next)) {
                    ++m_next;
                }
                else {
                    break;
                }
            }
        }

        Token ReadNumber() noexcept {
            bool digit = false;
            bool point = false;
            unsigned divide = 1;
            m_number = 0.0f;

            for (char c = *m_next;
                 m_next != m_end;
                 c = *++m_next) {
                if ('0' <= c && '9' >= c) {
                    digit = true;
                    m_number = 10 * m_number + (c - '0');

                    if (point) {
                        divide *= 10;
                    }
                }
                else if ('.' == c) {
                    if (point) {
                        return Token::Invalid;
                    }

                    point = true;
                }
                else {
                    break;
                }
            }

            if (digit) {
                m_number /= divide;
                return Token::Number;
            }

            return Token::Invalid;
        }

    public:

        Scanner(Scanner const &) = delete;

        Scanner &operator=(Scanner const &) = delete;

        Scanner(char const *const begin,
                char const *const end) noexcept :
                m_end(end),
                m_next(begin) {}

        float GetNumber() const noexcept {
            return m_number;
        }

        Token GetToken() const noexcept {
            return m_token;
        }

        unsigned GetLine() const noexcept {
            return m_line;
        }

        void Next() noexcept {
            SkipWhitespace();

            if (m_next == m_end) {
                m_token = Token::EndOfFile;
                return;
            }

            char const c = *m_next;

            if ('+' == c) {
                ++m_next;
                m_token = Token::Add;
            }
            else if ('-' == c) {
                ++m_next;
                m_token = Token::Subtract;
            }
            else if ('*' == c) {
                ++m_next;
                m_token = Token::Multiply;
            }
            else if ('/' == c) {
                ++m_next;
                m_token = Token::Divide;
            }
            else if ('(' == c) {
                ++m_next;
                m_token = Token::LeftParenthesis;
            }
            else if (')' == c) {
                ++m_next;
                m_token = Token::RightParenthesis;
            }
            else if ('.' == c || '0' <= c && '9' >= c) {
                m_token = ReadNumber();
            }
            else {
                m_token = Token::Invalid;
            }
        }
    };
}

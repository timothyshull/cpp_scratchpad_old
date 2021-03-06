/*
    Copyright 2005-2007 Adobe Systems Incorporated
    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or a copy at http://stlab.adobe.com/licenses.html)
*/

/*************************************************************************************************/

#include <adobe/once.hpp>
#include <adobe/string.hpp>
#include <adobe/name.hpp>
#include <adobe/implementation/token.hpp>
#include <adobe/implementation/lex_shared_fwd.hpp>
#include <adobe/implementation/parser_shared.hpp>
#include <adobe/circular_queue.hpp>
#include <adobe/istream.hpp>

#include <boost/array.hpp>

#include <iostream>
#include <sstream>

#include "eop_lex_stream.h"

/*************************************************************************************************/

#ifdef BOOST_MSVC
namespace std
{
    using ::isspace;
    using ::isdigit;
    using ::isalnum;
    using ::isalpha;
}
#endif

/*************************************************************************************************/

ADOBE_ONCE_DECLARATION(adobe_lex_stream)

/*************************************************************************************************/

namespace {

    using namespace adobe;

/*************************************************************************************************/
#if 0
#pragma mark -
#endif

/*************************************************************************************************/
    namespace implementation {

        struct lex_fragment_t {
            lex_fragment_t(stream_lex_token_t token = stream_lex_token_t(),
                           const line_position_t &line_position = line_position_t()) :
                    token_value_m(move(token)), line_position_m(line_position) {}

            lex_fragment_t(move_from <lex_fragment_t> x) :
                    token_value_m(move(x.source.token_value_m)), line_position_m(move(x.source.line_position_m)) {}

            lex_fragment_t &operator=(lex_fragment_t x) {
                token_value_m = move(x.token_value_m);
                line_position_m = move(x.line_position_m);
                return *this;
            }

            stream_lex_token_t token_value_m;
            line_position_t line_position_m;
        };

    } // namespace implementation

    template<std::size_t S,
            typename I>  // I models InputIterator
    struct stream_lex_base_t {
    public:
        typedef std::istream::pos_type pos_type;
        typedef boost::function<void(char)> parse_token_proc_t;

        stream_lex_base_t(I first, I last, const line_position_t &position);

        virtual ~stream_lex_base_t();

        const stream_lex_token_t &get_token();

        void putback_token();

        void put_token(stream_lex_token_t token);

        bool get_char(char &c);

        void putback_char(char c);

        int peek_char();

        void ignore_char();

        void throw_exception(const name_t &expected, const name_t &found);

        void throw_parser_exception(const char *error_string);

        virtual void skip_white_space() = 0;

        const line_position_t &next_position();

        bool is_line_end(char c);

        void set_parse_token_proc(parse_token_proc_t proc);

        std::vector<char> identifier_buffer_m;

    private:
        I first_m;
        I last_m;
        std::streampos streampos_m;
        line_position_t line_position_m;
        parse_token_proc_t parse_proc_m;
        boost::array<char, 8> putback_m; // stack-based is faster
        std::size_t index_m; // for putback_m

#if !defined(ADOBE_NO_DOCUMENTATION)
        circular_queue <implementation::lex_fragment_t> last_token_m; // N token lookahead
#endif // !defined(ADOBE_NO_DOCUMENTATION)
    };

/*************************************************************************************************/

    template<std::size_t S, typename I>
    stream_lex_base_t<S, I>::stream_lex_base_t(I first, I last, const line_position_t &position) :
            identifier_buffer_m(128),
            first_m(first),
            last_m(last),
            streampos_m(1),
            line_position_m(position),
            index_m(0),
            last_token_m(S) {}

/*************************************************************************************************/

    template<std::size_t S, typename I>
    stream_lex_base_t<S, I>::~stream_lex_base_t() {}

/*************************************************************************************************/

    template<std::size_t S, typename I>
    bool stream_lex_base_t<S, I>::get_char(char &c) {
        if (index_m) {
            c = static_cast<char>(putback_m[index_m]);

            --index_m;

            streampos_m += 1;

            return true;
        }

        if (first_m == last_m) return false;

        c = static_cast<char>(*first_m);

        ++first_m;

        streampos_m += 1;

        return true;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::putback_char(char c) {
        putback_m[++index_m] = c;

        streampos_m -= 1;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    int stream_lex_base_t<S, I>::peek_char() {
        if (index_m)
            return putback_m[index_m];
        else if (first_m == last_m)
            return EOF;
        else
            return *first_m;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::ignore_char() {
        if (index_m)
            --index_m;
        else if (first_m == last_m)
            return;
        else
            ++first_m;

        streampos_m += 1;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    const stream_lex_token_t &stream_lex_base_t<S, I>::get_token() {
        assert(parse_proc_m);

        if (last_token_m.empty()) {
            char c;

            /*
                REVISIT (sparent) : You can't get(c), tellg(), and then putback(c) on a stream - the
                tellg() in the middle will cause the putback(c) to move the stream to an invalid state.
                So instead of calling skip_space(c) we break up the call with the tellg() in the middle,
                prior to the callback.
            */

            skip_white_space();

            line_position_m.position_m = streampos_m; // remember the start of the token position

            /*
                REVISIT (sparent) : I don't like that eof is not handled as the other tokens are handled
                there should be a way to make this logic consistant.
            */

            if (!get_char(c)) // eof
                put_token(stream_lex_token_t(eof_k, any_regular_t()));
            else
                parse_proc_m(c);
        }

        stream_lex_token_t &result(last_token_m.front().token_value_m);

        last_token_m.pop_front();

        return result;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::put_token(stream_lex_token_t token) {
        last_token_m.push_back(implementation::lex_fragment_t(move(token), line_position_m));
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::putback_token() {
        last_token_m.putback(); // REVISIT (sparent) : Check for overflow
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    const line_position_t &stream_lex_base_t<S, I>::next_position() {
/*
    REVISIT (sparent) : Clean this up - this primes the ring buffer so we can get the next position
*/
        get_token();
        putback_token();

        return last_token_m.front().line_position_m;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    bool stream_lex_base_t<S, I>::is_line_end(char c) {
        using adobe::is_line_end;

        std::size_t num_chars_eaten(is_line_end(first_m, last_m, c));

        if (num_chars_eaten != 0) {
            ++line_position_m.line_number_m;

            if (num_chars_eaten == 2)
                streampos_m += 1;

            line_position_m.line_start_m = streampos_m;
        }

        return num_chars_eaten != 0;
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::throw_parser_exception(const char *error_string) {
        using adobe::throw_parser_exception;

        throw_parser_exception(error_string, line_position_m);
    }

/*************************************************************************************************/

    template<std::size_t S, typename I>
    void stream_lex_base_t<S, I>::set_parse_token_proc(parse_token_proc_t proc) {
        parse_proc_m = proc;
    }

/*************************************************************************************************/

/*************************************************************************************************/

    typedef boost::array<adobe::name_t, 3> keyword_table_t;

/*************************************************************************************************/

    const keyword_table_t *keywords_g;
    const char *compound_match_g;
    const adobe::name_t *name_table_g;
    const int *compound_index_g;
    const int *simple_index_g;

/*************************************************************************************************/

    void init_once() {
        static keyword_table_t keywords_s = {{
                                                     adobe::true_k,
                                                     adobe::false_k
                                             }};

        static const char compound_match_s[] = {
                /*           0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F   */
                /* 00 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 10 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 20 */    '0', '=', '0', '0', '0', '0', '&', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 30 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '=', '=', '=', '0',
                /* 40 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 50 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 60 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 70 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '|', '0', '0', '0',
                /* 80 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* 90 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* A0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* B0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* C0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* D0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* E0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                /* F0 */    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'
        };

        static const adobe::name_t name_table_s[] = {
                /* 00 */    adobe::empty_k,
                /* 01 */    adobe::equal_k,
                /* 02 */    adobe::and_k,
                /* 03 */    adobe::or_k,
                /* 04 */    adobe::less_equal_k,
                /* 05 */    adobe::greater_equal_k,
                /* 06 */    adobe::not_equal_k,

                /* 07 */    adobe::add_k,
                /* 08 */    adobe::subtract_k,
                /* 09 */    adobe::multiply_k,
                /* 0A */    adobe::divide_k,
                /* 0B */    adobe::modulus_k,
                /* 0C */    adobe::question_k, // Removed...
                /* 0D */    adobe::colon_k,
                /* 0E */    adobe::semicolon_k,
                /* 0F */    adobe::assign_k,
                /* 10 */    adobe::not_k,
                /* 11 */    adobe::open_brace_k,
                /* 12 */    adobe::close_brace_k,
                /* 13 */    adobe::less_k,
                /* 14 */    adobe::greater_k,
                /* 15 */    adobe::open_parenthesis_k,
                /* 16 */    adobe::close_parenthesis_k,
                /* 17 */    eop::reference_k,
                /* 18 */    adobe::open_bracket_k,
                /* 19 */    adobe::close_bracket_k,
                /* 1A */    adobe::comma_k,
                /* 1B */    adobe::dot_k,
                /* 1C */    eop::destructor_k
        };

        static const int compound_index_s[] = {
                /*           0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F    */
                /* 00 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 10 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 20 */    0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 30 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01, 0x05,
                            0x00,
                /* 40 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 50 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 60 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 70 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
                            0x00,
                /* 80 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 90 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* A0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* B0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* C0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* D0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* E0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* F0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00
        };

        static const int simple_index_s[] = {
                /*           0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F    */
                /* 00 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 10 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 20 */    0x00, 0x10, 0x00, 0x00, 0x00, 0x0B, 0x17, 0x00, 0x15, 0x16, 0x09, 0x07, 0x1A, 0x08, 0x1B,
                            0x0A,
                /* 30 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x0E, 0x13, 0x0F, 0x14,
                            0x00,
                /* 40 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 50 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x19, 0x00,
                            0x00,
                /* 60 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 70 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x12, 0x1C,
                            0x00,
                /* 80 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* 90 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* A0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* B0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* C0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* D0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* E0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00,
                /* F0 */    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00
        };

        adobe::sort(keywords_s);

        keywords_g = &keywords_s;
        compound_match_g = &compound_match_s[0];
        name_table_g = &name_table_s[0];
        compound_index_g = &compound_index_s[0];
        simple_index_g = &simple_index_s[0];
    }

/*************************************************************************************************/

    void once_instance() {
        ADOBE_ONCE_INSTANCE(adobe_lex_stream);
    }

/*************************************************************************************************/

} // namespace

/*************************************************************************************************/

ADOBE_ONCE_DEFINITION(adobe_lex_stream, init_once
)

/*************************************************************************************************/

namespace eop {

/*************************************************************************************************/

    aggregate_name_t reference_k = {"reference"};
    aggregate_name_t pound_k = {"pound"};
    aggregate_name_t shift_left_k = {"shift_left"};
    aggregate_name_t shift_right_k = {"shift_right"};
    aggregate_name_t destructor_k = {"destructor"};

/*************************************************************************************************/

#ifndef NDEBUG

    std::ostream &operator<<(std::ostream &out, const stream_lex_token_t &token) {
        out << "{" << token.first << ": " << token.second << "}";
        return out;
    }

#endif

/*************************************************************************************************/

    struct lex_stream_t::implementation_t : stream_lex_base_t<2, std::istream_iterator<char> > {
        typedef stream_lex_base_t<2, std::istream_iterator<char> > _super;

    public:
        typedef std::istream::pos_type pos_type;

        implementation_t(std::istream &in, const line_position_t &position);

        void set_keyword_extension_lookup(const keyword_extension_lookup_proc_t &proc);

    private:
        void parse_token(char c);

        bool is_comment(char c, stream_lex_token_t &result);

        bool is_string(char c, stream_lex_token_t &result);

        bool is_number(char c, stream_lex_token_t &result);

        bool is_compound(char c, stream_lex_token_t &result);

        bool is_simple(char c, stream_lex_token_t &result);

        bool is_identifier_or_keyword(char c, stream_lex_token_t &result);

        void skip_white_space();

        bool skip_space(char &c);

        keyword_extension_lookup_proc_t keyword_proc_m;
    };

/*************************************************************************************************/

    lex_stream_t::lex_stream_t(std::istream &in, const line_position_t &position) :
            object_m(new lex_stream_t::implementation_t(in, position)) { once_instance(); }

#if !defined(ADOBE_NO_DOCUMENTATION)

    lex_stream_t::lex_stream_t(const lex_stream_t &rhs) :
            object_m(new lex_stream_t::implementation_t(*rhs.object_m)) { once_instance(); }

    lex_stream_t::~lex_stream_t() { delete object_m; }

    lex_stream_t &lex_stream_t::operator=(const lex_stream_t &rhs) {
        *object_m = *rhs.object_m;
        return *this;
    }

#endif // !defined(ADOBE_NO_DOCUMENTATION)

    const stream_lex_token_t &lex_stream_t::get() { return object_m->get_token(); }

    void lex_stream_t::putback() { object_m->putback_token(); }

    const line_position_t &lex_stream_t::next_position() { return object_m->next_position(); }

    void lex_stream_t::set_keyword_extension_lookup(
            const keyword_extension_lookup_proc_t &proc) { return object_m->set_keyword_extension_lookup(proc); }

/*************************************************************************************************/

#if 0
#pragma mark -
#endif

/*************************************************************************************************/

    lex_stream_t::implementation_t::implementation_t(std::istream &in, const line_position_t &position) :
            _super(std::istream_iterator<char>(in), std::istream_iterator<char>(), position) {
        in.unsetf(std::ios_base::skipws);

        _super::set_parse_token_proc(boost::bind(&lex_stream_t::implementation_t::parse_token, boost::ref(*this), _1));
    }

/*************************************************************************************************/

    void lex_stream_t::implementation_t::set_keyword_extension_lookup(const keyword_extension_lookup_proc_t &proc) {
        keyword_proc_m = proc;
    }

/*************************************************************************************************/

    bool lex_stream_t::implementation_t::is_number(char c, stream_lex_token_t &result) {
        if (!std::isdigit(c)) return false;

        _super::putback_char(c);

        std::stringstream temp;
        temp.imbue(std::locale::classic());

        while (true) {
            if (!_super::get_char(c)) break;

            if (!std::isdigit(c) && c != '.') {
                _super::putback_char(c);

                break;
            }

            temp << c;
        }

        double re(0);
        temp >> re;

        result = stream_lex_token_t(number_k, any_regular_t(re));
        return true;
    }

/*************************************************************************************************/

    bool lex_stream_t::implementation_t::is_identifier_or_keyword(char c, stream_lex_token_t &result) {
        if (!std::isalpha(c) && c != '_') return false;

        identifier_buffer_m.clear();

        do {
            if (std::isalnum(c) || c == '_') {
                identifier_buffer_m.push_back(c);
            }
            else {
                _super::putback_char(c);
                break;
            }
        }
        while (_super::get_char(c));

        identifier_buffer_m.push_back(0);

        name_t ident(&identifier_buffer_m.front());
        keyword_table_t::const_iterator
        iter(lower_bound(*keywords_g, ident));

        if ((iter != keywords_g->end() && *iter == ident) ||
            (!keyword_proc_m.empty() && keyword_proc_m(ident))) {
            result = stream_lex_token_t(keyword_k, any_regular_t(ident));
        }
        else {
            result = stream_lex_token_t(identifier_k, any_regular_t(ident));
        }

        return true;
    }

/*************************************************************************************************/

    bool lex_stream_t::implementation_t::is_comment(char c, stream_lex_token_t &result) {
        if (c == '#') {
            while (_super::get_char(c) && !is_line_end(c)) identifier_buffer_m.push_back(c);

            identifier_buffer_m.push_back(0);

            result = stream_lex_token_t(trail_comment_k, any_regular_t(std::string(&identifier_buffer_m[0])));
            return true;
        }

        if (c != '/') return false;

        std::istream::int_type peek_c(_super::peek_char());

        if (peek_c == EOF || (peek_c != '/' && peek_c != '*')) return false;

        (void) _super::get_char(c);

        identifier_buffer_m.clear();

        if (c == '/') {
            while (_super::get_char(c) && !is_line_end(c)) {
                identifier_buffer_m.push_back(c);
            }

            identifier_buffer_m.push_back(0);

            result = stream_lex_token_t(trail_comment_k, any_regular_t(std::string(&identifier_buffer_m[0])));
        }
        else // if (c == '*')
        {
            while (true) {
                if (!_super::get_char(c))
                    throw_parser_exception("Unexpected EOF in comment.");

                if (c == '*') {
                    peek_c = _super::peek_char();

                    if (peek_c != EOF && peek_c == '/') {
                        _super::ignore_char();
                        break;
                    }
                }
                else if (is_line_end(c)) { c = '\n'; }

                identifier_buffer_m.push_back(c);
            }

            identifier_buffer_m.push_back(0);

            result = stream_lex_token_t(lead_comment_k, any_regular_t(std::string(&identifier_buffer_m[0])));
        }

        return true;

    }

/*************************************************************************************************/

    bool lex_stream_t::implementation_t::is_string(char c, stream_lex_token_t &result) {
        if (c != '\'' && c != '\"') return false;

        identifier_buffer_m.clear();

        while (true) {
            char end_char(c);

            while (_super::get_char(c) && c != end_char) {
                // REVISIT (sparent) : Handle quoted characters here.
                // Also handle invalid characters such as line endings.
                identifier_buffer_m.push_back(c);
            }

            if (c != end_char) throw_parser_exception("Unexpected EOF in string.");

            if (!skip_space(c)) break;

            if (c != '\'' && c != '\"') {
                _super::putback_char(c);
                break;
            }
        }

        identifier_buffer_m.push_back(0);
        result = stream_lex_token_t(string_k, any_regular_t(std::string(&identifier_buffer_m[0])));

        return true;
    }

/*************************************************************************************************/

/*
    is_compound() works by noting that in all the current compound tokens the token is unique in
    the first character and only requires that the proper second character be present.
*/

    bool lex_stream_t::implementation_t::is_compound(char c, stream_lex_token_t &result) {
        char next_char(compound_match_g[(unsigned char) c]);

        if (next_char == '0') return false;

        int actual_next(_super::peek_char());

        if (actual_next == EOF) return false;

        char actual_char(actual_next);

        /*
            Special case the shift operators here - they aren't unique in the second character.
        */

        if (c == '<' && actual_char == '<') {
            result = stream_lex_token_t(shift_left_k, any_regular_t());
            _super::ignore_char();
            return true;
        }

        if (c == '>' && actual_char == '>') {
            result = stream_lex_token_t(shift_right_k, any_regular_t());
            _super::ignore_char();
            return true;
        }

        if (actual_char != next_char) return false;

        _super::ignore_char();

        /*
        There is only a single 3 character compound. It is special cased here rather than adding an
        additional table. The token is '<=='.
        */

        if (c == '<' && _super::peek_char() == '=') {
            _super::ignore_char();
            result = stream_lex_token_t(is_k, any_regular_t());
            return true;
        }

        result = stream_lex_token_t(name_table_g[compound_index_g[(unsigned char) c]], any_regular_t());
        return true;
    }

/*************************************************************************************************/

    bool lex_stream_t::implementation_t::is_simple(char c, stream_lex_token_t &result) {
        int index(simple_index_g[(unsigned char) c]);

        if (index == 0) return false;

        result = stream_lex_token_t(name_table_g[index], any_regular_t());
        return true;
    }

/*************************************************************************************************/

    void lex_stream_t::implementation_t::skip_white_space() {
        char c;
        stream_lex_token_t tmp;

        while (get_char(c)) {
            // Handle any type of line ending.
            if (!is_line_end(c) && !std::isspace(c) && !is_comment(c, tmp)) {
                putback_char(c);

                break;
            }
        }
    }

    bool lex_stream_t::implementation_t::skip_space(char &c) {
        skip_white_space();
        return get_char(c);
    }

/*************************************************************************************************/

    void lex_stream_t::implementation_t::parse_token(char c) {
        stream_lex_token_t result;

        if (!(is_number(c, result)
              || is_identifier_or_keyword(c, result)
              //       ||  is_comment(c, result)
              || is_string(c, result)
              || is_compound(c, result)
              || is_simple(c, result))) { throw_parser_exception("Syntax Error"); }

        put_token(move(result));
    }

/*************************************************************************************************/

} // namespace eop

/*************************************************************************************************/

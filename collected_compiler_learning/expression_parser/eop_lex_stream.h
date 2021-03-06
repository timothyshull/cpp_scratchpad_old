/*
    Copyright 2005-2007 Adobe Systems Incorporated
    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or a copy at http://stlab.adobe.com/licenses.html)
*/

/*************************************************************************************************/

#ifndef EOP_LEX_STREAM_HPP
#define EOP_LEX_STREAM_HPP

/*************************************************************************************************/

#include <adobe/config.hpp>

#include <adobe/istream.hpp>

#include <iosfwd>

#include "eop_lex_stream_fwd.h"

/*************************************************************************************************/

void swap(eop::lex_stream_t &, eop::lex_stream_t &);

/*************************************************************************************************/

namespace eop {

/*
%----------------------------------------------------------------

comment    = "//" {character} eol.
whitespace = {" " | eol | comment}.

identifer  = (letter | "_") {letter | "_" | digit}.
keyword    = "case" | "const" | "do" | "else" | "enum" | "false" 
               | "goto" | "if" | "operator" | "requires" 
               | "return" | "struct" | "switch" | "template" 
               | "true" | "typedef" | "typename" | "while".
number     = digit {digit} ["." digit {digit}].
string     = """" {character} """".
operator   = "!=" | "&&" | "<=" | "==" | ">=" | "||" | "!" 
               | "%" | "&" | "(" | ")" | "*" | "+" | "," | "." 
               | "/" | ":" | ";" | "<" | "=" | ">" | "[" | "]" 
               | "{" | "|" | "}" | "~".


Notes:  Currently "/*" {character} "*\/" comments are also supported
        Currently "#" {character} eol. is a comment.
        primitives = digit, letter, eol.
        
        definition of number could use some refinement.

*/

/*************************************************************************************************/

    extern aggregate_name_t reference_k;
    extern aggregate_name_t pound_k;
    extern aggregate_name_t shift_left_k;
    extern aggregate_name_t shift_right_k;
    extern aggregate_name_t destructor_k;

/*************************************************************************************************/

    class lex_stream_t {
    public:
        lex_stream_t(std::istream &in, const line_position_t &position);

#if !defined(ADOBE_NO_DOCUMENTATION)

        lex_stream_t(const lex_stream_t &rhs);

        ~lex_stream_t();

        lex_stream_t &operator=(const lex_stream_t &rhs);

#endif // !defined(ADOBE_NO_DOCUMENTATION)

        const stream_lex_token_t &get();

        void putback();

        const line_position_t &next_position();

        void set_keyword_extension_lookup(const keyword_extension_lookup_proc_t &proc);

#if !defined(ADOBE_NO_DOCUMENTATION)
    private:
        friend void::swap(lex_stream_t &, lex_stream_t &);

        struct implementation_t;

        implementation_t *object_m;
#endif // !defined(ADOBE_NO_DOCUMENTATION)
    };

/*************************************************************************************************/

} // namespace eop

/*************************************************************************************************/

inline void swap(eop::lex_stream_t &x, eop::lex_stream_t &y) {
    std::swap(x.object_m, y.object_m);
}

/*************************************************************************************************/

#endif

/*************************************************************************************************/

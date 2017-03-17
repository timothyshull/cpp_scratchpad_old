//
// Created by Tim Shull on 12/2/16.
//

#include "c_strings.h"

#include <cctype>
#include <cstring>
#include <cstddef>

//#ifndef TOLOWER
//# define TOLOWER(Ch) tolower (Ch)
//#endif

//# define BOUNDS_VIOLATED (__builtin_trap (), 0)
//
///* Verify that pointer's value >= low.  Return pointer value.  */
//# define CHECK_BOUNDS_LOW(ARG)					\
//  (((__ptrvalue (ARG) < __ptrlow (ARG)) && BOUNDS_VIOLATED),	\
//   __ptrvalue (ARG))
//
///* Verify that pointer's value < high.  Return pointer value.  */
//# define CHECK_BOUNDS_HIGH(ARG)				\
//  (((__ptrvalue (ARG) > __ptrhigh (ARG)) && BOUNDS_VIOLATED),	\
//   __ptrvalue (ARG))

int to_lower(int chr) {
    return (chr >= 'A' && chr <= 'Z') ? (chr + 32) : (chr);
}

int to_upper(int chr) {
    return (chr >= 'a' && chr <= 'z') ? (chr - 32) : (chr);
}

int str_case_cmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (const unsigned char *) s1;
    const unsigned char *p2 = (const unsigned char *) s2;
    int result;

    if (p1 == p2) {
        return 0;
    }

    while ((result = to_lower(*p1) - to_lower(*p2++)) == 0) {
        if (*p1++ == '\0') {
            break;
        }
    }

    return result;
}

char *str_cat(char *dest, const char *src) {
    char *s1 = dest;
    const char *s2 = src;
    char c;

    /* Find the end of the string.  */
    do {
        c = *s1++;
    } while (c != '\0');

    /* Make S1 point before the next character, so we can increment
    it while memory is read (wins on pipelined cpus).  */
    s1 -= 2;

    do {
        c = *s2++;
        *++s1 = c;
    } while (c != '\0');

    return dest;
}

int str_cmp(const char *p1, const char *p2) {
    register const unsigned char *s1 = (const unsigned char *) p1;
    register const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1, c2;

    do {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);

    return c1 - c2;
}

char *str_cpy(char *dest, const char *src) {
    char c;
    char *s = (char *)CHECK_BOUNDS_LOW(src); // checks that the current pointer is 8 + the base pointer address
    const std::ptrdiff_t off = CHECK_BOUNDS_LOW(dest) - s - 1;
    size_t n;

    do {
        c = *s++;
        s[off] = c;
    } while (c != '\0');

    n = s - src;
    (void) CHECK_BOUNDS_HIGH(src + n);
    (void) CHECK_BOUNDS_HIGH(dest + n);

    return dest;
}
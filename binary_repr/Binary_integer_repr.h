#ifndef INTEGER_REPR_H
#define INTEGER_REPR_H

#include "uint_type.h"

template<typename T, typename Enable = void>
class Binary_integer_repr {};

template<typename Int_type>
class Binary_integer_repr<Int_type, typename std::enable_if<std::is_integral<Int_type>::value>::type> {
    using Unsigned_integer_type = typename __impl::__Unsigned_integer_type<sizeof(Int_type) * CHAR_BIT>::type;
    union Agnostic_int {
        Int_type o_;
        Unsigned_integer_type i_;
    };

    Agnostic_int val_;
    std::bitset<sizeof(Unsigned_integer_type) * CHAR_BIT> repr_;

    template<typename T>
    friend
    std::ostream& operator<<(std::ostream& os, const Binary_integer_repr<T>& ir);

    template<typename T>
    friend
    Binary_integer_repr<T> operator>>(const Binary_integer_repr<T>& lhs, const Binary_integer_repr<T>& rhs);

    template<typename T>
    friend
    Binary_integer_repr<T> operator>>(const Binary_integer_repr<T>& lhs, const int& rhs);

public:
    explicit Binary_integer_repr(Int_type value)
    {
        val_.o_ = value;
        repr_ = val_.i_;
    }

//    Binary_integer_repr<Int_type> &operator&=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign bitwise and
//    Binary_integer_repr<Int_type> &operator^=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign exclusive or
//    Binary_integer_repr<Int_type> &operator|=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign bitwise or
//    Binary_integer_repr<Int_type> &operator-=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign difference
//    Binary_integer_repr<Int_type> &operator<<=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign left shift
//    Binary_integer_repr<Int_type> &operator*=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign product
//    Binary_integer_repr<Int_type> &operator/=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign quotient
//    Binary_integer_repr<Int_type> &operator%=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign remainder
//    Binary_integer_repr<Int_type> &operator>>=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign right shift
//    Binary_integer_repr<Int_type> &operator+=(Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Assign sum
//    //Other modification operators
//    Binary_integer_repr<Int_type> &operator--(Binary_integer_repr<Int_type> &lhs); // Prefix decrement - decrement and return new value
//    Binary_integer_repr<Int_type> operator--(Binary_integer_repr<Int_type> &lhs, int unused); // Postfix decrement - decrement and return copy of old value
//    Binary_integer_repr<Int_type> &operator++(Binary_integer_repr<Int_type> &lhs); // Prefix increment - increment and return new value
//    Binary_integer_repr<Int_type> operator++(Binary_integer_repr<Int_type> &lhs, int unused); // Postfix increment - increment and return copy of old value
//
////Comparison operators
//    bool operator==(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Equal
//    bool operator>(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Greater than
//    bool operator>=(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Greater than or equal
//    bool operator<(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // less than
//    bool operator<=(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // less than or equal
//    bool operator!(const Binary_integer_repr<Int_type> &lhs); // logical complement
//    bool operator!=(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // no equal
//
////Other operators
//    Binary_integer_repr<Int_type> operator+(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Addition
//    Binary_integer_repr<Int_type> operator+(const Binary_integer_repr<Int_type> &lhs); // Unary plus
//    Binary_integer_repr<Int_type> operator-(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Subtraction
//    Binary_integer_repr<Int_type> operator-(const Binary_integer_repr<Int_type> &lhs); // Unary minus
//    ContainedInteger_repr<Int_type>* operator&(const Binary_integer_repr<Int_type> &lhs); // Address of
//    Binary_integer_repr<Int_type> operator&(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Bitwise and
//    Binary_integer_repr<Int_type> operator~(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Bitwise complement
//    Binary_integer_repr<Int_type> operator^(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Bitwise exclusive or
//    Binary_integer_repr<Int_type> operator|(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Bitwise or
//    Binary_integer_repr<Int_type> operator/(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Division
//    Binary_integer_repr<Int_type> operator<<(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Left shift
//    Binary_integer_repr<Int_type> operator*(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Multiplication
//    ContainedInteger_repr<Int_type> &operator*(const Binary_integer_repr<Int_type> &lhs); // Dereference
//    Binary_integer_repr<Int_type> operator%(const Binary_integer_repr<Int_type> &lhs, const Binary_integer_repr<Int_type> &rhs); // Remainder
};

template<typename Integer_type = int>
std::ostream& operator<<(std::ostream& os, const Binary_integer_repr<Integer_type>& ir)
{
    os << ir.repr_;
    return os;
}

template<typename Int_type>
Binary_integer_repr<Int_type> operator>>(const Binary_integer_repr<Int_type>& lhs, const Binary_integer_repr<Int_type>& rhs)
{
    Binary_integer_repr<Int_type> tmp{lhs.val_.o_};
    tmp.val_.o_ >>= static_cast<int>(rhs.val_.o_);
    tmp.repr_ = tmp.val_.i_;
    return tmp;
} // Right shift

template<typename Int_type>
Binary_integer_repr<Int_type> operator>>(const Binary_integer_repr<Int_type>& lhs, const int& rhs)
{
    Binary_integer_repr<Int_type> tmp{lhs.val_.o_};
    tmp.val_.o_ >>= static_cast<int>(rhs);
    tmp.repr_ = tmp.val_.i_;
    return tmp;
} // Right shift

#endif //INTEGER_REPR_H

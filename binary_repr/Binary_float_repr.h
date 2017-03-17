#ifndef FLOAT_REPR_H
#define FLOAT_REPR_H

#include "uint_type.h"

template<typename T, typename Enable = void>
class Binary_float_repr {};

template<typename Float_type>
class Binary_float_repr<Float_type, typename std::enable_if<std::is_floating_point<Float_type>::value>::type> {
    using Unsigned_integer_type = typename __impl::__Unsigned_integer_type<sizeof(Float_type) * CHAR_BIT>::type;
    union Float_int {
        Float_type f_;
        Unsigned_integer_type i_;
    };

    Float_int val_;
    std::bitset<sizeof(Float_type) * CHAR_BIT> repr_;

    template<typename T>
    friend
    std::ostream& operator<<(std::ostream& os, const Binary_float_repr<T>& fr);

    template<typename T>
    friend
    Binary_float_repr<Float_type> operator>>(const Binary_float_repr<T>& lhs, const Binary_float_repr<T>& rhs);

    template<typename T>
    friend
    Binary_float_repr<T> operator>>(const Binary_float_repr<T>& lhs, const int& rhs);

public:
    explicit Binary_float_repr(Float_type value)
    {
        val_.f_ = value;
        repr_ = val_.i_;
    }

//    Binary_float_repr<Float_type>& operator&=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs)
//    {
//        lhs.val_.f_ &= rhs.val_.f_;
//        lhs.repr_ = lhs.val_.i_;
//        return lhs;
//    }; // Assign bitwise and
//
//    Binary_float_repr<Float_type>& operator&=(Binary_float_repr<Float_type>& lhs, const int& rhs)
//    {
//        lhs.val_.f_ &= rhs;
//        lhs.repr_ = lhs.val_.i_;
//        return lhs;
//    }; // Assign bitwise and

//    Binary_float_repr<Float_type>& operator^=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign exclusive or
//    Binary_float_repr<Float_type>& operator|=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign bitwise or
//    Binary_float_repr<Float_type>& operator-=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign difference
//    Binary_float_repr<Float_type>& operator<<=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign left shift
//    Binary_float_repr<Float_type>& operator*=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign product
//    Binary_float_repr<Float_type>& operator/=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign quotient
//    Binary_float_repr<Float_type>& operator%=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign remainder
//    Binary_float_repr<Float_type>& operator>>=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign right shift
//    Binary_float_repr<Float_type>& operator+=(Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Assign sum
////Other modification operators
//    Binary_float_repr<Float_type>& operator--(Binary_float_repr<Float_type>& lhs); // Prefix decrement - decrement and return new value
//    Binary_float_repr<Float_type> operator--(Binary_float_repr<Float_type>& lhs, int unused); // Postfix decrement - decrement and return copy of old value
//    Binary_float_repr<Float_type>& operator++(Binary_float_repr<Float_type>& lhs); // Prefix increment - increment and return new value
//    Binary_float_repr<Float_type> operator++(Binary_float_repr<Float_type>& lhs, int unused); // Postfix increment - increment and return copy of old value
//
////Comparison operators
//    bool operator==(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Equal
//    bool operator>(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Greater than
//    bool operator>=(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Greater than or equal
//    bool operator<(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // less than
//    bool operator<=(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // less than or equal
//    bool operator!(const Binary_float_repr<Float_type>& lhs); // logical complement
//    bool operator!=(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // no equal
//
////Other operators
//    Binary_float_repr<Float_type> operator+(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Addition
//    Binary_float_repr<Float_type> operator+(const Binary_float_repr<Float_type>& lhs); // Unary plus
//    Binary_float_repr<Float_type> operator-(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Subtraction
//    Binary_float_repr<Float_type> operator-(const Binary_float_repr<Float_type>& lhs); // Unary minus
//    ContainedFloat_repr <Float_type>* operator&(const Binary_float_repr<Float_type>& lhs); // Address of
//    Binary_float_repr<Float_type> operator&(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Bitwise and
//    Binary_float_repr<Float_type> operator~(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Bitwise complement
//    Binary_float_repr<Float_type> operator^(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Bitwise exclusive or
//    Binary_float_repr<Float_type> operator|(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Bitwise or
//    Binary_float_repr<Float_type> operator/(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Division
//    Binary_float_repr<Float_type> operator<<(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Left shift
//    Binary_float_repr<Float_type> operator*(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Multiplication
//    ContainedFloat_repr <Float_type>& operator*(const Binary_float_repr<Float_type>& lhs); // Dereference
//    Binary_float_repr<Float_type> operator%(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs); // Remainder
};

template<typename Float_type = float>
std::ostream& operator<<(std::ostream& os, const Binary_float_repr<Float_type>& fr)
{
    os << fr.repr_;
    return os;
}

template<typename Float_type>
Binary_float_repr<Float_type> operator>>(const Binary_float_repr<Float_type>& lhs, const Binary_float_repr<Float_type>& rhs)
{
    Binary_float_repr<Float_type> tmp{lhs.val_.f_};
    tmp.val_.i_ >>= static_cast<int>(rhs.val_.f_);
    tmp.repr_ = tmp.val_.i_;
    return tmp;
}; // Right shift

template<typename Float_type>
Binary_float_repr<Float_type> operator>>(const Binary_float_repr<Float_type>& lhs, const int& rhs)
{
    Binary_float_repr<Float_type> tmp{lhs.val_.f_};
    tmp.val_.i_ >>= rhs;
    tmp.repr_ = tmp.val_.i_;
    return tmp;
}; // Right shift

#endif //FLOAT_REPR_H

#ifndef INTEGER_TYPE_H
#define INTEGER_TYPE_H

namespace __impl {
    template<int size> struct __Unsigned_integer_type;
    template<> struct __Unsigned_integer_type<8> { using type = uint8_t; };
    template<> struct __Unsigned_integer_type<16> { using type = uint16_t; };
    template<> struct __Unsigned_integer_type<32> { using type = uint32_t; };
    template<> struct __Unsigned_integer_type<64> { using type = uint64_t; };
};

#endif //INTEGER_TYPE_H

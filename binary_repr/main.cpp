#include<iostream>
#include<limits>

#include "uint_type.h"
#include "Binary_integer_repr.h"
#include "Binary_float_repr.h"

//std::bitset<sizeof(float)*CHAR_BIT> foo(*reinterpret_cast<unsigned long*>(&f));

int main()
{
    std::cout << Binary_float_repr<double>(4.322) << "\n";
    std::cout << (Binary_float_repr<double>(4.322) >> 2) << "\n";
    std::cout << Binary_integer_repr<uint32_t>(87) << "\n";
    std::cout << (Binary_integer_repr<uint32_t>(87) >> 2) << "\n";
    return 0;
}

// 0 10000000001 0001010010011011101001011110001101010011111101111101
// 0 10000000001 0001010010011011101001011110001101010011111101111101
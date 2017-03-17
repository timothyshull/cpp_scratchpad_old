//
// Created by Timothy Shull on 12/25/15.
//

#include "8_13.h"
#include <iostream>

Score& Score::operator++() {
    ++score_;
    return *this;
}

const Score& Score::operator++(int i) {
    Score tmp{*this};
    ++(*this);
    return tmp;
}


Score& Score::operator--() {
    --score_;
    return *this;
}


const Score& Score::operator--(int i) {
    Score tmp{*this};
    --(*this);
    return tmp;
}

void testScore() {
    Score player1{50};
    player1++;
    std::cout << "Score = " << player1.getScore() << std::endl;
    (--player1)--;
    std::cout << "Score = " << player1.getScore() << std::endl;
}

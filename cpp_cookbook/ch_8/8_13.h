//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_13_H
#define CPP_COOKBOOK_8_13_H

class Score {
    int score_;

public:
    Score() : score_{0} { }

    Score(int score) : score_(score) { }

    Score& operator++();

    const Score& operator++(int);

    Score& operator--();

    const Score& operator--(int);


    int getScore() const {
        return score_;
    }
};

void testScore();

#endif //CPP_COOKBOOK_8_13_H

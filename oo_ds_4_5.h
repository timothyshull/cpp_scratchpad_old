//
// Created by Timothy Shull on 12/26/15.
//

#ifndef CPP_OO_DATA_STRUCTURES_4_5_H
#define CPP_OO_DATA_STRUCTURES_4_5_H

#include <vector>

class TowersOfHanoi {
private:
    using poleNo = int;
    using diskNo = int;
    using poleHeight = int;
    using PolePtr = struct PoleWithDisks {
        std::vector<diskNo> diskArray;
        diskNo ringHeight;
        poleNo poleNum;
    }*;

    int maxDisks;
    int maxHeight;
    int maxDiskNo;
    PolePtr polePtr1, polePtr2, polePtr3;
public:
    PoleWithDisks pole1, pole2, pole3;

    TowersOfHanoi(int);

    ~TowersOfHanoi();

    void buildAndInitPoles();

    void moveDisk(PolePtr, PolePtr);

    void solve1Hanoi(diskNo, PolePtr, PolePtr, PolePtr);

    void solveHanoi(int);;

    void drawPole(PoleWithDisks);

    constexpr int getMaxDisks() const { return maxDisks; }
};

void testHanoi();

#endif //CPP_OO_DATA_STRUCTURES_4_5_H

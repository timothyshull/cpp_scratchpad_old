//
// Created by Timothy Shull on 12/26/15.
//

#include "4_5.h"
#include <iostream>

TowersOfHanoi::TowersOfHanoi(int maxDisksIn) {
    maxDisks = maxDisksIn;
    maxDiskNo = maxDisks - 1;
    maxHeight = maxDisks;

    pole1.diskArray.reserve(static_cast<size_t>(maxDisks));
    pole2.diskArray.reserve(static_cast<size_t>(maxDisks));
    pole3.diskArray.reserve(static_cast<size_t>(maxDisks));
}


TowersOfHanoi::~TowersOfHanoi() {
//    delete pole1.diskArray;
//    delete pole2.diskArray;
//    delete pole3.diskArray;
}


void TowersOfHanoi::buildAndInitPoles() {
    int initVal = maxDisks - 1;

    for (int i = 0; i < maxDisks; i++) {
        pole1.diskArray[i] = initVal;
        pole2.diskArray[i] = 0;
        pole3.diskArray[i] = 0;
    }
    pole1.ringHeight = initVal;
    pole1.poleNum = 1;
    pole2.ringHeight = 0;
    pole2.poleNum = 2;
    pole3.ringHeight = 0;
    pole3.poleNum = 3;

    polePtr1 = &pole1;
    polePtr2 = &pole2;
    polePtr3 = &pole3;
}


void TowersOfHanoi::moveDisk(TowersOfHanoi::PolePtr fromPole, TowersOfHanoi::PolePtr toPole) {
    diskNo currentDiskNo{fromPole->diskArray[fromPole->ringHeight]};

    poleHeight oldHeight = fromPole->ringHeight;

    fromPole->diskArray[oldHeight] = 0;
    fromPole->ringHeight = oldHeight - 1;

    poleHeight newHeight = toPole->ringHeight + 1;

    toPole->ringHeight = newHeight;
    toPole->diskArray[newHeight] = currentDiskNo;
}

void TowersOfHanoi::solve1Hanoi(TowersOfHanoi::diskNo noOfDisks, TowersOfHanoi::PolePtr startPole,
                                TowersOfHanoi::PolePtr finishPole,
                                TowersOfHanoi::PolePtr tempPole) {
    if (noOfDisks > 0) {
        solve1Hanoi(noOfDisks - 1, startPole, tempPole, finishPole);
        moveDisk(startPole, finishPole);
        std::cout << "move disk " << noOfDisks << " from pole " << startPole->poleNum << " to pole " <<
            finishPole->poleNum << "\n";
        solve1Hanoi(noOfDisks - 1, tempPole, finishPole, startPole);
    }
}


void TowersOfHanoi::solveHanoi(int noOfDisks) {
    solve1Hanoi(noOfDisks, polePtr1, polePtr3, polePtr2);
    solve1Hanoi(noOfDisks, polePtr3, polePtr2, polePtr1);
}


void TowersOfHanoi::drawPole(TowersOfHanoi::PoleWithDisks pole) {
    static std::vector<std::string> polePicture = {
            "               ",
            "               ",
            "       --      ",
            "       01      ",
            "      ----     ",
            "      02       ",
            "     ------    ",
            "     03        ",
            "    --------   ",
            "    04         ",
            "   ----------  ",
            "   05          ",
            "  ------------ ",
    };

    std::cout << "\n";

    for (auto i : pole.diskArray) {
        diskNo currentDiskNum = i;

        switch (i) {
            case 0:
                std::cout << polePicture[0] << "\n" << polePicture[1] << "\n";
                break;
            case 1:
                std::cout << polePicture[0] << "\n" << polePicture[1] << "\n" << polePicture[2] << "\n" <<
                polePicture[3] << "\n";
                break;
            case 2:
                std::cout << polePicture[4] << "\n" << polePicture[5] << "\n";
                break;
            case 3:
                std::cout << polePicture[6] << "\n" << polePicture[7] << "\n";
                break;
            case 4:
                std::cout << polePicture[8] << "\n" << polePicture[9] << "\n";
                break;
            case 5:
                std::cout << polePicture[10] << "\n" << polePicture[11] << "\n";
                break;
        }
    }

    std::cout << "  ============ \nPole" << pole.poleNum << std::endl;
}

void testHanoi() {
    TowersOfHanoi hanoiObj{6};
    int maxDiskNo = hanoiObj.getMaxDisks() - 1;
    std::cout << "OOP Towers of Hanoi with recursion.\n";
    hanoiObj.buildAndInitPoles();
    std::cout << "States of poles before moves: \n";
    hanoiObj.drawPole(hanoiObj.pole1);
    hanoiObj.drawPole(hanoiObj.pole2);
    hanoiObj.solveHanoi(maxDiskNo);
    std::cout << "\nStates of poles after move: \n";
    hanoiObj.drawPole(hanoiObj.pole1);
    hanoiObj.drawPole(hanoiObj.pole2);
}

// Programming Projects Ch1, problem 1

#include <iostream>

using namespace std;

const double OZ_TO_METRIC_TON = 35273.92;

int main() {
    double cerealWtInOz;

    cout << "Please enter the weight of your cereal box in ounces: " << endl;
    cin >> cerealWtInOz;

    cout << "The weight of your cereal box in metric tons is: " << cerealWtInOz / OZ_TO_METRIC_TON << endl;
    cout << "It would take " << 1 / (cerealWtInOz / OZ_TO_METRIC_TON) << " boxes of cereal to make one metric ton of cereal" << endl;

    return 0;
}
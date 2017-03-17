#include <iostream>

double calc_inflation(double old_val, double new_val);

void prompt_input();

int main() {
    std::cout << "Calculate miles per gallon...\n";
    while (!std::cin.eof()) {
        prompt_input();
    }
    return 0;
}

double calc_inflation(double old_val, double new_val) {
    return (new_val - old_val) / old_val;
}

void prompt_input() {
    std::cout << "Enter old price: ";
    std::string line1;
    std::getline(std::cin, line1);

    std::cout << "Enter new price: ";
    std::string line2;
    std::getline(std::cin, line2);

    double prev_price = std::stod(line1);
    double curr_price = std::stod(line2);

    std::cout << calc_inflation(prev_price, curr_price) << std::endl;
}


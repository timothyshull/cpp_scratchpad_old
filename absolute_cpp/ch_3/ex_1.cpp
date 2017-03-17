#include <iostream>

const double liter_to_gallon{0.264179};

double get_mpg(double liters, int miles);

void prompt_input();

int main() {
    std::cout << "Calculate miles per gallon...\n";
    while (!std::cin.eof()) {
        prompt_input();
    }
    return 0;
}

double get_mpg(double liters, int miles) {
    double gallons = liters * (1.0 / liter_to_gallon);
    return miles / gallons;
}

void prompt_input() {
    std::cout << "Enter liters of gasoline consumed: ";
    std::string line1;
    std::getline(std::cin, line1);

    std::cout << "Enter miles traveled: ";
    std::string line2;
    std::getline(std::cin, line2);

    double input_liters = std::stod(line1);
    int input_miles = std::stoi(line2);

    std::cout << get_mpg(input_liters, input_miles) << std::endl;
}


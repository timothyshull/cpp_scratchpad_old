#include <iostream>

double calc_inflation(double old_val, double new_val);

double simple_interest(double principal, double interest, int time);

void prompt_input();

int main() {
    std::cout << "Calculate estimated interest...\n";
    while (!std::cin.eof()) {
        prompt_input();
    }
    return 0;
}

double calc_inflation(double old_val, double new_val) {
    return (new_val - old_val) / old_val;
}

double simple_interest(double principal, double interest, int time) {
    return principal * (1.0 + interest * time);
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
    double int_rate = calc_inflation(prev_price, curr_price);

    std::cout << "The estimated interest rate is: " << int_rate << std::endl;
    std::cout << "The estimated price one year from now is: " << simple_interest(curr_price, int_rate, 1) << std::endl;
    std::cout << "The estimated price two years from now is: " << simple_interest(curr_price, int_rate, 2) << std::endl;
}



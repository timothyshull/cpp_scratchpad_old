#include <iostream>

enum State {
    STATE_STANDING,
    STATE_JUMPING,
    STATE_DUCKING,
    STATE_DIVING
};

int main() {
    enum State state1 = STATE_STANDING;
    enum State state2 = STATE_JUMPING;
    enum State state3 = STATE_DUCKING;
    enum State state4 = STATE_DIVING;
    std::cout << state1 << std::endl;
    std::cout << state2 << std::endl;
    std::cout << state3 << std::endl;
    std::cout << state4 << std::endl;
    std::cout << sizeof(State) << std::endl;
    std::cout << sizeof(state1) << std::endl;
    return 0;
}
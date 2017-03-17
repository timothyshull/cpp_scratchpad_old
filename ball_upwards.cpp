#include <cassert>

class Ball {
    constexpr static double g = 9.81;
public:
    // simpler solution
    // return static_cast<int>(std::round(static_cast<double>(v0 / 3.6) / 0.981));

    static int maxBall(int v0)
    {
        auto v = v0 * (1000.0 / 3600.0);
        double max = 0.0;
        auto t = 1;
        while (true) {
            auto t0 = t / 10.0;
            auto h = (v * t0) - (0.5 * g * t0 * t0);
            if (h < max) {
                --t;
                break;
            }
            max = h;
            ++t;
        }
        return t;
    }
};

int main() {
    auto t = Ball::maxBall(37);
    assert(10 == t);
    t = Ball::maxBall(45);
    assert(13 == t);
    t = Ball::maxBall(99);
    assert(28 == t);
    t = Ball::maxBall(85);
    assert(24 == t);
    return 0;
}
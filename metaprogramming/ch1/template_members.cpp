
struct mathematics {
    template<typename scalar_t>
    scalar_t sq(scalar_t x) const {
        return x * x;
    }
};

// class template with template member function
template<typename scalar_t>
struct more_mathematics {
    template<typename other_t>
    static scalar_t product(scalar_t x, int y) {
        return x * y;
    }
};

int main() {
    double a = mathematics().sq(3.14);
    double b = more_mathematics<double>().product(3.14, 5);
    return 0;
}
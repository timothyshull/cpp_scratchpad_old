template<bool STATEMENT>
struct static_assertion {
};
template<>
struct static_assertion<false>;

int main() {
    static_assertion<sizeof(int) == 314> ASSERT_LARGE_INT;
    return 0;
}

template<bool STATEMENT>
struct static_assertion;

template<>
struct static_assertion<true> {
    static_assertion() {}

    template<typename T>
    static_assertion(T) {}
};

template<>
struct static_assertion<false>;
struct error_CHAR_IS_UNSIGNED {
};

int main() {
    const static_assertion<sizeof(double) != 8> ASSERT1("invalid double");
    const static_assertion<(char(255) > 0)> ASSERT2(error_CHAR_IS_UNSIGNED());
}
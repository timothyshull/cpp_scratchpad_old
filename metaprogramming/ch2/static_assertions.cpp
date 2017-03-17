
template<typename T>
void myfunc() {
    using ERROR_T_DOES_NOT_CONTAIN_type = typename T::type;
    const int ASSERT_T_MUST_HAVE_STATIC_CONSTANT_value(T::value);
};
// check concepts about types
template<typename T1, typename T2>
struct static_assert_can_copy_T1_to_T2 {
    static void concept_check(T1 x, T2 y) {
        T2 z(x);       // T2 must be constructable from T1
        y = x;         // T2 must be assignable from T1
    }

    static_assert_can_copy_T1_to_T2() {
        void (*f)(T1, T2) = concept_check;
    }
};

// use when deriving
template<typename T>
class math_operations : static_assert_can_copy_T1_to_T2<T, double> {
};

// or on the stack
template<typename T>
T sqrt(T x) {
    static_assert_can_copy_T1_to_T2<T, double> CHECK1;
}

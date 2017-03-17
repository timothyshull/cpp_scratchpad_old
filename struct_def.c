#include <stdlib.h>
#include <stdio.h>

int main() {
    // Putting the struct typename before the definition requires subsequent instances to be initialized with
    // struct <typename>
    typedef struct TEST_STRUCT {
        int first;
        float second;
    };

    struct TEST_STRUCT test_struct;

    test_struct.first = 10;
    test_struct.second = 11.0;

    printf("%d\n", test_struct.first);
    printf("%f\n", test_struct.second);

    // Defining a struct with the typename after the definition allows the instance to be created using <typename> <varname>
    typedef struct {
        int first;
        int second;
        int third;
    } new_struct;


    new_struct new_struct1 = {
            first: 10,
            second: 11,
            third: 12
    };

    printf("%d\n", new_struct1.first);
    printf("%d\n", new_struct1.second);
    printf("%d\n", new_struct1.third);
    return 0;
}
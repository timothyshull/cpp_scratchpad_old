#include <stdlib.h>
#include <printf.h>

void func(int **p1, int *p2) {
    *p1 = p2;
}

void func2(int *p) {
    *p = 10;
}


int main(int argc, char *argv[]) {
    int *test = (int *)malloc(sizeof(int));
    *test = 1;
    printf("%d\n", *test);
    int *alias = test;
    int *test2 = (int *)malloc(sizeof(int));
    *test2 = 2;
    printf("%d\n", *test2);
    func(&test, test2);
    printf("%d\n", *test);
    printf("%d\n", *test2);
    func2(test);
    printf("%d\n", *test);
    printf("%d\n", *test2);
    free(test2);
    free(alias);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int bytes_read;
    int nbytes = 100;
    char *my_string;

    puts("Please enter a line of text.");

    /* These 2 lines are the heart of the program. */
    size_t my_string_size = nbytes + 1;
    my_string = (char *) malloc(my_string_size);
    bytes_read = getline(&my_string, (size_t *) &nbytes, stdin);

    if (bytes_read == -1) {
        puts("ERROR!");
    } else {
        puts("You typed:");
        puts(my_string);
    }

    return 0;
}
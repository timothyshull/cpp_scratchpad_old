#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *get_line(void) {
    const size_t size_increment = 10;
    char *buffer = malloc(size_increment);
    char *current_position = buffer;
    size_t maximum_length = size_increment;
    size_t length = 0;
    int character;
    if (current_position == NULL) { return NULL; }
    while (1) {
        character = fgetc(stdin);
        if (character == '\n') { break; }
        if (++length >= maximum_length) {
            char *new_buffer = realloc(buffer, maximum_length += size_increment);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            current_position = new_buffer + (current_position - buffer);
            buffer = new_buffer;
        }
        *current_position++ = (char) character;
    }
    *current_position = '\0';
    return buffer;
}

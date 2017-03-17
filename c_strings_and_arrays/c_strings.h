#ifndef C_STRINGS_AND_ARRAYS_C_STRINGS_H
#define C_STRINGS_AND_ARRAYS_C_STRINGS_H

char *strcat(char *s1, const char *s2) {
    strcpy(&s1[strlen(s1)], s2);
    return s1;
}

char *strcpy(char *s1, const char *s2) {
    char *s = s1;
    while ((*s++ = *s2++) != 0) {}
    return (s1);
}

size_t strlen(const char *s);

char *strncat(char *s1, const char *s2, size_t n) {
    unsigned len1 = strlen(s1);
    unsigned len2 = strlen(s2);

    if (len2 < n) {
        strcpy(&s1[len1], s2);
    } else {
        strncpy(&s1[len1], s2, n);
        s1[len1 + n] = '\0';
    }
    return s1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    for (; n > 0; s1++, s2++, --n) {
        if (*s1 != *s2) {
            return ((*(unsigned char *) s1 < *(unsigned char *) s2) ? -1 : +1);
        } else if (*s1 == '\0') {
            return 0;
        }
    }
    return 0;
}

char *strncpy(char *s1, const char *s2, size_t n) {
    char *s = s1;
    while (n > 0 && *s2 != '\0') {
        *s++ = *s2++;
        --n;
    }
    while (n > 0) {
        *s++ = '\0';
        --n;
    }
    return s1;
}

#endif //C_STRINGS_AND_ARRAYS_C_STRINGS_H

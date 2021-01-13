#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_char_frequency(char *string, char ch) {
    int count = 0;
    while (*string != '\0')
        if (*string++ == ch)
            count++;

    return count;
}

char *remove_non_alpha_characters(char *string) {
    int count = 0;
    char *new_string = (char *) calloc(200, sizeof(char));

    while (*string != '\0') {
        if (isalpha(*string))
            *new_string++ = *string, count++;
        string++;
    }

    *new_string = '\0';
    new_string -= count;
    return new_string;
}

int get_length(char *string) {
    int length = 0;
    while (*string++ != '\0')
        length++;
    return length + 1;
}

char *concat_strings(char *str1, char *str2) {
    int count = 0;
    char *new_string = (char *) calloc(200, sizeof(char));

    while (*str1 != '\0')
        *new_string++ = *str1++, count++;

    while (*str2 != '\0')
        *new_string++ = *str2++, count++;

    *new_string = '\0';
    new_string -= count;

    return new_string;
}

void copy_strings(char *dst, char *src) {

}

_Bool find_substring(char *string) {
    return 0;
}

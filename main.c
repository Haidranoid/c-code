#include <stdio.h>
#include "stringfunctionsshared.h"

int main() {
    char *str1 = {"Hello, "};
    char *str2 = {"My name is eduardo"};
    char *str3 = {"Hi, Welcome! this is my house."};
    char str4[100];


    printf("length: %i\n", get_length(str2));
    printf("concatenated: %s\n", concat_strings(str1, str2));
    printf("only alpha: %s\n", remove_non_alpha_characters(str3));
    printf("char frequency: %i\n", get_char_frequency(str3, 'i'));
    copy_strings(str4, str2);
    printf("string copied: %s\n", str4);
    printf("substring found: %s\n", substring("Antologia de un perro",4,5));

    return 0;
}

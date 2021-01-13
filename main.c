#include <stdio.h>
#include "libraries/string-functions/StringFunctions.h"

int main() {
    char *str1 = {"Hello, "};
    char *str2 = {"My name is eduardo"};
    char *str3 = {"Hi, Welcome! this is my house."};

    printf("length: %i\n", get_length(str2));
    printf("concatenated: %s\n", concat_strings(str1, str2));
    printf("only alpha: %s\n", remove_non_alpha_characters(str3));
    printf("char frequency: %i\n", get_char_frequency(str3, 'i'));

    return 0;
}
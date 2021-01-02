#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int get_length(const char array[]) {
    int count = 0;
    char c = array[0];

    while (c != '\0') {
        count++;
        c = array[count];
    }

    return count;
}

void concatenate(char result[], const char str1[], const char str2[]) {
    int str1_length = get_length(str1);
    int str2_length = get_length(str2);
    int pos = 0;

    for (int i = 0; i < str1_length; ++i)
        result[pos++] = str1[i];

    for (int i = 0; i < str2_length; ++i)
        result[pos++] = str2[i];

    printf("String concatenated: %s\n", result);

}

bool compare_str(const char str1[], const char str2[]) {
    int str1_count = get_length(str1);
    int str2_count = get_length(str1);

    if (str1_count != str2_count)
        return false;

    for (int i = 0; i < str1_count; ++i)
        if (str1[i] != str2[i])
            return false;

    return true;
}

void reverse_string(char str[]) {
    int length = (int) strlen(str) - 1;
    char reverse_str[length];

    for (int i = length; i >= 0; i--) {
        reverse_str[length - i] = str[i];
    }

    printf("\noriginal: %s", str);
    printf("\nreversed: %s", reverse_str);
}

int challenge_char_arrays(int argc, char *argv[]) {
    // -----------------------------------------------
    char str[] = "This is a new string";

    int count = get_length(str);
    printf("The number of characters is: %i\n", count);

    // -----------------------------------------------
    char result[80];
    const char str1[40] = "My name is jose eduardo";
    const char str2[40] = " martinez lara";

    concatenate(result, str1, str2);
    // -----------------------------------------------
    const char str3[] = "This text should be compared";

    if (compare_str(str3, str3))
        printf("The strings are equal!");
    else
        printf("The string are not equal.");

    // -----------------------------------------------
    char str5[100];

    printf("Introduce the string to be reversed: ");
    scanf("%s", str5);

    reverse_string(str5);

    return 0;
}

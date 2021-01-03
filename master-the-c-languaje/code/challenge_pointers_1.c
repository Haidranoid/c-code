#include <stdio.h>
#include <string.h>

int string_length(const char *string) {
    const char *initial_address = string;

    while (*string)
        string++;

    return (int)(string - initial_address);
}

int challenge_pointers_1(int argc, char *argv[]) {
    const char *string = "hi, my name is eduardo";
    printf("%d", string_length(string));

    return 0;
}

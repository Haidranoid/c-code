#include <stdio.h>
#include <stdbool.h>

int program_arguments(int argc, char *argv[]) {

    int argument_numbers = argc;

    char *argument_1 = argv[0];
    char *argument_2 = argv[1];

    printf("number of arguments: %i", argument_numbers);
    printf("\nargument 1, program name: %s", argument_1);
    printf("\nargument 2, command line: %s", argument_2);

    return 0;
}
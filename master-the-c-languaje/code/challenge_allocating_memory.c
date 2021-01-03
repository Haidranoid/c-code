#include <stdio.h>
#include <stdlib.h>

int challenge_allocating_memory(int argc, char *argv[]) {
    char *string = NULL;
    int bytes;

    printf("Introduce the max number of bytes to use: \n");
    scanf("%i", &bytes);

    string = (char *) malloc(bytes * sizeof(char));
    if (string) {
        printf("Introduce the text: \n");
        scanf(" ");
        gets(string);

        printf("The text introduced was: %s\n", string);

    } else {
        printf("Something went wrong.");
    }

    free(string);
    string = NULL;


    return 0;
}

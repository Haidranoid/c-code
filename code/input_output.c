#include <stdio.h>

int input_output() {

    char str[100];
    double i;

    printf("Enter a value: ");
    scanf("%s %lf", str, &i);

    printf("\nYou entered: %s %lf", str, i);
    getchar();

    return 0;
}
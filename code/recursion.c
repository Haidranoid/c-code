#include <stdio.h>

int factorial(int n) {
    int fac = 0;

    if (n == 1)
        fac = 1;
    else
        fac = n * factorial(n - 1);

    return fac;
}

int sum(int n) {
    int total = 0;

    if (n == 1)
        total = 1;
    else
        total = n + sum(n - 1);

    return total;
}

int recursion(int argc, char *argv[]) {

    printf("factorial 5: %i\n", factorial(5));
    printf("sum 1 - 5: %i\n", sum(5));
    return 0;
}
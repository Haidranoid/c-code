#include <stdio.h>

int challenge_prime_numbers(int argc, char *argv[]) {

    int numbers[100] = {0};

    numbers[1] = 2;
    numbers[2] = 3;

    for (int i = 4; i < 100; i++) {
        for (int j = 2; j <= i; j++) {
            if (j == i) {
                numbers[i - 1] = i;  // it's prime number
                break;
            }
            if ((i % j == 0))
                break; // it's not a prime number
        }
    }

    for (int i = 0; i < 100; i++) {
        if (numbers[i] != 0)
            printf("%i ", numbers[i]);
    }


    return 0;
}
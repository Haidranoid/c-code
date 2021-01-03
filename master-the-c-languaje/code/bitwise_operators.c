#include <stdio.h>
#include <stdlib.h>

int bitwise_operators(int argc, char *argv[]) {

    unsigned int a = 60; //0011 1100
    unsigned int b = 13; //0000 1101

    printf("a : %i\n", a); // 1100 0011 - 60
    printf("b : %i\n", b); // 1100 0011 - 13

    printf("a & b: %i\n", a & b); // 0000 1100 - 12
    printf("a | b: %i\n", a | b); // 0011 1101 - 61
    printf("a ^ b: %i\n", a ^ b); // 0011 0001 - 49

    printf("~a : %i\n", ~a); // 1100 0011 - 195 / -61
    printf("~b : %i\n", ~b); // 1111 0010 - 242 / -14

    printf("a << 2: %i\n", a << 2); // 1111 0000 - 240
    printf("a >> 2: %i\n", a >> 2); // 0000 1111 - 15

    printf("b << 2: %i\n", b << 2); // 0011 0100 - 52
    printf("b >> 2: %i\n", b >> 2); // 0000 0011 - 3

    return 0;
}
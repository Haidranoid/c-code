#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int convertBinaryToDecimal(long long n) {
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

char *convertDecimalToBinary(int n) {
    char *binaryNumber = (char *) calloc(9, sizeof(char));

    for (int i = 0; i < 8; i++)
        binaryNumber[i] = '0';

    for (int i = 0; n > 0; i++) {
        binaryNumber[7 - i] = (n % 2) + '0';
        n = n / 2;
    }

    binaryNumber[8] = '\0';
    printf("%s\n",binaryNumber);

    free(binaryNumber);
    binaryNumber = NULL;

    return binaryNumber;
}

int main(int argc, char *argv[]) {
    int flags = 0b10110110; // 182 - 1011 0110
    int _mask = 0b00001111; // 15  - 0000 1111

    int flags1 = 0b10101111; //
    int _mask1 = 0b00101011; //

    int c;

    // keeping certain bits - using AND
    c = flags & _mask; // 0000 0110
    convertDecimalToBinary(c);

    // turning bits On - using OR
    c = flags | _mask; // 1011 1111
    convertDecimalToBinary(c);

    // turning bits Off  - using & and ~
    c = flags & ~(_mask); // 1011 0000
    convertDecimalToBinary(c);

    // toggling bits using ^
    c = flags ^ _mask; // 1011 1001
    convertDecimalToBinary(c);

    // checking the value of the bits based on mask
    if ((flags1 & _mask1) == _mask1)
        printf("The bits are equal!\n");


    return 0;
}
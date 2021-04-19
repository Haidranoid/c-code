#include <stdio.h>
#include <stdlib.h>

char *convertDecimalToBinary8(uint8_t n) {
    char *binaryNumber = (char *) calloc(9, sizeof(char));

    binaryNumber[8] = '\0';
    for (int i = 0; i < 8; i++)
        binaryNumber[i] = '0';

    for (int i = 0; n > 0; i++) {
        binaryNumber[7 - i] = (n % 2) + '0';
        n = n / 2;
    }

    printf("%s\n",binaryNumber);

    free(binaryNumber);
    binaryNumber = NULL;

    return binaryNumber;
}

int bitmasks(int argc, char *argv[]) {
    int flags = 0b10110110; // 182 - 1011 0110
    int _mask = 0b00001111; // 15  - 0000 1111

    int flags1 = 0b10101111; //
    int _mask1 = 0b00101011; //

    int c;

    // keeping certain bits - using AND
    c = flags & _mask; // 0000 0110
    convertDecimalToBinary8(c);

    // turning bits On - using OR
    c = flags | _mask; // 1011 1111
    convertDecimalToBinary8(c);

    // turning bits Off  - using & and ~
    c = flags & ~(_mask); // 1011 0000
    convertDecimalToBinary8(c);

    // toggling bits using ^
    c = flags ^ _mask; // 1011 1001
    convertDecimalToBinary8(c);

    // checking the value of the bits based on mask
    if ((flags1 & _mask1) == _mask1)
        printf("The bits are equal!\n");


    return 0;
}
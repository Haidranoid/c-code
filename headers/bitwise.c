#include "bitwise.h"

char *convertDecimalToBinary32(uint32_t n, uint8_t divider) {
    char *binaryNumber = (char *) calloc(33, sizeof(char));

    binaryNumber[32] = '\0';
    for (int i = 0; i < 32; i++)
        binaryNumber[i] = '0';

    for (int i = 0; n > 0; i++) {
        binaryNumber[31 - i] = (n % 2) + '0';
        n = n / 2;
    }

    for (int i = 0; i < 32; i++)
        if (i % divider == 0 && i != 0)
            printf(" %c", binaryNumber[i]);
        else
            printf("%c", binaryNumber[i]);
    printf("\n\n");

    free(binaryNumber);
    binaryNumber = NULL;

    return binaryNumber;
}
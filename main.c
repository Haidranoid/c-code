#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");

    free(binaryNumber);
    binaryNumber = NULL;

    return binaryNumber;
}

int main(int argc, char *argv[]) {
    // setting data -----------------------------------------
    uint32_t packed_data = 0;
    printf("sizeof packed_data: %zd bits\n", (sizeof(packed_data) * 8));

    // 7 - 0000 0111
    packed_data |= 0b111 << 18;
    printf("inserting number 7\n");
    convertDecimalToBinary32(packed_data, 14);
    packed_data = 0;

    // to ensure that n is between 0 and 255, apply AND gate with 0xFF - 255 before it is shifted
    int number1 = 129; // 1000 0001
    int number2 = 402; // overflow

    packed_data |= number1 << 18;
    printf("inserting number 129\n");
    convertDecimalToBinary32(packed_data, 14);
    packed_data = 0;

    // OVERFLOW
    packed_data |= number2 << 18;
    printf("inserting number 402 (overflow)\n");
    convertDecimalToBinary32(packed_data, 14);
    packed_data = 0;

    // Using mask to avoid overflow, 0xFF or 255
    packed_data |= (number2 & 0xFF) << 18;
    printf("inserting number 402 (overflow controlled)\n");
    convertDecimalToBinary32(packed_data, 14);

    // getting data -----------------------------------------
    packed_data = 0;
    packed_data |= (215 & 0xFF) << 18;
    uint8_t n = (packed_data >> 18) & 0b11111111;
    printf("%i", n);

    return 0;
}
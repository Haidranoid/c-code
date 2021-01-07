#include <stdio.h>
#include <stdlib.h>
#include "../headers/bitwise.h"

#define MASK_32_BITS 0xffffffff

int challenge_pack_data(int argc, char *argv[]) {
    uint32_t *number = (uint32_t *) malloc(sizeof(uint32_t));
    uint8_t *number_bit = (uint8_t *) malloc(sizeof(uint8_t));
    uint32_t *number_shifted = (uint32_t *) malloc(sizeof(uint32_t));
    *number_shifted = 1;


    printf("Introduce a number: ");
    scanf("%u", number);

    *number &= MASK_32_BITS;
    convertDecimalToBinary32(*number, 8);

    printf("Introduce the number of bit to turn on (0-31): ");
    scanf("%hhd", number_bit);

    *number_shifted <<= *number_bit;

    convertDecimalToBinary32(*number_shifted, 8);

    printf("Number before setting on %i bit: %i\n", *number_bit, *number);
    convertDecimalToBinary32(*number, 8);

    *number |= *number_shifted;

    printf("Number after setting on %i bit: %i\n", *number_bit, *number);
    convertDecimalToBinary32(*number, 8);

    free(number);
    free(number_bit);

    return 0;
}
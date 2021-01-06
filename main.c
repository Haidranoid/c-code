#include <stdio.h>
#include <math.h>

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

long long convertDecimalToBinary(int n) {
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n != 0) {
        remainder = n % 2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }

    return binaryNumber;

}

int main(int argc, char *argv[]) {
    int flags = 0b00001111; // 15 - 0000 1111
    int mask = 0b10110110; // 182 - 1011 0110

    // turning bits On using OR
    flags = flags | mask; // 1011 1111

    // turning bits Off using & and ~
    flags = flags & ~(mask); // 0000 1001



    return 0;
}
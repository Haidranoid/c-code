#include <stdio.h>
#include <memory.h>

void display_array(int array[], int lng) {
    for (int i = 0; i < lng; i++) {
        printf("%i: %i\n", i, array[i]);
    }
}

void function_memset(){
    //    int numbers[100] = {0, 1, 2, [3 ... 99] = 10, [10] = 100};
    int numbers[100];
    printf("%zd\n", sizeof(numbers));
    //    memset(numbers, 0, 100 * sizeof(int));
    memset(numbers, 0, sizeof(numbers));

    display_array(numbers, 100);

}

int main(int argc, char *argv[]) {
    unsigned int a = 60;	/* 60 = 0011 1100 */
    unsigned int b = 13;	/* 13 = 0000 1101 */
    int c = 0;

    c = a & b;       /* 12 = 0000 1100 */
    printf("Line 1 - Value of c is %d\n", c );

    c = a | b;       /* 61 = 0011 1101 */
    printf("Line 2 - Value of c is %d\n", c );

    c = a ^ b;       /* 49 = 0011 0001 */
    printf("Line 3 - Value of c is %d\n", c );

    c = ~a;          /*-61 = 1100 0011 */
    printf("Line 4 - Value of c is %d\n", c );

    c = a << 2;     /* 240 = 1111 0000 */
    printf("Line 5 - Value of c is %d\n", c );

    c = a >> 2;     /* 15 = 0000 1111 */
    printf("Line 6 - Value of c is %d\n", c );

    return 0;
}
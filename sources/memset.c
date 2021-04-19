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
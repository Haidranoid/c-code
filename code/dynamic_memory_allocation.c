#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int dynamic_memory_allocation(int argc, char *argv[]) {

    // malloc
    int *ptr_number = (int *) malloc(25 * sizeof(int));

    if (!ptr_number)
        printf("Cannot allocate memory");


    free(ptr_number);
    ptr_number = NULL;

    // calloc - initialize the memory in 0's
    int *ptr_number_2 = (int *) calloc(25, sizeof(int));

    if (!ptr_number_2)
        printf("Cannot allocate memory");

    free(ptr_number_2);
    ptr_number_2 = NULL;

    // realloc
    char *str;

    // initial memory allocation
    str = (char *) malloc(15);
    strcpy(str, "eduardo");
    printf("Address = %p, String = %s\n", str, str);

    // reallocating memory
    str = (char *) realloc(str, 25);
    strcat(str," martinez lara");
    printf("Address = %p, String = %s\n", str, str);

    free(str);
    str = NULL;

    return 0;
}

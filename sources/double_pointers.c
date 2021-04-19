#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void double_pointers_basics() {
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("address of &a  = %p |  value of a  = %i\n", &a, a);
    printf("address of &p1 = %p |  value of p1 = %p\n", &p1, p1);
    printf("address of &p2 = %p |  value of p2 = %p\n", &p2, p2);
    puts("");
    printf("deferring address of *p1 = %i\n", *p1);
    printf("deferring address of *p2 = %p\n", *p2);
    puts("");
    printf("deferring address of **p2 = %i\n", **p2);
}

// if you want to assign a new value directly
void assign_value_single_pointer(int *ptr) {
    // this pointer have a different address in memory
    // but its value is the same as ptr
    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %i \n", &ptr, ptr, *ptr);
    int a = 5;
    printf("before [ptr = &a]:  ptr = %p  |  &a = %p\n", ptr, &a);
    ptr = &a; // this WONT affect the original pointer because is a copy
    // *ptr = 5; // this WILL affect the value what is pointing to
    printf("after  [ptr = &a]:  ptr = %p  |  &a = %p\n", ptr, &a);

    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %i \n", &ptr, ptr, *ptr);
}

// if you want to assign a new value based on new memory allocation
void assign_value_double_pointer(int **ptr) {
    // this pointer have a different address in memory
    // but its value is the same as ptr
    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %p  |  deferring **ptr = %i \n", &ptr,
           ptr, *ptr, **ptr);

    int a = 5;
    printf("before [*ptr = &a]:  *ptr = %p  |  &a = %p\n", *ptr, &a);
    *ptr = &a; // this WILL affect the value what is pointing to
    printf("after  [*ptr = &a]:  *ptr = %p  |  &a = %p\n", *ptr, &a);

    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %p  |  deferring **ptr = %i \n", &ptr,
           ptr, *ptr, **ptr);
}

void assign_value() {
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = 10;

    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %i \n", &ptr, ptr, *ptr);
//    assign_value_single_pointer(ptr); // the pointer is passing a copy of ptr
    assign_value_double_pointer(&ptr); // the pointer is passing a copy of ptr

    printf("address of &ptr  = %p  |  value of ptr  = %p  |  deferring *ptr = %i \n", &ptr, ptr, *ptr);
}

void allocate_memory_wrong(char *string) {
    string = (char *) calloc(20, sizeof(char));
    strncpy(string, "My name is eduardo", 20);
}

void allocate_memory_right(char **string) {
    *string = (char *) calloc(20, sizeof(char));
    strncpy(*string, "My name is eduardo", 20);
}

int double_pointers(int argc, char *argv[]) {
    char *string = NULL;

//    allocate_memory_wrong(string);
    allocate_memory_right(&string);

//    while (*string != '\0')
//        printf("%c",*string++);
    printf("string: %s", string);

    free(string);
    string = NULL;

    return 0;
}
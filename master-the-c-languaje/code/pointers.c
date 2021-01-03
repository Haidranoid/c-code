#include <stdio.h>
#include <string.h>

void void_pointers() {
    int i = 10;
    float f = 2.34f;
    char ch = 'k';

    void *ptr_void;

    ptr_void = &i;
    printf("Value of i  = %d\n", *(int *) ptr_void);

    ptr_void = &f;
    printf("Value of f  = %.2f\n", *(float *) ptr_void);

    ptr_void = &ch;
    printf("Value of ch  = %c\n", *(char *) ptr_void);
}

void basics_pointers() {
    int variable = 150;

    int *ptr_variable = NULL;
    ptr_variable = &variable;


    // the value that is pointing cannot be changed
    // const int *ptr_variable = NULL;
    //*ptr_variable = 20; // ERROR

    // the address that is using cannot be changed
    //int * const ptr_variable = NULL;
    //ptr_variable = &variable; // ERROR

    printf("Address of variable: %p\n", &variable);
    printf("Address of pointer: %p\n", &ptr_variable);
    printf("Value of the pointer: %p\n", ptr_variable);
    printf("Value pointing to: %i\n", *ptr_variable);
}

void arrays_and_pointers() {

    char multiple[] = "a string";
    char *p = multiple;

    for (int i = 0; i < strlen(multiple); i++) {
        printf("multiple[%d] = %c  *(p+%d) = %c  &multiple[%d] = %p  p+%d = %p\n",
               i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
    }
}

void strings_and_pointers() {

}

void copy_string_array(char to[], const char from[]) {
    int i;
    for (i = 0; from[i] != '\0'; i++)
        to[i] = from[i];

    to[i] = '\0';
}

void copy_string_pointer(char *to, char *from) {
    for (; *from != '\0'; from++, to++) {
        *to = *from;
    }
    *to = '\0';
}

void cpystr(char *to, char *from) {

    while (*from) // the null character is equal to the value 0
        *to++ = *from++;
    *to = '\0';
}

int pointers(int argc, char *argv[]) {
//    void_pointers();
    arrays_and_pointers();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef int (*basic_math_operation)(int, int);

// some random numbers
int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int array2[] = {38, 27, 87, 63, 59, 223, 132, 1, 19, 7};


int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mult(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

/// Array of pointers to functions
basic_math_operation array_functions[4] = {&add, &sub, &mult, &divide};
// INSERT YOUR FUNCTION POINTER INITIALIZATION HERE = { &add,&sub,&mult,&divide };

// performs the given operation on elements of the arrays
int *performOp(const int *a, const int *b, int size, basic_math_operation);

// displays the elements of an array
void display(const int *x, int size);

// main method
int challenge_functions_pointers() {

    int choice = 0;

    // size of the array
    unsigned int size = 0;

    int *result = NULL;

    // set size to minimum size of the two arrays
    size = sizeof(array1);

    if (sizeof(array2) < size)
        size = sizeof(array2);

    size = size / sizeof(int);

    while (choice != 5) {
        printf("\n\nWhich operation do you want to perform? \n");
        printf("1.Add \n");
        printf("2.Subtract \n");
        printf("3.Multiply \n");
        printf("4.Divide \n");
        printf("5.None ... \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;
        if (choice < 1 || choice > 5) continue;

        int j = choice - 1;

        result = performOp(array1, array2, size, array_functions[j]);

        printf("\n\nThe Results are ...\n");
        display(result, size);

        if (result != NULL)
            free(result);
    }

    return 0;
}


// performs the given operation on all elements of the arrays A and B
int *performOp(const int *a, const int *b, int size, basic_math_operation operation) {
    // INCLUDE YOUR CODE HERE
    int *result_array = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i)
        *result_array++ += operation(*a++, *b++);

    return result_array - 10;
}


// function for displaying the results stored in array x
void display(const int *x, int size) {

    for (int i = 0; i < size; ++i)
        printf("%i ", *x++);

    fputc('\n', stdout);
}
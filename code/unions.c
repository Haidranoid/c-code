#include <stdio.h>

struct owner {
    char socsecuritity[12];
};

struct leasecompany {
    char name[40];
    char headquarters[40];
};

struct car_data {
    char make[15];
    int status;
    union { // anonymous union
        struct owner owner_car;
        struct leasecompany leaser_car;
    };
};

/*struct{
    char *name;
    enum symbolType type;
    union {
        int i;
        float f;
        char c;
    }data;
} table[entries];*/

union car {
    int i;
    float f;
    char word[40];
};

union mixed {
    char c;
    float f;
    int i;
};

union mixed x;

union number {
    int x;
    double y;
};

void foo(union number n) {
    union number x = n;
}

int unions(int argc, char *argv[]) {

/*
    union car car1, car2, *car3;
    printf("Memory size occupied by data: %zu\n", sizeof(union car));
*/

/*    x.c = 'J';
    printf("Character = %c\n", x.c);

    x.f = 784.3323f;
    printf("Float = %.4f\n", x.f);

    x.i = 16;
    printf("Int = %i\n", x.i);
*/

/*
    union number value = {.x = 15}; // initialize x

    value.x = 100;
    printf("Value of integer x: %d\n", value.x);
    printf("Value of double y: %f\n", value.y);

    puts("");

    value.y = 100.00;
    printf("Value of integer x: %d\n", value.x);
    printf("Value of double y: %f\n", value.y);
*/

    union number x;
    union number *y = &x;

    y->y = 10;
    printf("Value of integer x: %d\n", y->x);
    printf("Value of double y: %f\n", y->y);

    printf("%zu", sizeof(double));

    return 0;
}
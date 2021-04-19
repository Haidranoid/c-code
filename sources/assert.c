#include <stdio.h>
#include <math.h>
#include <limits.h>

// SWITCH OFF RUNTIME ASSERTIONS
//#define NDEBUG
// SWITCH ON ASSERTIONS
#undef NDEBUG

#include <assert.h>

void test1() {
    int y = 5;

    for (int x = 0; x < 20; ++x) {
        printf("x = %d y = %d\n", x, y);
        assert(x < y);
    }
}

void test2() {
    double x, y, z;

    puts("Enter a pair of numbers (0 0 to quit); ");
    while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("Anser is %f\n", sqrt(2));
        puts("Next pair of numbers: ");
    }
    puts("Done");
}

//static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
void test3() {
    puts("char is 16 bits.");
}

int asserts() {
    return 0;
}
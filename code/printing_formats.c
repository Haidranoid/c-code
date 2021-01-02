#include <stdio.h>
#include <stdbool.h>

int printing_formats() {
    int int_var = 100;
    float float_var = 334.734346;
    double double_var = 8.44e+11;
    char char_var = 'v';

    bool x = true;
    _Bool y = 0;

    printf("int_var = %i\n", int_var);
    printf("float_var = %f\n", float_var);
    printf("float_var = %.2f\n", float_var);
    printf("double_var = %e\n", double_var);
    printf("double_var = %g\n", double_var);
    printf("char_var = %c\n", char_var);

    printf("bool_var = %i\n", x);
    printf("bool_var = %i\n", y);

    fprintf(stdout, x ? "true" : "false");
    return 0;
}
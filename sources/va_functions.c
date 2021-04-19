#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double average(double v1, double v2, ...);

double sample_stddev(int n_args, ...);

int va_functions(int argc, char *argv[]) {

    // va function with sentinel
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;
    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n", average((double) num2, v2, (double) num1, (double) num4, (double) num3, 0.0));

    // va function with n_args
    printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
    return 0;
}

double average(double v1, double v2, ...) {

    va_list args;
    va_start(args, v2);

    int count = 2;
    double sum = v1 + v2;
    double arg = va_arg(args, double);

    while (arg != 0.0) {
        sum += arg;
        ++count;
        arg = va_arg(args, double);
    }

    va_end(args);
    return sum / count;
}

double sample_stddev(int n_args, ...) {
    va_list args1;
    va_list args2;

    va_start(args1, n_args);
    va_copy(args2, args1);

    // first list
    double sum = 0;

    for (int i = 0; i < n_args; i++) {
        double arg = va_arg(args1, double);
        sum += arg;
    }

    va_end(args1); // you need to end first list to use the copy

    double mean = sum / n_args; // average

    // second list
    double sum_sq_diff = 0;

    for (int i = 0; i < n_args; i++) {
        double arg = va_arg(args2, double);
        sum_sq_diff += (arg - mean) * (arg - mean);
    }

    va_end(args2);

    return sqrt(sum_sq_diff / n_args);
}
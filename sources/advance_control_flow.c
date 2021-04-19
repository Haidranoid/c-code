#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void null_statement() {
    int i = 0;

    for (; i < 10; i++) { // null statement
        printf("%i ", i);
    }
}

void goto_keyword() {
    const int maxInput = 5;
    int i = 0;
    double number, average, sum = 0.0;

    for (; i < maxInput; i++) { // null statement
        printf("%d, Enter a number: ", i);
        scanf("%lf", &number);

        if (number < 0.0)
            goto jump;
        sum += number;
    }

    jump:
    average = sum / (i - 1);
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", average);
}

void comma_operator() {
/*    while (i < 100)
        sum += data[i], ++i; // execute 2 statements

    int i{5, 10}; // 10 is assigned

    int j = (f1(), f2()); // execute both, assign f2 value

    x = (y = 3, (z = ++y + 2) + 5);

    for (int i = 0, j = 100; i != 10; ++i, j -= 10);

    houseprice = 249,500; // assigns 249
    houseprice = {249, 500}; // assigns 500*/
}

void my_function(){
    printf("in my function()\n");
    longjmp(buf,1);

    /* NOT REACHED */
}

void setjmp_and_longjmp(){

    if (setjmp(buf)) {
        printf("back in main\n");
    } else{
        printf("first time run\n");
        my_function();
    }
}

int advance_control_flow(int argc, char *argv[]) {
    setjmp_and_longjmp();

    return 0;
}
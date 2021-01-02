#include <stdio.h>

int enums() {

    enum primary_color {
        red,
        yellow,
        blue
    };

    enum primary_color my_color;

    my_color = blue;

    printf("%d \n", red);
    printf("%d \n", yellow);
    printf("%d \n", blue);


    printf("my color: %d \n", my_color);

    return 0;
}
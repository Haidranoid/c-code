#include <stdio.h>
#include <stdlib.h>

int challenge_rectangle(int argc, char *argv[]) {

//    double width = atoi(argv[1]);
//    double height = atoi(argv[2]);

    double width = 0, height = 0;
    printf("Input the width and height of the rectangle: ");
    scanf("%lf %lf", &width, &height);

    double area = 0, perimeter = 0;
    area = width * height;
    perimeter = (width * 2) + (height * 2);

    printf("\nThe area is: %.2lf u^2", area);
    printf("\nThe perimeter is: %.2lf u", perimeter);

    return 0;
}
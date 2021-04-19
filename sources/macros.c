#include <stdio.h>

#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))
#define WARNING(s) fprintf(stderr, __VA__ARGS__)

#define PRINT(a,b) \
    printf("value 1 = %d\n",a);\
    printf("value 2 = %d\n",b);

#define FOO BAR
#define BAR (12)

#define MISC(x) \
    puts("Incrementing.."); \
    x++;

#define MAX(a,b) (a > b ? a : b)

#define FOR(i,n) for( ; i < n; i++)

int macros(int argc, char *argv[]) {
    PRINT(10,20)

    int c = 5;
    int area  = CIRCLE_AREA(c + 2);

    printf("Area is %d\n",area);

//    WARNING("%s: this program is here\n","Jason");

    printf("c before : %i\n", c);
    MISC(c)
    printf("c after : %i\n", c);

    printf("Max number: %i\n", MAX(5,9));

    int i = 0;
    FOR(i,10)
        printf("%i - Hello\n",i);


    return 0;
}
#include <stdio.h>

int main(int argc, char *argv[]) {
    #ifdef MY_MACRO
        printf("MY_MACRO is defined with value: %d\n",MY_MACRO);
    #endif
    printf("Hello, wold!\n");
    return 0;
}
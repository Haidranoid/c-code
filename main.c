#include <stdio.h>

void double_pointers(){
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("address of &a  = %p |  value of a  = %i\n", &a, a);
    printf("address of &p1 = %p |  value of p1 = %p\n", &p1, p1);
    printf("address of &p2 = %p |  value of p2 = %p\n", &p2, p2);
    puts("");
    printf("deferring address of *p1 = %i\n", *p1);
    printf("deferring address of *p2 = %p\n", *p2);
    puts("");
    printf("deferring address of **p2 = %i\n", **p2);
}

int main(int argc, char *argv[]) {
    
    return 0;
}
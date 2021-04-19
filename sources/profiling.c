// profiling.c
#include <stdio.h>

void func1(void){
    printf("\n Inside func1 \n");
    int i = 0;

    for (; i<0xffffffff ; i++);

    return;
}

static void func2(void){
    printf("\n Inside func2 \n");
    int i = 0;

    for (; i<0xffffffaa ; i++);
    return;
}

int profiling(void){
    printf("\n Inside main() \n");
    int i = 0;

    for (; i<0xffffffff ; i++);
    func1();
    func2();

    return 0;
}

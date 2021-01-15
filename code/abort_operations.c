#include <stdio.h>
#include <stdlib.h>

void sign_off(void) {
    puts("in sign_off...");
}

void too_bad(void) {
    puts("in too_bad...");
}

void exit_and_atexit(){
    int n;

    atexit(sign_off);
    puts("Enter an integer:");

    if (scanf("%d", &n) != 1) {
        puts("That's not integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
}

void aborts(){
    FILE *fp;
    fp = fopen("somefile.txt","r");

    if (fp == NULL){
        printf("Going to abort the program\n");
        abort();
    }

    printf("Going to close the file \n");
    fclose(fp);
}

int abort_operations() {
    aborts();
    return 0;
}
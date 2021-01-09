#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

int process(int i, int j) {
    int val = 0;

#ifdef DEBUG
    fprintf(stderr, "process(%d, %d)\n", i,j);
#endif // DEBUG

    val = i * j;

#ifdef DEBUG
    fprintf(stderr, "return %d\n", val);
#endif // DEBUG

    return val;
}

int macro_debug(int argc, char *argv[]) {
    int arg1 = 0;
    int arg2 = 0;

    if (argc == 3) {
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);
    } else{
        perror("Expected 2 numbers as arguments");
        exit(1);
    }


#ifdef DEBUG
    fprintf(stderr, "processed %i arguments \n",argc - 1);
        fprintf(stderr, "arg1 = %i, arg2 = %i \n",arg1,arg2);
#endif // DEBUG

    printf("%i\n", process(arg1, arg2));

    return 0;
}
#include <stdio.h>

void joseph_function(){
    printf("%s was called\n", __func__);
}

int predefined_macros(int argc, char *argv[]) {

#if (__STDC__ == 1)
    printf("Implementation is ISO-conforming.\n");
#else
    printf("Implementation is not ISO-conforming.\n");
#endif

    printf("File is %s, in line %i\n", __FILE__, __LINE__);
    printf("Program last compiled at %s on %s\n", __TIME__, __DATE__);
    joseph_function();
    return 0;
}
#include <stdio.h>

// if_def_directive
//#define JUST_CHECKING
#define JUST_CHECKING
#define LIMIT 4

// if_directive
#define MY_DEF 5
#define MY_OTHER_DEF 2

// if_else_directive
#define US 0
#define UK 1
#define France 2
#define Germany 3
#define Country France

// pragma_gcc
//#pragma GCC poison printf
//#pragma GCC warning "hello"
//#pragma GCC error "what"
//#pragma message "ok"

void if_def_directive() {
    int i = 0;
    int total = 0;
    for (i = 1; i <= LIMIT; i++) {
        total += 2 * i * i + 1;

#ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
#endif
    }
    printf("Grand total - %d\n", total);

}


void if_directive() {
#if MY_DEF == 5 && MY_OTHER_DEF == 2
    printf("Hello");
#endif
}

void if_else_directive() {
#if Country == US || Country == UK
#define Greeting "Hello."
#elif Country == France
#define Greeting "Bonjour."
#elif Country == Germany
#define Greeting "Guten Tag."
#endif

    printf("Greeting is: %s", Greeting);
}

void pragma_gcc(){
    printf("Hello.");
}

int PREPROCESSOR(int argc, char *argv[]) {
    pragma_gcc();
    return 0;
}
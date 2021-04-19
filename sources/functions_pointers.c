#include <stdio.h>

typedef void (*FuncType3)(void);
//typedef void FuncType3(void);

void function(char * string){
    printf("Hello world! - %s\n", string);
}

//void function2(void greeting(int)){
void function2(void (*greeting)(char*)){
    greeting("function 2");
}

void function3(void){
    printf("Hello from function 3!\n");
}

int functions_pointers(int argc, char *argv[]) {

    void (*f1)(char*);
    f1 = function;
    f1("function 1");


    void (*f2)(char*) = function;
//    function2(function); //or
    function2(f2);

    FuncType3 f3 = function3;
    f3();

    return 0;
}
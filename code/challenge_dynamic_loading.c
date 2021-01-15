#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void check_for_error(){
    char *error = NULL;

    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
}

int challenge_dynamic_loading() {
    void *handle = NULL;

    int (*get_length)(char *) = NULL;
    int (*get_char_frequency)(char *, char) = NULL;
    char *(*remove_non_alpha_characters)(char *) = NULL;
    char *(*concat_strings)(char *, char *) = NULL;
    void (*copy_strings)(char *, char *) = NULL;
    char *(*substring)(const char *, int, int) = NULL;

//    handle = dlopen("/Users/administaff/Desktop/Projects/c-code/cmake-build-debug/libstring-functions-shared.dylib",RTLD_LAZY); // Mac
    handle = dlopen("/Users/eduardo/Desktop/c-code/cmake-build-debug/libstring-functions-shared.dylib",RTLD_LAZY); // Mac

    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror(); // clear error code

    get_length = dlsym(handle, "get_length");
    check_for_error();
    get_char_frequency = dlsym(handle, "get_char_frequency");
    check_for_error();
    remove_non_alpha_characters = dlsym(handle, "remove_non_alpha_characters");
    check_for_error();
    concat_strings = dlsym(handle, "concat_strings");
    check_for_error();
    copy_strings = dlsym(handle, "copy_strings");
    check_for_error();
    substring = dlsym(handle, "substring");
    check_for_error();

    char *str1 = {"Hello, "};
    char *str2 = {"My name is eduardo"};
    char *str3 = {"Hi, Welcome! this is my house."};
    char str4[100];

    printf("length: %i\n", get_length(str2));
    printf("concatenated: %s\n", concat_strings(str1, str2));
    printf("only alpha: %s\n", remove_non_alpha_characters(str3));
    printf("char frequency: %i\n", get_char_frequency(str3, 'i'));
    copy_strings(str4, str2);
    printf("string copied: %s\n", str4);
    printf("substring found: %s\n", substring("Antologia de un perro",4,5));

    dlclose(handle);
    return 0;
}
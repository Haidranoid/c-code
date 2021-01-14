#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int dynamic_loading() {
    void *handle = NULL;
    double (*cosine)(double) = NULL;
    char *error = NULL;

    handle = dlopen("/usr/bin/cygwin1.dll", RTLD_LAZY); // Windows
//    handle = dlopen("/usr/lib/libm.dylib", RTLD_LAZY); // Mac
//    handle = dlopen("/lib/x86_64-linux-gnu/libm.so.6", RTLD_LAZY); // Mac

    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror(); // clear error code

    cosine = dlsym(handle, "cos");

    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }

    printf("%f\n", cosine(2.0));

    dlclose(handle);

    return 0;
}
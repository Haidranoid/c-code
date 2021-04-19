#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void *hello_fun() {
    printf("Hello world\n");
    return NULL;
}

void *print_message_function(void *ptr);

struct thread_data {
    int thread_id;
    int sum;
    char *message;
};

void *print_hello(void *thread_arg) {
    struct thread_data *my_data = (struct thread_data *) thread_arg;
    printf("taskid = %d, sum = %d, message = %s\n", my_data->thread_id, my_data->sum, my_data->message);
    return NULL;
}

void *hello_return(void *args) {
    char *hello = (char *) calloc(100, sizeof(char));
    strncpy(hello, "Hello world", 100);
    return (void *) hello;
}

int threads() {
/*    pthread_t thread = 0;
    pthread_create(&thread, NULL, hello_fun, NULL);
    pthread_join(thread, NULL); // blocks the main execution
    */


/*    pthread_t thread1 = 0, thread2 = 0;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1 = 0, iret2 = 0;

    // create independent threads each of wich will execute function
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void *) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void *) message2);

    // wait till thread are complete before main continues. unless we
    // wait we run the risk of executing an exit which will terminate
    // the process and all thread before threads have completed
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);*/



/*    pthread_t thread;
    struct thread_data my_data = {24, 300, "Hello from threading"};

    pthread_create(&thread, NULL, print_hello, (void *) &my_data);
    pthread_join(thread, NULL);*/


    char *str;
    pthread_t thread;

    pthread_create(&thread, NULL, hello_return, NULL);
    pthread_join(thread, (void **) &str);

    printf("Message created in thread: %s", str);

    pthread_exit(NULL); // waits to terminate all threads
}

void *print_message_function(void *ptr) {
    char *message = (char *) ptr;
    printf("%s \n", message);
    return NULL;
}
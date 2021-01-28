#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void signal_SIGSTOP() {
    printf("Testing SIGNSTOP\n");
    raise(SIGSTOP);

    // ps wuax | awk '$8 ~ "T"'   -MAC
    // ps                         -LINUX

    // kill -s SIGCONT PID
    printf("I am back\n\n");
}

void signal_SIGALRM() {
    alarm(5);

    // NEED TO CATCH SIGALRM or process terminates
    // signal (SIGALRM, alarmhandler);

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
}

void handle_divided_by_zero(int signum) {
    if (signum == SIGFPE) {
        perror("Received SIGFPE, Divide by Zero Exception\n: ");
        exit(0);
    } else {
        printf("Received %d Signal\n", signum);
        return;
    }
}

void signal_catching() {
    int result;
    int v1 = 0, v2 = 0;
    v1 = 121;
    v2 = 0;

    void (*signal_result)(int) = signal(SIGFPE, handle_divided_by_zero);

    if (signal_result == SIG_ERR) {
        perror("Signal Error: ");
        exit(1);
    }

    result = v1 / v2;
    printf("Result of Divide by Zero is %d\n", result);
}

void signal_handler(int signal_value) {
    int response = 0; // user's response to signal 1 or 2

    printf("%s%d", "\ninterrupt signal received : ", signal_value);

    // check for invalid responses
    while (response != 1 && response != 2) {
        printf("\nDo you wish to continue ( 1 = yes or 2 = no )? ");
        scanf("%d", &response);
    }

    // determinate if  it is time to exit
    if (response == 1) {
//        signal(SIGINT, signal_handler);
        return; // this also works
    } else {
        exit(EXIT_SUCCESS);
    }
}

void signal_catching_2() {
    int i, x;
    signal(SIGINT, signal_handler);
    srand(clock());

    for (i = 1; i <= 100; i++) {
        x = 1 + rand() % 50; // if x = 25, raise SIGINT

        if (x == 25)
            raise(SIGINT);

        printf("%4d", i);

        if (i % 10 == 0)
            printf("\n");

    }
}


void signal_ignore(int signum) {
    // DO NOTHING
}

void signal_ignoring() {
    //    signal(SIGINT,signal_ignore); //WRONG
    signal(SIGINT, SIG_IGN);         //RIGHT
    for (int i = 0; i < 100; ++i) {
        printf("%i ", i);
        raise(SIGINT);
    }
}

#define MAX_COUNT 10
#define BUF_SIZE 100

void do_fork() {
    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();
    for (int i = 0; i <= MAX_COUNT; i++) {
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));
    }
}

int signals() {
    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();
    for (int i = 0; i <= MAX_COUNT; i++) {
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));
    }
    return 0;
}
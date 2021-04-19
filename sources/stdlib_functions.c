#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#define SIZE 10

void random_numbers() {
    srand(time(0));

    for (int i = 0; i < 5; ++i) {
        printf(" %d ", rand());
    }
    puts("");

    for (int i = 0; i < 10; ++i) {
        printf(" %d ", rand());
    }
    puts("");

    for (int i = 0; i < 10; ++i) {
        //      rand()  % max number + initial number
        printf(" %d ", rand() % 10 + 1);
    }
}

void ato_functions() {
    char *a = "100";

    printf("Value = %d\n", atoi(a));
    printf("Value = %.2f\n", atof(a));
    printf("Value = %ld\n", atol(a));

}

void strto_functions() {
    char *a = "100";

    char *str = "123.456xyz";
    char *str_end;
    double value;

    value = strtod(str, &str_end);
    printf("\nValue = %lf\n", value);

    char *str_1 = "365.25 7.0";
    char *str_end_1;
    float value_1 = strtof(str_1, &str_end_1);
    float value_2 = strtof(str_end_1, NULL);

    printf("Value = %f : %f\n", value_1, value_2);

    char *str_2 = "2030300 This is test";
    char *ptr = NULL;
    long ret = 0;

    ret = strtol(str_2, &ptr, 10);
    printf("\nThe number(unsigned long integer) is %ld\n", ret);
    printf("String part is |%s|\n", ptr);
}

void system_function() {
    char command[50];
//    strcpy(command,"ls -l");
    strcpy(command, "pwd");
    system(command);
}

void env_variables() {
    char *str = NULL;

    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Environment Variable\" : %s\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Environment Variable\" : %s\n", str);

    assert((str = getenv("LOGNAME")) != NULL);
    printf("Value of \"LOGNAME Environment Variable\" : %s\n", str);

    assert((str = getenv("JSON")) != NULL);
    printf("Value of \"JSON Environment Variable\" : %s\n", str);

}

static_assert(sizeof(double) == 2 * sizeof(int), "double not twiche int size");

void show_array(const int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%i ", *array++);
    puts("");
}

void memcpy_and_memmove() {
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 2.0e30};

    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);

    // the third param must the total bytes size of the dst array
    memcpy(target, values, SIZE * sizeof(int));

    puts("target (copy of values): ");
    show_array(target, SIZE);

    puts("Using memmove() with overlapping ranges:");

    // the third param must the total bytes size of the dst array
    memmove(values + 2, values, 5 * sizeof(int));

    puts("values -- elements 0-4 copied to 2-6");
    show_array(values, SIZE);


    puts("Using memcpy() to copy double to int:");
    // the third param must the total bytes size of the dst array
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target -- 5 doubles into 10 int positions: ");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);
}

// non  standard functions
void strdup_and_strndup() {
    char *p0 = "Jose eduardo martinez lara";
    char *p1 = "Jason";
    char *p2 = NULL;

    p2 = strdup(p1);
    printf("Duplicated string is: %s\n", p2);
    p2 = strndup(p0, 7);
    printf("Duplicated string is: %s\n", p2);
}

void clock_and_times() {
/*
    clock_t start = 0, end = 0;
    double cpu_time = 0.0;
    start = clock();
    // executing tasks.....
    end = clock();
    cpu_time = (double) (end - start) / CLOCKS_PER_SEC; // Processor time in seconds
*/

    time_t calendar_start = time(NULL);
    clock_t cpu_start = clock();
    int count = 0;

    const long long iterations = 10000000000LL;
    char answer = 'y';
    double x = 0.0;

    printf("Initial clock time = %lld Initial calendar time = %lld\n", (long long) cpu_start,
           (long long) calendar_start);

    while (tolower(answer) == 'y') {
        for (long long i = 0LL; i < iterations; i++)
            x = sqrt(3.14159265);

        printf("%lld square roots completed.\n", iterations * (++count));
        printf("Do you wnt to run some more(y or n) ? \n");
        scanf("\n%c", &answer);
    }

    clock_t cpu_end = clock();
    time_t calendar_end = time(NULL);

    printf("Final clock time = %lld Final calendar time = %lld\n", (long long) cpu_end, (long long) calendar_end);
    printf("CPU time for %lld iterations is %.2lf seconds\n", count * iterations,
           ((double) (cpu_end - cpu_start)) / CLOCKS_PER_SEC);
    printf("Elapsed calendar time to execute the program is %8.2lf seconds.\n", difftime(calendar_end, calendar_start));
}

void dates() {
    char *date_str;
    const time_t date_time = time(NULL);
    date_str = ctime(&date_time);
    printf("Today is %s\n", date_str);


    time_t calendar = time(NULL);

    struct tm *time_data;
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char *months[] = {"January", "February", "March", "April", "May",
                            "July", "August", "September", "November", "December"};

/*  time_data = localtime(&calendar);
    printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon],
           time_data->tm_mday, time_data->tm_year + 1900);
    */

    const char *suffix[] = {"st", "nd", "rd", "th"};

    enum sufindex {
        st, nd, rd, th
    } sufsel = th;

    struct tm birthday = {0};
    char name[30] = {'\0'};

    printf("Enter a name: ");
    scanf("%s", name);

    printf("Enter the birthday for %s as day month year integers separated by space\n"
           "e.g. Enter 1st February 1985 as 1 2 1985: ", name);
    fflush(stdin);
    scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);

    birthday.tm_mon -= 1;
    birthday.tm_year -= 1900;

    if (mktime(&birthday) == -1) {
        fprintf(stderr, "Operation failed.\n");
        exit(1);
    }

    switch (birthday.tm_mday) {
        case 1:
        case 21:
        case 31:
            sufsel = st;
            break;
        case 2:
        case 22:
            sufsel = nd;
            break;
        case 3:
        case 23:
            sufsel = rd;
            break;

        default:
            sufsel = th;
            break;
    }

    printf("%s was born on the %d%s %s %d, which was a %s.\n", name,
           birthday.tm_mday,
           suffix[sufsel],
           months[birthday.tm_mon],
           birthday.tm_year,
           days[birthday.tm_wday]);
}

int stdlib_functions() {

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_arr(double *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%lf\n", *array++);
    }
}

double *generate_randoms(int size, double min, double max) {
    srand(time(0));
    double random;
    double *random_array = (double *) calloc(size, sizeof(double));

    for (int i = 0; i < size; i++) {
//        random = rand() % 11 - 5; // challenge 1
//        *random_array++ = (random / 10); // challenge 1

        // n > 0 && n < 1
//        random = (rand() / (double) RAND_MAX);
        random = ((double) rand() * (max - min)) / (double) RAND_MAX + min; // challenge 2
        *random_array++ = random;
    }
    random_array -= size;

    return random_array;
}

int compare(const void *p1, const void *p2) {
    const double n1 = *(const double *) p1;
    const double n2 = *(const double *) p2;

    if (n1 - n2 > 0) {
        return 1;
    } else if (n1 - n2 < 0) {
        return -1;
    } else {
        return 0;
    }
}

void sort_array(double *array, int size) {
    qsort(array, size, sizeof(double), compare);
}

void get_date(){
    time_t date;
    date = time(NULL);
    char *string_date = ctime(&date);
    printf("%s", string_date);
}

int challenge_stdlib() {
    /*    double *random_array = generate_randoms(30, 0, 50);
    show_arr(random_array, 30);
    sort_array(random_array, 30);
    show_arr(random_array, 30);*/

    get_date();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


int comp_ints(const void *p1, const void *p2);

int data_structures() {
    int data[] = {54, 3, 12, 9, 24};
//    printf("%zd\n", (sizeof(data) / sizeof(int)));

    qsort(data, 5, sizeof(int), comp_ints);

    for (int i = 0; i < 5; ++i)
        printf("%d ", data[i]);

    return 0;
}

int comp_ints(const void *p1, const void *p2) {
    // returns > 0  if p1 > p2
    // returns < 0  if p1 < p2
    // returns 0    if p1 = p2
    const int i1 = *(const int *) p1;
    const int i2 = *(const int *) p2;
    return i1 - i2;
}

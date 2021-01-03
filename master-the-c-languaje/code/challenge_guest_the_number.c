#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int challenge_guest_the_number(int argc, char *argv[]) {

    srand(time(NULL));
    int r = rand() % 21;

    bool won = false;
    int number_tried;

    for (int i = 0; i < 5; ++i) {
        printf("Try[#%i] Introduce the number: ", i + 1);
        scanf("%i", &number_tried);

        if (number_tried == r) {
            won = true;
            break;
        } else if (number_tried < r) {
            printf("The number is greater than %i\n", number_tried);
        }else{
            printf("The number is lower than %i\n", number_tried);
        }
    }

    if (won)
        printf("You have won!!");
    else
        printf("You lose, the number was %i", r);


    return 0;
}
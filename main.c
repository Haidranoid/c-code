#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void reading_file_chars() {
    FILE *fp;
    const char *filename = "../file.txt";
    fp = fopen(filename, "rw");

    if (fp == NULL)
        perror("Error in opening file");

    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
    fp = NULL;
}

void reading_keyboard_chars() {
    char ch = 0;
/*
    ch = getc(stdin);
    printf("1- read in character %c\n", ch);
*/

//    printf("2- read in character %c\n", getchar());

    // ignores whitespaces from input
    while (isspace(ch = (char) getchar()))
        ungetc(ch, stdin);

    printf("3- char is %c\n", getchar());
}

int main(int argc, char *argv[]) {

    return 0;
}
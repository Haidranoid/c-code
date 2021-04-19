#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int challenge_files(int argc, char *argv[]) {
    FILE *fp;
    fpos_t pos;
    fp = fopen("../file.txt", "r");

    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);

    int i = 0;
    while (i < pos) {
        i++;
        fseek(fp, -i, SEEK_END);
        printf("%c", fgetc(fp));
    }

    fclose(fp);
    fp = NULL;

    return 0;
}

void file_challenge_2() {
    FILE *fp_original;
    FILE *fp_temp;
    char ch;

    fp_original = fopen("../file.txt", "r");
    fp_temp = fopen("../file_temp.txt", "w");

    if (fp_original == NULL || fp_temp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    while ((ch = fgetc(fp_original)) != EOF)
        fputc(toupper(ch), fp_temp);

    remove("../file.txt");
    rename("../file_temp.txt", "../file.txt");

    fclose(fp_original);
    fclose(fp_temp);
    fp_original = NULL;
    fp_temp = NULL;
}

void file_challenge_1() {
    FILE *fp;
    int lines = 0;
    char ch;

    fp = fopen("../file.txt", "r");

    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
        if (ch == '\n') lines++;

    printf("Number of lines in file %i", ++lines);

    fclose(fp);
    fp = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>

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

//    printf("2- read in character %c\n", getchar()); // default stdin

    char *string = (char *) calloc(50, sizeof(char));
    int count = 0;

    while ((ch = (char) getchar()) != '\n' || count == 49) {
        *string = ch;
        string++;
        count++;
    }
    *string = '\0';

    printf("3- the sentence is is %s\n", string);
}

void writing_file_chars() {
    FILE *fp;
    const char *filename = "../file_writing.txt";
    fp = fopen(filename, "w+");

    if (fp == NULL)
        perror("Error in opening file");

    for (int i = 0; i < 48; ++i)
        fputc((char) i, fp);


    fclose(fp);
    fp = NULL;
}

void writing_terminal_chars() {
    /*for (int i = 60; i < 100; ++i)
        fputc((char) i, stdout);*/

    char *string = "Hello Eduardo, \n whats up!";

    while (*string != '\0')
        putchar(*string++); // default stdout
}

void reading_file_strings() {}

void reading_terminal_strings() {

    size_t characters;
    size_t buff_size = 50;

    char *buffer = (char *) calloc(buff_size, sizeof(char));

    if (buffer == NULL)
        exit(1);

    printf("Introduce a sentence: ");

//    fgets(buffer, 50, stdin);

    characters = getline(&buffer, &buff_size, stdin);
    if (characters == -1)
        perror("an error ocurred");

    printf("Sentence: %s", buffer);
    printf("Characters: %zd", characters);
}

void writing_file_strings() {
    char string[40];
    strcpy(string, "hello, how are you?");

    FILE *fp;
    const char *filename = "../file_writing.txt";

    fp = fopen(filename, "w+");

    if (fp == NULL)
        perror("Error in opening file");

    fputs(string, fp); // dont add new line

    fclose(fp);
    fp = NULL;
}

void writing_terminal_strings() {
    char string[40];
    strcpy(string, "hello, how are you?");

//    puts(string); // adds new line

    fputs(string, stdout); // dont add new line
}

int io(int argc, char *argv[]) {
    writing_file_strings();
    return 0;
}
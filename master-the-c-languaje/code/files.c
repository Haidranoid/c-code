#include <stdio.h>
#include <stdlib.h>

void reading_files(){
    FILE *fp;
    int c;
    char str[60];

    fp = fopen("../file.txt", "r");

    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    /*while ((c = fgetc(fp)) != EOF)
        printf("%c", c);*/

    while (fgets(str, 60, fp) != NULL)
        printf("%s", str);

    fclose(fp);
    fp = NULL;
}

void writing_files(){
    FILE *fp;
    int ch;

    fp = fopen("../file.txt", "w+");

    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }
/*    for(ch = 33; ch<= 100;ch++){
        fputc(ch, fp);
    }*/

    fputs("This is jose eduardo martinez lara.\n", fp);
    fputs("I am happy to be here", fp);

    fprintf(fp,"\n%s %s %s %s %d","hello","my","number","is",555);

    fclose(fp);
}

void positioning_files(){
    FILE *fp;
    int len;
    fp = fopen("../file.txt", "r");

    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);

    fclose(fp);
    printf("Total size of file.txt = %d bytes",len);
}

int files(int argc, char *argv[]) {
    positioning_files();
    return 0;
}
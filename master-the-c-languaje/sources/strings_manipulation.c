#include <stdio.h>
#include <string.h>


void coping_strings() {
    // ------------------------------ coping strings ----------------------------------
    char my_string_1[] = "My name is Eduardo";
    char my_temp[50];

    //strcpy(temp, my_string_1);
    strncpy(my_temp, my_string_1, sizeof(my_temp) - 1); // avoid buffer overflow

    printf("The length of my_string_1 is: %d \n", strlen(my_string_1));
    printf("my_string_1 :%s \n", my_temp);

    printf("The length of my_temp is: %d \n", strlen(my_string_1));
    printf("my_temp :%s \n", my_temp);

}

void concatenating_strings() {
    // ------------------------------ concatenating strings ----------------------------------
    char my_string_2[80] = "my string, ";
    char input[80];

    printf("Introduce the string to concat: ");
    fgets(input, 80, stdin); // avoids buffer overflow
    //scanf("%s",input);

    strncat(my_string_2, input, 80);
    printf("The final string is: %s", my_string_2);
}

void comparing_strings() {
    // ------------------------------ comparing strings ----------------------------------
    printf("strcmp('A','A') is ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp('A','B') is ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp('B','A') is ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp('C','A') is ");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp('Z','a') is ");
    printf("%d\n", strcmp("Z", "a"));

    printf("strcmp('apples','apple') is ");
    printf("%d\n", strcmp("apples", "apple"));
}

void comparing_strings_2() {
    if (strncmp("astronomy", "astro", 5) == 0)
        printf("Found: astronomy");

    if (strncmp("astounding", "astro", 5) == 0)
        printf("Found: astounding");
}

void searching_character(){
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *ptr_got_char = NULL;
    ptr_got_char = strchr(str, ch);

    if (ptr_got_char != NULL)
        printf("Char found: %s", ptr_got_char);
}

void searching_substring(){
    char str[] = "Every dog has his day";
    char word[] = "dog";
    char *ptr_got_substring = NULL;

    ptr_got_substring = strstr(str, word);

    if (ptr_got_substring != NULL)
        printf("String found: %s", ptr_got_substring);
}

void parsing_string(){
    char str[] = "Hello how are you - my name is - jason";
    const char s[] = "-";
    char *token;

    // gets the first word
    token = strtok(str, s);

    while (token != NULL) {
        printf("%s\n", token);

        token = strtok(NULL, s);
    }
}

int strings_manipulation(int argc, char *argv[]) {
    parsing_string();

    return 0;
}

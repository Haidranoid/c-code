#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

/*
find the frequency of characters in a string
remove all the characters in a string except alphabets
calculate the length of a string without using strlen
concatenate two strings without using strcat
copy a string manually without using strcpy
find the substring of a given string*/

int get_length(char *string);

int get_char_frequency(char *string, char ch);

char *remove_non_alpha_characters(char *string);

char *concat_strings(char *str1, char *str2);

void copy_strings(char *dst, char *src);

char *substring(const char *string, int from, int n);

#endif //STRINGFUNCTIONS_H

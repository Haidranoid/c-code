#ifndef TESTSHARED_H
#define TESTSHARED_H

int get_length(char *string);

int get_char_frequency(char *string, char ch);

char *remove_non_alpha_characters(char *string);

char *concat_strings(char *str1, char *str2);

void copy_strings(char *dst, char *src);

char *substring(const char *string, int from, int n);


#endif //TESTSHARED_H

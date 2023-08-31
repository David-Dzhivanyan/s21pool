#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(char *data);
int s21_strcmp(char *a, char *b);
char *s21_strcpy(char *data, char *src);
char *s21_strcat(char *data, char *src);
char *s21_strchr(char *data, int ch);
char *s21_strstr(char *str1, char *str2);
char *s21_strtok(char *srcString, char *sep);

#endif
#include <stdio.h>

#include "s21_string.h"

void s21_strlen_test(char *str, int expected) {
    printf("%s\n", str);
    int answ = s21_strlen(str);
    printf("%d\n", answ);
    if (answ == expected)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcmp_test(char *str1, char *str2, int expected) {
    printf("%s %s\n", str1, str2);
    int answ = s21_strcmp(str1, str2);
    printf("%d\n", answ);
    if (answ == expected)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcpy_test(char *str1, char *str2, char *expected) {
    printf("%s %s\n", str1, str2);
    char *answ = s21_strcpy(str1, str2);
    if (s21_strcmp(answ, expected) == 0) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

void s21_strcat_test(char *str1, char *str2, char *expected) {
    printf("%s %s\n", str1, str2);
    char *answ = s21_strcat(str1, str2);
    if (s21_strcmp(answ, expected) == 0) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

void s21_strchr_test(char *str1, char str2, char *expected) {
    printf("%s %c\n", str1, str2);
    char *answ = s21_strchr(str1, str2);
    if (answ == NULL && answ == expected) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else if (s21_strcmp(answ, expected) == 0) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

void s21_strstr_test(char *str1, char *str2, char *expected) {
    printf("%s %s\n", str1, str2);
    char *answ = s21_strstr(str1, str2);
    if (answ == NULL && answ == expected) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else if (s21_strcmp(answ, expected) == 0) {
        printf("%s\n", answ);
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

void s21_strtok_test(char *str1, char *str2, int expected) {
    int count = 0;
    printf("%s %s\n", str1, str2);
    char *cur_word = s21_strtok(str1, str2);
    while (cur_word != NULL) {
        printf("%s ", cur_word);
        cur_word = s21_strtok(NULL, str2);
        count++;
    }

    if (count == expected) {
        printf("\nSUCCESS\n");
    } else
        printf("\nFAIL\n");
}

int main() {
#if strlen
    s21_strlen_test("qwe", 3);
    s21_strlen_test("qwe1", 4);
    s21_strlen_test("", 0);
#endif
#if strcmp
    s21_strcmp_test("qwe", "qwe", 0);
    s21_strcmp_test("qwE", "qwe", -32);
    s21_strcmp_test("qwE", "qw", 69);
#endif
#if strcpy
    char s1[4] = "qwe";
    s21_strcpy_test(s1, "da", "da");
    s21_strcpy_test(s1, "12345", "12345");
    s21_strcpy_test(s1, "", "");
#endif
#if strcat
    char s1[100] = "davit";
    s21_strcat_test(s1, " molodec", "davit molodec");
    s21_strcat_test(s1, "123", "davit molodec123");
    s21_strcat_test(s1, "", "davit molodec123");
#endif
#if strchr
    s21_strchr_test("davit", 't', "t");
    s21_strchr_test("da", ' ', NULL);
    s21_strchr_test(" ", ' ', " ");
    s21_strchr_test("a", ' ', NULL);
    s21_strchr_test("davit", 'd', "davit");
#endif
#if strstr
    s21_strstr_test("davit", "it", "it");
    s21_strstr_test("da", " ", NULL);
    s21_strstr_test(" ", " ", " ");
    s21_strstr_test("a", " ", NULL);
    s21_strstr_test("davit", "vi", "vit");
#endif
#if strtok
    char str[] = "davit bolshoi molodec";
    char str1[] = "davitbolshoimolodec";
    char str2[] = ";;;;";
    s21_strtok_test(str, " ", 3);
    s21_strtok_test(str1, " ", 1);
    s21_strtok_test(str2, ";", 0);
#endif
    return 0;
}
#include "s21_string.h"

#include <stdio.h>

int s21_strlen(char *data) {
    int count = 0;
    while (data[count] != '\0') {
        count += 1;
    }

    return count;
}

int s21_strcmp(char *a, char *b) {
    int flag = 0, count = 0;

    while (flag == 0 && (a[count] != '\0' || b[count] != '\0')) {
        if (a[count] != b[count]) {
            flag = a[count] - b[count];
        }
        count += 1;
    }

    return flag;
}

char *s21_strcpy(char *data, char *src) {
    char *str = data;
    while (*src != '\0') {
        *data = *src;
        data++;
        src++;
    }
    *data = '\0';
    return str;
}

char *s21_strcat(char *data, char *src) {
    char *str = data + s21_strlen(data);
    while (*src != '\0') {
        *str = *src;
        str++;
        src++;
    }
    *str = '\0';
    return data;
}

char *s21_strchr(char *data, int ch) {
    char *flag = NULL;
    while (*data != '\0') {
        if (*data == ch) {
            flag = data;
            break;
        }
        data++;
    }

    return flag;
}

int check(char *str1, char *str2) {
    int flag = 1;
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            flag = 0;
            break;
        }
        str1++;
        str2++;
    }

    return flag;
}

char *s21_strstr(char *str1, char *str2) {
    char *flag = NULL;
    while (*str1 != '\0') {
        if (*str1 == *str2 && check(str1, str2)) {
            flag = str1;
            break;
        }
        str1++;
    }
    return flag;
}

int is_delim(char c, char *sep) {
    while (*sep != '\0') {
        if (c == *sep) return 1;
        sep++;
    }
    return 0;
}

char *s21_strtok(char *srcString, char *sep) {
    static char *memorized_string;
    if (srcString == NULL) {
        srcString = memorized_string;
    }
    if (srcString == NULL) {
        return NULL;
    }

    while (is_delim(*srcString, sep)) srcString++;

    if (*srcString == '\0') {
        return NULL;
    }

    char *pos = srcString;

    while (!is_delim(*srcString, sep) && *srcString != '\0') srcString++;

    memorized_string = srcString;

    if (*srcString != '\0') {
        *srcString = '\0';
        memorized_string += 1;
    }

    return pos;
}

// int main() {
//
//     char srcString[] = "ABCAOB";
//
//     char *sep = "A O";
//     char *token = s21_strtok(srcString, sep);
//     while (token) {
//         printf("%s\n", token);
//         token = s21_strtok(NULL, sep);
//     }
//     return 0;
// }

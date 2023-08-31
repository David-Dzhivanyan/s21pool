#include <stdio.h>

#define LEN 100

int input(int *buff1, int *buff2, int *len1, int *len2);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *maxLength);
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *maxLength);
void output(int *a, int length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int buff1[LEN] = {0}, buff2[LEN] = {0}, result1[LEN] = {0}, result[LEN] = {0}, len1 = 0, len2 = 0,
        result_length = 0, result_length1 = 0, maxLength = 0;
    if (input(buff1, buff2, &len1, &len2)) {
        sum(buff1, len1, buff2, len2, result, &result_length, &maxLength);
        output(result, result_length);
        printf("\n");
        sub(buff1, len1, buff2, len2, result1, &result_length1, &maxLength);
        if (result[LEN - len1] != result1[LEN - result_length] && result1[LEN - result_length1] == 9) {
            printf("n/a");
        } else {
            output(result1, result_length1);
        }
    } else {
        printf("n/a");
    }
}

int input(int *buff1, int *buff2, int *len1, int *len2) {
    int buff1Twink[LEN], buff2Twink[LEN], count = LEN - 1, i = 0, flag = 1;
    char lineBreak = '\0';
    while (lineBreak != '\n') {
        if (scanf("%d%c", &buff1Twink[i], &lineBreak) != 2 || buff1Twink[i] < 0 || buff1Twink[i] >= 10) {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag) {
        *len1 = i;
        for (int j = *len1 - 1; j >= 0; j--, count--) {
            buff1[count] = buff1Twink[j];
        }
    }
    if (flag) {
        count = LEN - 1;
        lineBreak = '\0';
        i = 0;
        while (lineBreak != '\n') {
            if (scanf("%d%c", &buff2Twink[i], &lineBreak) != 2 || (lineBreak != ' ' && lineBreak != '\n') ||
                buff2Twink[i] < 0 || buff2Twink[i] >= 10) {
                flag = 0;
                break;
            }
            i++;
        }
    }
    if (flag) {
        *len2 = i;
        for (int j = *len2 - 1; j >= 0; j--, count--) {
            buff2[count] = buff2Twink[j];
        }
    }

    return flag;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *maxLength) {
    int count = LEN - 1, answLength = 0, sum, discharge = 0;

    if (len1 > len2)
        *maxLength = len1;
    else
        *maxLength = len2;

    for (int i = *maxLength; i >= 0; i--, count--, answLength++) {
        sum = buff1[count] + buff2[count] + discharge;
        if (sum >= 10) {
            sum = sum - 10;
            discharge = 1;
        } else {
            discharge = 0;
        }
        result[count] = sum;
    }
    *result_length = answLength;
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length, int *maxLength) {
    int count = LEN - 1, answLength = 0, subt, discharge = 0, flag = 1;

    if (len1 > len2)
        *maxLength = len1;
    else
        *maxLength = len2;

    for (int i = *maxLength; i >= 0; i--, count--, answLength++) {
        subt = buff1[count] - buff2[count] - discharge;
        if (subt < 0) {
            subt = subt + 10;
            discharge = 1;
        } else {
            discharge = 0;
        }
        result[count] = subt;
    }
    *result_length = answLength;

    return flag;
}

void output(int *a, int length) {
    int count = 0;
    int j = LEN - length;
    while (a[j] == 0 && count <= length) {
        count++;
        j++;
    }
    if (count != length) {
        length = length - count;
        printf("%d", a[LEN - length]);
        for (int i = LEN - length + 1; i <= LEN - 1; i++) {
            printf(" %d", a[i]);
        }
    } else {
        printf("%d", 0);
    }
}
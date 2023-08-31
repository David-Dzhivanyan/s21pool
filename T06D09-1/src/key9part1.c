/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int sum, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int data[NMAX] = {0}, answ[NMAX] = {0}, n;
    if (input(data, &n)) {
        int sum = sum_numbers(data, n);
        if (sum == 0) {
            printf("n/a");
        } else {
            printf("%d", sum);
            int len = find_numbers(data, n, sum, answ);
            output(answ, len);
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int flag = 1;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        flag = 0;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", &a[i]) != 1) {
                flag = 0;
            }
        }
    }
    return flag;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int sum, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && (sum % buffer[i] == 0)) {
            numbers[count] = buffer[i];
            count = count + 1;
        }
    }
    return count;
}

void output(int *a, int length) {
    if (length != 0) printf("\n%d", a[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", a[i]);
    }
}
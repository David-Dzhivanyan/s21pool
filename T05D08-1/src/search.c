#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int even(int num);
void output(int *a, int n);
int search(int *a, int n, int i);

int main() {
    int data[NMAX] = {0}, n;
    if (input(data, &n)) {
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char lineBreak;
    int flag = 1;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        flag = 0;
    } else {
        for (int i = 0; i < *n; i++) {
            if (i == *n - 1) {
                if (scanf("%d%c", &a[i], &lineBreak) != 2 || (lineBreak != '\n' && lineBreak != '\0')) {
                    flag = 0;
                }
            } else if (scanf("%d", &a[i]) != 1) {
                flag = 0;
            }
        }
    }
    return flag;
}

double mean(int *a, int n) {
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
    }
    return sum / n;
}
double variance(int *a, int n) {
    double sum = 0., mean1 = mean(a, n);
    for (int i = 0; i < n; i++) {
        sum += (a[i] - mean1) * (a[i] - mean1);
    }
    return sum / n;
}

int even(int num) {
    int flag = 1;
    if (num % 2 != 0) {
        flag = 0;
    }
    return flag;
}

void output(int *a, int n) {
    int answ = 0;
    for (int i = 0; i < n; i++) {
        if (search(a, n, a[i]) == 1 && answ == 0) {
            answ = a[i];
        }
    }
    printf("%d", answ);
}

int search(int *a, int n, int i) {
    int flag = 1;
    if (!even(i)) {
        flag = 0;
    }
    if (i < mean(a, n)) {
        flag = 0;
    }
    if (sqrt(variance(a, n)) * 3 < (mean(a, n) - i)) {
        flag = 0;
    }
    if (i == 0) {
        flag = 0;
    }
    return flag;
}

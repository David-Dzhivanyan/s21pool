#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int data[NMAX] = {0}, n;
    int i = input(data, &n);
    if (i == 1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int n) {
    int maxValue = a[0];
    for (int i = 1; i < n; i++) {
        if (maxValue < a[i]) maxValue = a[i];
    }
    return maxValue;
}
int min(int *a, int n) {
    int minValue = a[0];
    for (int i = 1; i < n; i++) {
        if (minValue > a[i]) minValue = a[i];
    }
    return minValue;
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
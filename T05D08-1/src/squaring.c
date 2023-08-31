#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int data[NMAX] = {0}, n;
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char lineBreak;
    int flag = 1;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > 10) {
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

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}

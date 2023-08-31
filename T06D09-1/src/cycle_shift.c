#include <stdio.h>
#define NMAX 10

int input(int *a, int *length, int *c);
void arrayShift(int *a, int length, int c);
void output(int *a, int length);

int main() {
    int data[NMAX] = {0}, n, c;
    if (input(data, &n, &c)) {
        arrayShift(data, n, c);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *length, int *c) {
    int flag = 1;
    if (scanf("%d", length) != 1 || *length <= 0 || *length > NMAX) {
        flag = 0;
    }
    if (flag) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", &a[i]) != 1) {
                flag = 0;
            }
        }
    }
    if (flag && (scanf("%d", c) != 1)) flag = 0;
    return flag;
}

void arrayShift(int *a, int length, int c) {
    int item;
    if (c >= 0) {
        for (int i = 0; i < c % length; i++) {
            item = a[0];
            for (int i = 0; i < length - 1; i++) {
                a[i] = a[i + 1];
            }
            a[length - 1] = item;
        }
    } else {
        for (int i = 0; i < (c * -1) % length; i++) {
            item = a[length - 1];
            for (int i = length - 1; i > 0; i--) {
                a[i] = a[i - 1];
            }
            a[0] = item;
        }
    }
    output(a, length);
}

void output(int *a, int length) {
    printf("%d", a[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", a[i]);
    }
}
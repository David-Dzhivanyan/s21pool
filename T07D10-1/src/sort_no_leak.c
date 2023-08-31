#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
    } else {
        int *data = (int *)malloc(n * sizeof(int));
        if (NULL == data) {
            printf("n/a");
        } else {
            if (input(data, n)) {
                sort(data, n);
                output(data, n);
            } else {
                printf("n/a");
            }
        }
        free(data);
    }
    return 0;
}

int input(int *a, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (i == 9) {
            if (scanf("%d", &a[i]) != 1) {
                flag = 0;
            }
        } else if (scanf("%d", &a[i]) != 1) {
            flag = 0;
        }
    }
    return flag;
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int twink = a[j];
                a[j] = a[j + 1];
                a[j + 1] = twink;
            }
        }
    }
}

void output(int *a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
}

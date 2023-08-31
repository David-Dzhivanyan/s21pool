#include <stdio.h>

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int data[10] = {0};
    if (input(data)) {
        sort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int flag = 1;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) {
            flag = 0;
        }
    }
    return flag;
}

void sort(int *a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (a[j] > a[j + 1]) {
                int twink = a[j];
                a[j] = a[j + 1];
                a[j + 1] = twink;
            }
        }
    }
}

void output(int *a) {
    printf("%d", a[0]);
    for (int i = 1; i < 10; i++) {
        printf(" %d", a[i]);
    }
}

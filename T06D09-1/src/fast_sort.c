#include <stdio.h>

int input(int *a, int *b);
void fast_sort(int *a, int left, int right);
void puzirek(int *a);
void output(int *a);

int main() {
    int data[10] = {0}, data1[10] = {0};
    if (input(data, data1)) {
        fast_sort(data, 0, 9);
        output(data);
        printf("\n");
        puzirek(data1);
        output(data1);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *b) {
    int flag = 1;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) {
            flag = 0;
        }
        b[i] = a[i];
    }
    return flag;
}

void fast_sort(int *a, int left, int right) {
    int lBoundary = left;
    int rBoundary = right;
    int flag = a[left];
    while (left < right) {
        while ((a[right] >= flag) && (left < right)) {
            right--;
        }
        if (left != right) {
            a[left] = a[right];
            left++;
        }
        while ((a[left] <= flag) && (left < right)) {
            left++;
        }
        if (left != right) {
            a[right] = a[left];
            right--;
        }
    }
    a[left] = flag;
    flag = left;
    left = lBoundary;
    right = rBoundary;
    if (left < flag) {
        fast_sort(a, left, flag - 1);
    }
    if (right > flag) {
        fast_sort(a, flag + 1, right);
    }
}

void puzirek(int *a) {
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

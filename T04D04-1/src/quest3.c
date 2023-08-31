#include <stdio.h>

int fib(int a, int b, int count, int numFib);

int main() {
    int numFib;
    char lineBreak;
    if (scanf("%d%c", &numFib, &lineBreak) != 2 || lineBreak != '\n' || numFib <= 0) {
        printf("n/a");
    } else {
        printf("%d", fib(1, 1, 2, numFib));
    }
    return 1;
}

int fib(int a, int b, int count, int numFib) {
    if (numFib <= 2) {
        return 1;
    }
    int c = a + b;
    count = count + 1;
    if (numFib == count) {
        return c;
    } else {
        return fib(b, c, count, numFib);
    }
}

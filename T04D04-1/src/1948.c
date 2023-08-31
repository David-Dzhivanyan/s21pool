#include <stdio.h>

int primeNumb(int a);
int greatestPrimeDivisor(int a);

int main() {
    int a;
    char lineBreak;
    if (scanf("%d%c", &a, &lineBreak) != 2 || lineBreak != '\n' || a == 0 || a == 1 || a == -1) {
        printf("n/a");
    } else {
        printf("%d", greatestPrimeDivisor(a));
    }
    return 1;
}

int greatestPrimeDivisor(int a) {
    if (a < 0) {
        a = a * (-1);
    }
    int answ, count = a;
    for (int i = 2; i <= a; i++) {
        while (count > 0) {
            count = count - i;
        }
        if (count == 0) {
            if (primeNumb(i) == 1) {
                answ = i;
            }
        }
        count = a;
    }
    return answ;
}

int primeNumb(int a) {
    int answ = 0, count = a;
    for (int i = 2; i <= a; i++) {
        while (count > 0) {
            count = count - i;
        }
        if (count == 0) {
            answ = answ + 1;
        }
        count = a;
    }
    if (answ == 1) {
        return 1;
    } else {
        return 0;
    }
}

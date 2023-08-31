#include <stdio.h>

int decoder();
int coder();

int main(int argc, char* argv[]) {
    int t = coder();

    //    if (argv[1] == "0") {
    //        coder();
    //    } else if (argv[1] == "1") {
    //        decoder();
    //    } else {
    //        printf("n/a");
    //    }
    //    int a;
    //    char lineBreak;
    //    if (scanf("%d%c", &a, &lineBreak) != 2 || lineBreak != '\n') {
    //        printf("n/a");
    //    } else {
    //    }
}

int coder() {
    char str;
    char b;
    if (scanf("%c", &str) != 1 || str != ' ') {
        b = str;
    } else {
        printf("n/a");
    }
    int evenOdd = 1;
    while (str != '\n') {
        if (evenOdd == 0) {
            if (scanf("%c", &str) != 1 || str != ' ') {
                printf("%X", str);
            } else {
                printf("n/a");
            }
            evenOdd = 1;
        } else if (evenOdd == 1) {
            if (scanf("%c", &str) != 1 || str == ' ' || str == '\n') {
                printf("%c", str);
            } else {
                printf("n/a");
            }
            evenOdd = 0;
        }
    }
    return 1;
}

int decoder() {}
#include <stdio.h>

int max(int a, int b);

int main() {
  int a, b;
  char lineBreak;
  if (scanf("%d %d%c", &a, &b, &lineBreak) != 3 || lineBreak != '\n') {
    printf("n/a");
  } else {
    printf("%d", max(a, b));
  }
  return 0;
}

int max(int a, int b) {
  if (a >= b) {
    return (a);
  } else {
    return (b);
  }
}
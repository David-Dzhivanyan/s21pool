#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
  int a, b;
  char lineBreak;
  if (scanf("%d %d%c", &a, &b, &lineBreak) != 3 || lineBreak != '\n') {
    printf("n/a");
  } else if (b == 0) {
    printf("%d %d %d n/a", sum(a, b), sub(a, b), mul(a, b));
  } else {
    printf("%d %d %d %d", sum(a, b), sub(a, b), mul(a, b), div(a, b));
  }
  return 0;
}

int sum(int a, int b) {
  return (a + b);
}
int sub(int a, int b) {
  return (a - b);
}
int mul(int a, int b) {
  return (a * b);
}
int div(int a, int b) {
  return (a / b);
}
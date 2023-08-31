#include <stdio.h>

int main() {
  float x, y;
  char lineBreak;
  if (scanf("%f %f%c", &x, &y, &lineBreak) != 3 || lineBreak != '\n') {
    printf("n/a");
  } else if ((x * x) + (y * y) < 25) {
    printf("GOTCHA");
  } else {
    printf("MISS");
  }
  return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
  float x;
  char lineBreak;
  if (scanf("%f%c", &x, &lineBreak) != 2 || lineBreak != '\n' || x == 0) {
    printf("n/a");
  } else {
    float y =
        7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0 / 3.0) - 1e3) * x + 3.0) / (pow(x, 2) / 2.0)
            - x * pow((10 + x), (2.0 / x))
            - 1.01;
    printf("%.1f", y);
  }

  return 0;
}

#include "rendering.h"

#include "polish_notation.h"
#include "value_calculation.h"

#define WIDTH 80
#define HEIGHT 25

int rendering(const double *mas) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (mas[x] == y)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    return (0);
}

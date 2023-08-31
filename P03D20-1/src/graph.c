#include "polish_notation.h"
#include "rendering.h"
#include "value_calculation.h"

int main() {
    char *list;
    char *str = lexicon_main();

    double *mas;

    list = polish_notation(str);
    mas = mas_y(list);
    rendering(mas);
    free(list);
    free(str);
    free(mas);
    return 1;
}

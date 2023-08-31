#ifndef VALUE_CALCULATION_H
#define VALUE_CALCULATION_H
#include "lexicon_list.h"
#include "structures.h"

double *init_mas_x();
double *mas_y(char *str);
double y_calculation(double x, char *str, char *twink);
void substitution_x(double x, char *str);
Stack_num *calculation(char *cur_word, Stack_num *num, double *result, double x);
int stack_count(Stack_num *num);

#endif

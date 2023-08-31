#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H
#include "structures.h"

char *polish_notation(char *str);
int is_operand(char symbol);
int get_priority(char operand);
Stack *check_priority(Stack *stack_operands, char *list, char operand);

#endif

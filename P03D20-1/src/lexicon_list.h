#ifndef LEXICON_LIST_H
#define LEXICON_LIST_H
#define SIZE 100
#define OPERANDS "+-/*sScCtl()"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lexicon_main();
int validation(char* str);
void formatting(char* str, int* flag);
void del_space(char* str);
int operand_validity(const char* str, int i, const char operand[5]);

#endif

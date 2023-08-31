#include "value_calculation.h"

#include "lexicon_list.h"
#include "polish_notation.h"
#include "structures.h"
#define EPS 1E-6

double *mas_y(char *str) {
    double *y_mas = malloc(80 * sizeof(double));
    char *twink = malloc(80 * sizeof(char));
    double *x_mas;
    x_mas = init_mas_x();
    for (int i = 0; i < 80; ++i) {
        y_mas[i] = y_calculation(x_mas[i], str, twink);
    }

    for (int i = 0; i < 80; ++i) {
        if ((y_mas[i] >= -1) && (y_mas[i] <= 1))
            y_mas[i] = round(y_mas[i] * 12) + 12;
        else
            y_mas[i] = 1000;
    }
    free(x_mas);
    free(twink);
    return y_mas;
}

double *init_mas_x() {
    double *x_mas = malloc(80 * sizeof(double));
    double x = 0;
    double step = 4 * M_PI / 80;
    for (int i = 0; i < 80; ++i) {
        x_mas[i] = x;
        x += step;
    }

    return x_mas;
}

double y_calculation(double x, char *str, char *twink) {
    double result = 1000;

    Stack_num *num;
    twink = strcpy(twink, str);
    char *cur_word = strtok(twink, " ");
    if (strcmp(cur_word, "x") == 0) {
        num = init_num(x);
    } else {
        num = init_num(atof(cur_word));
    }
    while (cur_word != NULL) {
        cur_word = strtok(NULL, " ");
        num = calculation(cur_word, num, &result, x);
    }
    if (stack_count(num) == 1) {
        num = calculation(cur_word, num, &result, x);
    }
    destroy_num(num);
    return result;
}

Stack_num *calculation(char *cur_word, Stack_num *num, double *result, double x) {
    Stack_num *twink = num;

    if (cur_word != NULL && !is_operand(*cur_word) && strcmp(cur_word, "x") != 0) {
        twink = push_num(twink, atof(cur_word));
    } else if (cur_word != NULL && !is_operand(*cur_word) && strcmp(cur_word, "x") == 0) {
        twink = push_num(twink, x);
    } else if (cur_word != NULL && is_operand(*cur_word)) {
        if ((*cur_word == '+' || *cur_word == '-' || *cur_word == '*' || *cur_word == '/') &&
            stack_count(twink) >= 2) {
            if (*cur_word == '+') {
                *result = twink->next->value + twink->value;
            } else if (*cur_word == '-') {
                *result = twink->next->value - twink->value;
            } else if (*cur_word == '*') {
                *result = twink->next->value * twink->value;
            } else if (*cur_word == '/') {
                if (twink->value < EPS)
                    *result = 1000;
                else
                    *result = twink->next->value / twink->value;
            }
            twink = pop_num(twink);
            twink = pop_num(twink);
        } else {
            if (*cur_word == '-') {
                *result = twink->value * -1;
            } else if (*cur_word == 's') {
                *result = sin(twink->value);
            } else if (*cur_word == 'S') {
                if (twink->value < EPS)
                    *result = 1000;
                else
                    *result = sqrt(twink->value);
            } else if (*cur_word == 'c') {
                *result = cos(twink->value);
            } else if (*cur_word == 'l') {
                if (twink->value < EPS)
                    *result = 1000;
                else
                    *result = log(twink->value);
            } else if (*cur_word == 't') {
                *result = tan(twink->value);
            } else if (*cur_word == 'C') {
                *result = cos(twink->value) / sin(twink->value);
            }
            twink = pop_num(twink);
        }
        twink = push_num(twink, *result);
    } else if (stack_count(num) == 1) {
        *result = twink->value;
        twink = pop_num(twink);
    }

    return twink;
}

int stack_count(Stack_num *num) {
    Stack_num *twink = num;
    int count = 0;
    while (twink != NULL) {
        count += 1;
        twink = twink->next;
    }
    destroy_num(twink);
    return count;
}

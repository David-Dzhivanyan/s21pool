#include "polish_notation.h"

#include "lexicon_list.h"
#include "structures.h"

char *polish_notation(char *str) {
    char *list = malloc(SIZE * sizeof(char));

    int first = 1;
    Stack *stack_operands = NULL;
    while (*str != '\0') {
        if (is_operand(*str) && first) {
            stack_operands = init(*str);
            first = 0;
        } else if (is_operand(*str)) {
            stack_operands = check_priority(stack_operands, list, *str);
        } else {
            if (*(str + 1) != '\0' && !is_operand(*(str + 1))) {
                char *r = malloc(SIZE * sizeof(char));
                strcpy(r, str);
                *(r + 1) = '\0';
                strcat(list, r);
                free(r);
            } else {
                char *r = malloc(SIZE * sizeof(char));
                strcpy(r, str);
                *(r + 1) = '\0';
                strcat(list, r);
                free(r);
                strcat(list, " ");
            }
        }
        str++;
    }

    Stack *twink = stack_operands;
    while (twink != NULL) {
        char o[3] = {twink->value};
        strcat(list, o);
        strcat(list, " ");
        twink = pop(twink);
    }

    destroy(twink);
    printf("%s\n", list);
    return list;
}

int get_priority(char operand) {
    int priority = 0;
    if (operand == '+' || operand == '-') {
        priority = 0;
    } else if (operand == '*' || operand == '/') {
        priority = 1;
    } else if (operand == 's' || operand == 'S' || operand == 'c' || operand == 'C' || operand == 'l' ||
               operand == 't') {
        priority = 2;
    } else if (operand == '(' || operand == ')') {
        priority = 3;
    }

    return priority;
}

Stack *check_priority(Stack *stack_operands, char *list, char operand) {
    Stack *twink = stack_operands;

    while (twink != NULL && (get_priority(operand) <= get_priority(twink->value)) &&
           get_priority(operand) != 3 && (twink->value != '(')) {
        char o[3] = {twink->value};
        strcat(list, o);
        strcat(list, " ");
        twink = pop(twink);
    }
    if (operand == '(') {
        twink = push(twink, operand);
    } else if (operand == ')') {
        while (twink->value != '(') {
            char o[3] = {twink->value};
            strcat(list, o);
            strcat(list, " ");
            twink = pop(twink);
        }
        twink = pop(twink);
    } else {
        twink = push(twink, operand);
    }

    return twink;
}

int is_operand(char symbol) {
    int i = 0, flag = 0;
    while (OPERANDS[i] != '\0') {
        if (symbol == OPERANDS[i]) flag = 1;
        i++;
    }
    return flag;
}

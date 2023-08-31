#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct stack {
    char value;
    struct stack *next;
} Stack;

typedef struct stack_num {
    double value;
    struct stack_num *next;
} Stack_num;

Stack *init(char value);

Stack *push(Stack *root, char value);
Stack *pop(Stack *root);
void destroy(Stack *root);

Stack_num *init_num(double value);
Stack_num *push_num(Stack_num *root, double value);
Stack_num *pop_num(Stack_num *root);
void destroy_num(Stack_num *root);
#endif

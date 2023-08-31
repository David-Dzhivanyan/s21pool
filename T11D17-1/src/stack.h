#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int value;
    struct stack *next;
} Stack;

Stack *init(int value);
Stack *push(Stack *root, int value);
Stack *pop(Stack *root);
void destroy(Stack *root);

#endif
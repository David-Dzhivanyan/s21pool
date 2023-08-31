#include "stack.h"

#include <stdio.h>

Stack *push_test(Stack *root, int value, int expected) {
    Stack *elem = push(root, value);

    if (elem->value == expected) {
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
    return elem;
}

Stack *pop_test(Stack *root, int expected) {
    Stack *c = pop(root);
    if (c->value == expected) {
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
    return c;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    Stack *root = init(a);
    root = push_test(root, b, 2);
    root = push_test(root, c, 3);
    root = pop_test(root, 2);
    root = pop_test(root, 1);

    destroy(root);
}
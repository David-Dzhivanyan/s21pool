#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack *init(int value) {
    Stack *root;
    root = (Stack *)malloc(sizeof(Stack));

    root->value = value;
    root->next = NULL;
    return root;
}

Stack *push(Stack *root, int value) {
    Stack *elem;
    elem = (Stack *)malloc(sizeof(Stack));

    elem->value = value;
    elem->next = root;
    root = elem;
    return root;
}

Stack *pop(Stack *root) {
    Stack *elem = root;
    root = root->next;

    free(elem);
    return root;
}

void destroy(Stack *root) {
    Stack *elem = root;
    while (elem != NULL) {
        Stack *item = elem;
        elem = elem->next;
        free(item);
    }
}

// int main() {
//     Stack *node1 = init(1);
//     Stack *node2 = push(node1, 2);
//     Stack *node3 = push(node2, 3);
//     Stack *node4 = push(node3, 4);
//     Stack *node5 = push(node4, 5);
//     Stack *c1 = pop(node5);
//     printf("%d\n", c1->value);
//     Stack *c2 = node4;
//     while (c2 != NULL) {
//         printf("%d\n", c2->value);
//         c2 = c2->next;
//     }
//
//     destroy(c1);
//     return 0;
// }
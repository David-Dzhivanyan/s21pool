#include "structures.h"

#include "lexicon_list.h"

Stack *init(char value) {
    Stack *root;
    root = (Stack *)malloc(sizeof(Stack));
    root->value = value;
    root->next = NULL;
    return root;
}

Stack *push(Stack *root, char value) {
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

Stack_num *push_num(Stack_num *root, double value) {
    Stack_num *elem;
    elem = (Stack_num *)malloc(sizeof(Stack_num));

    elem->value = value;
    elem->next = root;
    root = elem;
    return root;
}

Stack_num *init_num(double value) {
    Stack_num *root;
    root = (Stack_num *)malloc(sizeof(Stack_num));
    root->value = value;
    root->next = NULL;
    return root;
}

Stack_num *pop_num(Stack_num *root) {
    Stack_num *elem = root;
    root = root->next;

    free(elem);
    return root;
}

void destroy_num(Stack_num *root) {
    Stack_num *elem = root;
    while (elem != NULL) {
        Stack_num *item = elem;
        elem = elem->next;
        free(item);
    }
}
#include "list.h"

#include <stdio.h>

#include "door_struct.h"

void add_door_test(Node *root, Door *door, int expected) {
    add_door(root, door);

    if (find_door(expected, root)) {
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

void remove_door_test(Node *root, Door *door, int expected) {
    add_door(root, door);
    Node *c = find_door(door->id, root);
    remove_door(c, root);
    if (find_door(expected, root) != c) {
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");
}

int main() {
    Door a = {1, 0};
    Door b = {2, 0};
    Door c = {3, 0};
    Node *node1 = init(&a);
    add_door_test(node1, &b, 2);
    add_door_test(node1, &c, 3);
    remove_door_test(node1, &b, 2);
    remove_door_test(node1, &c, 3);

    destroy(node1);
}
#include "list.h"
//#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

Node *init(const Door *door) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    root->item = *door;
    root->next = NULL;

    return root;
}

Node *add_door(Node *elem, const Door *door) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    root->item = *door;
    root->next = elem->next;
    elem->next = root;

    return root;
}

Node *find_door(int door_id, Node *root) {
    Node *twink = root;
    while (twink != NULL && twink->item.id != door_id) {
        twink = twink->next;
    }

    return twink;
}

Node *remove_door(Node *elem, Node *root) {
    Node *twink;
    if (elem == root) {
        twink = root->next;
        free(root);
    } else {
        twink = root;
        while (twink->next != elem) {
            twink = twink->next;
        }
        twink->next = elem->next;
        free(elem);
    }
    return (twink);
}

void destroy(Node *root) {
    Node *twink = root;
    while (twink != NULL) {
        root = remove_door(twink, root);
        twink = root;
    }
}

// int main() {
//     Door a = {1, 0};
//     Door b = {3, 3};
//     Door c = {3, 1};
//     Door d = {4, 1};
//     Door e = {5, 1};
//     Door *dor = &a;
//     Node *node1 = init(dor);
//     Node *node2 = add_door(node1, &b);
//     Node *node3 = add_door(node2, &c);
//     Node *node4 = add_door(node3, &d);
//     Node *node5 = add_door(node4, &e);
//     Node *c1 = find_door(5,node1);
//
//     remove_door(node2,node1);
//
//
//     Node *c2 = node1;
//     while (c2 != NULL){
//         printf("%d %d\n",c2->item.id, c2->item.status);
//         c2 = c2->next;
//     }
//
//     destroy(node1);
//     return 0;
// }

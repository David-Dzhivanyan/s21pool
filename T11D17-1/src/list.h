#include "door_struct.h"

#ifndef LIST_H
#define LIST_H

typedef struct node {
    struct door item;
    struct node *next;
} Node;

Node *init(const Door *door);
Node *add_door(Node *elem, const Door *door);
Node *find_door(int door_id, Node *root);
Node *remove_door(Node *elem, Node *root);
void destroy(Node *root);

#endif
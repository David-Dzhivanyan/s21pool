#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    int item;
    struct s_btree *left;
    struct s_btree *right;
    struct s_btree *parent;
} t_btree;

int cmpf(int item, int root_item);

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));

t_btree *bstree_create_node(int item);

#endif

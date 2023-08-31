#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *root;
    root = (t_btree *)malloc(sizeof(t_btree));
    root->item = item;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    return root;
}

int cmpf(int a, int b) { return a > b; }

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *elem = root, *twink = NULL;

    t_btree *new_elem = malloc(sizeof(t_btree));
    new_elem->item = item;

    while (elem != NULL) {
        twink = elem;
        if (cmpf(item, elem->item))
            elem = elem->right;
        else
            elem = elem->left;
    }

    new_elem->parent = twink;
    new_elem->left = NULL;
    new_elem->right = NULL;

    if (cmpf(item, twink->item))
        twink->right = new_elem;
    else
        twink->left = new_elem;
}

// int main() {
//     t_btree *a =  bstree_create_node(3);
//     bstree_insert(a, 5,biggest);
//     printf("%d", a->right->item);
//     return 0;
// }
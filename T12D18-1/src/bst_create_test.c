#include "bst.h"

void bst_create_test(int item, int expected) {
    t_btree *root = bstree_create_node(item);
    printf("%d\n", root->item);
    if (root->item == expected)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(root);
}

int main() {
    bst_create_test(3, 3);
    bst_create_test(2, 2);
    bst_create_test(0, 0);
    return 0;
}
#include "bst.h"

void bst_insert_test(t_btree *root, const int *expected) {
    printf("%d %d\n", root->left->item, root->right->item);
    if (root->left->item == expected[0] && root->right->item == expected[1])
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(root->left);
    free(root->right);
}

int main() {
    t_btree *a = bstree_create_node(4);
    bstree_insert(a, 3, cmpf);
    bstree_insert(a, 5, cmpf);
    int *expected = (int *)malloc(2 * sizeof(int));
    expected[0] = 3;
    expected[1] = 5;
    bst_insert_test(a, expected);
    free(expected);
    free(a);
    return 0;
}
#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdlib.h>

int main() {
    BST* bst = (BST*)calloc(sizeof(BST),1);
    initBST(bst);
    insertBST(bst, 5);
    insertBST(bst, 2);
    insertBST(bst, 4);
    insertBST(bst, 1);
    insertBST(bst, 2);
    insertBST(bst, 1);
    insertBST(bst, 8);
    insertBST(bst, 9);
    insertBST(bst, 5);
    insertBST(bst, 8);
    insertBST(bst, 8);

    printTreeInorder(bst);
    printf("\n");
    int index = findIndexFromLast(bst, 6);
    printf("the index from last is: %d\n", index);
    (sameHeightLeaves(bst)) ? printf("Tree's leaves are at the same height\n"): printf("Tree's leaves are not at the same height\n");
    
    destroyBST(bst);
    return 0;
}

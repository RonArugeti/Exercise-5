//
//  BST.c
//  Exercise-5
//
//  Created by Ron Arugeti on 23/05/2022.
//

#include <assert.h>
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

#define IS_NULL(ptr) do{\
if((ptr) != NULL) printf("pointer is okey");\
else{ printf("pointer is NULL"); exit(1);}\
}while(0)

void initBST(BST* bst)
{
    IS_NULL(bst);
    bst->root->right = NULL;
    bst->root->left = NULL;
    bst->root->element = 0;
}

void insertBST(BST* bst, int value)
{
    BST* tempBst = (BST*)calloc(sizeof(BST),1);
    if(value <= (bst->root->element)){
        if((bst->root->left) == NULL){
            bst->root->left = (TreeNode*)calloc(sizeof(TreeNode),1);
        bst->root->left->element = value;
        }
        else{
            tempBst->root = bst->root->left;
            insertBST(tempBst, value);
            free(tempBst);
            tempBst = NULL;
        }
}
    if (value > bst->root->element) {
        if (bst->root->right == NULL){
            bst->root->right = (TreeNode*)calloc(sizeof(TreeNode),1);
            bst->root->right->element = value;
        }
        else{
            tempBst->root = bst->root->left;
            insertBST(tempBst, value);
            free(tempBst);
            tempBst = NULL;
    }
  }
}

void printTreeInorder(BST* bst)
{
    BST* tempBst = (BST*)calloc(sizeof(BST),1);
    if (bst->root != NULL)
    {
        tempBst->root = bst->root->left;
        printTreeInorder(tempBst);
        free(tempBst);
        tempBst = NULL;
        printf("%d,", bst->root->element);
        tempBst->root = bst->root->right;
        printTreeInorder(tempBst);
        free(tempBst);
        tempBst = NULL;
    }
}

void destroyBST(BST* bst)
{
    BST* tempBst = (BST*)calloc(sizeof(BST),1);
if (bst->root != NULL) {
    if (bst->root->left == NULL && bst->root->right == NULL){
        free(bst->root);
        bst->root = NULL;
    }
    if (bst->root->left != NULL && bst->root->right != NULL) {
        tempBst->root = bst->root->left;
        destroyBST(tempBst);
        free(tempBst);
        tempBst = NULL;
    }
    if (bst->root->left == NULL && bst->root->right != NULL) {
        tempBst->root = bst->root->right;
        destroyBST(tempBst);
        free(tempBst);
        tempBst = NULL;
    }
    if (bst->root->left != NULL && bst->root->right == NULL) {
        tempBst->root = bst->root->left;
        destroyBST(tempBst);
        free(tempBst);
        tempBst = NULL;
    }
}
    free(bst);
    bst = NULL;
}

int findIndexFromLast(BST* bst, int N)
{
    while (N >= 0) {
    if (bst->root != NULL) {
        BST* tempBst = (BST*)calloc(sizeof(BST),1);
        tempBst->root = bst->root->right;
        findIndexFromLast(tempBst, N);
       
        printf("%d", bst->root->element);
        tempBst->root = bst->root->left;
        findIndexFromLast(tempBst, --N);
        free(tempBst);
        tempBst->root = NULL;
    }}
        return bst->root->element;
        
}
    int sameHeightLeaves(BST* bst)
{
        BST* tempBst = (BST*)calloc(sizeof(BST),1);
    if (bst->root != NULL) return 0;
        tempBst->root = bst->root->left;
        int lh = sameHeightLeaves(tempBst);
        free(tempBst);
        tempBst->root = NULL;
        tempBst->root = bst->root->right;
        int rh = sameHeightLeaves(tempBst);
        free(tempBst);
               tempBst->root = NULL;
        return (lh == rh)?1:0;
}

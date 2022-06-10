#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

#define IS_NULL(ptr) do{\
if((ptr) != NULL) printf("Tree is NOT NULL\n");\
else{ printf("Tree is NULL\n"); exit(1);}\
}while(0)


void initBST(BST* bst)
{
    IS_NULL(bst);
    bst->root = (TreeNode*)calloc(sizeof(TreeNode),1);
    bst->root->right = NULL;
    bst->root->left = NULL;
}

void insertBST(BST* bst, int value)
{
    BST* tempBst = (BST*)calloc(sizeof(BST),1);
    if (!bst->root->element){
        bst->root->element = value; return;}
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
            tempBst->root = bst->root->right;
            insertBST(tempBst, value);
            free(tempBst);
            tempBst = NULL;
    }
  }
}

void printTreeInorder(BST* bst)
{
        if (bst->root != NULL)
        {
            BST* tempBst = (BST*)calloc(sizeof(BST),1);
            tempBst->root = bst->root->left;
            printTreeInorder(tempBst);
            printf("%d,", bst->root->element);
            tempBst->root = bst->root->right;
            printTreeInorder(tempBst);
            free(tempBst);
            tempBst = NULL;
        }
}

void destroyBST(BST* bst)
{
    destroyTreeNode(bst->root);
  
    free(bst);
    bst = NULL;
}

int findIndexFromLast(BST* bst, int N)
{
    static int n = 0;    // counter from form the end
    static int val = 0; // value to return from call
    if (bst->root != NULL) {
        BST* tempBst = (BST*)calloc(sizeof(BST),1);
        tempBst->root = bst->root->right;
        val = findIndexFromLast(tempBst, N);
        --n;
        if(n *(-1) == N)
        return bst->root->element;
        tempBst->root = bst->root->left;
        val = findIndexFromLast(tempBst, N);
        free(tempBst);
        tempBst->root = NULL;
    }
    return val;
}

int sameHeightLeaves(BST* bst)
{
    return !(heightRec(bst->root->left) - heightRec(bst->root->right));
    
}

int heightRec(TreeNode* root)
{
  if (root == NULL)
    return -1;

    int heLeft = 0;
    int heRight = 0;
    heLeft = 1+heightRec(root->left);
    heRight = 1+heightRec(root->right);
    return (heLeft > heRight)? heLeft: heRight;
}

void destroyTreeNode(TreeNode* root)
{
    if (root != NULL){
        destroyTreeNode(root->left);
        destroyTreeNode(root->right);
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root =  NULL;
        }
    }
}

//
//  main.c
//  Exercise-5
//
//  Created by Ron Arugeti on 22/05/2022.
//
#define _CRT_SECURE_NO_WRNINGS
#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

int main() {
    // insert code here...
    TreeNode *newNode, *root, *temp;
    int choice, key;
    char ans = 'N';
    do {
        printf("\n1.Create");
        printf("\n2.CreateTreeNode");
        printf("\n3.Search");
        printf("\n4.Recursive Traversals");
        printf("\n5.Exit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do {
            BST* bst = (BST*)calloc(sizeof(BST),1);
                   init
                } while (ans == 'Y');
                break;
            case 2:
                
                newNode = insertBST(bst, newNode->element)
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice %d, cohice");
                break;
        }
    } while (choice != 5);
    initBST(bst);
    
}

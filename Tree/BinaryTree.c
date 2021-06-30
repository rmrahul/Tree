//
//  BinaryTree.c
//  Tree
//
//  Created by Rahul Mane on 14/08/18.
//  Copyright © 2018 developer. All rights reserved.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>


struct BSTNode{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode * newNode(int data){
    struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

struct BSTNode* insertBST(struct BSTNode *root, int data){
    if(root==NULL){
        return newNode(data);
    }
    
    if(data <= root->data){
        //left side
        root -> left = insertBST(root->left, data);
    }
    else{
        root -> right = insertBST(root->right, data);
        //right side
    }
    return root;
}

void inorderBST(struct BSTNode *root){
    if(root != NULL){
        inorderBST(root->left);
        printf("[%d \t]",root->data);
        inorderBST(root->right);
    }
}

struct BSTNode * searchBSTNode(struct BSTNode *root,int dataToSearch,int level){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == dataToSearch){
        printf("Found at level : %d",level);
        return root;
    }
    else if(dataToSearch <= root->data){
        root = searchBSTNode(root->left, dataToSearch,++level);
    }
    else if(dataToSearch > root->data){
        root = searchBSTNode(root->right, dataToSearch,++level);
    }
    
    return root;
}

int countBST(struct BSTNode *root){
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return (1 + countBST(root->left) + countBST(root->right));
    }
}


int mainBST(){
    
    /* Let us create following BST
           50
         /     \
        30      70
       /  \    /  \
     20   40  60   80 */
    printf("\n\n\nSTARTED INSERT\n\n");
    struct BSTNode *root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    
    printf("\n\n\nSEARCH 60\n\n");
    
    struct BSTNode *searchNode = searchBSTNode(root, 123,0);
    if(searchNode != NULL){
        printf("Found node : %d",searchNode->data);
    }
    else{
        printf("NOT Found node :");
    }
    
    printf("\n\n\n COUNT\n\n");
    printf("%d \n",countBST(root));
    
    printf("\n\n\nPRINTING\n\n");
    inorderBST(root);
    
    printf("\n\n\nPROGRAM END\n\n");
    return 0;
}

//
//  Tree.c
//  Tree
//
//  Created by Rahul Mane on 13/08/18.
//  Copyright © 2018 developer. All rights reserved.
//

#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

int count = 0;



/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level){
    if (root == NULL){
        printf("\nPosition available at level : %d\n",level);
        return;
    }
    if (level == 1)
        printf("[%d]\t", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

int height(struct node* root){
    if(root == NULL){
        return 0;
    }else{
        int lDepth = height(root->left);
        int rDepth = height(root->right);
        
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

int degreeOfNode(struct node *root){
    if(root->right == NULL && root->left == NULL){
        return 0;
    }
    else if(root ->right == NULL || root->left == NULL){
        return 1;
    }
    return 2;
}

/* Print nodes at a given level */
struct node* getCorrectNode(struct node* root, int level){
    
    if (root->left == NULL){
        return root;
    }
    else if (root->right == NULL){
        return root;
    }
    else if (level > 1)
    {
    
        int degree = degreeOfNode(root->left);
        if(degree < 2){
            struct node *leftNode = getCorrectNode(root->left, level-1);
            if(leftNode->left == NULL || leftNode->right == NULL){
                return leftNode;
            }
        }
        else{
            struct node *rightNode =  getCorrectNode(root->right, level-1);
            if(rightNode->left == NULL || rightNode->right == NULL){
                return rightNode;
            }
        }
    }
    return NULL;
}


void display(struct node *root){
    if(root != NULL){
        display(root ->left);
        printf("Data : %d \t",root->data);
        display(root ->right);
    }
}


struct node * insert(struct node *root, int data){
    struct node *newNode;
    if(root == NULL){
        newNode = (struct node *)malloc(sizeof(struct node));
        root = newNode;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        count++;
    }
    else{
        
        int h = height(root);
        struct node *nodeToAdd = getCorrectNode(root, h);
        if(nodeToAdd == NULL){
            nodeToAdd = getCorrectNode(root, h+1);
        }
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        if(nodeToAdd->left == NULL){
            nodeToAdd->left = newNode;
        }
        else if(nodeToAdd -> right == NULL){
            nodeToAdd -> right = newNode;
        }
        else{
            printf("Not sure what to do..");
        }
        /*
         if(count%2 != 0){
         printf("Adding data to left \n");
         root->left = insert(root->left,data);
         }
         else{
         printf("Adding data to Right \n");
         root->right = insert(root->right,data);
         }
         */
        /*
         if(root->left == NULL){
         printf("Adding data to left \n");
         root->left = insert(root->left, data);
         }
         else if(root -> right == NULL){
         printf("Adding data to Right \n");
         root -> right = insert(root->right, data);
         }
         else{
         printf("Node is already full \n");
         //Node is already full... can't add anymore data...
         }*/
        
    }
    
    return root;
}


int mainTree(){
    int choice, value;
    struct node *root = NULL;
    
    printf("----- BINARY TREE-----");
    
    while (1) {
        printf("\n\n\n\n----- MENU-----");
        printf("\n\n1.Insert");
        printf("\n\n2.Display");
        printf("\n\n3.Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: printf("\nEnter the value to be insert: ");
                scanf("%d", &value);
                root = insert(root,value);
                break;
            case 2: printLevelOrder(root); break;
            case 3: exit(0);
            default: printf("\nPlease select correct operations!!!\n");
        }
    }
    
    return 0;
}

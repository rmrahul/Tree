//
//  LinkList.c
//  Tree
//
//  Created by Rahul Mane on 13/08/18.
//  Copyright © 2018 developer. All rights reserved.
//

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * insertInLinkedList(struct node *currentNode, int data){
    
    if(currentNode == NULL){
        currentNode = (struct node *) malloc(sizeof(struct node));
        currentNode->data = data;
        currentNode->next = NULL;
    }
    else{
        struct node *temp;
        
        temp = (struct node *) malloc(sizeof(struct node));
        currentNode->next = temp;
        
        temp->data = data;
        temp->next = NULL;
        
        currentNode = temp;
    }
    return currentNode;
}

void print(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("[ %d : next] --> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

void printRev(struct node *head){
    if(head == NULL){
        printf("NULL");
    }
    else{
        printRev(head->next);
        printf(" <-- [ %d: rev]",head->data);
    }
}

int mainLinkList()
{
    int linkedListSize;
    struct node *HEAD = NULL;
    struct node *current = NULL;
    
    printf("Program to print reverse linked list : Enter size\n");
    scanf("%d",&linkedListSize);
    
    printf("Enter elements for size : %d\n",linkedListSize);
    
    while(linkedListSize-- > 0){
        int data;
        scanf("%d",&data);
        
        current = insertInLinkedList(current,data);
        if(HEAD == NULL){
            HEAD = current;
        }
    }
    
    printf("=== Printing NORMAL ====\n");
    print(HEAD);
    printf("=== Printing REVERSE ====\n");
    printRev(HEAD);
    
    printf("\n\n\n=== PROGRAM ENDS ====\n\n\n");
    return 0;
}


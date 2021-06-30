//
//  Graph.c
//  Tree
//
//  Created by Rahul Mane on 19/08/18.
//  Copyright © 2018 developer. All rights reserved.
//

#include "Graph.h"

struct graphNode{
    int vertex;
    struct graphNode *next;
};

struct Graph{
    int numOfVertices;
    struct graphNode ** adjList;
    int *visited;
};

struct graphNode * createNode(int data){
    struct graphNode *newNode = (struct graphNode *) malloc(sizeof(struct graphNode));
    newNode -> vertex = data;
    newNode -> next = NULL;
    return newNode;
}
struct Graph * createGraph(int vertices){
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph -> numOfVertices = vertices;
    graph -> adjList = malloc(vertices * sizeof(struct graphNode));
    graph -> visited = malloc(vertices * sizeof(int));
    
    for(int i = 0;i < vertices; i++){
        graph -> adjList[i] = NULL;
        graph -> visited[i] = 0;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct graphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numOfVertices; v++)
    {
        struct graphNode* temp = graph->adjList[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph* graph, int vertex) {
    struct graphNode* adjList = graph->adjList[vertex];
    struct graphNode* temp = adjList;
    
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);
    
    while(temp!=NULL) {
        int connectedVertex = temp->vertex;
        
        if(graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int mainGraph(){
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    printGraph(graph);

    
    //DFS(graph,0);
    //DFS(graph,1);
    DFS(graph,2);
    return 0;
}

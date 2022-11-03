
//Prueba basado en el codigo encontrado

#include <stdio.h>
#include <stdlib.h>

//Define the maximun number of vertices in the graph
#define N 10

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct graphNode* head[N];
};
 
// Data structure to store adjacency list nodes of the graph
struct graphNode
{
	int ID;
	char description;
	char type;
	char effort;
	int time;
	char dutyManager;
	int destID;
    struct Node* next;
};
 
// Data structure to store a graph edge
struct Edge {
    int ID, destID, effort;
};



int main(void){
	return 0;
}

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    // initialize head pointer for all vertices
    int i;
    for (i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
 
    // add edges to the directed graph one by one
    for (i = 0; i < n; i++)
    {
        // get the source and destination vertex
        int ID = edges[i].ID;
        int destID = edges[i].destID;
        int effort = edges[i].effort;
 
        // allocate a new node of adjacency list from src to dest
        struct graphNode* newNode = (struct graphNode*)malloc(sizeof(struct graphNode));
        newNode->destID = destID;
        newNode->effort = effort;
 
        // point new node to the current head
        newNode->next = graph->head[ID];
 
        // point head pointer to the new node
        graph->head[ID] = newNode;
    }
 
    return graph;
}

// Function to print adjacency list representation of a graph
void printGraph(struct Graph* graph)
{
	int i;
    for (i = 0; i < N; i++)
    {
        // print current vertex and all its neighbors
        struct graphNode* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("%d —> %d (%d)\t", i, ptr->destID, ptr->effort);
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}

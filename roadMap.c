
// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<process.h>
#include<string.h> 
#define infinity 1000;



// A structure to represent an adjacency list node
struct AdjacentListNode
{
    int index;
    int time;
    char line;
    struct AdjacentListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjacentList
{
    struct AdjacentListNode *start;  // pointer to start node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct TownGraph
{
    int vertex;
    struct AdjacentList* column;
};
 
// A utility function to create a new adjacency list node
struct AdjacentListNode* newAdjacentListNode(int index,int time,char line)
{
    struct AdjacentListNode* newNode =
            (struct AdjacentListNode*) malloc(sizeof(struct AdjacentListNode));
    newNode->index = index;
    newNode->time=time;
    newNode->next = NULL;
    newNode->line= line;
    return newNode;
}
 
// A utility function that creates a TownGraph ofvertexvertexertices
struct TownGraph* createTownGraph(int vertex)
{
    struct TownGraph* graph = (struct TownGraph*) malloc(sizeof(struct TownGraph));
    graph->vertex = vertex;
 
    // Create an column of adjacency lists.  Size of column will bevertex
    graph->column = (struct AdjacentList*) malloc(vertex * sizeof(struct AdjacentList));
 
     // Initialize each adjacency list as empty by making start as NULL
    int i;
    for (i = 0; i <vertex; ++i)
        graph->column[i].start = NULL;
 
    return graph;
}

char neww;
int hours,minutes;
float SumOfTheDistances,weight;

float *Dijkstra( struct TownGraph* graph,int StartingTown,int EndTown);
struct AdjacentListNode* newAdjacentListNode(int index,int time,char line);
char SearchLine(struct TownGraph* graph,int source, int indexx);
float SearchWeight(struct TownGraph* graph,int source, int indexx);
char * Return_city(int CityTemp[], int y);
// Adds an edge to an undirected graph
float addEdge(struct TownGraph* graph, int source, int index,int time,char line)
{

    // Add an edge from source to dest.  A new node is added to the adjacency
    // list of source.  The node is added at the begining
    struct AdjacentListNode* newNode = newAdjacentListNode(index,time,line);
    newNode->next = graph->column[source].start;
    graph->column[source].start = newNode;
 
    // Since graph is undirected, add an edge from dest to source also
    newNode = newAdjacentListNode(source,time,line);
    newNode->time=time;
    newNode->line=line;
    newNode->next = graph->column[index].start;
    graph->column[index].start = newNode;
    
    
}
 

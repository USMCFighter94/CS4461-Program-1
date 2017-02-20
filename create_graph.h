#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#define MAX_DEGREE 3
#define MIN_DEGREE 1
#define NUMBER_OF_BRIDGES 10
typedef unsigned int vertex;
typedef struct Node {
       int vertexNum;
       struct Node *next;
} Node;

typedef struct List{
           Node *head;
} List;

void mallocGraph(void);
List** createGraph(void);
void printList(void);
void addNode(int nodeA, int nodeB);
int getRandomEdge(void);
void freeGraph(void);

#endif

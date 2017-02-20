#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#define MAX_DEGREE 3
#define MIN_DEGREE 1
#define NUMBER_OF_BRIDGES 10
typedef unsigned int vertex;

vertex*** mallocGraph(void);
vertex*** createGraph(void);
void freeGraph(vertex***);
int getRandomEdge(void);

#endif

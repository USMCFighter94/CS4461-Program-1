#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#define MAX_DEGREE 3
#define MIN_DEGREE 1
#define NUMBER_OF_BRIDGES 10
typedef unsigned char vertex;

vertex*** createGraph(void);
vertex*** mallocGraph(void);
int getRandomEdge(void);

#endif

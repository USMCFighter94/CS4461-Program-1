#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#define MAX_DEGREE_CONNECT 3
#define NUMBER_OF_BRIDGES 10
typedef unsigned char vertex;

vertex*** createGraph(void);
vertex*** mallocGraph(vertex ***graph);

#endif

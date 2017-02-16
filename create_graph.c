#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create_graph.h"

vertex*** createGraph(void) {
  vertex ***graph = NULL;
  graph = mallocGraph(graph);

  srand(time(NULL));
  int vertexes, edges;

  for (vertexes = 0; vertexes < NUMBER_OF_BRIDGES; vertexes++) {
    printf("%d:\t", vertexes);
    for (edges = 0; edges < MAX_DEGREE_CONNECT; edges++) {
      if (rand() % 2 == 1) {
        int linkedVertex = rand() % NUMBER_OF_BRIDGES;
        graph[vertexes][edges] = *graph[linkedVertex];
        printf("%d, ", linkedVertex);
      } else
        graph[vertexes][edges] = NULL;
    }
    printf("\n");
   }
   return graph;
}

vertex*** mallocGraph(vertex ***graph) {
  if ((graph = (vertex ***) malloc(sizeof(vertex **) * NUMBER_OF_BRIDGES)) == NULL) {
    printf("Graph memory allocation error\n");
    exit(1);
  }

  int vertexCounter = 0, edgeCounter = 0;

  for (; vertexCounter < NUMBER_OF_BRIDGES; vertexCounter++) {
    if ((graph[vertexCounter] = (vertex **) malloc(sizeof(vertex *) * MAX_DEGREE_CONNECT)) == NULL) {
      printf("Edge memory allocation error\n");
      exit(1);
    }

    for (; edgeCounter < MAX_DEGREE_CONNECT; edgeCounter++) {
      if ((graph[vertexCounter][edgeCounter] = (vertex *) malloc(sizeof(vertex))) == NULL) {
        printf("Vertex memory allocation error\n");
        exit(1);
      }
    }
  }
  return graph;
}

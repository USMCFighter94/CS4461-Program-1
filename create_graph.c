#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create_graph.h"

int main(void) {
  vertex ***graph = NULL;
  graph = mallocGraph(graph);

  srand(time(NULL));
  int vertexes, edges;

  for (vertexes = 0; vertexes < 10; vertexes++) {
    printf("%d:\t", vertexes);
    for (edges = 0; edges < 3; edges++) {
      if (rand() % 2 == 1) {
        int linkedVertex = rand() % 10;
        graph[vertexes][edges] = *graph[linkedVertex];
        printf("%d, ", linkedVertex);
      } else
        graph[vertexes][edges] = NULL;
    }
    printf("\n");
   }
   return 0;
}

vertex*** mallocGraph(vertex ***graph) {
  if ((graph = (vertex ***) malloc(sizeof(vertex **) * 10)) == NULL) {
    printf("Graph memory allocation error\n");
    exit(1);
  }

  int vertexCounter = 0, edgeCounter = 0;

  for (; vertexCounter < 10; vertexCounter++) {
    if ((graph[vertexCounter] = (vertex **) malloc(sizeof(vertex *) * 3)) == NULL) {
      printf("Edge memory allocation error\n");
      exit(1);
    }

    for (; edgeCounter < 3; edgeCounter++) {
      if ((graph[vertexCounter][edgeCounter] = (vertex *) malloc(sizeof(vertex))) == NULL) {
        printf("Vertex memory allocation error\n");
        exit(1);
      }
    }
  }
  return graph;
}

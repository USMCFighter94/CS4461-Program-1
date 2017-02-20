#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create_graph.h"

int usedVertex[MAX_DEGREE] = {-1}, usedVertexCounter = 0;

vertex*** createGraph(void) {
  vertex ***graph = mallocGraph();
  int vertexes, edges, randEdge, i;

  srand(time(NULL));

  for (vertexes = 0; vertexes < NUMBER_OF_BRIDGES; vertexes++) {
    printf("%d:\t", vertexes);
    for (edges = 0, usedVertexCounter = 0; edges < MAX_DEGREE; edges++) {
      if (rand() % 2 == 1) {
        randEdge = getRandomEdge();
        if (randEdge != -1) {
          graph[vertexes][edges] = *graph[randEdge];
          printf("%d, ", randEdge);
        } else
            break;
      } else {
        /* Make sure every bridge has at least one connection */
        if (edges == (MAX_DEGREE - 1) && usedVertexCounter == 0) {
          randEdge = getRandomEdge();
          graph[vertexes][edges] = *graph[randEdge];
          printf("%d, ", randEdge);
        } else
            graph[vertexes][edges] = NULL;
      }
    }
    printf("\n");
    /* Reset edge trackers */
    for (i = 0; i < MAX_DEGREE; i++)
      usedVertex[i] = -1;
   }
   return graph;
}

int getRandomEdge() {
  int linkedVertex = rand() % NUMBER_OF_BRIDGES, i; /* Get random bridge */
  usedVertex[usedVertexCounter++] = linkedVertex; /* Add it to the list of used */
  if (usedVertexCounter == 1) /* First edge in graph, can just return without check */
    return linkedVertex;

  for (i = 0; i < MAX_DEGREE; i++) /* Check if edge already exists */
    if (i != (usedVertexCounter - 1) && usedVertex[i] == linkedVertex) {
      linkedVertex = -1;
      usedVertexCounter--;
      break;
    }
  return linkedVertex;
}

vertex*** mallocGraph(void) {
  vertex ***graph = NULL;
  int vertexCounter = 0, edgeCounter = 0;

  if ((graph = (vertex ***) malloc(sizeof(vertex **) * NUMBER_OF_BRIDGES)) == NULL) {
    printf("Graph memory allocation error\n");
    exit(1);
  }

  for (; vertexCounter < NUMBER_OF_BRIDGES; vertexCounter++) {
    if ((graph[vertexCounter] = (vertex **) malloc(sizeof(vertex *) * MAX_DEGREE)) == NULL) {
      printf("Edge memory allocation error\n");
      exit(1);
    }

    for (; edgeCounter < MAX_DEGREE; edgeCounter++) {
      if ((graph[vertexCounter][edgeCounter] = (vertex *) malloc(sizeof(vertex))) == NULL) {
        printf("Vertex memory allocation error\n");
        exit(1);
      }
    }
  }
  return graph;
}

void freeGraph(vertex ***graph) {
  int i = 0, j = 0;
  for (; i < NUMBER_OF_BRIDGES; i++) {
    for (; j < MAX_DEGREE; j++) {
      free(graph[i][j]);
    }
    free(graph[i]);
  }
  free(graph);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEGREE_CONNECT 3

typedef unsigned char vertex;

int main(void) {
  vertex ***graph;
  srand(time(NULL));

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

  for (vertexCounter = 0; vertexCounter < 10; vertexCounter++) {
    printf("%d:\t", vertexCounter);
    for (edgeCounter = 0; edgeCounter < 3; edgeCounter++) {
      if (rand() % 2 == 1) {
        int linkedVertex = rand() % 10;
        graph[vertexCounter][edgeCounter] = *graph[linkedVertex];
        printf("%d, ", linkedVertex);
      } else
        graph[vertexCounter][edgeCounter] = NULL;
    }
    printf("\n");
   }
   return 0;
}

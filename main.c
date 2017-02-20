#include <stdio.h>
#include <stdlib.h>
#include "create_graph.h"

int main(void) {
  vertex ***graph = createGraph();
  printf("Pointer == %p\n", &graph);

  freeGraph(graph);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "create_graph.h"

int main(void) {
  List** graph = createGraph();

  printf("\n\n\n");
  printList();
  freeGraph();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "create_graph.h"

List** graph;

void sendMessage(int believedRoot, int distanceFromRoot, int IDOfNode, int dest, int msgNum) {
  printf("<%d, %d, %d>\n", believedRoot, distanceFromRoot, IDOfNode);

  Message newMessage;
  newMessage.sourceNode = IDOfNode;
  newMessage.rootNode = believedRoot;
  newMessage.distance = distanceFromRoot;

  graph[dest]->head->lastReceievedMessages[msgNum] = newMessage;
}

void initConfigMessage(Node* bridge, int nodeNum) {
  int i = 0;

  printf("Bridge vertexNum == %d\n", bridge->vertexNum);
  while (bridge) {
    int dest = bridge->vertexNum;
    if (dest != nodeNum)
      sendMessage(nodeNum, 0, nodeNum, dest, i++);
    bridge = bridge->next;
  }
}

int main(void) {
  int i, j;
  graph = createGraph();

  for (i = 0; i < NUMBER_OF_BRIDGES; i++) {
    initConfigMessage(graph[i]->head, graph[i]->head->vertexNum);
  }

  // for (i = 0; i < NUMBER_OF_BRIDGES; i++) {
  //   printf("\n");
  //   Node* p = graph[i]->head;
  //   while (p) {
  //     for (j = 0; j < MAX_DEGREE; j++) {
  //       Message tmpMsg = p->lastReceievedMessages[j];
  //       printf("<%d, %d, %d>\n", tmpMsg.rootNode, tmpMsg.distance, tmpMsg.sourceNode);
  //     }
  //     p = p->next;
  //   }
  //   printf ("\n");
  // }

  freeGraph();
  return 0;
}

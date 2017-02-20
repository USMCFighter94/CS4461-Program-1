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

  Node* destNode = graph[dest]->head;
  destNode->lastReceievedMessages[msgNum] = newMessage;
  graph[dest]->head = destNode;

  //graph[dest]->head->lastReceievedMessages[msgNum] = newMessage;
}

void initConfigMessage(Node* bridge) {
  int i = 0;
  int nodeNum = bridge->vertexNum;
  while (bridge) {
    int dest = bridge->vertexNum;
    if (dest != nodeNum)
      sendMessage(nodeNum, 0, nodeNum, dest, i++);
    bridge = bridge->next;
  }
}



int main(void) {
  int i;
  List** graph = createGraph();
  for (i = 0; i < NUMBER_OF_BRIDGES; i++) {
    initConfigMessage(graph[i]->head);
  }

  freeGraph();
  return 0;
}

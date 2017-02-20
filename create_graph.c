#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create_graph.h"

List* graph[NUMBER_OF_BRIDGES] = {0};
int usedVertex[MAX_DEGREE] = {-1}, usedVertexCounter = 0;

void mallocGraph(void) {
  int i;
  for (i = 0; i < NUMBER_OF_BRIDGES; i++){
    graph[i] = (List *) malloc(sizeof(List));
    graph[i]->head = NULL;
  }
}

List** createGraph(void) {
  mallocGraph();
  int vertex, edge, randEdge, i;
  srand(time(NULL));

  for (vertex = 0; vertex < NUMBER_OF_BRIDGES; vertex++) {
    printf("%d:\t", vertex);
    for (edge = 0, usedVertexCounter = 0; edge < MAX_DEGREE; edge++) {
      if (rand() % 2 == 1) {
        randEdge = getRandomEdge();
        if (randEdge != -1 && randEdge != vertex) {
          addNode(vertex, randEdge);
          printf("%d, ", randEdge);
        } else
            break;
      } else {
        /* Make sure every bridge has at least one connection */
        if (edge == (MAX_DEGREE - 1) && usedVertexCounter == 0) {
          randEdge = getRandomEdge();
          addNode(vertex, randEdge);
          printf("%d, ", randEdge);
        }
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

void addNode(int nodeA, int nodeB) {
  if (graph[nodeA]->head == NULL) {
    Node* src = (Node *) malloc(sizeof(Node));
    src->vertexNum = nodeA;
    src->next = NULL;
    graph[nodeA]->head = src;
  }

  Node* dest = (Node *) malloc(sizeof(Node));
  dest->vertexNum = nodeB;
  dest->next = NULL;
  Node* tmp = graph[nodeA]->head;

  while (tmp->next != NULL)
    tmp = tmp->next;

  tmp->next = dest;
}

void printList(void){
  int i;
  for (i = 0; i < NUMBER_OF_BRIDGES; i++) {
    Node* p = graph[i]->head;
    printf("%d:\t", i);
    while (p){
      int num = p->vertexNum;
      if (num != i)
        printf ("%d, ", p->vertexNum);
      p = p->next;
    }
    printf ("\n");
  }
}

void freeGraph(void){
  int i;
  for (i = 0; i < NUMBER_OF_BRIDGES; i++){
    Node* p = graph[i]->head;
    while (p) {
      p = p->next;
      free(p);
    }
    free(p);
  }
}

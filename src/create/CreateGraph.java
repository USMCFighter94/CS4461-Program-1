package create;

import helpers.Node;

import java.util.ArrayList;
import java.util.Random;


public class CreateGraph {

	ArrayList<Node> graph = new ArrayList<>();
	int usedVertex[] = {-1, -1, -1}, usedVertexCounter = 0;

	public ArrayList<Node> createGraph() {
		int vertex, edge, randEdge, i;

		for (vertex = 0; vertex < 10; vertex++) {
			System.out.print(vertex + ":\t");
			Node newNode = new Node();
			newNode.setVertexNum(vertex);

			ArrayList<Integer> edgeList = new ArrayList<>();
			for (edge = 0, usedVertexCounter = 0; edge < 3; edge++) {

				if (randInt(0, 1) == 1) {
					randEdge = getRandomEdge();
					if (randEdge != -1 && randEdge != vertex) {
						edgeList.add(randEdge);
						System.out.print(randEdge + ", ");
						randEdge = -1;
					} else
						continue;
				} else {
					/* Make sure every bridge has at least one connection to start */
					if (edge == (2) && usedVertexCounter == 0) {
						randEdge = getRandomEdge();
						edgeList.add(randEdge);
						System.out.print(randEdge + ", ");
						randEdge = -1;
					}
				}
			}
			System.out.println("");
			/* Reset edge trackers */
			for (i = 0; i < 3; i++)
				usedVertex[i] = -1;

			newNode.setConnectedBridges(edgeList);
			newNode.setRootPort(vertex);
			newNode.setDistanceToRoot(0);
			graph.add(newNode);
		}
		return graph;
	}

	int getRandomEdge() {
		int linkedVertex = randInt(0, 9), i; /* Get random bridge */
		usedVertex[usedVertexCounter++] = linkedVertex; /* Add it to the list of used */

		if (usedVertexCounter == 1) /* First edge in graph, can just return without check */
			return linkedVertex;

		for (i = 0; i < 3; i++) /* Check if edge already exists */
			if (i != (usedVertexCounter - 1) && usedVertex[i] == linkedVertex) {
				linkedVertex = -1;
				usedVertexCounter--;
				break;
			}
		return linkedVertex;
	}

	public static int randInt(int min, int max) {
		Random rand = new Random();
		return rand.nextInt((max - min) + 1) - min;
	}
}

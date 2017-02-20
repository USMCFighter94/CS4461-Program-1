package graph;

import graph.Node;

import java.util.ArrayList;
import java.util.Random;


public class CreateGraph {

	ArrayList<Node> graph = new ArrayList<>();
	int usedVertex[] = {-1, -1, -1}, usedVertexCounter = 0;

	public ArrayList<Node> createGraph() {
		int vertex, edge, randEdge, i;
		
		for (vertex = 0; vertex < 10; vertex++) { // Initialize all nodes
			Node newNode = new Node();
			ArrayList<Integer> edgeList = new ArrayList<>();
			
			newNode.setVertexNum(vertex);
			newNode.setRootPort(vertex);
			newNode.setDistanceToRoot(0);
			newNode.setConnectedBridges(edgeList);
			
			graph.add(newNode);
		}

		for (vertex = 0; vertex < 10; vertex++) {
			System.out.print(vertex + ":\t");

			ArrayList<Integer> edgeList = graph.get(vertex).getConnectedBridges();
			for (edge = 0, usedVertexCounter = 0; edge < 3; edge++) {
				if (randInt(0, 1) == 1 || edge == 0) { // random unless first time to ensure every vertex has at least one
					randEdge = getRandomEdge();
					if (randEdge != -1 && randEdge != vertex) {
						edgeList.add(randEdge);
						addToConnectedBridge(randEdge, vertex);
						System.out.print(randEdge + ", ");
						randEdge = -1;
					} else
						continue;
				}
			}
			System.out.println("");
			/* Reset edge trackers */
			for (i = 0; i < 3; i++)
				usedVertex[i] = -1;
		}
		return graph;
	}
	
	void addToConnectedBridge(int source, int edgePair) {
		ArrayList<Integer> edgeList = graph.get(source).getConnectedBridges();
		boolean found = false;
		
		for (int i = 0; i < edgeList.size(); i++) {
			if (edgeList.get(i) == edgePair) {
				found = true;
				break;
			}
		}
		
		if (!found) {
			edgeList.add(edgePair);
			graph.get(source).setConnectedBridges(edgeList);
		}
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

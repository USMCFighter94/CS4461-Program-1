import helpers.Message;
import helpers.Node;
import create.CreateGraph;

import java.util.ArrayList;


public class Network {

	private static ArrayList<Node> graph;

	static void sendMessage(int believedRoot, int distanceFromRoot, int IDOfNode, int dest) {
		System.out.println("<" + believedRoot + ", " + distanceFromRoot + ", " + IDOfNode + ">");

		Message newMessage = new Message();
		newMessage.setSourceNode(IDOfNode);
		newMessage.setRootNode(believedRoot);
		newMessage.setDistance(distanceFromRoot);

		graph.get(dest).addLastReceivedMessage(newMessage);
	}

	static void initConfigMessage(Node bridge) {
		int nodeNum = bridge.getVertexNum();
		ArrayList<Integer> connected = bridge.getConnectedBridges();

		for (int i = 0; i < connected.size(); i++) {
			int dest = connected.get(i);
			sendMessage(nodeNum, 0, nodeNum, dest);
		}
	}

	public static void main(String[] args) {
		CreateGraph create = new CreateGraph();
		graph = create.createGraph();

		for (int i = 0; i < 10; i++) {
			initConfigMessage(graph.get(i));
		}
		

		System.out.println("");

		for (int i = 0; i < 10; i++) {
			Node p = graph.get(i);
			ArrayList<Message> messages = p.getLastReceievedMessages();

			if (messages.size() == 0)
				continue;

			for (int j = 0; j < 1; j++) {
				Message tmpMsg = p.getLastReceievedMessages().get(j);
				System.out.println("<" + tmpMsg.getRootNode() + ", " + tmpMsg.getDistance() + ", " + tmpMsg.getSourceNode() + ">");
			}
		}
	}
}

import helpers.Message;
import helpers.Node;
import create.CreateGraph;

import java.util.ArrayList;

public class Network {

	private static ArrayList<Node> graph;

	static void sendMessage(int believedRoot, int distanceFromRoot, int IDOfNode, int dest) {
		System.out.println("<" + believedRoot + ", " + distanceFromRoot + ", " + IDOfNode + ">"); // Print out current message

		Message newMessage = new Message();
		newMessage.setSourceNode(IDOfNode);
		newMessage.setRootNode(believedRoot);
		newMessage.setDistance(distanceFromRoot);

		graph.get(dest).addLastReceivedMessage(newMessage); // Send message to destination
	}

	static void message(Node bridge) {
		int nodeNum = bridge.getVertexNum(), root = bridge.getRootPort(), distance = bridge.getDistanceToRoot();
		ArrayList<Integer> connected = bridge.getConnectedBridges();

		for (int i = 0; i < connected.size(); i++) {
			int dest = connected.get(i);
			sendMessage(root, distance, nodeNum, dest);
		}
	}

	static void checkForNewRoot(Node node) {
		ArrayList<Message> messages = node.getLastReceievedMessages();

		for (int i = 0; i < messages.size(); i++) {
			Message tmpMsg = messages.get(i);
			int msgRoot = tmpMsg.getRootNode(), nodeRoot = node.getRootPort(), source = tmpMsg.getSourceNode(), current = node.getVertexNum();

			if (msgRoot < nodeRoot) { // This message is from a root bridge with a smaller ID, so update
				node.setRootPort(msgRoot);
				node.setDistanceToRoot(tmpMsg.getDistance() + 1);
			} else if (msgRoot < nodeRoot && tmpMsg.getDistance() < node.getDistanceToRoot()) { // Claims same root, but shorter distance
				node.setRootPort(msgRoot);
				node.setDistanceToRoot(tmpMsg.getDistance() + 1);
			} else if (msgRoot < nodeRoot && tmpMsg.getDistance() == node.getDistanceToRoot() && tmpMsg.getSourceNode() < node.getVertexNum()) { // Same root and distance, but smaller ID
				node.setRootPort(msgRoot);
				node.setDistanceToRoot(tmpMsg.getDistance() + 1);
			}

			if (source > current) // This is now a designated port
				node.setDesignatedPort(source);
			else
				node.setBlockedPort(source);
		}
	}

	public static void main(String[] args) {
		int numWithIncorrectRoot = 0;
		CreateGraph create = new CreateGraph();
		graph = create.createGraph();

//		do {
		for (int i = 0; i < 50; i++) {
			numWithIncorrectRoot = 0;
			for (int j = 0; j < 10; j++)
				message(graph.get(j));

			System.out.println("");

			for (int j = 0; j < 10; j++) {
				Node node = graph.get(j);
				checkForNewRoot(node);
				message(node);
			}

			System.out.println("");

			for (int j = 0; j < 10; j++) {
				Node node = graph.get(j);
				if (node.getRootPort() == node.getVertexNum() && node.getVertexNum() != 0)
					numWithIncorrectRoot++;
			}
			System.out.println("Number with Incorrect Root = "  + numWithIncorrectRoot);
			System.out.println("");
//		} while (numWithIncorrectRoot != 0);
		}
	}
}

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
	
	static void checkForNewRoot(Node node) {
		ArrayList<Message> messages = node.getLastReceievedMessages();
		
		for (int i = 0; i < messages.size(); i++) {
			Message tmpMsg = messages.get(i);
			int msgRoot = tmpMsg.getRootNode(), nodeRoot = node.getRootPort();
			
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
			System.out.println("<" + node.getRootPort() + ", " + node.getDistanceToRoot() + ", " + node.getVertexNum() + ">");
			ArrayList<Message> nullArray = new ArrayList<>();
			node.setLastReceievedMessages(nullArray);
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
			Node node = graph.get(i);
			checkForNewRoot(node);
		}
	}
}

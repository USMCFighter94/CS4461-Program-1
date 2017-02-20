package helpers;

import java.util.ArrayList;

public class Node {
	int vertexNum, distanceToRoot, rootPort, designatedPort, blockedPort;
    ArrayList<Integer> connectedBridges = new ArrayList<>();
    ArrayList<Message> lastReceievedMessages = new ArrayList<>();
    
	public int getVertexNum() {
		return vertexNum;
	}

	public void setVertexNum(int vertexNum) {
		this.vertexNum = vertexNum;
	}
	
	public int getDistanceToRoot() {
		return distanceToRoot;
	}
	
	public void setDistanceToRoot(int distanceToRoot) {
		this.distanceToRoot = distanceToRoot;
	}
	
	public int getRootPort() {
		return rootPort;
	}
	
	public void setRootPort(int rootPort) {
		this.rootPort = rootPort;
	}
	
	public int getDesignatedPort() {
		return designatedPort;
	}
	
	public void setDesignatedPort(int designatedPort) {
		this.designatedPort = designatedPort;
	}
	
	public int getBlockedPort() {
		return blockedPort;
	}
	
	public void setBlockedPort(int blockedPort) {
		this.blockedPort = blockedPort;
	}
	
	public ArrayList<Integer> getConnectedBridges() {
		return connectedBridges;
	}

	public void setConnectedBridges(ArrayList<Integer> connectedBridges) {
		this.connectedBridges = connectedBridges;
	}
	
	public ArrayList<Message> getLastReceievedMessages() {
		return lastReceievedMessages;
	}
	
	public void setLastReceievedMessages(ArrayList<Message> lastReceievedMessages) {
		this.lastReceievedMessages = lastReceievedMessages;
	}
	
	public void addLastReceivedMessage(Message message) {
		lastReceievedMessages.add(message);
	}
}

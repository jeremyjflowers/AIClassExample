#include "Edge.h"
#include "Node.h"
#include <raylib.h>

Edge::Edge(Node* node1, Node* node2)
{
	connectedNode1 = node1;
	connectedNode2 = node2;
}

void Edge::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Update the position to match the position of the first connected node
	setWorldPostion(connectedNode1->getWorldPosition());
}

void Edge::draw()
{
	//Draws aline to represent each edge on the graph
	DrawLine(getWorldPosition().x * 32, getWorldPosition().y * 32, connectedNode2->getWorldPosition().x * 32, connectedNode2->getWorldPosition().y * 32, WHITE);
}

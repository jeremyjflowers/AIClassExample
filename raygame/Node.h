#pragma once
#include "Actor.h"
#include <vector>

class Edge;

class Node : public Actor
{
public:
	Node(int x, int y, int nodeSize);
	std::vector<Edge*> edges;
	MathLibrary::Vector2 graphPosition;
	float gScore;
	int color = 0xFFFFFFFF;
	int size = 1;
	bool visited;
	void draw()override;
	void update(float deltaTime) override;
};
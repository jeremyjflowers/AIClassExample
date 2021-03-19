#pragma once
#include "SteeringBehaviour.h"
#include <Vector2.h>

class WanderBehaviour : public SteeringBehaviour
{
public:
	WanderBehaviour();
	WanderBehaviour(Agent* agent, float circleRadius);
	void setAngle();
	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* agent, float deltatime) override;
private:
	Agent* m_target;
	float m_wanderForce;
	float m_circleRadius = 1;
};
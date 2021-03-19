#include "WanderBehaviour.h"
#include <vector>
#include "Agent.h"

WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	m_circleRadius = 5;
}

WanderBehaviour::WanderBehaviour(Agent* agent, float circleRadius)
{
	m_circleRadius = circleRadius;
	m_target = agent;
}

//forward * preferred distance
//add player worldPosition to worldposition then multiply be previous one
//just get the circles position relative to the player and add that to the players worldPosition
//This is how you get the circle displace from the player

void WanderBehaviour::setAngle()
{

}

MathLibrary::Vector2 WanderBehaviour::calculateForce(Agent* agent)
{
	//Initalize variables to help with calculating wander
	float circleDistance = 3;
	float circleRadius = 6;
	float wanderAngle = 20;

	//Calculating the circles center
	MathLibrary::Vector2 circleCenter = agent->getForward() * circleDistance;
	//Calculating the wanderAngle to make the change per frame as dramatic as possible
	wanderAngle += (wanderAngle * rand()) - (wanderAngle * 100.0f);
	//Calculating the direction at which the agent will head when wandering
	MathLibrary::Vector2 direction = MathLibrary::Vector2(cos(wanderAngle), sin(wanderAngle));
	//math to calculate WanderForce that the agent will head towards.
	MathLibrary::Vector2 WanderForce = circleCenter + (direction * circleRadius);

	return WanderForce;
}

void WanderBehaviour::update(Agent* agent, float deltatime)
{
	//If the agent isn't null, calculate a new force and add it to the agent
	if (agent)
		agent->addForce(calculateForce(agent));

}
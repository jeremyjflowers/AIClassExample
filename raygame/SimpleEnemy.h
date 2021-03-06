#pragma once
#include "Enemy.h"

enum EnemyState
{
	WANDER,
	SEEK
};

class WanderBehaviour;
class SeekBehaviour;

class SimpleEnemy :
	public Enemy
{
	using Enemy::Enemy;
	bool checkTargetInSight();

	void onCollision(Actor* other) override;
	void start() override;
	void update(float deltaTime) override;

	void setTarget(Actor* target) override;

private:
	EnemyState m_currentState;
	WanderBehaviour* m_wander;
	SeekBehaviour* m_seek;
};

#pragma once
#include "PlacableActor.h"
class Dog : public PlacableActor
{
public:
	Dog(int x, int y, int deltaX = 0, int deltaY = 0);

	virtual ActorType GetType() override { return ActorType::Dog; }
	virtual void Draw() override;
	virtual void Update() override;
	bool IsFriendly() { return isFriendly; }
	void UpdateFriendly(bool f) { isFriendly = f; }

protected:
	void InitDirection();

private:
	int m_movementInX;
	int m_movementInY;

	int m_currentMovementX;
	int m_currentMovementY;

	int m_directionX;
	int m_directionY;

	bool isFriendly;

	void UpdateDirection(int& current, int& direction, int& movement);

};
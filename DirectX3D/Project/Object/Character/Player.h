#pragma once
class Player : public Groot
{
	enum AnimState
	{
		IDLE, RUN, ATTACK
	} curState = IDLE;
public:
	Player();
	~Player();

	void Update();
	void Render();

	void Debug();

	ColliderSphere* GetCollider() { return collider; }

private:

	ColliderSphere* collider;
};
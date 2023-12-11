#pragma once
class Boss : public ModelAnimator
{
	enum AnimState
	{
		IDLE, ATTACK, DIE
	}; 
	AnimState curState = AnimState::IDLE;
public:
	Boss();
	~Boss();

	void Update();
	void Render();

	void Debug();

	void SetClip(AnimState state);

private:
	void Move();

private:

	ColliderSphere* fingertip;
	ColliderSphere* head;
	ColliderBox* body;
};
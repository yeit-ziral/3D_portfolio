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

	void Attack1(); // for enclosed enemy
	void Attack2(); // point attack
	void Attack3(); // attack phase changing 

	void Move(); // teleport to random place

private:
	ColliderSphere* col;

	vector<Bomb*> bombs;


	float speed = 1.0f;
	float takeTime = 0.2f;

	float atkTurm = 7.0f;
	float moveTurm = 21.0f;

	
};
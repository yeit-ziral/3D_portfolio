#pragma once
class Groot : public ModelAnimator
{
	enum AnimState
	{
		IDLE, RUN, ATTACK
	} curState = IDLE;
public:
	Groot();
	~Groot();

	void Update();
	void Render();

	void Debug();
	void PostRender();

	void UpdateLeftHand();

	Matrix GetHeadPosition(); // "mixamorig:Neck" 위치 받아 보내는 함수

	void SetClip(AnimState state);

protected:
	void Move();

protected:

	float speed = 1.0f;
	float takeTime = 0.2f;

	Model* weapon;

	Transform* leftHand;

	float moveSpeed = 20.0f;

	float rotSpeed = 3.0f;

	ProgressBar* hpBar;
};
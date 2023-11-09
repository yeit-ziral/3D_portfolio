#pragma once
class Crate : public Transform
{
public:
	Crate();
	~Crate();

	void Update();
	void Render();

	void Debug();

	void SetIsAppear(bool value) { isAppear = value; }

private:
	ColliderBox* collider;

	bool isAppear = true;
};
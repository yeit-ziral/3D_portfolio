#pragma once
class Crate : public ModelInstancing
{
public:
	Crate();
	~Crate();

	void Update();
	void Render();

	void Debug();

	void SetIsAppear(bool value) { isAppear = value; }

private:
	ModelReader* reader;
	ColliderBox* collider;

	bool isAppear = true;
};
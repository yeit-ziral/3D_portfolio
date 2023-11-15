#pragma once
class Bomb : public Model
{
public:
	Bomb();
	~Bomb();

	void Update();
	void Render();

	void Debug();

	void Throw();

	ColliderSphere* GetCollider() { return collider; }

	void SetIsAppear(bool value) { isAppear = value; }

	bool IsAppear() { return isAppear; }

	void Explode();

private:
	ColliderSphere* collider;

	int speed = 0;

	int time = 3;

	float nowTime = 0;

	bool isAppear = false;

	Vector3 direction;

	Model* explosion;

	bool isExplode = false;

	ColliderSphere* expCol;

	float exTime = 0;
};
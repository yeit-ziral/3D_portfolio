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

	void Charging();

	ColliderSphere* GetExpCollider() { return exp->GetCollider(); }

	void Explode();

private:
	ColliderSphere* collider;

	int time = 3;

	float speed = 0;

	float nowTime = 0;

	bool isAppear = false;

	Vector3 direction;

	Explosion* exp;
};
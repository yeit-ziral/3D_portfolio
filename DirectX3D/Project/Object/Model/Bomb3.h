#pragma once
class Bomb3 : public Model
{
public:
	Bomb3();
	~Bomb3();

	void Update();
	void Render();

	void Debug();

	void Throw();

	ColliderSphere* GetCollider() { return collider; }

	void SetIsAppear(bool value) { isAppear = value; }

	bool IsAppear() { return isAppear; }

	ColliderSphere* GetExpCollider() { return exp->GetCollider(); }

	void Explode();

	bool IsCollision(ColliderBox* value) { return collider->Collision(value); }
	bool IsCollision(ColliderSphere* value) { return collider->Collision(value); }

private:
	ColliderSphere* collider;

	float speed = 0;

	bool isAppear = false;

	Vector3 direction;

	Explosion* exp;

	bool isCollision = false;
};
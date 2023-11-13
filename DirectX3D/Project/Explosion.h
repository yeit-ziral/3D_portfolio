#pragma once
class Explosion : public Model
{
	enum class Range
	{
		SMALL,
		MIDIUM,
		LARGE
	};
public:
	Explosion();
	~Explosion();

	void Update();
	void Render();

	void Debug();

	void Throw();

	ColliderSphere* GetCollider() { return collider; }

	void SetIsAppear(bool value) { isAppear = value; }

	void Explode();

	void SetRange(Range value);

private:
	ColliderSphere* collider;

	int speed = 0;

	int time = 3;

	float nowTime = 0;

	bool isAppear = false;

	Vector3 direction;

	float explosionRange;
};
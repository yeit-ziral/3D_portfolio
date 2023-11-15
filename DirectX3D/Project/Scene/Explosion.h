#pragma once
class Explosion : public Scene
{
public:
	Explosion();
	~Explosion();

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	Bomb* bomb;

	Model* exp;

	ColliderSphere* collider;
};


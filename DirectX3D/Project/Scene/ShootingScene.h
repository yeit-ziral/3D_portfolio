#pragma once
class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	Pumpkin* pumpkin;
	Pumpkin* pumpkin2;

	Skeleton* skeleton;

	Ghost* ghost;
};


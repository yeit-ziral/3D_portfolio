#pragma once
class BossScene : public Scene //Block �����غ��� ���� ���� Scene
{
public:
	BossScene();
	~BossScene();

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	Boss* boss;
};
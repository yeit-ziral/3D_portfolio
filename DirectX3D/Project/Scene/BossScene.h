#pragma once
class BossScene : public Scene //Block 실험해보기 위해 만든 Scene
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
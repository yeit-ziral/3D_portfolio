#pragma once
class BlockScene : public Scene //Block �����غ��� ���� ���� Scene
{
public:
	BlockScene();
	~BlockScene();

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	Crate* crate;

	Groot* groot;
};
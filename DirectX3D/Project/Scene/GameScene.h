#pragma once
class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void Update()		override;
	virtual void PreRender()	override;
	virtual void Render()		override;
	virtual void PostRender()	override;

private:
	Quad* floor;

	Groot* groot;

	Sphere* sphere;
};
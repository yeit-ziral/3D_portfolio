#include "Framework.h"
#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	bomb = new Bomb();
}

ExplosionScene::~ExplosionScene()
{
	delete bomb;
}

void ExplosionScene::Update()
{
	bomb->Update();

	if (KEY_PRESS(VK_LBUTTON))
	{
		bomb->Charging();
	}

	else if (KEY_UP(VK_LBUTTON) && !bomb->IsAppear())
		bomb->Throw();

}

void ExplosionScene::PreRender()
{
}

void ExplosionScene::Render()
{
	bomb->Render();
}

void ExplosionScene::PostRender()
{
	bomb->Debug();
}

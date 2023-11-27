#include "Framework.h"
#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	bomb = new Bomb3();

	box = new ColliderBox(Vector3(3,3,3));

	box->translation.y -= 5;
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
		//bomb->Charging();
	}

	else if (KEY_UP(VK_LBUTTON) && !bomb->IsAppear())
		bomb->Throw();

	if (bomb->IsCollisionBox(box))
		bomb->SetCollision(true);

	box->Update();
}

void ExplosionScene::PreRender()
{
}

void ExplosionScene::Render()
{
	bomb->Render();

	box->Render();
}

void ExplosionScene::PostRender()
{
	bomb->Debug();
}

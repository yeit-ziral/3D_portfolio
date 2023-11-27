#include "Framework.h"
#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	//bomb = new Bomb3();

	//box = new ColliderBox(Vector3(3,3,3));

	//box->translation.y -= 10;

	groot = new Groot();
	groot->scale *= 0.1f;
}

ExplosionScene::~ExplosionScene()
{
	//delete bomb;
	//delete box;

	delete groot;
}

void ExplosionScene::Update()
{
	//bomb->Update();

	//if (KEY_PRESS(VK_LBUTTON))
	//{
	//	bomb->Charging();
	//}

	//else if (KEY_UP(VK_LBUTTON) && !bomb->IsAppear())
	//	bomb->Throw();

	//if (box->Collision(bomb->GetCollider()))
	//	bomb->SetCollision(true);

	//box->Update();

	groot->Update();
}

void ExplosionScene::PreRender()
{
}

void ExplosionScene::Render()
{
	//bomb->Render();

	//box->Render();

	groot->Render();
}

void ExplosionScene::PostRender()
{
	//bomb->Debug();

	groot->Debug();
}

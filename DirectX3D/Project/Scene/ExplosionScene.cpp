#include "Framework.h"
#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	terrain = new Terrain(L"Landscape/Dirt.png", L"HeightMap/HeightMap.png");

	//bomb = new Bomb3();

	//box = new ColliderBox(Vector3(3,3,3));

	//box->translation.y -= 10;

	groot = new Groot();
	groot->scale *= 0.1f;
}

ExplosionScene::~ExplosionScene()
{
	delete terrain;

	//delete bomb;
	//delete box;

	delete groot;
}

void ExplosionScene::Update()
{
	terrain->Update();

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

	terrain->OnTheGround(&groot->translation);

	if (groot->GetBombIsExist())
	{
		if (terrain->GetHeight(groot->GetBombGPos()) > groot->GetBombGPos().y)
			groot->BombIsGround(true);
	}

	CAMERA->translation = groot->GetGlobalPosition();
	CAMERA->translation.y += 3.0f;
	CAMERA->translation.z -= 1.0f;
	CAMERA->rotation.y = groot->rotation.y + XM_PI;
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

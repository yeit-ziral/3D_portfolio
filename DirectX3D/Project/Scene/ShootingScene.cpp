#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	pumpkin = new Pumpkin();
	//pumpkin2 = new Pumpkin();
	skeleton = new Skeleton();
	ghost = new Ghost();
}

ShootingScene::~ShootingScene()
{
	delete pumpkin;
	//delete pumpkin2;
	delete ghost;
	delete skeleton;
}

void ShootingScene::Update()
{
	pumpkin ->Update();
	//pumpkin2->Update();
	ghost	->Update();
	skeleton->Update();

	if (pumpkin->GetCollider()->Collision(ghost->GetCollider()))
	{
		pumpkin->SetIsAppear(false);
		ghost->SetIsAppear(false);
	}
	if (pumpkin->GetCollider()->Collision(skeleton->GetCollider()))
	{
		pumpkin->SetIsAppear(false);
		skeleton->SetIsAppear(false);
	}

	//if (KEY_DOWN(VK_LBUTTON)) // Scene으로 이동시켜야 함
	//{
	//	if (pumpkin->IsAppear() == false && pumpkin2->IsAppear() == false)
	//	{
	//		pumpkin->Throw();
	//	}
	//	else if (pumpkin->IsAppear() && !pumpkin2->IsAppear())
	//	{
	//		pumpkin2->Throw();
	//	}

	//}

	if (KEY_DOWN(VK_LBUTTON) && !pumpkin->IsAppear())
		pumpkin->Throw();
}

void ShootingScene::PreRender()
{
}

void ShootingScene::Render()
{
	pumpkin ->Render();
	//pumpkin2->Render();
	ghost	->Render();
	skeleton->Render();
}

void ShootingScene::PostRender()
{
	pumpkin ->Debug();
	//pumpkin2->Debug();
	ghost	->Debug();
	skeleton->Debug();
}

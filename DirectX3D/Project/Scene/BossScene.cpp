#include "Framework.h"
#include "BossScene.h"

BossScene::BossScene()
{
	boss = new Boss();
	boss->scale *= 0.1f;
}

BossScene::~BossScene()
{
	delete boss;
}

void BossScene::Update()
{
	boss->Update();
}

void BossScene::PreRender()
{
}

void BossScene::Render()
{
	boss->Render();
}

void BossScene::PostRender()
{
	boss->Debug();
}

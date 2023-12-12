#include "Framework.h"
#include "BossScene.h"

BossScene::BossScene()
{
	boss = new Boss();
	boss->translation *= 0.5f;
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

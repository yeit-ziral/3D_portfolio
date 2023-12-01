#include "Framework.h"
#include "BlockScene.h"

BlockScene::BlockScene()
{
	crate = new Crate();

	crate->translation.x = 0;

	bomb = new Pumpkin();

	bomb->translation.x = 3;
}

BlockScene::~BlockScene()
{
	delete crate;

	delete bomb;
}

void BlockScene::Update()
{
	crate->GetCollider()->Block(bomb->GetCollider());

	crate->Update();

	bomb->Update();
}

void BlockScene::PreRender()
{
}

void BlockScene::Render()
{
	crate->Render();

	bomb->Render();
}

void BlockScene::PostRender()
{
	ImGui::SliderFloat("CratePosX", &crate->translation.x, -10, 10);
	ImGui::SliderFloat("CratePosY", &crate->translation.y, -10, 10);
	ImGui::SliderFloat("CratePosZ", &crate->translation.z, -10, 10);

	crate->Debug();

	bomb->Debug();
}

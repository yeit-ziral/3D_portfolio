#include "Framework.h"
#include "BlockScene.h"

BlockScene::BlockScene()
{
	//crate = new Crate();
	
	//groot = new Groot();
	//groot->scale *= 0.1f;

	crates = new CrateInstancing();

	//crate->translation.x = 30;

	//CAMERA->translation = { 0,0,0 };
}

BlockScene::~BlockScene()
{
	//delete groot;

	delete crates;
}

void BlockScene::Update()
{
	//crate->GetCollider()->Block(bomb->GetCollider());
	//crate->GetCollider()->Block(groot->GetCurBombCollider());

	//groot->Update();

	crates->Update();

	//CAMERA->translation = groot->GetGlobalPosition();
	//CAMERA->translation.y += groot->GetGlobalScale().y;
}

void BlockScene::PreRender()
{
}

void BlockScene::Render()
{
	//groot->Render();

	crates->Render();
}

void BlockScene::PostRender()
{
	//ImGui::SliderFloat("CratePosX", &crate->translation.x, -10, 10);
	//ImGui::SliderFloat("CratePosY", &crate->translation.y, -10, 10);
	//ImGui::SliderFloat("CratePosZ", &crate->translation.z, -10, 10);

	//ImGui::SliderFloat("CratePosX", &crate->translation.x, -10, 10);
	//ImGui::SliderFloat("CratePosY", &crate->translation.y, -10, 10);
	//ImGui::SliderFloat("CratePosZ", &crate->translation.z, -10, 10);

	crates->Debug();

	//groot->PostRender();
}

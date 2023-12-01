#include "Framework.h"
#include "BlockScene.h"

BlockScene::BlockScene()
{
	for (int i = 0; i < 3; i++)
	{
		crates.emplace_back(new Crate);
		crates[i]->SetLabel("ColliderSphere" + to_string(i));
		crates[i]->translation.x = 3 * i;
	}
}

BlockScene::~BlockScene()
{
	for (Crate* box : crates)
	{
		delete box;
	}

	crates.clear();
}

void BlockScene::Update()
{
	for (Crate* box : crates)
	{
		box->Update();
	}

	Vector3 temp = crates[0]->GetCollider()->GetGlobalScale();

	crates[0]->GetCollider()->Block(crates[1]->GetCollider());
}

void BlockScene::PreRender()
{
}

void BlockScene::Render()
{
	for (Crate* box : crates)
	{
		box->Render();
	}
}

void BlockScene::PostRender()
{
	for (Crate* box : crates)
		box->Debug();
}

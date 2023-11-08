#include "Framework.h"
#include "BoxScene.h"

BoxScene::BoxScene()
{
	box = new Crate();
	box2 = new Crate();
	box2->translation = { 2.0f, 0.0f, 0.0f };
	box3 = new Crate();
}

BoxScene::~BoxScene()
{
	delete box;
	delete box2;
	delete box3;
}

void BoxScene::Update()
{
	box->Update();
	box2->Update();
	box3->Update();
}

void BoxScene::PreRender()
{
}

void BoxScene::Render()
{
	box->Render();
	box2->Render();
	box3->Render();
}

void BoxScene::PostRender()
{
	box->Debug();
	box2->Debug();
	box3->Debug();
}

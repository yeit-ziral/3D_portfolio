#include "Framework.h"
#include "BoxScene.h"

BoxScene::BoxScene()
{
	box = new Box();
	box2 = new Box();
	box2->SetTranslation({ 2.0f, 0.0f, 0.0f });
}

BoxScene::~BoxScene()
{
	delete box;
	delete box2;
}

void BoxScene::Update()
{
	box->Update();
	box2->Update();
}

void BoxScene::PreRender()
{
}

void BoxScene::Render()
{
	box->Render();
	box2->Render();
}

void BoxScene::PostRender()
{
	box->PostRender();
	box2->PostRender();
}

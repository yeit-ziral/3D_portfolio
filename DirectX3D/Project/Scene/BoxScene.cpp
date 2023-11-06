#include "Framework.h"
#include "BoxScene.h"

BoxScene::BoxScene()
{
	//for (int x = 0; x < 10; x++)
	//{
	//	for (int z = 0; z < 10; z++)
	//	{
	//		Box* box = new Box();
	//		box->translation = { (float)x * 2.0f, 0.0f, (float)z * 2.0f };

	//		boxies.emplace_back(box);
	//	}
	//}

	box1 = new Box();

	box2 = new Box();
	box2->translation = { 2.0f, 2.0f, 0.0f };
}

BoxScene::~BoxScene()
{
	//for (auto box : boxies)
	//	delete box;

	//boxies.clear();

	delete box1;
	delete box2;
}

void BoxScene::Update()
{
	//for (auto box : boxies)
	//	box->Update();

	box1->Update();
	box2->Update();
}

void BoxScene::PreRender()
{
}

void BoxScene::Render()
{
	//for (auto box : boxies)
	//	box->Render();

	box1->Render();
	box2->Render();
}

void BoxScene::PostRender()
{
	//for (auto box : boxies)
	//	box->Debug();

	box1->Debug();
	box2->Debug();
}

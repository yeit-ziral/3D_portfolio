#include "Framework.h"
#include "Box.h"

Box::Box()
{

	cube = new Cube({ 1.0f, 0.0f, 0.0f, 1.0f });
	quadTop = new Quad(cube->GetTopVertices());
	quadBottom = new Quad(cube->GetBottomVertices());
	quadFront = new Quad(cube->GetFrontVertices());
	quadBack = new Quad(cube->GetBackVertices());
	quadRight = new Quad(cube->GetRightVertices());
	quadLeft = new Quad(cube->GetLeftVertices());

	   quadTop->SetParent(cube);
	quadBottom->SetParent(cube);
	 quadFront->SetParent(cube);
	  quadBack->SetParent(cube);
	 quadRight->SetParent(cube);
	  quadLeft->SetParent(cube);

	  cube->SetParent(this);

	  collider = new ColliderBox({ 2.0f, 2.0f, 2.0f });
}

Box::~Box()
{
	delete    quadTop;
	delete quadBottom;
	delete  quadFront;
	delete   quadBack;
	delete  quadRight;
	delete   quadLeft;

	delete collider;
}

void Box::Update()
{
		  cube->Update();
	   quadTop->Update();
	quadBottom->Update();
	 quadFront->Update();
	  quadBack->Update();
	 quadRight->Update();
	  quadLeft->Update();

	  collider->Update();
	  collider->translation = cube->GetGlobalPosition();
}

void Box::Render()
{
		  //cube->Render();
	   quadTop->Render();
	quadBottom->Render();
	 quadFront->Render();
	  quadBack->Render();
	 quadRight->Render();
	  quadLeft->Render();

	  collider->Render();
}

void Box::PostRender()
{
	cube->Debug();

	collider->Debug();
}

void Box::SetTranslation(Vector3 pos)
{
	cube->translation = pos;
}

void Box::SetQuadShader(wstring wstr)
{
	   quadTop->GetMaterial()->SetShader(wstr);
	quadBottom->GetMaterial()->SetShader(wstr);
	 quadFront->GetMaterial()->SetShader(wstr);
	  quadBack->GetMaterial()->SetShader(wstr);
	 quadRight->GetMaterial()->SetShader(wstr);
	  quadLeft->GetMaterial()->SetShader(wstr);
}

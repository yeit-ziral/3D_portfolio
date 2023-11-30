#include "Framework.h"
#include "Crate.h"

Crate::Crate()
    :Model("Crate")
{
	reader = new ModelReader("Crate");
	GetReader()->GetMaterial()[0]->Load(L"Crate.mat");

	scale *= 0.02;

	collider = new ColliderBox();

	collider->scale = this->GetGlobalScale() * 1.5f;

	collider->SetParent(this);
}

Crate::~Crate()
{
	delete reader;
	delete collider;
}

void Crate::Update()
{
	if (!isAppear)
		return;

	Model::Update();

	collider->Update();
}

void Crate::Render()
{
	if (!isAppear)
		return;
	Model::Render();
	collider->Render();
}

void Crate::Debug()
{
	Model::Debug();
}

void Crate::Move()
{
}

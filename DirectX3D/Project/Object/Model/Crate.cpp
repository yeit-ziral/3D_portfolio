#include "Framework.h"
#include "Crate.h"

Crate::Crate()
    :Model("Crate")
{
	reader = new ModelReader("Crate");
	GetReader()->GetMaterial()[0]->Load(L"Crate.mat");

	scale *= 2;

	collider = new ColliderBox();

	collider->scale *= this->scale.x * 0.4f;
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

	collider->translation = Model::GetGlobalPosition();
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

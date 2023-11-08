#include "Framework.h"
#include "Crate.h"

Crate::Crate()
	:ModelInstancing("Crate")
{
	reader = new ModelReader("Crate");
	reader->GetMaterial()[0]->Load(L"Crate");

	collider = new ColliderBox({3, 3, 3});

	collider->SetParent(this);

	ModelInstancing::Add();
}

Crate::~Crate()
{
	delete collider;
}

void Crate::Update()
{
	if (!isAppear)
		return;

	ModelInstancing::Update();

	collider->Update();
	collider->translation = Model::GetGlobalPosition();
}

void Crate::Render()
{
	if (!isAppear)
		return;
	ModelInstancing::Render();
	collider->Render();
}

void Crate::Debug()
{
	ModelInstancing::Debug();
}

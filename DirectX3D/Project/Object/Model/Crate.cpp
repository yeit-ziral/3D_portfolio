#include "Framework.h"
#include "Crate.h"

Crate::Crate()
{
	collider = new ColliderBox({3, 3, 3});
	collider->SetParent(this);
}

Crate::~Crate()
{
	delete collider;
}

void Crate::Update()
{
	if (!isAppear)
		return;

	collider->Update();

	collider->translation = this->translation;
}

void Crate::Render()
{
	if (!isAppear)
		return;

	collider->Render();
}

void Crate::Debug()
{
	collider->Debug();
}

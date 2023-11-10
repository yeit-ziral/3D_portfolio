#include "Framework.h"
#include "Crate.h"

Crate::Crate()
{
	collider = new ColliderBox();
	isAppear = true;
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
	collider->translation = translation;
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

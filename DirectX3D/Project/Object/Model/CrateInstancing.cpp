#include "Framework.h"
#include "CrateInstancing.h"

CrateInstancing::CrateInstancing()
	:ModelInstancing("Crate")
{
	for (UINT i = 0; i < 10; i++)
	{
		ModelInstancing::Add();
	}

	for (UINT i = 0; i < 10; i++)
	{
		transforms[i]->scale *= 0.05;
		transforms[i]->translation.x += (i * 3);
	}

	for (UINT i = 0; i < 10; i++)
	{
		ColliderBox* colBox = new ColliderBox();
		colBox->scale *= 3;
		colBoxies.emplace_back(colBox);
	}
}

CrateInstancing::~CrateInstancing()
{
}

void CrateInstancing::Update()
{
	ModelInstancing::Update();

	for (UINT i = 0; i < 10; i++)
	{
		colBoxies[i]->translation = transforms[i]->GetGlobalPosition();
		colBoxies[i]->translation.z -= 2;
		colBoxies[i]->SetIsActive(transforms[i]->IsActive());
	}

	for (ColliderBox* colBox : colBoxies)
		if (colBox->IsActive())
			colBox->Update();

	if (colBoxies[0]->Collision(colBoxies[1]))
	{
		colBoxies[0]->SetIsActive(false);
		transforms[0]->SetIsActive(false);
	}
	else
	{
		colBoxies[0]->SetIsActive(true);
		transforms[0]->SetIsActive(true);
	}
}

void CrateInstancing::Render()
{
	ModelInstancing::Render();

	for (ColliderBox* colBox : colBoxies)
		if (colBox->IsActive())
			colBox->Render();
}

void CrateInstancing::Debug()
{
	ModelInstancing::Debug();

	for (ColliderBox* colBox : colBoxies)
		//if (colBox->IsActive())
			colBox->Debug();
}

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
	}

	for (ColliderBox* colBox : colBoxies)
		colBox->Update();
}

void CrateInstancing::Render()
{
	ModelInstancing::Render();

	for (ColliderBox* colBox : colBoxies)
		colBox->Render();
}

void CrateInstancing::Debug()
{
	ModelInstancing::Debug();

	for (ColliderBox* colBox : colBoxies)
		colBox->Debug();
}

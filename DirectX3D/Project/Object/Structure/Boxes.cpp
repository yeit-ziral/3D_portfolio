#include "Framework.h"
#include "Boxes.h"

Boxes::Boxes()
{
	boxes.resize(100);

	for (int i = 0; i < 100; i++)
	{
		Box* box = new Box();

		box->SetQuadShader(L"06TextureInstancing");

		boxes[i] = box;
	}

	instanceData.resize(600);

	
}

Boxes::~Boxes()
{
}

void Boxes::Update()
{
}

void Boxes::Render()
{
}

void Boxes::PostRender()
{
}

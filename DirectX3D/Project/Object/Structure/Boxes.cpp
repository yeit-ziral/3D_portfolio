#include "Framework.h"
#include "Boxes.h"

Boxes::Boxes()
{
	boxes.resize(COUNT * COUNT);

	for (float z = 0; z < 10; z++)
	{
		for (float x = 0; x < 10; x++)
		{
			boxes[x + z] = new Crate();

			boxes[x + z]->translation = { x * 10, 0, z * 10 };
		}
	}
}

Boxes::~Boxes()
{
	for (Crate* b : boxes)
		delete b;

	boxes.clear();
}

void Boxes::Update()
{
	for (Crate* b : boxes)
		b->Update();
}

void Boxes::Render()
{
	for (Crate* b : boxes)
		b->Render();
}

void Boxes::PostRender()
{
	for (Crate* b : boxes)
		b->Debug();
}

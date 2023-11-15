#include "Framework.h"
#include "Explosion.h"

Explosion::Explosion()
{
	bomb = new Bomb();

	exp = new Model("Explosion_S");

	exp->rotation.x = XM_PIDIV2;

	exp->scale *= 0.0f;

	collider = new ColliderSphere();

	collider->scale *= 0.0f;
}

Explosion::~Explosion()
{
	delete bomb;

	delete exp;

	delete collider;
}

void Explosion::Update()
{
	bomb->Update();

	if (KEY_DOWN(VK_LBUTTON) && !bomb->IsAppear())
		bomb->Throw();

	exp->Update();

	exp->scale += { Time::Delta() * 0.01f, Time::Delta() * 0.01f, Time::Delta() * 0.01f };

	collider->Update();

	collider->scale += { Time::Delta() * 0.5f, Time::Delta() * 0.5f, Time::Delta() * 0.5f };
}

void Explosion::PreRender()
{
}

void Explosion::Render()
{
	bomb->Render();

	exp->Render();

	collider->Render();
}

void Explosion::PostRender()
{
	bomb->Debug();

	exp->Debug();

	collider->Render();
}

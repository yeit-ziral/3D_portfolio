#include "Framework.h"
#include "Bomb3.h"

Bomb3::Bomb3()
	:Model("Grenade")
{
	GetReader()->GetMaterial()[0]->Load(L"Bomb.mat");

	scale *= 1.0f;

	rotation.x += XM_PIDIV2;

	collider = new ColliderSphere();

	collider->SetParent(this);

	exp = new Explosion();
}

Bomb3::~Bomb3()
{
	delete collider;
	delete exp;
}

void Bomb3::Update()
{
	Model::Update();
	collider->Update();

	if (isAppear)
	{
		translation += direction * speed * Time::Delta();

		direction.y -= 0.5f * Time::Delta();

		if (isCollision)
		{
			exp->translation = this->GetGlobalPosition();
			Explode();
			translation = CAMERA->GetGlobalPosition();
			speed = 0.0f;
			isAppear = false;
		}
	}

	exp->Update();
}

void Bomb3::Render()
{
	exp->Render();

	if (!isAppear)
		return;
	Model::Render();
	collider->Render();
}

void Bomb3::Debug()
{
	Model::Debug();

	exp->Debug();
}

void Bomb3::Throw()
{
	if (speed < 20)
		speed += Time::Delta() * 10;

	isAppear = true;
}

void Bomb3::Explode()
{
	exp->SetExplode(true);
}

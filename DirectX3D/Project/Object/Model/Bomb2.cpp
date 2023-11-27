#include "Framework.h"
#include "Bomb2.h"

Bomb2::Bomb2()
	:Model("Dynamite")
{
	GetReader()->GetMaterial()[0]->Load(L"Bomb.mat");

	scale *= 1.0f;

	rotation.x += XM_PIDIV2;

	collider = new ColliderSphere();

	collider->SetParent(this);

	exp = new Explosion();
}

Bomb2::~Bomb2()
{
	delete collider;
	delete exp;
}

void Bomb2::Update()
{
	Model::Update();
	collider->Update();

	if (isAppear)
	{
		nowTime += Time::Delta();

		translation += direction * speed * Time::Delta();

		direction.y -= 0.5f * Time::Delta();

		if (nowTime > 3.0f)
		{
			nowTime = 0.0f;
			exp->translation = this->GetGlobalPosition();
			Explode();
			translation = CAMERA->GetGlobalPosition();
			speed = 0.0f;
			isAppear = false;
		}
	}

	exp->Update();
}

void Bomb2::Render()
{
	exp->Render();

	if (!isAppear)
		return;
	Model::Render();
	collider->Render();
}

void Bomb2::Debug()
{
	Model::Debug();

	exp->Debug();
}

void Bomb2::Throw()
{
	Ray ray = CAMERA->ScreenPointToRay(mousePos);

	direction = ray.direction.GetNormalized();
}

void Bomb2::Charging()
{
	if (speed < 20)
		speed += Time::Delta() * 10;

	isAppear = true;
}

void Bomb2::Explode()
{
	exp->SetExplode(true);
}

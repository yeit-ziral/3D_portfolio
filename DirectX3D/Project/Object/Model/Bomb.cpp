#include "Framework.h"
#include "Bomb.h"

Bomb::Bomb()
	:Model("Bomb")
{
	GetReader()->GetMaterial()[0]->Load(L"Bomb.mat");

	scale *= 10.0f;

	collider = new ColliderSphere();

	collider->SetParent(this);

	explosion = new Model("Explosion_S");
	explosion->rotation.z -= PI * 0.5f;
	explosion->scale *= 0.0f;

	expCol = new ColliderSphere();
}

Bomb::~Bomb()
{
	delete collider;
	delete explosion;
}

void Bomb::Update()
{
	Model::Update();
	collider->Update();

	//collider->translation = Model::GetGlobalPosition();
	collider->translation += {0.0f, 0.4f, 0.0f};

	collider->scale = scale * 0.3f;

	if (isAppear)
	{
		nowTime += Time::Delta();

		translation += direction * speed * Time::Delta();

		direction.y -= 0.5f * Time::Delta();

		if (nowTime > 4.0f)
		{
			nowTime = 0.0f;
			translation = CAMERA->GetGlobalPosition();
			isAppear = false;
		}

		if (this->GetGlobalPosition().y <= 0)
		{
			Explode();
		}
	}

	if (isExplode)
	{
		explosion->Update();

		float temp = Time::Delta() * 3;

		explosion->scale += {temp, temp, temp};

		expCol->translation = explosion->GetGlobalPosition();

		expCol->scale = explosion->scale;

		exTime += Time::Delta();

		if (exTime > 2.0f)
		{
			exTime = 0.0f;

			isExplode = false;
		}
	}
}

void Bomb::Render()
{
	if (!isAppear)
		return;
	Model::Render();
	collider->Render();
}

void Bomb::Debug()
{
	Model::Debug();
}

void Bomb::Throw()
{
	Ray ray = CAMERA->ScreenPointToRay(mousePos);

	direction = ray.direction.GetNormalized();

	isAppear = true;
	speed = 20;
}

void Bomb::Explode()
{
	if (this->GetGlobalPosition().y <= 0.0f)
	{
		isExplode = true;

		isAppear = false;

		explosion->translation = this->GetGlobalPosition();
	}
}

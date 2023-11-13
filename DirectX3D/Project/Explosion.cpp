#include "Framework.h"
#include "Explosion.h"

Explosion::Explosion()
	:Model("Explosion_S")
{
	collider = new ColliderSphere();


}

Explosion::~Explosion()
{
}

void Explosion::Update()
{
	if (!isAppear)
		return;

	collider->translation = this->GetGlobalPosition();

	nowTime += Time::Delta();

	float explosionTemp = explosionRange * Time::Delta();

	this->scale = { explosionTemp, explosionTemp, explosionTemp };
	collider->scale = { explosionTemp, explosionTemp, explosionTemp };

	if (nowTime > time)
		SetIsAppear(false);
}

void Explosion::Render()
{
	if (!isAppear)
		return;
	Model::Render();
	collider->Render();
}

void Explosion::Debug()
{
}

void Explosion::Throw()
{
}

void Explosion::Explode()
{
	SetIsAppear(true);

	nowTime = 0.0f;
}

void Explosion::SetRange(Range value)
{
	if (value == Range::SMALL)
		explosionRange = 5.0f;
	if (value == Range::MIDIUM)
		explosionRange = 10.0f;
	if (value == Range::LARGE)
		explosionRange = 15.0f;
}

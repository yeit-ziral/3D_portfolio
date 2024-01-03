#include "Framework.h"
#include "Boss.h"



Boss::Boss()
	:ModelAnimator("Knight D Pelegrini")
{
	CreateTexture();
	ReadClip("Breathing Idle");
	ReadClip("Pushing");
	ReadClip("Death");

	reader->GetMaterial()[0]->Load(L"Knight_MAT2.mat");

	clips[ATTACK]->SetEndEvent(0.7f, bind(&Boss::SetClip, this, IDLE));

	col = new ColliderSphere();

	for (int a = 0; a < 10; a++)
	{
		Bomb* bomb = new Bomb();

		bombs.emplace_back(bomb);
	}
}

Boss::~Boss()
{
}

void Boss::Update()
{
	ModelAnimator::Update();

	if (KEY_DOWN('1'))
		PlayClip( 0, speed, takeTime);

	if (KEY_DOWN('2'))
		PlayClip( 1, speed, takeTime);

	if (KEY_DOWN('3'))
		PlayClip( 2, speed, takeTime);
}

void Boss::Render()
{
	ModelAnimator::Render();
}

void Boss::Debug()
{
	ModelAnimator::Debug();
}

void Boss::SetClip(AnimState state)
{
	if (curState != state)
	{
		PlayClip(state);
		curState = state;
	}
}

void Boss::Attack1()
{
}

void Boss::Attack2()
{
}

void Boss::Attack3()
{
}

void Boss::Move()
{

}

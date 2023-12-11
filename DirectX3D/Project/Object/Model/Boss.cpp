#include "Framework.h"
#include "Boss.h"



Boss::Boss()
	:ModelAnimator("Knight D Pelegrini")
{
}

Boss::~Boss()
{
}

void Boss::Update()
{
}

void Boss::Render()
{
}

void Boss::Debug()
{
}

void Boss::SetClip(AnimState state)
{
	if (curState != state)
	{
		PlayClip( state);
		curState = state;
	}
}

void Boss::Move()
{
	if (!KEY_PRESS(VK_LBUTTON))
	{
		if (KEY_PRESS('W'))
		{
			//Ray ray = CAMERA->ScreenPointToRay({ WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f, 0.0f });

			//Vector2 dir = { ray.direction.x, ray.direction.z };
			//
			//float theta = -atan2f(dir.y, dir.x) * 2;

			//rotation.y = theta + (PI * 1.304f);//CAMERA->GetRotY();
			translation -= Forward() * moveSpeed * Time::Delta();
			SetClip(RUN);
		}

		if (KEY_PRESS('S'))
		{
			translation -= Backward() * moveSpeed * Time::Delta();
			SetClip(RUN);
		}
		if (KEY_UP('W') || KEY_UP('S'))
			SetClip(IDLE);

		if (KEY_PRESS('A'))
		{
			rotation.y -= rotSpeed * Time::Delta();
		}
		if (KEY_PRESS('D'))
		{
			rotation.y += rotSpeed * Time::Delta();
		}

		if (KEY_DOWN(VK_LBUTTON))
		{
			SetClip(ATTACK);
		}
	}
}

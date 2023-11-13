#include "Framework.h"
#include "Player.h"

Player::Player()
{
	Groot::Groot();

	collider = new ColliderSphere();
}

Player::~Player()
{
	Groot::~Groot();

	delete collider;
}

void Player::Update()
{
	Groot::Update();
}

void Player::Render()
{
	Groot::Render();
}

void Player::Debug()
{
	Groot::PostRender();
}
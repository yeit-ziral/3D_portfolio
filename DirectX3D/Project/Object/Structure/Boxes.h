#pragma once
class Boxes
{
public:
	Boxes();
	~Boxes();

	void Update();
	void Render();
	void PostRender();

private:
	const UINT COUNT = 10;

	vector<Crate*> boxes;

	int instanceIndex = 0;
};
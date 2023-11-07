#pragma once
class Box : public Transform
{
public:
	Box();
	~Box();

	void Update();
	void Render();
	void PostRender();

	void SetTranslation(Vector3 pos);

	Vector3 GetPos() { return cube->GetGlobalPosition(); }

	void SetQuadShader(wstring wstr);

private:
	Cube* cube;
	Quad* quadTop;
	Quad* quadBottom;
	Quad* quadFront;
	Quad* quadBack;
	Quad* quadRight;
	Quad* quadLeft;

	ColliderBox* collider;
};
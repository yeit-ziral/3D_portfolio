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
	vector<Box*> boxes;

	vector<InstanceData> instanceData;

	VertexBuffer* instanceBuffer;
};
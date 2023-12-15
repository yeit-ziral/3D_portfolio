#pragma once
class CrateInstancing : public ModelInstancing
{
public:
	CrateInstancing();
	~CrateInstancing();

	void Update();
	void Render();
	void Debug();

private:
	vector<ColliderBox*> colBoxies;
};


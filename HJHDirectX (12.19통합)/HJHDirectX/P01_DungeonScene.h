#pragma once
class P01_DungeonScene : public GameNode
{
	//ĳ���� ���â�� ���� �� ��ư
	P02_UIButton* bttn;

public:
	P01_DungeonScene();
	~P01_DungeonScene();

	HRESULT Init();
	void Release();
	void Update();
	void Render();
	//static void SetSene();
};


#pragma once
class P01_DungeonScene : public GameNode
{
	//캐릭터 장비창에 설정 될 버튼
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


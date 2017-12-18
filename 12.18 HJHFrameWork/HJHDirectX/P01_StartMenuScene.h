#pragma once

//class P02_UIObject;
class P00_SkinedMeshPure;
class P02_UIButtonScene;

class P01_StartMenuScene :public GameNode

{
private:
	TCHAR _sMeshFilename[MAX_PATH];

	P00_SkinnedMeshPure* player;
	P00_SkinnedMeshPure* background;
	P00_SkinnedMeshPure* cpy;


	MAT _mWorld;

	P02_UIButton* changeBttn1;
	P02_UIButton* changeBttn2;
	P02_UIButton* exitBttn;

public:
	P01_StartMenuScene();
	~P01_StartMenuScene();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	static void ChageMaptoolScene();
	static void ChageDungeonScene();
};


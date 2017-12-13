#pragma once

class P02_UIObject;
class P00_SkinedMeshPure;
class P01_StartMenuScene :public GameNode

{
private:
	TCHAR _sMeshFilename[MAX_PATH];

	P00_SkinnedMeshPure* player;
	P00_SkinnedMeshPure* background;
	P00_SkinnedMeshPure* cpy;
	//vector<P00_SkinnedMeshPure*> _vZealot;

	MAT _mWorld;



public:
	P01_StartMenuScene();
	~P01_StartMenuScene();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


#pragma once

class P01_LoadingScene : public GameNode
{
private:
	P02_Loading* loading;

public:
	P01_LoadingScene();
	~P01_LoadingScene();

	
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	
	void LoadTexture();


};


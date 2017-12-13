#pragma once

enum LOAD_KIND
{
	LOAD_KIND_IMAGE,
	LOAD_KIND_SOUND,
	LOAD_KIND_END
};

struct tagImageResourse
{
	
};

class P01_LoadingScene : public GameNode
{
private:
	int _x, _y;
	float _width;



	//D3DXIMAGE_INFO _loadingImage[2];
	//LPTXUR _loadingTex[2];
	//LPD3DXSPRITE _pD3DSprite[2];
	
	//Texture* _loadingTexture[2];


	

	//MAT _mWorld;

public:
	P01_LoadingScene();
	~P01_LoadingScene();

	//HRESULT Init(int x, int y, int width, int height);
	HRESULT Init(P00_SpritePure* loadingIm01, P00_SpritePure* loadingIm02, float x, float y, int width, int height);
	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

};


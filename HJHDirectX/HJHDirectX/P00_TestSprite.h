#pragma once
#include "Texture.h"

class P00_SpritePure;
class P00_TestSprite : public GameNode
{
private:
	P00_SpritePure* _pSprite;

	D3DXIMAGE_INFO	_pImageInfo[2];
	LPTXUR			_pTex[2];

	LPD3DXSPRITE _pD3DSprite;

	Texture* _pTestTexture[2];
public:
	P00_TestSprite();
	~P00_TestSprite();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


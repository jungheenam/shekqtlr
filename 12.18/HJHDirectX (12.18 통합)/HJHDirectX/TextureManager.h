#pragma once
#include "SingletonBase.h"
#include "Texture.h"
class TextureManager : public SingletonBase<TextureManager>
{
private:
	map<tstring, Texture*> _mTexture;

public:
	TextureManager();
	~TextureManager();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	BOOL ReleaseTexture(tstring key);

	Texture* Add(tstring key, TCHAR* sFilename, DWORD dFilter = D3DX_FILTER_NONE , DWORD dColor = 0x00FFFFFF);
	
	Texture* Find(tstring key);
};




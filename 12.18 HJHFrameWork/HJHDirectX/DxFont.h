#pragma once
#include "SingletonBase.h"
class DxFont : public SingletonBase<DxFont>
{
public:
	enum FONT_TYPE { NORMAL = 0, CHAT, QUEST, BUTTON };
private:
	LPD3DXFONT _pFont;
	TCHAR _cFontName;
	map<FONT_TYPE, LPD3DXFONT> _mFont;
public:
	DxFont();
	~DxFont();
	HRESULT Init();
	void Release();

	LPD3DXFONT GetFont(FONT_TYPE eFontType);

	void DxDrawText(TCHAR* str, float x, float y, D3DCOLOR c = D3DCOLOR_XRGB(0, 0, 0));
	void DxDrawText(TCHAR* str, float x, float y, float w, float h, D3DCOLOR c = D3DCOLOR_XRGB(0, 0, 0));
	void DxDrawTextCenter(TCHAR* str, float x, float y, float w, float h, D3DCOLOR c = D3DCOLOR_XRGB(0, 0, 0));
};


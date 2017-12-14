#include "stdafx.h"
#include "DxFont.h"


DxFont::DxFont() : _pFont(nullptr)
{
}


DxFont::~DxFont()
{
}

HRESULT DxFont::Init()
{
	D3DXFONT_DESC hFont =
	{
		16, 0
		, FW_BOLD, 1, FALSE
		, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS
		, ANTIALIASED_QUALITY, FF_DONTCARE, _T("Consolas")
	};

	_tcscpy(hFont.FaceName, _T("Consolas"));

	
	D3DXCreateFontIndirect(DXDEV, &hFont, &_pFont);

	return S_OK;
}

void DxFont::Release()
{
	SAFE_RELEASE(_pFont);
}

LPD3DXFONT DxFont::GetFont(FONT_TYPE eFontType)
{
	if (_mFont.find(eFontType) == _mFont.end())
	{
		switch (eFontType)
		{
			case FONT_TYPE::NORMAL:


			break;

			case FONT_TYPE::CHAT:


			break;

			case FONT_TYPE::QUEST:


			break;

			case FONT_TYPE::BUTTON:
			D3DXFONT_DESC fd;
			ZeroMemory(&fd, sizeof(LPD3DXFONT_DESC));

			fd.Height = 25;
			fd.Width = 12;
			fd.Weight = FW_NORMAL;
			fd.Italic = false;
			fd.CharSet = DEFAULT_CHARSET;
			fd.OutputPrecision = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily = FF_DONTCARE;
			_tcscpy(fd.FaceName, _T("±Ã¼­Ã¼"));

			D3DXCreateFontIndirect(DXDEV, &fd, &_mFont[eFontType]);
			break;
		}
	}


	return _mFont[eFontType];
}

void DxFont::DxDrawText(TCHAR * str, float x, float y, D3DCOLOR c)
{
	RECT rc = { x, y, x + WINSIZEX, y + 30 };
	_pFont->DrawText(NULL, str, -1, &rc, 0, c);
}

void DxFont::DxDrawText(TCHAR* str, float x, float y, float w, float h, D3DCOLOR c)
{
	RECT rc = { x, y, x + w, y + h };
	_pFont->DrawText(NULL, str, -1, &rc, 0, c);
}

void DxFont::DxDrawTextCenter(TCHAR * str, float x, float y, float w, float h, D3DCOLOR c)
{
	RECT rc = { x, y, x + w, y + h };
	_pFont->DrawText(NULL, str, -1, &rc, DT_CENTER | DT_VCENTER | DT_WORDBREAK, c);
}

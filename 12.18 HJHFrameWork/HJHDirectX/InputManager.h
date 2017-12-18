#pragma once
#include "SingletonBase.h"
#define MAX_INPUT_KEY 256
#define MAX_INPUT_BTN 8
class InputManager : public SingletonBase<InputManager>
{
public:
	enum INPUT_STATE
	{
		INPUT_NONE = 0,
		INPUT_DOWN = 1,
		INPUT_UP = 2,
		INPUT_STAY = 3,
		INPUT_DOUBLECLICK = 4
	};
private:
	BYTE		_bKeyCur[MAX_INPUT_KEY];
	BYTE		_bKeyOld[MAX_INPUT_KEY];
	BYTE		_bKeyMap[MAX_INPUT_KEY];

	BYTE		_bBtnCur[MAX_INPUT_BTN];
	BYTE		_bBtnOld[MAX_INPUT_BTN];
	BYTE		_bBtnMap[MAX_INPUT_BTN];

	D3DXVECTOR3	_vCur;
	D3DXVECTOR3 _vOld;
	D3DXVECTOR3 _vEps;

	DWORD		_dTimeDC;
	DWORD		_dBtnBgn[MAX_INPUT_BTN];
	INT			_dBtnCnt[MAX_INPUT_BTN];


	D3DXVECTOR3 _vMouse;
public:
	InputManager();
	~InputManager();
	HRESULT Init();
	void Release();
	void Update();
	void Render();

	BOOL KeyDown(int nKey);
	BOOL KeyUp(int nKey);
	BOOL KeyStay(int nKey);
	int  KeyState(int nKey);

	BOOL BtnDown(int nKey);
	BOOL BtnUp(int nKey);
	BOOL BtnStay(int nKey);
	int  BtnState(int nKey);

	D3DXVECTOR3 GetMousePos() { return _vCur; };
	D3DXVECTOR3 GetMouseEps() { return _vEps; };

	D3DXVECTOR3 GetMouse3DPos(float fX, float fY);
	D3DXVECTOR3 GetMouse3DPosUnprojection(float fX, float fY);

	void AddZ(int d);

	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);
};


#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager()
{
	ZeroMemory(&_bKeyOld, sizeof(_bKeyOld));
	ZeroMemory(&_bKeyCur, sizeof(_bKeyCur));
	ZeroMemory(&_bKeyMap, sizeof(_bKeyMap));

	ZeroMemory(&_bBtnCur, sizeof(_bBtnCur));
	ZeroMemory(&_bBtnOld, sizeof(_bBtnOld));
	ZeroMemory(&_bBtnMap, sizeof(_bBtnMap));

	_vCur = D3DXVECTOR3(0, 0, 0);
	_vOld = D3DXVECTOR3(0, 0, 0);
	_vEps = D3DXVECTOR3(0, 0, 0);

	_dTimeDC = 0;
	ZeroMemory(&_dBtnBgn, sizeof(_dBtnBgn));
	ZeroMemory(&_dBtnCnt, sizeof(_dBtnCnt));
}


InputManager::~InputManager()
{
}

HRESULT InputManager::Init()
{
	ZeroMemory(&_bKeyOld, sizeof(_bKeyOld));
	ZeroMemory(&_bKeyCur, sizeof(_bKeyCur));
	ZeroMemory(&_bKeyMap, sizeof(_bKeyMap));

	ZeroMemory(&_bBtnCur, sizeof(_bBtnCur));
	ZeroMemory(&_bBtnOld, sizeof(_bBtnOld));
	ZeroMemory(&_bBtnMap, sizeof(_bBtnMap));

	_vCur = D3DXVECTOR3(0, 0, 0);
	_vOld = D3DXVECTOR3(0, 0, 0);
	_vEps = D3DXVECTOR3(0, 0, 0);


	_dTimeDC = GetDoubleClickTime();

	ZeroMemory(&_dBtnBgn, sizeof(_dBtnBgn));
	ZeroMemory(&_dBtnCnt, sizeof(_dBtnCnt));

	_dBtnBgn[0] = GetTickCount();

	for (int i = 1; i<MAX_INPUT_BTN; ++i)
	{
		_dBtnBgn[i] = _dBtnBgn[0];
	}

	memset(_dBtnCnt, 0, sizeof(_dBtnCnt));

	UINT uNumLines = 0;
	SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &uNumLines, 0);


	return S_OK;
}

void InputManager::Release()
{
}

void InputManager::Update()
{
	INT i = 0;

	memcpy(_bKeyOld, _bKeyCur, sizeof(_bKeyOld));
	memcpy(_bBtnOld, _bBtnCur, sizeof(_bBtnOld));


	memset(_bKeyCur, 0, sizeof(_bKeyCur));
	memset(_bKeyMap, 0, sizeof(_bKeyMap));

	memset(_bBtnCur, 0, sizeof(_bBtnCur));
	memset(_bBtnMap, 0, sizeof(_bBtnMap));

	GetKeyboardState(_bKeyCur);

	_bBtnCur[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) ? 1 : 0;
	_bBtnCur[1] = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) ? 1 : 0;
	_bBtnCur[2] = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) ? 1 : 0;

	for (i = 0; i < MAX_INPUT_KEY; ++i)
	{
		BYTE vKey = _bKeyCur[i] & 0x80;

		_bKeyCur[i] = (vKey) ? 1 : 0;

		INT nOld = _bKeyOld[i];
		INT nCur = _bKeyCur[i];

		if (0 == nOld && 1 == nCur) _bKeyMap[i] = INPUT_DOWN;
		else if (1 == nOld && 0 == nCur) _bKeyMap[i] = INPUT_UP;
		else if (1 == nOld && 1 == nCur) _bKeyMap[i] = INPUT_STAY;
		else							 _bKeyMap[i] = INPUT_NONE;
	}


	// Mouse
	for (i = 0; i<MAX_INPUT_BTN; ++i)
	{
		INT nOld = _bBtnOld[i];
		INT nCur = _bBtnCur[i];

		if (0 == nOld && 1 == nCur) _bBtnMap[i] = INPUT_DOWN;
		else if (1 == nOld && 0 == nCur) _bBtnMap[i] = INPUT_UP;
		else if (1 == nOld && 1 == nCur) _bBtnMap[i] = INPUT_STAY;
		else							 _bBtnMap[i] = INPUT_NONE;	// NONE
	}


	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(_hWnd, &pt);

	_vOld.x = _vCur.x;
	_vOld.y = _vCur.y;

	_vCur.x = FLOAT(pt.x);
	_vCur.y = FLOAT(pt.y);

	_vEps = _vCur - _vOld;
	_vOld.z = _vCur.z;



	// Double Check
	DWORD dBtnCur = GetTickCount();

	for (i = 0; i<MAX_INPUT_BTN; ++i)
	{
		if (INPUT_DOWN == _bBtnMap[i])
		{
			if (1 == _dBtnCnt[i])
			{
				if ((dBtnCur - _dBtnBgn[i]) >= _dTimeDC)
				{
					_dBtnCnt[i] = 0;
				}
			}


			++_dBtnCnt[i];

			if (1 == _dBtnCnt[i])
			{
				_dBtnBgn[i] = dBtnCur;
			}
		}


		if (INPUT_UP == _bBtnMap[i])
		{
			if (1 == _dBtnCnt[i])
			{
				if ((dBtnCur - _dBtnBgn[i]) >= _dTimeDC)
				{
					_dBtnCnt[i] = 0;
				}
			}

			else if (2 == _dBtnCnt[i])
			{
				if ((dBtnCur - _dBtnBgn[i]) <= _dTimeDC)
				{
					_bBtnMap[i] = INPUT_DOUBLECLICK;
				}

				_dBtnCnt[i] = 0;
			}
		}

	}
}

void InputManager::Render()
{
	//VEC3 vPos = GetMouse3DPos(_vCur.x, _vCur.y);
	//TCHAR str[256];
	//_stprintf(str, _T("Mouse Position : x: %f		, y: %f		, z: %f"), vPos.x, vPos.y, vPos.z);
	//FONTM->DxDrawText(str, 6, WINSIZEY - 40, WINSIZEX, 30, D3DXCOLOR(1, 1, 0, 1));
}

BOOL InputManager::KeyDown(int nKey)
{
	return _bKeyMap[nKey] == INPUT_DOWN;
}

BOOL InputManager::KeyUp(int nKey)
{
	return _bKeyMap[nKey] == INPUT_UP;
}

BOOL InputManager::KeyStay(int nKey)
{
	return _bKeyMap[nKey] == INPUT_STAY;
}

int InputManager::KeyState(int nKey)
{
	return _bKeyMap[nKey];
}

BOOL InputManager::BtnDown(int nKey)
{
	return _bBtnMap[nKey] == INPUT_DOWN;
}

BOOL InputManager::BtnUp(int nKey)
{
	return _bBtnMap[nKey] == INPUT_UP;
}

BOOL InputManager::BtnStay(int nKey)
{
	return _bBtnMap[nKey] == INPUT_STAY;
}

int InputManager::BtnState(int nKey)
{
	return _bBtnMap[nKey];
}

D3DXVECTOR3 InputManager::GetMouse3DPos(float fX, float fY)
{
	VEC3 vPick;
	VEC3 vPickDir;

	MAT mView;
	MAT mProj;
	MAT mI;

	D3DVIEWPORT9 dViewport;

	VEC3 vCamPos;
	VEC3 vCamAxisX;
	VEC3 vCamAxisY;
	VEC3 vCamAxisZ;

	DXDEV->GetViewport(&dViewport);
	DXDEV->GetTransform(D3DTS_VIEW, &mView);
	DXDEV->GetTransform(D3DTS_PROJECTION, &mProj);

	D3DXMatrixInverse(&mI, 0, &mView);

	vCamPos = VEC3(mI._41, mI._42, mI._43);
	vCamAxisX = VEC3(mI._11, mI._12, mI._13);
	vCamAxisY = VEC3(mI._21, mI._22, mI._23);
	vCamAxisZ = VEC3(mI._31, mI._32, mI._33);

	float fW = (float)dViewport.Width;
	float fH = (float)dViewport.Height;

	float fNear = -mProj._43 / mProj._33;

	// (-1, 1)로 정규화
	float fViewX = (2.0f * fX / fW - 1) / mProj._11;
	float fViewY = -(2.0f * fY / fH - 1) / mProj._22;
	float fViewZ = fNear;

	fViewX *= fNear;
	fViewY *= fNear;

	vPick = vCamPos + fViewX * vCamAxisX + fViewY * vCamAxisY + fViewZ * vCamAxisZ;

	return vPick;
}

D3DXVECTOR3 InputManager::GetMouse3DPosUnprojection(float fX, float fY)
{
	VEC3 vPick;

	MAT mView;
	MAT mProj;
	MAT mViewport;
	D3DVIEWPORT9 dViewport;

	DXDEV->GetViewport(&dViewport);
	D3DXMatrixViewport(&mViewport, &dViewport);

	DXDEV->GetTransform(D3DTS_VIEW, &mView);
	DXDEV->GetTransform(D3DTS_PROJECTION, &mProj);

	vPick = VEC3(fX, fY, 0);
	D3DXVec3Unproject(&vPick, &vPick, &dViewport, &mProj, &mView, nullptr);

	return vPick;
}

void InputManager::AddZ(int d)
{
	_vOld.z = _vCur.z;
	_vCur.z += float(d);
}

LRESULT InputManager::WndProc(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (WM_MOUSEWHEEL == uMsg)
	{
		INT c = HIWORD(wParam);
		INT d = LOWORD(wParam);

		_vMouse.x = LOWORD(lParam);
		_vMouse.y = HIWORD(lParam);

		AddZ(short(HIWORD(wParam)));
	}

	return TRUE;
}

#include "stdafx.h"
#include "P00_MultiAnimationUnit.h"


P00_MultiAnimationUnit::P00_MultiAnimationUnit()
{
	D3DXMatrixIdentity(&_mWorld);

	_dTimeCur = 0;
}


P00_MultiAnimationUnit::~P00_MultiAnimationUnit()
{
	Release();
}

HRESULT P00_MultiAnimationUnit::Init(void *, void *, void *, void *)
{
	return S_OK;
}

void P00_MultiAnimationUnit::Release()
{
}

void P00_MultiAnimationUnit::Update()
{
}

void P00_MultiAnimationUnit::Render()
{
}

int P00_MultiAnimationUnit::SetAttribute(TCHAR * sCommand, void * pValue)
{
	if (_tcsicmp(sCommand, _T("World Matrix")) == 0)
	{
		_mWorld = *(D3DXMATRIX*)pValue;
		return 0;
	}
	else if (_tcsicmp(sCommand, _T("Frame Speed")) == 0)
	{
		float fTime = *(float*)pValue;
		_dTimeCur += fTime;
		return 0;
	}
	else if (_tcsicmp(sCommand, _T("Current Time")) == 0)
	{
		float fTime = *(float*)pValue;
		_dTimeCur = fTime;
		return 0;
	}

	return -1;
}

int P00_MultiAnimationUnit::GetAttribute(TCHAR * sCommand, void * pValue)
{
	if (_tcsicmp(sCommand, _T("World Matrix")) == 0)
	{
		*(D3DXMATRIX*)pValue = _mWorld;
		return 0;
	}
	else if (_tcsicmp(sCommand, _T("Current Time")) == 0)
	{
		*(double*)pValue = _dTimeCur;
		return 0;
	}

	return -1;
}

int P00_MultiAnimationUnit::SetPosition(VEC3 vPos)
{
	_mWorld._41 = vPos.x;
	_mWorld._42 = vPos.y;
	_mWorld._43 = vPos.z;

	return 0;
}

int P00_MultiAnimationUnit::GetPosition(VEC3 vPos)
{
	vPos.x = _mWorld._41;
	vPos.y = _mWorld._42;
	vPos.z = _mWorld._43;

	return 0;
}

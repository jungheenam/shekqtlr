#pragma once
#include "SingletonBase.h"
#include "DxGrid.h"
#include "DxLight.h"
class Dx : public SingletonBase<Dx>
{
public:
	LPDIRECT3D9		  _pDx9;
	LPDIRECT3DDEVICE9 _pDev;
	
	DxGrid			  _cGrid;
	DxLight			  _cLight;
public:
	Dx();
	~Dx();
	HRESULT Init();
	void Update();
	void Release();
	HRESULT BeginDraw();
	void EndDraw();
	void BaseSamplerState();
	void InitWorldMatrix();
};
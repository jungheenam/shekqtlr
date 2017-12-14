#include "stdafx.h"
#include "P00_TestXFileInstance.h"


P00_TestXFileInstance::P00_TestXFileInstance()
{
	_pOrig		= nullptr;
	_pMesh		= nullptr;
	_pMtl		= nullptr;
	_pTex		= nullptr;
	_nSubset	= 0;

	D3DXMatrixIdentity(&_mWorld);
}


P00_TestXFileInstance::~P00_TestXFileInstance()
{
	this->Release();
}

HRESULT P00_TestXFileInstance::Init()
{


	return S_OK;
}

void P00_TestXFileInstance::Release()
{
}

void P00_TestXFileInstance::Update()
{
}

void P00_TestXFileInstance::Render()
{
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	DXM->BaseSamplerState();

	DXDEV->SetTransform(D3DTS_WORLD, &_mWorld);

	for (int i = 0; i < _nSubset; ++i)
	{
		DXDEV->SetTexture(0, _pTex[i]);
		DXDEV->SetMaterial(&_pMtl[i]);
		_pMesh->DrawSubset(i);
	}

	static MAT mIdt(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);
	DXDEV->SetTransform(D3DTS_WORLD, &mIdt);
}

HRESULT P00_TestXFileInstance::Load(TCHAR * sFile, void * pOriginal)
{
	_pOrig = (P00_TestXFile*)pOriginal;
	
	_pMesh		= _pOrig->GetMesh();
	_pMtl		= _pOrig->GetMaterial();
	_pTex		= _pOrig->GetTexture();
	_nSubset	= _pOrig->GetSubset();

	return S_OK;
}

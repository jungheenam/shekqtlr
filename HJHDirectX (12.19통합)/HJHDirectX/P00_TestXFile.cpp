#include "stdafx.h"
#include "P00_TestXFile.h"


P00_TestXFile::P00_TestXFile()
{
	_pMesh	 = nullptr;
	_pMtl	 = nullptr;
	_pTex	 = nullptr;
	_nSubset = 0;
}


P00_TestXFile::~P00_TestXFile()
{
	this->Release();
}

HRESULT P00_TestXFile::Init()
{

	return S_OK;
}

void P00_TestXFile::Release()
{
	for (int i = 0; i < _nSubset; ++i) SAFE_RELEASE(_pTex[i]);

	SAFE_DELETE_ARRAY(_pMtl);
	SAFE_DELETE_ARRAY(_pTex);

	SAFE_RELEASE(_pMesh);
}

void P00_TestXFile::Update()
{
}

void P00_TestXFile::Render()
{
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	DXM->BaseSamplerState();

	for (int i = 0; i < _nSubset; ++i)
	{
		DXDEV->SetTexture(0, _pTex[i]);
		DXDEV->SetMaterial(&_pMtl[i]);
		_pMesh->DrawSubset(i);
	}
}

HRESULT P00_TestXFile::Load(TCHAR * sFile, void* pOriginal)
{
	LPD3DXBUFFER pAdjBuf = nullptr;
	LPD3DXBUFFER pMtlBuf = nullptr;
	DWORD dSubset;

	D3DXLoadMeshFromX(sFile, D3DXMESH_SYSTEMMEM, DXDEV, &pAdjBuf, &pMtlBuf, 0, &dSubset, &_pMesh);

	_nSubset = dSubset;

	_tcscpy(_sFile, sFile);

	DWORD  dOption = D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_COMPACT | D3DXMESHOPT_VERTEXCACHE;
	DWORD* pAdj = (DWORD*)pAdjBuf->GetBufferPointer();
	
	HRESULT hr;
	hr = _pMesh->OptimizeInplace(dOption, pAdj, 0, 0, 0);
	if (FAILED(hr))
	{
		SAFE_RELEASE(pAdjBuf);
		SAFE_RELEASE(pMtlBuf);
		SAFE_RELEASE(_pMesh);
		return E_FAIL;
	}

	if (_nSubset <= 0 || pMtlBuf == nullptr)
	{
		SAFE_RELEASE(pAdjBuf);
		SAFE_RELEASE(pMtlBuf);
		return S_OK;
	}

	_pMtl = new DMTL[_nSubset];
	_pTex = new LPTXUR[_nSubset];

	XMTL* pMtl = (XMTL*)pMtlBuf->GetBufferPointer();
	for (int i = 0; i < _nSubset; ++i) memcpy(&_pMtl[i], &pMtl[i].MatD3D, sizeof(DMTL));

	TCHAR sFolderName[MAX_PATH]	= { 0 };
	TCHAR sDir[_MAX_DIR]		= { 0 };

	_splitpath(sFile, NULL, sDir, NULL, NULL);
	_makepath(sFolderName, NULL, sDir, NULL, NULL);

	for (int i = 0; i < _nSubset; ++i)
	{
		TCHAR sTexFile[MAX_PATH]	= { 0 };
		TCHAR sFilename[_MAX_FNAME] = { 0 };
		TCHAR sExt[_MAX_EXT]		= { 0 };

		TCHAR* pTexName = pMtl[i].pTextureFilename;

		if (pTexName == nullptr || _tcslen(pTexName) < 3) continue;

		_splitpath(pTexName, NULL, NULL, sFilename, sExt);
		_makepath(sTexFile, NULL, sFolderName, sFilename, sExt);

		LPTXUR pTex = nullptr;
		D3DXCreateTextureFromFile(DXDEV, sTexFile, &pTex);
		_pTex[i] = pTex;
	}

	SAFE_RELEASE(pAdjBuf);
	SAFE_RELEASE(pMtlBuf);

	return S_OK;
}

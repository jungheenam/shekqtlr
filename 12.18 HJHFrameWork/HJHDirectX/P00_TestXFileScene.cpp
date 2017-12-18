#include "stdafx.h"
#include "P00_TestXFileScene.h"


P00_TestXFileScene::P00_TestXFileScene()
{
}


P00_TestXFileScene::~P00_TestXFileScene()
{
}

HRESULT P00_TestXFileScene::Init()
{
	CreateXFile(&_pOrig, _T("XFile/TestXFile/Dwarf.x"));

	CreateXFile(&_pClone, NULL, _pOrig);

	MAT mWorld;
	D3DXMatrixScaling(&mWorld, 10, 10, 10);
	mWorld._41 = -10;
	_pClone->SetWorldMatrix(&mWorld);

	return S_OK;
}

void P00_TestXFileScene::Release()
{
	SAFE_DELETE(_pOrig);
	SAFE_DELETE(_pClone);
}

void P00_TestXFileScene::Update()
{
	if (_pOrig)		_pOrig->Update();
	if (_pClone)	_pClone->Update();
}

void P00_TestXFileScene::Render()
{
	if (_pOrig)		_pOrig->Render();
	if (_pClone)	_pClone->Render();
}

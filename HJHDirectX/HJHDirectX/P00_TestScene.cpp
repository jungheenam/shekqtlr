#include "stdafx.h"
#include "P00_TestScene.h"


P00_TestScene::P00_TestScene()
{
	_pTest = nullptr;
}


P00_TestScene::~P00_TestScene()
{
	this->Release();
}

HRESULT P00_TestScene::Init()
{
	_pTest = new P00_TEST_CLASS;
	_pTest->Init();

	return S_OK;
}

void P00_TestScene::Release()
{
	SAFE_RELEASE(_pTest);
}

void P00_TestScene::Update()
{
	_pTest->Update();
}

void P00_TestScene::Render()
{
	_pTest->Render();
}

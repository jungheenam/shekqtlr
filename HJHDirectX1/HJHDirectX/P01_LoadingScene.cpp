#include "stdafx.h"
#include "P01_LoadingScene.h"


P01_LoadingScene::P01_LoadingScene()
{


	//_loadingTex[0] = NULL;
	//_loadingTex[1] = NULL;

}


P01_LoadingScene::~P01_LoadingScene()
{
}

//HRESULT P01_LoadingScene::Init(int x, int y, int width, int height)
//{
//	_x = x;
//	_y = y;
//
//	RECT loadingProgess = { x, y, width, height };
//	TEXTUREM->Add(_T("loading01"), _T("Texture/P02_UI/loding01.png"), D3DX_FILTER_NONE);
//	TEXTUREM->Add(_T("loading02"), _T("Texture/P02_UI/loding02.png"), D3DX_FILTER_NONE);
//
//	return S_OK;
//}

HRESULT P01_LoadingScene::Init( P00_SpritePure * loadingIm01 , P00_SpritePure * loadingIm02 , float x , float y , int width , int height )
{
	return E_NOTIMPL;
}

HRESULT P01_LoadingScene::Init()
{
	//TEXTUREM->Add(_T("loading01"), _T("Texture/P02_UI/loding01.png"), D3DX_FILTER_NONE);
	//TEXTUREM->Add(_T("loading02"), _T("Texture/P02_UI/loding02.png"), D3DX_FILTER_NONE);
	loading = new P02_Loading;
	loading->Init();

	this->LoadTexture();

	return S_OK;
}

void P01_LoadingScene::Release()
{

}

void P01_LoadingScene::Update()
{
	loading->Update();
	if ( loading->LoadingDone() )SCENEM->Change( _T( "P02_UIButtonScene" ) );
}

void P01_LoadingScene::Render()
{
	loading->Render();


	//RECT rc = { 0,0,1920,1080 };
	//VEC3 pos = VEC3(0, 0, 0);
	//VEC2 scale = VEC2(WINSIZEX / 1920.0f, WINSIZEY / 1080.0f);
	//
	//							
	//TEXTUREM->Find(_T("loading01"))->Render(&rc, &pos, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));
	//TEXTUREM->Find(_T("loading01"))->SpriteState();
	//
	//TEXTUREM->Find(_T("loading02"))->Render(&rc, &pos, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));
	//TEXTUREM->Find(_T("loading02"))->SpriteState();
}

void P01_LoadingScene::LoadTexture()
{
	for ( int i = 0; i < 100; ++i )
	{
		loading->LoadTexture( _T( "test" ) , _T( "Texture/p02_UI/inventory.png" ) );
	}
}



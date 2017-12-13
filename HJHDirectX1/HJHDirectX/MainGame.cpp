#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

HRESULT MainGame::Init()
{
	GameNode::Init();

	SCENEM->Add(_T("P00_MultiAnimationScene"), new P00_MultiAnimationScene);
	SCENEM->Add(_T("P00_TestScene"), new P00_TestScene);
	SCENEM->Add(_T("P02_UIButtonScene"), new P02_UIButtonScene);
	SCENEM->Add( _T( "P01_StartMenuScene" ) , new P01_StartMenuScene );
	SCENEM->Add(_T("P01_LoadingScene"), new P01_LoadingScene);
	SCENEM->Add( _T( "P01_Inventory" ) , new P01_Inventory );
	SCENEM->Change(_T("P01_LoadingScene"));



	return S_OK;
}

void MainGame::Release()
{
	GameNode::Release();
}

void MainGame::Update()
{
	GameNode::Update();
	DXM->Update();

	INPUTM->Update();
	SCENEM->Update();
	//CAM->MovePosition(VEC3(0, 0, 0));
	//CAM->MoveFree();
}

void MainGame::Render()
{
	DXM->BeginDraw();
	// +-------------------------------------------------------+ //

	SCENEM->Render();

	// +-------------------------------------------------------+ //
	TIMER->Render();
	DXM->EndDraw();
}
#include "stdafx.h"
#include "P01_StartMenuScene.h"
#include "P02_UIButton.h"


P01_StartMenuScene::P01_StartMenuScene()
{
}


P01_StartMenuScene::~P01_StartMenuScene()
{
	this->Release();
}

HRESULT P01_StartMenuScene::Init()
{

	
	CreateAnimationUnit(NULL, &player, _T("XFile/P01_StartScene/22/player.x"));
	CreateAnimationUnit(NULL, &background, _T("XFile/P01_StartScene/44/background.x"));
	CreateAnimationUnit(NULL, &cpy, NULL, player);


	MAT relative, rotation, scale;
	//D3DXMatrixIdentity( &rotation );
	D3DXMatrixIdentity(&scale);
	D3DXMatrixRotationY(&rotation, D3DX_PI / 2);
	D3DXMatrixScaling(&scale, 0.6f, 0.6f, 0.6f);

	relative = scale * rotation;

	cpy->SetAttribute(_T("World Matrix"), &relative);
	cpy->SetPosition(VEC3(0, 15, 40));

	background->SetAttribute(_T("World Matrix"), &rotation);
	background->SetPosition(VEC3(0, 35, 0));

	changeBttn1 = new P02_UIButton;
	changeBttn1->Init(TRUE, VEC3(WINSIZEX / 2 +200, WINSIZEY / 2 -100, 0), VEC2(242, 50), VEC2(1.0f, 1.0f), _T("MapToolScene"), ChageMaptoolScene);
	
	changeBttn2 = new P02_UIButton;
	changeBttn2->Init(TRUE, VEC3(WINSIZEX / 2 + 200, WINSIZEY / 2, 0), VEC2(242, 50), VEC2(1.0f, 1.0f), _T("DungeonScene"), ChageDungeonScene);

	exitBttn = new P02_UIButton;
	exitBttn->Init(false, VEC3(WINSIZEX / 2 + 200, WINSIZEY / 2 + 100, 0), VEC2(242, 50), VEC2(1.0f, 1.0f), _T("EXIT"));
	

	return S_OK;

}

void P01_StartMenuScene::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(background);
}

void P01_StartMenuScene::Update()
{
	static float fSpeed = 1.0f;
	float fFrameSpeed = _fElapsedTime * fSpeed;
	cpy->SetAttribute(_T("Frame Speed"), &fFrameSpeed);
	
	
	changeBttn1->Update();
	changeBttn2->Update();
	
	exitBttn->Update();
	if (exitBttn->GetIsClick()) PostQuitMessage(0);
}

void P01_StartMenuScene::Render()
{
	
	cpy->Render();
	background->Render();

	changeBttn1->Render();
	changeBttn2->Render();
	exitBttn->Render();
}

void P01_StartMenuScene::ChageMaptoolScene()
{
	SCENEM->Change(_T("P00_MultiAnimationScene"));
}

void P01_StartMenuScene::ChageDungeonScene()
{
	SCENEM->Change(_T("P01_DungeonScene"));
}



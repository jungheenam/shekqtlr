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

	/*CreateAnimationUnit(NULL, &_pMultiAniOrig, _T("XFile/P01_StartScene/11/startBackground.x"));
	_pMultiAniOrig->SetPosition(VEC3(0, 0, 0));*/
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




	UIM->SetSceneButton(button[0], VEC3(WINSIZEX / 2 + 200, WINSIZEY / 2 - 100, 0), VEC2(242, 50), _T("MapToolScene"), _T("P00_MultiAnimationScene"));

	UIM->SetSceneButton(button[1], VEC3(WINSIZEX / 2 + 200, WINSIZEY / 2, 0), VEC2(242, 50), _T("DungeonScene"), _T("P01_LoadingScene"));

	UIM->SetButton(button[2], VEC3(WINSIZEX / 2 + 200, WINSIZEY / 2 + 100, 0), VEC2(242, 50), _T("EXIT"));


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

	UIM->Update();
}

void P01_StartMenuScene::Render()
{
	cpy->Render();
	background->Render();

	UIM->Render();
}

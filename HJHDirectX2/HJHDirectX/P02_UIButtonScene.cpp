#include "stdafx.h"
#include "P02_UIButton.h"
#include "P02_UIButtonScene.h"


P02_UIButtonScene::P02_UIButtonScene()
{
}


P02_UIButtonScene::~P02_UIButtonScene()
{
}

HRESULT P02_UIButtonScene::Init()
{
	UIM->SetButton( button1 , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 50 , 0 ) , VEC2( 242 , 50 ) , _T( "¤¾¤·" ) );

	UIM->SetButton( button2 , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 100 , 0 ) , VEC2( 242 , 50 ) , _T( "¤²¤·" ) );

	UIM->SetSceneButton( button3 , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 200 , 0 ) , VEC2( 242 , 50 ) , _T( "¾ÀÅ×½ºÆ®" ) , _T( "P01_StartMenuScene" ) );


	UIM->SetScroll( scroll , VEC3( WINSIZEX / 2 , WINSIZEY / 2 , 0 ) , 0 , 100 );





	return S_OK;
}

void P02_UIButtonScene::Release()
{

}

void P02_UIButtonScene::Update()
{
	UIM->Update();
	//ITEM->Update();
}

void P02_UIButtonScene::Render()
{

	UIM->Render();
	INVEN->Render();
	//ITEM->Render();


	TCHAR str[ 32 ];
	_stprintf( str , _T( "½ºÅÈ : " ) , PLAYERSTAT->getStat()._Atk );
	FONTM->DxDrawText( str , 6 , WINSIZEX / 2 , 50 , D3DXCOLOR( 1 , 1 , 0 , 1 ) );

}

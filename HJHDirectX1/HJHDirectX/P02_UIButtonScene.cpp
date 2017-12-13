#include "stdafx.h"
#include "P02_UIButtonScene.h"


P02_UIButtonScene::P02_UIButtonScene()
{
}


P02_UIButtonScene::~P02_UIButtonScene()
{
	this->Release();
}

HRESULT P02_UIButtonScene::Init()
{
	//콜백버튼 - 헤더에 선언된 변수사용불가
	//노멀버튼 - 헤더에 선언된 변수사용가능
	
	button = new P02_UIButton;
	//		콜백함수 사용함					포지션					이미지사이즈			스케일				버튼위문자	버튼눌렀을때 작동할함수
	button->Init( TRUE , VEC3( WINSIZEX / 2 , WINSIZEY / 2 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) ,_T("ㅎㅇ"), SetSence );

	button2 = new P02_UIButton;
	//		콜백함수 사용안함					포지션								이미지사이즈				스케일		  버튼위 문자
	button2->Init( false , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 100 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) , _T( "ㅂ2" ) );


	bar = new P02_Progressbar;
	bar->Init( VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 300 , 0 ) , VEC2( 242 , 50 ) );
	test = 0;
	
	
	return S_OK;
}

void P02_UIButtonScene::Release()
{
}

void P02_UIButtonScene::Update()
{
	//업데이트
	button->Update();
	button2->Update();
	//콜백함수가 아니면 GetIsClick 여부를 확인하고 트루면 함수호출
	if ( button2->GetIsClick() == true ) SetSence();
	//================================================

	bar->Update();
	test++;
	bar->SetGauge( test , 500 );
	ITEM->Update();
}

void P02_UIButtonScene::Render()
{

	//랜더
	button->Render();
	button2->Render();

	bar->Render();

	INVEN->Render();
	//ITEM->Render();


	TCHAR str[ 32 ];
	_stprintf( str , _T( "스탯 : " ) , PLAYERSTAT->getStat()._Atk );
	FONTM->DxDrawText( str , 6 , WINSIZEX / 2 , 50 , D3DXCOLOR( 1 , 1 , 0 , 1 ) );

}

// 버튼 테스트용 함수
void P02_UIButtonScene::SetSence()
{
	SCENEM->Change( _T( "P00_MultiAnimationScene" ) );

}

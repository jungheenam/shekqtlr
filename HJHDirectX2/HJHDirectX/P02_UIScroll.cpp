#include "stdafx.h"
#include "P02_UIScroll.h"


P02_UIScroll::P02_UIScroll()
{
}


P02_UIScroll::~P02_UIScroll()
{
}



void P02_UIScroll::Update()
{
	this->BarMove();

	P02_UIobject::Update();
}

void P02_UIScroll::Render()
{
	RECT imageSize1 = { 0,0,117,9 };
	RECT imageSize2 = { 0,0,432,13 };


	scroll.textureBar->Render( &imageSize2 , &position , NULL , NULL , NULL , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	scroll.textureRc->Render( &imageSize1 , &position , NULL , NULL , NULL , D3DXCOLOR( 1 , 1 , 1 , 1 ) );


	P02_UIobject::Render();
}

void P02_UIScroll::SetScrollbar(VEC3 _position, float min , float max )
{
	ZeroMemory( &scroll , sizeof( tagScrollbar ) );
	SetPosition( _position );
	scroll.min = min;
	scroll.max = max;
	scroll.currentPos.x = position.x;
	scroll.currentPos.y = position.y;
	scroll.barLength = ( scroll.currentPos.x , scroll.max ) * 432;


	scroll.barRc = RectMake( position.x , position.y , scroll.barLength , 50 );
	scroll.currentBarRC = RectMake( scroll.currentPos.x , scroll.currentPos.y , 117 , 9 );

	scroll.textureBar = TEXTUREM->Add( _T( "scrollbar" ) , _T( "Texture/p02_uitest/scrollbar.png" ) );
	scroll.textureRc = TEXTUREM->Add( _T( "bar" ) , _T( "Texture/p02_uitest/bar.png" ) );
	
}

void P02_UIScroll::BarMove()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	if ( INPUTM->KeyDown( VK_LBUTTON ) )
	{
		if ( PtInRect( &scroll.currentBarRC , ptMouse ) ) scroll.isClick = true;
		
	}
	if ( scroll.isClick ) scroll.currentPos.x = ptMouse.x;


}

float P02_UIScroll::RrturnResult( float result )
{
	float tempResult = result;


	return tempResult;
}


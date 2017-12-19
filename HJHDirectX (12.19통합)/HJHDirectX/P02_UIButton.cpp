#include "stdafx.h"
#include "P02_UIButton.h"


P02_UIButton::P02_UIButton()
	:position( 0 , 0 , 0 ) , size( 0 , 0 ) , scale( 0 , 0 ) , isclick( false ) , buttonstat( BUTTONSTAT_NORMAL )
{



}


P02_UIButton::~P02_UIButton()
{
}

HRESULT P02_UIButton::Init( BOOL _callback , VEC3 _postion , VEC2 _size , VEC2 _scale , TCHAR* _string , CALLBACK_FUNTION _void )
{

	cb = _callback;
	str = _string;
	if ( cb ) callback = static_cast< CALLBACK_FUNTION >( _void );

	textureBT[ BUTTONSTAT_NORMAL ] = TEXTUREM->Find( _T( "normal" ) );
	textureBT[ BUTTONSTAT_OVER ] = TEXTUREM->Find( _T( "over" ) );
	textureBT[ BUTTONSTAT_DOWN ] = TEXTUREM->Find( _T( "down" ) );


	SetSize( _size );
	SetPosition( _postion );
	SetScale( _scale );

	SetRect( &rc , position.x , position.y , ( position.x + size.x )* scale.x , ( position.y + size.y )* scale.x );

	return S_OK;
}


void P02_UIButton::Release()
{
}

void P02_UIButton::Update()
{
	this->ButtonStat();
}

void P02_UIButton::Render()
{
	RECT imageSize = { 0,0,size.x,size.y };
	textureBT[ buttonstat ]->Render( &imageSize , &position , NULL , NULL , &scale , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	FONTM->DxDrawTextCenter( str , position.x , position.y , size.x , size.y , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
}

void P02_UIButton::ButtonStat()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	if ( PtInRect( &rc , ptMouse ) )
	{
		//	buttonstat = BUTTONSTAT_OVER;
		if ( INPUTM->KeyDown( VK_LBUTTON ) )
		{
			buttonstat = BUTTONSTAT_DOWN;
		}
		else if ( INPUTM->KeyUp( VK_LBUTTON ) && buttonstat == BUTTONSTAT_DOWN )
		{
			buttonstat = BUTTONSTAT_NORMAL;
			if ( cb ) callback();
			else SetIsClick( true );
		}
	}
	else
	{
		buttonstat = BUTTONSTAT_NORMAL;
		if ( !cb ) SetIsClick( false );
	}

}





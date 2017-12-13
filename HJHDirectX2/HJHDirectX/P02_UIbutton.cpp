#include "stdafx.h"
#include "P02_UIbutton.h"


P02_UIbutton::P02_UIbutton()
	:buttonstat( BUTTONSTAT_NORMAL ) ,
	buttonDelegate( nullptr )
{
}


P02_UIbutton::~P02_UIbutton()
{
}

void P02_UIbutton::SetButton( VEC2 _size , VEC3 _position )
{
	textureBT[ BUTTONSTAT_NORMAL ] = TEXTUREM->Add( _T( "normal" ) , _T( "Texture/P02_UITest/mainButton01.png" ) , D3DX_FILTER_NONE );
	textureBT[ BUTTONSTAT_OVER ] = TEXTUREM->Add( _T( "over" ) , _T( "Texture/P02_UITest/mainButton01.png" ) , D3DX_FILTER_NONE );
	textureBT[ BUTTONSTAT_SELECT ] = TEXTUREM->Add( _T( "select" ) , _T( "Texture/P02_UITest/mainButton02.png" ) , D3DX_FILTER_NONE );

	SetSize( _size );
	SetPosition( _position );

}

void P02_UIbutton::Update()
{
	P02_UIobject::UpdateChildren();
	SetRect( &rc , position.x , position.y ,
		position.x + size.x , position.y + size.y );

	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	if ( PtInRect( &rc , ptMouse ) )
	{
		
		if ( INPUTM->KeyState( VK_LBUTTON ) )
		{
			if ( buttonstat == BUTTONSTAT_OVER )buttonstat = BUTTONSTAT_SELECT;
		}
		else
		{
			if ( buttonstat == BUTTONSTAT_SELECT )
			{
				if ( buttonDelegate ) buttonDelegate->Click( this );
			}
			buttonstat = BUTTONSTAT_OVER;
		}
	}
	else buttonstat = BUTTONSTAT_NORMAL;

	P02_UIobject::UpdateChildren();

}

void P02_UIbutton::Render()
{
	RECT imagesize;
	SetRect( &imagesize , 0 , 0 , 242 , 50 );
	textureBT[ buttonstat ]->Render( &imagesize , &position , NULL , 0.0F , &VEC2(1.f,1.f) , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	FONTM->DxDrawTextCenter( tempStr , position.x , position.y , size.x , size.y , D3DXCOLOR( 1 , 1 , 1 , 1 ) );

	P02_UIobject::Render();
}

void P02_UIbutton::SetButtonText( tstring _string )
{
	strcpy( tempStr , _string.c_str() );
}


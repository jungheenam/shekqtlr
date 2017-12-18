#include "stdafx.h"
#include "P02_Progressbar.h"


P02_Progressbar::P02_Progressbar()
{
}


P02_Progressbar::~P02_Progressbar()
{
}

HRESULT P02_Progressbar::Init( VEC3 _position , VEC2 _size )
{
	pos.x = _position.x;
	pos.y = _position.y;

	rc = RectMake( _position.x , _position.y , _size.x , _size.y );

	textureTop = TEXTUREM->Add( _T( "topbar" ) , _T( "Texture/P02_UITest/mainButton01.png" ) , D3DX_FILTER_NONE );
	textureBottom = TEXTUREM->Add( _T( "topbar" ) , _T( "Texture/P02_UITest/mainButton02.png" ) , D3DX_FILTER_NONE );

	width = textureBottom->getImageInfo()->fW;

	return S_OK;
}

HRESULT P02_Progressbar::Init( TCHAR * _toptexture , TCHAR * _bottom , VEC3 _position , VEC2 _size )
{
	pos.x = _position.x;
	pos.y = _position.y;

	rc = RectMake( _position.x , _position.y , _size.x , _size.y );

	TCHAR topTex[ 128 ];
	TCHAR bottmTex[ 128 ];

	ZeroMemory( topTex , sizeof( topTex ) );
	ZeroMemory( bottmTex , sizeof( bottmTex ) );

	_stprintf( topTex , _T( "%s.png" ) , _toptexture );
	_stprintf( bottmTex , _T( "%s.png" ) , _bottom );

	textureTop = TEXTUREM->Add( _toptexture , topTex , D3DX_FILTER_NONE , D3DXCOLOR( 1 , 0 , 1 , 1 ) );
	textureBottom = TEXTUREM->Add( _bottom , bottmTex );

	width = textureBottom->getImageInfo()->fW;

	return S_OK;
}

void P02_Progressbar::Release()
{
}

void P02_Progressbar::Update()
{
	rc = RectMakeCenter( pos.x , pos.y , textureBottom->getImageInfo()->fW , textureBottom->getImageInfo()->fH );

}

void P02_Progressbar::Render()
{
	RECT TopImgSize = { 0, 0, width,50 };
	RECT BottomImgSize = { 0, 0, textureBottom->getImageInfo()->fW , 50 };

	textureBottom->Render( &BottomImgSize , &pos );
	textureTop->Render( &TopImgSize , &pos );
}

void P02_Progressbar::SetGauge( float currentGauge , float maxGauge )
{
	width = ( currentGauge / maxGauge ) * textureBottom->getImageInfo()->fW;
}

#include "stdafx.h"
#include "P02_Loading.h"



loadItem::loadItem()
{
}

loadItem::~loadItem()
{
}

HRESULT loadItem::initForTexture( tstring _keyName , TCHAR* _fileName  )
{
	//텍스처 키값,파일경로 
	loadkind = LOADKIND_TEXTURE1;
	//ZeroMemory( &texture , sizeof( tagTextureResource ) );

	texture.keyName = _keyName;
	texture.fileName = _fileName;


	return S_OK;
}


P02_Loading::P02_Loading()
{
}


P02_Loading::~P02_Loading()
{
}

HRESULT P02_Loading::Init()
{
	bar = new P02_Progressbar;
	bar->Init(_T("Texture/P02_UI/LoadingBarTop"), _T( "Texture/P02_UI/LoadingBarBottom" ) , VEC3( WINSIZEX/2 , WINSIZEY - 100  , 0 ) , VEC2( 242 , 50 ) );
	currentGauge = 0;
	bar->SetGauge( 0 , 0 );

	return S_OK;
}

void P02_Loading::Release()
{
}

void P02_Loading::Update()
{
	bar->Update();
}

void P02_Loading::Render()
{
	bar->Render();
}

void P02_Loading::LoadTexture( tstring _keyName , TCHAR * _fileName  )
{
	loadItem* item = new loadItem;
	item->initForTexture( _keyName , _fileName );

	load.push_back( item );

}

BOOL P02_Loading::LoadingDone()
{
	//게이지

	if ( currentGauge >= load.size() ) return TRUE;
	loadItem* item = load[ currentGauge ];
	
	//===============================================
	if ( item->getLoadKind() == LOADKIND_TEXTURE1 )
	{
		tagTextureResource tex = item->getTexture();
		TEXTUREM->Add( tex.keyName , tex.fileName );
	}
	//===============================================



	bar->SetGauge( currentGauge , load.size() );
	currentGauge++;


	return FALSE;
}

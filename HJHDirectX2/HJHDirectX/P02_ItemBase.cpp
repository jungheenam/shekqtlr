#include "stdafx.h"
#include "P02_ItemBase.h"


P02_ItemBase::P02_ItemBase()
{
}


P02_ItemBase::~P02_ItemBase()
{
}

P02_Inventory::P02_Inventory()
{
}

P02_Inventory::~P02_Inventory()
{
}

void P02_ItemBase::Init()
{

	SetItemInfo();
}

void P02_ItemBase::Release()
{
}

void P02_ItemBase::Update()
{
	ItemIconMove();
}

void P02_ItemBase::Render()
{

	ItemIconDraw();
}

void P02_ItemBase::SetItemInfo()
{

	tagItem helmat;
	helmat.itemKind = ITEMKIND_HELMAT;
	helmat.texture[ ITEMKIND_HELMAT ] = TEXTUREM->Add( _T( "helmat" ) , _T( "Texture/P02_ItemIcon/helmat.png" ) , D3DX_FILTER_NONE );
	helmat.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 100 , 0 );
	helmat.rcSize = VEC2( 34 , 34 );
	helmat.isPicked = false;
	helmat.CON = 10;
	helmat.DEX = 10;

	vItem.push_back( helmat );

	tagItem neck;
	neck.itemKind = ITEMKIND_NECK;
	neck.texture[ ITEMKIND_NECK ] = TEXTUREM->Add( _T( "neck" ) , _T( "Texture/P02_ItemIcon/neck.png" ) , D3DX_FILTER_NONE );
	neck.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 150 , 0 );
	neck.rcSize = VEC2( 34 , 34 );
	neck.isPicked = false;
	neck.CON = 10;
	neck.DEX = 10;

	vItem.push_back( neck );

	tagItem shoulder;
	shoulder.itemKind = ITEMKIND_SHOULDER;
	shoulder.texture[ ITEMKIND_SHOULDER ] = TEXTUREM->Add( _T( "shoulder" ) , _T( "Texture/P02_ItemIcon/shoulder.png" ) , D3DX_FILTER_NONE );
	shoulder.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 200 , 0 );
	shoulder.rcSize = VEC2( 34 , 34 );
	shoulder.isPicked = false;
	shoulder.CON = 10;
	shoulder.DEX = 10;

	vItem.push_back( shoulder );

	tagItem cape;
	cape.itemKind = ITEMKIND_CAPE;
	cape.texture[ ITEMKIND_CAPE ] = TEXTUREM->Add( _T( "cape" ) , _T( "Texture/P02_ItemIcon/cape.png" ) , D3DX_FILTER_NONE );
	cape.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 250 , 0 );
	cape.rcSize = VEC2( 34 , 34 );
	cape.isPicked = false;
	cape.CON = 10;
	cape.DEX = 10;

	vItem.push_back( cape );

	tagItem body;
	body.itemKind = ITEMKIND_BODY;
	body.texture[ ITEMKIND_BODY ] = TEXTUREM->Add( _T( "body" ) , _T( "Texture/P02_ItemIcon/chest.png" ) , D3DX_FILTER_NONE );
	body.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 300 , 0 );
	body.rcSize = VEC2( 34 , 34 );
	body.isPicked = false;
	body.CON = 10;
	body.DEX = 10;

	vItem.push_back( body );

	tagItem wirst;
	wirst.itemKind = ITEMKIND_WRIST;
	wirst.texture[ ITEMKIND_WRIST ] = TEXTUREM->Add( _T( "wirst" ) , _T( "Texture/P02_ItemIcon/wrist.png" ) , D3DX_FILTER_NONE );
	wirst.rcPosition = VEC3( WINSIZEX / 2  + 100, WINSIZEY / 2  , 0 );
	wirst.rcSize = VEC2( 34 , 34 );
	wirst.isPicked = false;
	wirst.CON = 10;
	wirst.DEX = 10;

	vItem.push_back( wirst );

	tagItem hand;
	hand.itemKind = ITEMKIND_HAND;
	hand.texture[ ITEMKIND_HAND ] = TEXTUREM->Add( _T( "hand" ) , _T( "Texture/P02_ItemIcon/hand.png" ) , D3DX_FILTER_NONE );
	hand.rcPosition = VEC3( WINSIZEX / 2 + 150, WINSIZEY / 2  , 0 );
	hand.rcSize = VEC2( 34 , 34 );
	hand.isPicked = false;
	hand.CON = 10;
	hand.DEX = 10;

	vItem.push_back( hand );

	tagItem belt;
	belt.itemKind = ITEMKIND_BELT;
	belt.texture[ ITEMKIND_BELT ] = TEXTUREM->Add( _T( "belt" ) , _T( "Texture/P02_ItemIcon/belt.png" ) , D3DX_FILTER_NONE );
	belt.rcPosition = VEC3( WINSIZEX / 2 + 200, WINSIZEY / 2  , 0 );
	belt.rcSize = VEC2( 34 , 34 );
	belt.isPicked = false;
	belt.CON = 10;
	belt.DEX = 10;

	vItem.push_back( belt );


	tagItem pants;
	pants.itemKind = ITEMKIND_PANTS;
	pants.texture[ ITEMKIND_PANTS ] = TEXTUREM->Add( _T( "pants" ) , _T( "Texture/P02_ItemIcon/pants.png" ) , D3DX_FILTER_NONE );
	pants.rcPosition = VEC3( WINSIZEX / 2 + 250, WINSIZEY / 2  , 0 );
	pants.rcSize = VEC2( 34 , 34 );
	pants.isPicked = false;
	pants.CON = 10;
	pants.DEX = 10;

	vItem.push_back( pants );

	tagItem shose;
	shose.itemKind = ITEMKIND_SHOES;
	shose.texture[ITEMKIND_SHOES] = TEXTUREM->Add( _T( "shose" ) , _T( "Texture/P02_ItemIcon/shose.png" ) , D3DX_FILTER_NONE );
	shose.rcPosition = VEC3( WINSIZEX / 2 + 300 , WINSIZEY / 2  , 0 );
	shose.rcSize = VEC2( 34 , 34 );
	shose.isPicked = false;
	shose.CON = 10;
	shose.DEX = 10;

	vItem.push_back( shose );

	tagItem ring;
	ring.itemKind = ITEMKIND_RING;
	ring.texture[ ITEMKIND_RING ] = TEXTUREM->Add( _T( "ring" ) , _T( "Texture/P02_ItemIcon/ring.png" ) , D3DX_FILTER_NONE );
	ring.rcPosition = VEC3( WINSIZEX / 2 + 350, WINSIZEY / 2  , 0 );
	ring.rcSize = VEC2( 34 , 34 );
	ring.isPicked = false;
	ring.CON = 10;
	ring.DEX = 10;

	vItem.push_back( ring );

	tagItem atifact;
	atifact.itemKind = ITEMKIND_ATIFACT;
	atifact.texture[ ITEMKIND_ATIFACT ] = TEXTUREM->Add( _T( "atifact" ) , _T( "Texture/P02_ItemIcon/atifact.png" ) , D3DX_FILTER_NONE );
	atifact.rcPosition = VEC3( WINSIZEX / 2 + 400, WINSIZEY / 2 , 0 );
	atifact.rcSize = VEC2( 34 , 34 );
	atifact.isPicked = false;
	atifact.CON = 10;
	atifact.DEX = 10;

	vItem.push_back( atifact );
}

void P02_ItemBase::ItemIconDraw()
{
	for ( int i = 0; i < vItem.size(); ++i )
	{
		RECT ImageSize = { 0,0,34,34 };

		vItem[ i ].texture[ i ]->Render( &ImageSize , &vItem[ i ].rcPosition ,
			&VEC2( vItem[ i ].rcPosition.x , vItem[ i ].rcPosition.y ) , 0.0f , &VEC2( 1.25f , 1.25f ) );
	}


	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;


	TCHAR str[ 128 ];
	_stprintf( str , "ÁÂÇ¥ : %f" , vItem[ 0 ].rcPosition.x );
	FONTM->DxDrawText( str , WINSIZEX / 2 , 70 , 200 , 200 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( str , "»óÅÂ : %d" , ( int )select );
	FONTM->DxDrawText( str , WINSIZEX / 2 , 50 , 200 , 200 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( str , "x : %d" , ptMouse.x );
	FONTM->DxDrawText( str , WINSIZEX / 2 , 90 , 200 , 200 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( str , "y : %d" , ptMouse.y );
	FONTM->DxDrawText( str , WINSIZEX / 2 , 110 , 200 , 200 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );


}

void P02_ItemBase::ItemIconMove()
{

	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	for ( int i = 0; i < vItem.size(); ++i ) 
	{
		SetRect( &vItem[ i ].rc , vItem[ i ].rcPosition.x , vItem[ i ].rcPosition.y ,
			vItem[ i ].rcPosition.x + vItem[ i ].rcSize.x * 1.25 , vItem[ i ].rcPosition.y + vItem[ i ].rcSize.y * 1.25 );

		if ( INPUTM->KeyState( VK_SHIFT ) && INPUTM->KeyDown( VK_LBUTTON ) && !select )
		{

			if ( PtInRect( &vItem[ i ].rc , ptMouse ) )
			{
				vItem[ i ].isPicked = true;
				select = true;
			}
			if ( vItem[ i ].isPicked )
			{
				vItem[ i ].rcPosition.x = ptMouse.x - 10;
				vItem[ i ].rcPosition.y = ptMouse.y - 10;
			}
			continue;
		}
		if ( vItem[ i ].isPicked )
		{
			vItem[ i ].rcPosition.x = ptMouse.x - 10;
			vItem[ i ].rcPosition.y = ptMouse.y - 10;
		}

		if ( INPUTM->KeyDown( VK_LBUTTON ) && vItem[ i ].isPicked )
		{
			vItem[ i ].isPicked = false;
			select = false;
			for ( int j = 0; j < INVEN->getInventory().size(); ++j )
			{
				if ( PtInRect( &INVEN->getInventory()[ j ].rc , ptMouse ) )
				{
					vItem[ i ].rcPosition.x = INVEN->getInventory()[ j ].rc.left;
					vItem[ i ].rcPosition.y = INVEN->getInventory()[ j ].rc.top;
				}
			}
		}

	}
}



void P02_Inventory::Init()
{
	this->SetSlot();
}


void P02_Inventory::Update()
{
}

void P02_Inventory::Render()
{
	RECT imageSize;
	SetRect( &imageSize , 0 , 0 , 47 , 46 );
	for ( int i = 0; i < vInven.size(); ++i )
	{
		vInven[ 0 ].Texture[ SLOT_NONE_HELMAT ]->Render( &imageSize , &vInven[ 0 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.25f , 1.25f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );

		////////
		vInven[1].Texture[SLOT_NONE_NECK]->Render(&imageSize, &vInven[0].rcPosition, NULL, 0.0f
			, &VEC2(1.25f, 1.25f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

}

void P02_Inventory::SetSlot()
{
	tagInventory slot[ 16 ];
	ZeroMemory( slot , sizeof( tagInventory ) );
	for ( int i = 0; i < 16; ++i ) 
		//for ( int x = 0; x < 4; ++x ) for ( int y = 0; y < 4; ++y )
	{
		if ( vInven.size() >= 16 ) break;

		slot[ 0 ].Texture[SLOT_NONE_HELMAT] = TEXTUREM->Add( _T( "slot" ) , _T( "Texture/P01_Inventory/InvenHelmat.png" ) , D3DX_FILTER_NONE );
		slot[ 0 ].rcPosition = VEC3( 0  , WINSIZEY / 2   , 0 );
		slot[ 0 ].rcSize = VEC2( 34 , 34 );
		SetRect( &slot[ 0 ].rc , slot[ 0 ].rcPosition.x , slot[ 0 ].rcPosition.y ,
			slot[ 0 ].rcPosition.x + slot[ 0 ].rcSize.x * 1.25f , slot[ 0 ].rcPosition.y + slot[ 0 ].rcSize.y *1.25f );
		slot[ 0 ].isItem = false;

		vInven.push_back( slot[ 0 ] );

		///////

		slot[1].Texture[SLOT_NONE_NECK] = TEXTUREM->Add(_T("slot"), _T("Texture/P01_Inventory/InvenNeck.png"), D3DX_FILTER_NONE);
		slot[1].rcPosition = VEC3(0, WINSIZEY / 2, 0);
		slot[1].rcSize = VEC2(34, 34);
		SetRect(&slot[1].rc, slot[1].rcPosition.x, slot[1].rcPosition.y,
			slot[1].rcPosition.x + slot[1].rcSize.x * 1.25f, slot[1].rcPosition.y + slot[1].rcSize.y *1.25f);
		slot[1].isItem = false;

		vInven.push_back(slot[1]);
	}


}

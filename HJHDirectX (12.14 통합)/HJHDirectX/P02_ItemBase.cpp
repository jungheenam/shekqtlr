#include "stdafx.h"
#include "P02_ItemBase.h"


P02_ItemBase::P02_ItemBase()
{
}


P02_ItemBase::~P02_ItemBase()
{
}

void P02_ItemBase::Init()
{
	toolTip.textureTT = TEXTUREM->Find( _T( "tooltip" ) );
	this->SetItemInfo();
}

void P02_ItemBase::Release()
{
}

void P02_ItemBase::Update()
{
	this->ItemIconMove();
}

void P02_ItemBase::Render()
{

	this->ItemIconDraw();
}

void P02_ItemBase::SetItemInfo()
{

	tagItem helmat;
	helmat.Name = _T( "머리" );
	helmat.itemKind = ITEMKIND_HELMAT;
	helmat.texture = TEXTUREM->Find( _T( "helmat" ) );
	helmat.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 100 , 0 );
	helmat.rcSize = VEC2( 34 , 34 );
	helmat.isPicked = false;
	helmat.onToolTip = false;
	helmat.CON = 10;
	helmat.DEX = 10;


	vItem.push_back( helmat );

	tagItem neck;
	neck.Name = _T( "목" );
	neck.itemKind = ITEMKIND_NECK;
	neck.texture = TEXTUREM->Find( _T( "neck" ) );
	neck.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 150 , 0 );
	neck.rcSize = VEC2( 34 , 34 );
	neck.isPicked = false;
	neck.onToolTip = false;
	neck.CON = 10;
	neck.DEX = 10;


	vItem.push_back( neck );

	tagItem shoulder;
	shoulder.Name = _T( "어깨" );
	shoulder.itemKind = ITEMKIND_SHOULDER;
	shoulder.texture = TEXTUREM->Find( _T( "shoulder" ) );
	shoulder.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 200 , 0 );
	shoulder.rcSize = VEC2( 34 , 34 );
	shoulder.isPicked = false;
	shoulder.onToolTip = false;
	shoulder.CON = 10;
	shoulder.DEX = 10;

	vItem.push_back( shoulder );

	tagItem cape;
	cape.Name = _T( "망토" );
	cape.itemKind = ITEMKIND_CAPE;
	cape.texture = TEXTUREM->Find( _T( "cape" ) );
	cape.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 250 , 0 );
	cape.rcSize = VEC2( 34 , 34 );
	cape.isPicked = false;
	cape.onToolTip = false;
	cape.CON = 10;
	cape.DEX = 10;

	vItem.push_back( cape );

	tagItem body;
	body.Name = _T( "상의" );
	body.itemKind = ITEMKIND_BODY;
	body.texture = TEXTUREM->Find( _T( "body" ) );
	body.rcPosition = VEC3( WINSIZEX / 2 , WINSIZEY / 2 - 300 , 0 );
	body.rcSize = VEC2( 34 , 34 );
	body.isPicked = false;
	body.onToolTip = false;
	body.CON = 10;
	body.DEX = 10;

	vItem.push_back( body );

	tagItem wirst;
	wirst.Name = _T( "손목" );
	wirst.itemKind = ITEMKIND_WRIST;
	wirst.texture = TEXTUREM->Find( _T( "wirst" ) );
	wirst.rcPosition = VEC3( WINSIZEX / 2 + 100 , WINSIZEY / 2 , 0 );
	wirst.rcSize = VEC2( 34 , 34 );
	wirst.isPicked = false;
	wirst.onToolTip = false;
	wirst.CON = 10;
	wirst.DEX = 10;

	vItem.push_back( wirst );

	tagItem hand;
	hand.Name = _T( "손" );
	hand.itemKind = ITEMKIND_HAND;
	hand.texture = TEXTUREM->Find( _T( "hand" ) );
	hand.rcPosition = VEC3( WINSIZEX / 2 + 150 , WINSIZEY / 2 , 0 );
	hand.rcSize = VEC2( 34 , 34 );
	hand.isPicked = false;
	hand.onToolTip = false;
	hand.CON = 10;
	hand.DEX = 10;

	vItem.push_back( hand );

	tagItem belt;
	belt.Name = _T( "벨트" );
	belt.itemKind = ITEMKIND_BELT;
	belt.texture = TEXTUREM->Find( _T( "belt" ) );
	belt.rcPosition = VEC3( WINSIZEX / 2 + 200 , WINSIZEY / 2 , 0 );
	belt.rcSize = VEC2( 34 , 34 );
	belt.isPicked = false;
	belt.onToolTip = false;
	belt.CON = 10;
	belt.DEX = 10;

	vItem.push_back( belt );


	tagItem pants;
	pants.Name = _T( "바지" );
	pants.itemKind = ITEMKIND_PANTS;
	pants.texture = TEXTUREM->Find( _T( "pants" ) );
	pants.rcPosition = VEC3( WINSIZEX / 2 + 250 , WINSIZEY / 2 , 0 );
	pants.rcSize = VEC2( 34 , 34 );
	pants.isPicked = false;
	pants.onToolTip = false;
	pants.CON = 10;
	pants.DEX = 10;

	vItem.push_back( pants );

	tagItem shose;
	shose.Name = _T( "신발" );
	shose.itemKind = ITEMKIND_SHOSE;
	shose.texture = TEXTUREM->Find( _T( "shose" ) );
	shose.rcPosition = VEC3( WINSIZEX / 2 + 300 , WINSIZEY / 2 , 0 );
	shose.rcSize = VEC2( 34 , 34 );
	shose.isPicked = false;
	shose.onToolTip = false;
	shose.CON = 10;
	shose.DEX = 10;

	vItem.push_back( shose );

	tagItem ring;
	ring.Name = _T( "반지" );
	ring.itemKind = ITEMKIND_RING;
	ring.texture = TEXTUREM->Find( _T( "ring" ) );
	ring.rcPosition = VEC3( WINSIZEX / 2 + 350 , WINSIZEY / 2 , 0 );
	ring.rcSize = VEC2( 34 , 34 );
	ring.isPicked = false;
	ring.onToolTip = false;
	ring.CON = 10;
	ring.DEX = 10;

	vItem.push_back( ring );

	tagItem atifact;
	atifact.Name = _T( "장신구" );
	atifact.itemKind = ITEMKIND_ATIFACT;
	atifact.texture = TEXTUREM->Find( _T( "atifact" ) );
	atifact.rcPosition = VEC3( WINSIZEX / 2 + 400 , WINSIZEY / 2 , 0 );
	atifact.rcSize = VEC2( 34 , 34 );
	atifact.isPicked = false;
	atifact.onToolTip = false;
	atifact.CON = 10;
	atifact.DEX = 10;

	vItem.push_back( atifact );
}

void P02_ItemBase::ItemIconDraw()
{
	static int temp = 0;
	for ( int i = 0; i < vItem.size(); ++i )
	{
		RECT ImageSize = { 0,0,34,34 };

		vItem[ i ].texture->Render( &ImageSize , &vItem[ i ].rcPosition ,
			&VEC2( vItem[ i ].rcPosition.x , vItem[ i ].rcPosition.y ) , 0.0f , &VEC2( 1.25f , 1.25f ) );

		if ( vItem[ i ].onToolTip ) temp = i;

	}

		if ( vItem[ temp ].onToolTip ) ItemToolTip( &vItem[ temp ] );

	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;


	TCHAR str[ 128 ];
	_stprintf( str , "좌표 : %f" , vItem[ 0 ].rcPosition.x );
	FONTM->DxDrawText( str , WINSIZEX / 2 , 70 , 200 , 200 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( str , "상태 : %d" , ( int )select );
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

		//툴팁 랜더
		if ( PtInRect( &vItem[ i ].rc , ptMouse ) ) vItem[ i ].onToolTip = true;
		else vItem[ i ].onToolTip = false;

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

void P02_ItemBase::ItemToolTip( tagItem* _item )
{
	RECT toolTipSize = { 0,0,278,195 };
	RECT IconSize = { 0,0,34,34 };
	toolTip.tooltipPos = { _item->rcPosition.x + 50,_item->rcPosition.y,0 };

	toolTip.textureTT->Render( &toolTipSize , &toolTip.tooltipPos , NULL , NULL , &VEC2( 1.f , 1.f ) , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_item->texture->Render( &IconSize , &VEC3( toolTip.tooltipPos.x + 10 , toolTip.tooltipPos.y + 10 , 0 ) , NULL , NULL , &VEC2( 1.9f , 1.9f ) );

	TCHAR tempstr[ 64 ];
	strcpy( tempstr , _item->Name.c_str() );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 130 , toolTip.tooltipPos.y + 20 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( tempstr , "민첩 : %d" , _item->DEX );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 15 , toolTip.tooltipPos.y + 100 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( tempstr , "체력 : %d" , _item->CON );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 15 , toolTip.tooltipPos.y + 140 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );


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
	SetRect( &imageSize , 0 , 0 , 34 , 34 );
	for ( int i = 0; i < vInven.size(); ++i )
	{
		vInven[ i ].TextureI->Render( &imageSize , &vInven[ i ].rcPosition , NULL , 0.0f
			, &VEC2( 1.25f , 1.25f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
	}
}

void P02_Inventory::SetSlot()
{
	tagInventory slot[ 16 ];
	ZeroMemory( slot , sizeof( tagInventory ) );
	for ( int i = 0; i < 16; ++i ) for ( int x = 0; x < 4; ++x ) for ( int y = 0; y < 4; ++y )
	{
		if ( vInven.size() >= 16 ) break;

		slot[ i ].TextureI = TEXTUREM->Find( _T( "slot" ) );
		slot[ i ].rcPosition = VEC3( 100 + 43 * y , WINSIZEY / 2 + 43 * x , 0 );
		slot[ i ].rcSize = VEC2( 34 , 34 );
		SetRect( &slot[ i ].rc , slot[ i ].rcPosition.x , slot[ i ].rcPosition.y ,slot[ i ].rcPosition.x + slot[ i ].rcSize.x * 1.25f , slot[ i ].rcPosition.y + slot[ i ].rcSize.y *1.25f );
		slot[ i ].isItem = false;

		vInven.push_back( slot[ i ] );
	}
}




HRESULT P01_CharacterUI::Init()
{


	select = false;

	this->SetSlot();

	return S_OK;
}

void P01_CharacterUI::Release()
{
}


void P01_CharacterUI::Update()
{


	KeyDown();
	SetSlot();
}


void P01_CharacterUI::KeyDown()
{
	if ( INPUTM->KeyDown( 'I' ) )
	{
		select = !select;
	}
}

void P01_CharacterUI::SetSlot()
{
	tagInventory slot[ 16 ];
	ZeroMemory( slot , sizeof( tagInventory ) );

	slot[0].TextureC[SLOT_NONE_HELMAT] = TEXTUREM->Find(_T("slot0"));
	slot[0].rcPosition = VEC3(28, WINSIZEY / 2 - 275, 0);
	slot[0].rcSize = VEC2(34, 34);
	SetRect(&slot[0].rc, slot[0].rcPosition.x, slot[0].rcPosition.y,
	slot[0].rcPosition.x + slot[0].rcSize.x * 1.25f, slot[0].rcPosition.y + slot[0].rcSize.y *1.25f);
	slot[0].isItem = false;

	vInven.push_back(slot[0]);

	//
	slot[1].TextureC[SLOT_NONE_NECK] = TEXTUREM->Find(_T("slot1"));
	slot[1].rcPosition = VEC3(28, WINSIZEY / 2-225 , 0);
	slot[1].rcSize = VEC2(34, 34);
	SetRect(&slot[1].rc, slot[1].rcPosition.x, slot[1].rcPosition.y,
		slot[1].rcPosition.x + slot[1].rcSize.x * 1.25f, slot[1].rcPosition.y + slot[1].rcSize.y *1.25f);
	slot[1].isItem = false;

	vInven.push_back(slot[1]);

	//
	slot[2].TextureC[SLOT_NONE_SHOULDER] = TEXTUREM->Find(_T("slot2"));
	slot[2].rcPosition = VEC3(28, WINSIZEY / 2 - 175, 0);
	slot[2].rcSize = VEC2(34, 34);
	SetRect(&slot[2].rc, slot[2].rcPosition.x, slot[2].rcPosition.y,
		slot[2].rcPosition.x + slot[2].rcSize.x * 1.25f, slot[2].rcPosition.y + slot[2].rcSize.y *1.25f);
	slot[2].isItem = false;

	vInven.push_back(slot[2]);

	//
	slot[3].TextureC[SLOT_NONE_CAPE] = TEXTUREM->Find(_T("slot3"));
	slot[3].rcPosition = VEC3(28, WINSIZEY / 2 - 121, 0);
	slot[3].rcSize = VEC2(34, 34);
	SetRect(&slot[3].rc, slot[3].rcPosition.x, slot[3].rcPosition.y,
		slot[3].rcPosition.x + slot[3].rcSize.x * 1.25f, slot[3].rcPosition.y + slot[3].rcSize.y *1.25f);
	slot[3].isItem = false;

	vInven.push_back(slot[3]);

	//
	slot[4].TextureC[SLOT_NONE_BODY] = TEXTUREM->Find(_T("slot4"));
	slot[4].rcPosition = VEC3(28, WINSIZEY / 2 - 70, 0);
	slot[4].rcSize = VEC2(34, 34);
	SetRect(&slot[4].rc, slot[4].rcPosition.x, slot[4].rcPosition.y,
		slot[4].rcPosition.x + slot[4].rcSize.x * 1.25f, slot[4].rcPosition.y + slot[4].rcSize.y *1.25f);
	slot[4].isItem = false;

	vInven.push_back(slot[4]);

	//
	slot[5].TextureC[SLOT_NONE_WRIST] = TEXTUREM->Find(_T("slot5"));
	slot[5].rcPosition = VEC3(28, WINSIZEY / 2 - 19, 0);
	slot[5].rcSize = VEC2(34, 34);
	SetRect(&slot[5].rc, slot[5].rcPosition.x, slot[5].rcPosition.y,
		slot[5].rcPosition.x + slot[5].rcSize.x * 1.25f, slot[5].rcPosition.y + slot[5].rcSize.y *1.25f);
	slot[5].isItem = false;

	vInven.push_back(slot[5]);

	//
	slot[6].TextureC[SLOT_NONE_HAND] = TEXTUREM->Find(_T("slot6"));
	slot[6].rcPosition = VEC3(382, WINSIZEY / 2 - 275, 0);
	slot[6].rcSize = VEC2(34, 34);
	SetRect(&slot[6].rc, slot[6].rcPosition.x, slot[6].rcPosition.y,
		slot[6].rcPosition.x + slot[6].rcSize.x * 1.25f, slot[6].rcPosition.y + slot[6].rcSize.y *1.25f);
	slot[6].isItem = false;

	vInven.push_back(slot[6]);

	//
	slot[7].TextureC[SLOT_NONE_BELT] = TEXTUREM->Find(_T("slot7"));
	slot[7].rcPosition = VEC3(382, WINSIZEY / 2 - 225, 0);
	slot[7].rcSize = VEC2(34, 34);
	SetRect(&slot[7].rc, slot[7].rcPosition.x, slot[7].rcPosition.y,
		slot[7].rcPosition.x + slot[7].rcSize.x * 1.25f, slot[7].rcPosition.y + slot[7].rcSize.y *1.25f);
	slot[7].isItem = false;

	vInven.push_back(slot[7]);

	//
	slot[8].TextureC[SLOT_NONE_PANTS] = TEXTUREM->Find(_T("slot8"));
	slot[8].rcPosition = VEC3(382, WINSIZEY / 2 - 175, 0);
	slot[8].rcSize = VEC2(34, 34);
	SetRect(&slot[8].rc, slot[8].rcPosition.x, slot[8].rcPosition.y,
		slot[8].rcPosition.x + slot[8].rcSize.x * 1.25f, slot[8].rcPosition.y + slot[8].rcSize.y *1.25f);
	slot[8].isItem = false;

	vInven.push_back(slot[8]);

	//
	slot[9].TextureC[SLOT_NONE_SHOES] = TEXTUREM->Find(_T("slot9"));
	slot[9].rcPosition = VEC3(382, WINSIZEY / 2 - 121, 0);
	slot[9].rcSize = VEC2(34, 34);
	SetRect(&slot[9].rc, slot[9].rcPosition.x, slot[9].rcPosition.y,
		slot[9].rcPosition.x + slot[9].rcSize.x * 1.25f, slot[9].rcPosition.y + slot[9].rcSize.y *1.25f);
	slot[9].isItem = false;

	vInven.push_back(slot[9]);

	//
	slot[10].TextureC[SLOT_NONE_RING01] = TEXTUREM->Find(_T("slot10"));
	slot[10].rcPosition = VEC3(382, WINSIZEY / 2 - 70, 0);
	slot[10].rcSize = VEC2(34, 34);
	SetRect(&slot[10].rc, slot[10].rcPosition.x, slot[10].rcPosition.y,
		slot[10].rcPosition.x + slot[10].rcSize.x * 1.25f, slot[10].rcPosition.y + slot[6].rcSize.y *1.25f);
	slot[10].isItem = false;

	vInven.push_back(slot[10]);

	//
	slot[11].TextureC[SLOT_NONE_RING02] = TEXTUREM->Find(_T("slot11"));
	slot[11].rcPosition = VEC3(382, WINSIZEY / 2 - 19, 0);
	slot[11].rcSize = VEC2(34, 34);
	SetRect(&slot[11].rc, slot[11].rcPosition.x, slot[11].rcPosition.y,
		slot[11].rcPosition.x + slot[11].rcSize.x * 1.25f, slot[11].rcPosition.y + slot[11].rcSize.y *1.25f);
	slot[11].isItem = false;

	vInven.push_back(slot[11]);

	//
	slot[12].TextureC[SLOT_NONE_WEAPON] = TEXTUREM->Find(_T("slot12"));
	slot[12].rcPosition = VEC3(181, WINSIZEY / 2 +110, 0);
	slot[12].rcSize = VEC2(34, 34);
	SetRect(&slot[12].rc, slot[12].rcPosition.x, slot[12].rcPosition.y,
		slot[12].rcPosition.x + slot[12].rcSize.x * 1.25f, slot[12].rcPosition.y + slot[12].rcSize.y *1.25f);
	slot[12].isItem = false;

	vInven.push_back(slot[12]);

	//
	slot[13].TextureC[SLOT_NONE_SHIELD] = TEXTUREM->Find(_T("slot13"));
	slot[13].rcPosition = VEC3(233, WINSIZEY / 2 + 110, 0);
	slot[13].rcSize = VEC2(34, 34);
	SetRect(&slot[13].rc, slot[13].rcPosition.x, slot[13].rcPosition.y,
		slot[13].rcPosition.x + slot[13].rcSize.x * 1.25f, slot[13].rcPosition.y + slot[13].rcSize.y *1.25f);
	slot[13].isItem = false;

	vInven.push_back(slot[13]);
}

void P01_CharacterUI::ItemMove()
{

}


void P01_CharacterUI::InvenMove()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

}

void P01_CharacterUI::Render()
{
	RECT rc = { 0,0, 702, 601 };
	VEC3 pos = VEC3( 0 , 0 , 0 );
	VEC2 scale = VEC2( WINSIZEX / 1024.0f , WINSIZEY / 768.0f );

	if ( select == true )
	{
		TEXTUREM->Find( _T( "characterInven" ) )->Render( &rc , &pos , &VEC2( 0 , 0 ) , 0.0f , &scale , D3DXCOLOR( 1 , 1 , 1 , 1.0f ) );

		RECT imageSize;
		SetRect( &imageSize , 0 , 0 , 47 , 46 );
		//for (int i = 0; i < vInven.size(); ++i)
		//{
		vInven[ 0 ].TextureC[ SLOT_NONE_HELMAT ]->Render( &imageSize , &vInven[ 0 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 1 ].TextureC[ SLOT_NONE_NECK ]->Render( &imageSize , &vInven[ 1 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 2 ].TextureC[ SLOT_NONE_SHOULDER ]->Render( &imageSize , &vInven[ 2 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 3 ].TextureC[ SLOT_NONE_CAPE ]->Render( &imageSize , &vInven[ 3 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 4 ].TextureC[ SLOT_NONE_BODY ]->Render( &imageSize , &vInven[ 4 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 5 ].TextureC[ SLOT_NONE_WRIST ]->Render( &imageSize , &vInven[ 5 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 6 ].TextureC[ SLOT_NONE_HAND ]->Render( &imageSize , &vInven[ 6 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 7 ].TextureC[ SLOT_NONE_BELT ]->Render( &imageSize , &vInven[ 7 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 8 ].TextureC[ SLOT_NONE_PANTS ]->Render( &imageSize , &vInven[ 8 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 9 ].TextureC[ SLOT_NONE_SHOES ]->Render( &imageSize , &vInven[ 9 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 10 ].TextureC[ SLOT_NONE_RING01 ]->Render( &imageSize , &vInven[ 10 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 11 ].TextureC[ SLOT_NONE_RING02 ]->Render( &imageSize , &vInven[ 11 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 12 ].TextureC[ SLOT_NONE_WEAPON ]->Render( &imageSize , &vInven[ 12 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
		//
		vInven[ 13 ].TextureC[ SLOT_NONE_SHIELD ]->Render( &imageSize , &vInven[ 13 ].rcPosition , NULL , 0.0f
			, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );


		//}
	}

}

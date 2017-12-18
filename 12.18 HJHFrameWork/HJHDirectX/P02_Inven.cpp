#include "stdafx.h"
#include "P02_Inven.h"


P02_Inven::P02_Inven()
{
	toolTip.pTextureToolTip = TEXTUREM->Find( _T( "tooltip" ) );
}


P02_Inven::~P02_Inven()
{
}

HRESULT P02_Inven::Init()
{
	// �κ� ���� 
	for ( int y = 0; y < 4; ++y ) for ( int x = 0; x < 4; ++x )
	{
		tagInvenInfo* tInven;
		tInven = new tagInvenInfo;
		tInven->pTexture = TEXTUREM->Find( _T( "slot" ) );
		tInven->nIndex = 4 * y + x;
		tInven->vPosition = VEC3( WINSIZEX / 2 + x * 34 , WINSIZEY / 2 + y * 34 , 0 );
		tInven->rc = RectMake( tInven->vPosition.x , tInven->vPosition.y , 34 , 34 );
		tInven->bIsItem = false;
		tInven->pItem = NULL;

		vInven.push_back( tInven );
	}

	//	���������� ,�̸��� �̹���Ű�� , ������
	addItem( 0 , _T( "helmat" ) , vInven[ 0 ]->vPosition );
	addItem( 1 , _T( "neck" ) , vInven[ 1 ]->vPosition );
	addItem( 2 , _T( "shoulder" ) , vInven[ 2 ]->vPosition );


	vInven[ 0 ]->pItem = vItem[ 0 ];

	return S_OK;
}

void P02_Inven::Release()
{
}

void P02_Inven::Update()
{
	this->ItemMove();
}

void P02_Inven::Render()
{
	RECT itemSize = { 0,0,34,34 };
	RECT invenSize = { 0,0,34,34 };
	int temp = 0;

	for ( int i = 0; i < vInven.size(); ++i )
	{
		vInven[ i ]->pTexture->Render( &invenSize , &vInven[ i ]->vPosition );
	}

	for ( int i = 0; i < vItem.size(); ++i )
	{
		SetRect( &vItem[ i ]->rc , vItem[ i ]->vPosition.x , vItem[ i ]->vPosition.y ,
			vItem[ i ]->vPosition.x + 34 , vItem[ i ]->vPosition.y + 34 );

		vItem[ i ]->pTexture->Render( &itemSize , &vItem[ i ]->vPosition );

		if ( vItem[ i ]->bToolTip ) temp = i;

		//�������� ����
		if ( vItem[ i ]->bPicked )
		{
			tagItemInfo* token;
			token = new tagItemInfo;
			token = vItem[ i ];
			vItem[ i ] = vItem[ vItem.size() - 1 ];
			vItem[ vItem.size() - 1 ] = token;
		}
	}
	if ( vItem[ temp ]->bToolTip ) ItemToolTip( vItem[ temp ] );


}

//������ ����� �Լ�
void P02_Inven::addItem( int ItemKind , tstring name , VEC3 pos )
{
	tagItemInfo* temp;

	temp = new tagItemInfo;
	temp->name = name;
	temp->nItemKind = ItemKind;
	temp->pTexture = TEXTUREM->Find( name );
	temp->vPosition = pos;
	temp->nDex = rand() % 20 + 79;
	temp->nCon = rand() % 20 + 79;
	temp->bPicked = false;
	temp->bToolTip = false;

	vItem.push_back( temp );
}


//�������� �巡���� �Լ�
void P02_Inven::ItemMove()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	for ( int i = 0; i < vItem.size(); ++i )
	{
		if ( PtInRect( &vItem[ i ]->rc , ptMouse ) ) vItem[ i ]->bToolTip = true;
		else vItem[ i ]->bToolTip = false;

		if ( INPUTM->KeyState( VK_SHIFT ) && INPUTM->KeyDown( VK_LBUTTON ) && !select )
		{

			if ( PtInRect( &vItem[ i ]->rc , ptMouse ) )
			{
				vItem[ i ]->bPicked = true;
				select = true;
			}
			if ( vItem[ i ]->bPicked )
			{
				vItem[ i ]->vPosition.x = ptMouse.x - 10;
				vItem[ i ]->vPosition.y = ptMouse.y - 10;
			}
			continue;
		}
		if ( vItem[ i ]->bPicked )
		{
			vItem[ i ]->vPosition.x = ptMouse.x - 10;
			vItem[ i ]->vPosition.y = ptMouse.y - 10;
		}

		//�κ�ĭ�� �����۳ֱ�
		if ( INPUTM->KeyDown( VK_LBUTTON ) && vItem[ i ]->bPicked )
		{
			for ( int inven = 0; inven < vInven.size(); ++inven )
			{
				if ( PtInRect( &vInven[ inven ]->rc , ptMouse ) && !vInven[ inven ]->bIsItem )
				{
					vItem[ i ]->vPosition = vInven[ inven ]->vPosition;
					InsertItem( vItem[ i ] , vInven[ inven ]->nIndex );
					vItem[ i ]->bPicked = false;
					select = false;

					vInven[ inven ]->bIsItem = false;
				}
			}
		}






	}

}

void P02_Inven::InsertItem( tagItemInfo * _item , int _invenIndex )
{
	vInven[ _invenIndex ]->pItem = _item;
	vInven[ _invenIndex ]->bIsItem = true;

}


//������ �������� �Ѱ��� �Լ�


//���� �Լ�
void P02_Inven::ItemToolTip( tagItemInfo * _item )
{
	RECT toolTipSize = { 0,0,278,195 };
	RECT IconSize = { 0,0,34,34 };
	toolTip.tooltipPos = { _item->vPosition.x + 50,_item->vPosition.y,0 };

	toolTip.pTextureToolTip->Render( &toolTipSize , &toolTip.tooltipPos , NULL , NULL , &VEC2( 1.f , 1.f ) , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_item->pTexture->Render( &IconSize , &VEC3( toolTip.tooltipPos.x + 10 , toolTip.tooltipPos.y + 10 , 0 ) , NULL , NULL , &VEC2( 1.9f , 1.9f ) );

	TCHAR tempstr[ 64 ];
	strcpy( tempstr , _item->name.c_str() );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 130 , toolTip.tooltipPos.y + 20 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( tempstr , "��ø : %d" , _item->nDex );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 15 , toolTip.tooltipPos.y + 100 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
	_stprintf( tempstr , "ü�� : %d" , _item->nCon );
	FONTM->DxDrawText( tempstr , toolTip.tooltipPos.x + 15 , toolTip.tooltipPos.y + 140 , 100 , 100 , D3DXCOLOR( 1 , 1 , 1 , 1 ) );
}


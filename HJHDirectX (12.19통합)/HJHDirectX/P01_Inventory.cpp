#include "stdafx.h"
#include "P01_Inventory.h"


P01_Inventory::P01_Inventory()
{
}


P01_Inventory::~P01_Inventory()
{
}

void P01_Inventory::Init()
{

	/*ITEM->Init();
	INVEN->Init();*/

	this->SetSlot();

	
}

void P01_Inventory::Release()
{
}

void P01_Inventory::Update()
{

	/*INVEN->Update();
	ITEM->Update();*/

	///////////////

	RECT imageSize;
	SetRect(&imageSize, 0, 0, 46, 46);
	for (int i = 0; i < vInven.size(); ++i)
	{
		vInven[i].TextureI->Render(&imageSize, &vInven[i].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
}

void P01_Inventory::Render()
{
	/*INVEN->Render();
	ITEM->Render();*/

	//////

	RECT imageSize;
		
	SetRect( &imageSize , 0 , 0 , 46 , 46 );
		
	for ( int i = 0; i < vInven.size(); ++i )	
	{
		vInven[ i ].TextureI->Render( &imageSize , &vInven[ i ].rcPosition , NULL , 0.0f, &VEC2( 1.0f , 1.0f ) , D3DXCOLOR( 1.0f , 1.0f , 1.0f , 1.0f ) );
	}

	
}

void P01_Inventory::SetSlot()
{
	tagInven slot[16];
	ZeroMemory(slot, sizeof(tagInven));
	for (int i = 0; i < 16; ++i) for (int x = 0; x < 4; ++x) for (int y = 0; y < 4; ++y)
	{
		if (vInven.size() >= 16) break;

		slot[i].TextureI = TEXTUREM->Find(_T("slot"));
		slot[i].rcPosition = VEC3(100 + 43 * y, WINSIZEY / 2 + 43 * x, 0);
		slot[i].rcSize = VEC2(46, 46);
		SetRect(&slot[i].rc, slot[i].rcPosition.x, slot[i].rcPosition.y, slot[i].rcPosition.x + slot[i].rcSize.x * 1.25f, slot[i].rcPosition.y + slot[i].rcSize.y *1.25f);
		slot[i].isItem = false;

		vInven.push_back(slot[i]);

		/*slot[0].TextureI = TEXTUREM->Find(_T("slot"));
		slot[0].rcPosition = VEC3(100 + 43 * y, WINSIZEY / 2 + 43 * x, 0);
		slot[0].rcSize = VEC2(34, 34);
		SetRect(&slot[0].rc, slot[0].rcPosition.x, slot[0].rcPosition.y, slot[0].rcPosition.x + slot[0].rcSize.x * 1.25f, slot[0].rcPosition.y + slot[0].rcSize.y *1.25f);
		slot[0].isItem = false;

		vInven.push_back(slot[0]);*/

	}
}

void P01_Inventory::pushItem(tagInventory * _inven)
{
	/*for ( int i = 0; i < vInven.size(); ++i )
		{
			if ( vInven[ i ].rcPosition == _inven->rcPosition ) vInven[ i ].isItem = true;
		}
		*/
	
		(*_inven).isItem = true;
}

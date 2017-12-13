#include "stdafx.h"
#include "P01_Inventory.h"


P01_Inventory::P01_Inventory()
{
}


P01_Inventory::~P01_Inventory()
{
}

HRESULT P01_Inventory::Init()
{



	TEXTUREM->Add(_T("characterInven"), _T("Texture/P01_Inventory/playerUI.png"), D3DX_FILTER_NONE);

	select = false;

	this->SetSlot();
	
	return S_OK;
}

void P01_Inventory::Release()
{
}

void P01_Inventory::Update()
{

	INVEN->Update();
	ITEM->Update();
	KeyDown();
	SetSlot();
}

void P01_Inventory::KeyDown()
{
	if (INPUTM->KeyDown('I'))
	{
		select = !select;
	}
}

void P01_Inventory::SetSlot()
{
	tagInventory slot[16];
	ZeroMemory(slot, sizeof(tagInventory));
	for (int i = 0; i < 1; ++i)
		//for (int x = 0; x < 8; ++x) for (int y = 0; y < 1; ++y)
	{
		if (vInven.size() >= 16) break;

		slot[0].Texture[SLOT_NONE_HELMAT] = TEXTUREM->Add(_T("slot"), _T("Texture/P02_UI/invenSlot.png"), D3DX_FILTER_NONE);
		slot[0].rcPosition = VEC3(28 , WINSIZEY / 2-275 , 0);
		slot[0].rcSize = VEC2(34, 34);
		SetRect(&slot[0].rc, slot[0].rcPosition.x, slot[0].rcPosition.y,
			slot[0].rcPosition.x + slot[0].rcSize.x * 1.25f, slot[0].rcPosition.y + slot[0].rcSize.y *1.25f);
		slot[0].isItem = false;

		vInven.push_back(slot[0]);

		
	}

	

}

void P01_Inventory::ItemMove()
{

	
}

void P01_Inventory::InvenMove()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;

	
	
}

void P01_Inventory::Render()
{
	RECT rc = { 0,0, 702, 601 };
	VEC3 pos = VEC3(0, 0, 0);
	VEC2 scale = VEC2(WINSIZEX / 1024.0f, WINSIZEY / 768.0f);

	

	
	
	
	if (select == true)
	{
		TEXTUREM->Find(_T("characterInven"))->Render(&rc, &pos, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));

		RECT imageSize;
		SetRect(&imageSize, 0, 0, 47, 46);
		for (int i = 0; i < vInven.size(); ++i)
		{
			vInven[0].Texture[SLOT_NONE_HELMAT]->Render(&imageSize, &vInven[0].rcPosition, NULL, 0.0f
				, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			////////
			/*vInven[i].Texture[SLOT_NONE_NECK]->Render(&imageSize, &vInven[i].rcPosition, NULL, 0.0f
				, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));*/

		}

	}

	ITEM->Render();
	

	
}

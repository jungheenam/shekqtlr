#include "stdafx.h"
#include "P01_PlayerEquipment.h"


P01_PlayerEquipment::P01_PlayerEquipment()
{
}


P01_PlayerEquipment::~P01_PlayerEquipment()
{
}

HRESULT P01_PlayerEquipment::Init()
{
	select = false;
	this->SetSlot();

	return S_OK;
}

void P01_PlayerEquipment::Release()
{
}

void P01_PlayerEquipment::Update()
{
	this->KeyDown();
}

void P01_PlayerEquipment::KeyDown()
{
	if (INPUTM->KeyDown('I'))
	{
		select = !select;
	}
}

void P01_PlayerEquipment::SetSlot()
{
	tagInventory slot[14];
	ZeroMemory(slot, sizeof(tagInventory));

	slot[0].TextureC[SLOT_NONE_HELMAT] = TEXTUREM->Find(_T("slot0"));
	slot[0].rcPosition = VEC3(28, WINSIZEY / 2 - 275, 0);
	slot[0].rcSize = VEC2(34, 34);
	SetRect(&slot[0].rc, slot[0].rcPosition.x, slot[0].rcPosition.y,
		slot[0].rcPosition.x + slot[0].rcSize.x * 1.25f, slot[0].rcPosition.y + slot[0].rcSize.y *1.25f);
	slot[0].isItem = false;

	vInven.push_back(slot[0]);

	//
	slot[1].TextureC[SLOT_NONE_NECK] = TEXTUREM->Find(_T("slot1"));
	slot[1].rcPosition = VEC3(28, WINSIZEY / 2 - 225, 0);
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
	slot[12].rcPosition = VEC3(181, WINSIZEY / 2 + 110, 0);
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

	//소지품 슬롯
	INVEN->SetSlot();
}

void P01_PlayerEquipment::ItemMove()
{
}

void P01_PlayerEquipment::InvenMove()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;
}

void P01_PlayerEquipment::Render()
{
	//캐릭터 장비창
	RECT rc = { 0,0, 702, 601 };
	VEC3 pos = VEC3(0, 0, 0);
	VEC2 scale = VEC2(WINSIZEX / 1024.0f, WINSIZEY / 768.0f);

	//캐릭터 인벤토리
	RECT rc1 = { 0,0, 254, 313 };
	VEC3 pos1 = VEC3(720, 25, 0);
	

	//인벤토리 슬롯
	RECT rc2 = { 0,0, 46, 46 };
	VEC3 pos2 = VEC3(720, 25, 0);
	

	if (select == true)
	{
		TEXTUREM->Find(_T("characterInven"))->Render(&rc, &pos, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));

		RECT imageSize;
		SetRect(&imageSize, 0, 0, 47, 46);

		vInven[0].TextureC[SLOT_NONE_HELMAT]->Render(&imageSize, &vInven[0].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[1].TextureC[SLOT_NONE_NECK]->Render(&imageSize, &vInven[1].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[2].TextureC[SLOT_NONE_SHOULDER]->Render(&imageSize, &vInven[2].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[3].TextureC[SLOT_NONE_CAPE]->Render(&imageSize, &vInven[3].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[4].TextureC[SLOT_NONE_BODY]->Render(&imageSize, &vInven[4].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[5].TextureC[SLOT_NONE_WRIST]->Render(&imageSize, &vInven[5].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[6].TextureC[SLOT_NONE_HAND]->Render(&imageSize, &vInven[6].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[7].TextureC[SLOT_NONE_BELT]->Render(&imageSize, &vInven[7].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[8].TextureC[SLOT_NONE_PANTS]->Render(&imageSize, &vInven[8].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[9].TextureC[SLOT_NONE_SHOES]->Render(&imageSize, &vInven[9].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[10].TextureC[SLOT_NONE_RING01]->Render(&imageSize, &vInven[10].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[11].TextureC[SLOT_NONE_RING02]->Render(&imageSize, &vInven[11].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[12].TextureC[SLOT_NONE_WEAPON]->Render(&imageSize, &vInven[12].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//
		vInven[13].TextureC[SLOT_NONE_SHIELD]->Render(&imageSize, &vInven[13].rcPosition, NULL, 0.0f
			, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));


		//============== 장비창 =================//

		TEXTUREM->Find(_T("playerInven"))->Render(&rc1, &pos1, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));

		//============== 슬롯 =================//

		TEXTUREM->Find(_T("slot"))->Render(&rc2, &pos2, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));

	}

}

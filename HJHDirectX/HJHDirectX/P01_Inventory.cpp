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



	return S_OK;
}

void P01_Inventory::Release()
{
}

void P01_Inventory::Update()
{

	INVEN->Update();
	ITEM->Update();
}

void P01_Inventory::Render()
{
	INVEN->Render();
	ITEM->Render();
}

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
}

void P01_PlayerEquipment::KeyDown()
{
	this->KeyDown();
}

void P01_PlayerEquipment::SetSlot()
{
	if (INPUTM->KeyDown('I'))
	{
		select = !select;
	}
}

void P01_PlayerEquipment::ItemMove()
{
}

void P01_PlayerEquipment::InvenMove()
{
}

void P01_PlayerEquipment::Render()
{
}

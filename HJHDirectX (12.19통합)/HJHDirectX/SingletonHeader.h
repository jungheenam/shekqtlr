#pragma once

#include "Dx.h"
#define DXM Dx::GetSingleton()
#define DXDEV DXM->_pDev

#include "InputManager.h"
#define INPUTM InputManager::GetSingleton()

#include "DxCamera.h"
#define CAM DxCamera::GetSingleton()

#include "Timer.h"
#define TIMER Timer::GetSingleton()
#define BASETIME (_fElapsedTime * 60.0f) 

#include "SceneManager.h"
#define SCENEM SceneManager::GetSingleton()

#include "DxFont.h"
#define FONTM DxFont::GetSingleton()

#include "TextureManager.h"
#define TEXTUREM TextureManager::GetSingleton()

#include "P02_PlayerStat.h"
#define PLAYERSTAT P02_PlayerStat::GetSingleton()

#include "P02_ItemBase.h"
#define ITEM P02_ItemBase::GetSingleton()
//#define INVEN P02_Inventory::GetSingleton()
//#define CHARUI P01_CharacterUI::GetSingleton()


//20171216 ΩÃ±€≈Ê √ﬂ∞° ¿Ã¡ÿº≠
#include "P01_GaugeBar.h"
#define GAUGE P01_GaugeBar::GetSingleton()

//20171219
#include "P01_Inventory.h"
#define INVENTORY  P01_Inventory::GetSingleton()

#include "P01_PlayerEquipment.h"
#define QUIPMENT P01_PlayerEquipment::GetSingleton()

#include "P01_Inventory.h"
#define INVEN P01_Inventory::GetSingleton()

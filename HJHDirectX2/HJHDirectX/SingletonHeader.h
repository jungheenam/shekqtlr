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

#include "P02_UIManger.h"
#define UIM P02_UIManger::GetSingleton()

#include "P02_ItemBase.h"
#define ITEM P02_ItemBase::GetSingleton()
#define INVEN P02_Inventory::GetSingleton()

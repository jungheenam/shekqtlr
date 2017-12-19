#include "stdafx.h"
#include "P01_DungeonScene.h"


P01_DungeonScene::P01_DungeonScene()
{
}


P01_DungeonScene::~P01_DungeonScene()
{
}

HRESULT P01_DungeonScene::Init()
{
	GAUGE->Init();
	QUIPMENT->Init();
	return S_OK;
}

void P01_DungeonScene::Release()
{
}

void P01_DungeonScene::Update()
{
	QUIPMENT->Update();
}

void P01_DungeonScene::Render()
{
	GAUGE->Render();
	QUIPMENT->Render();

}

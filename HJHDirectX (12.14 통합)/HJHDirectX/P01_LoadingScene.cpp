#include "stdafx.h"
#include "P01_LoadingScene.h"


P01_LoadingScene::P01_LoadingScene()
{


}


P01_LoadingScene::~P01_LoadingScene()
{
}


HRESULT P01_LoadingScene::Init()
{
	loading = new P02_Loading;
	loading->Init();
	this->LoadTexture();

	TEXTUREM->Add(_T("loadingIm"), _T("Texture/P01_Inventory/loadingScreen01.png"));

	return S_OK;
}

void P01_LoadingScene::Release()
{

}

void P01_LoadingScene::Update()
{
	loading->Update();
	if ( loading->LoadingDone() )SCENEM->Change( _T( "P01_StartMenuScene" ) );
}

void P01_LoadingScene::Render()
{
	RECT rc = { 0,0,1024,768 };
	VEC3 pos = VEC3(0, 0, 0);
	VEC2 scale = VEC2(WINSIZEX / 1024.0f, WINSIZEY / 768.0f);


	TEXTUREM->Find(_T("loadingIm"))->Render(&rc, &pos, &VEC2(0, 0), 0.0f, &scale, D3DXCOLOR(1, 1, 1, 1.0f));
	TEXTUREM->Find(_T("loadingIm"))->SpriteState();
	
	loading->Render();

	
}

void P01_LoadingScene::LoadTexture()
{
	//=================================��ư=======================================

	loading->LoadTexture( _T( "normal" ) , _T( "Texture/P02_UITest/mainButton01.png " ) );
	loading->LoadTexture( _T( "over" ) , _T( "Texture/P02_UITest/mainButton01.png " ) );
	loading->LoadTexture( _T( "down" ) , _T( "Texture/P02_UITest/mainButton02.png " ) );
	loading->LoadTexture( _T( "tooltip" ) , _T( "Texture/P02_UI/tooltip.png" ) );
	//============================================================================


	//=================================�κ�=======================================

	loading->LoadTexture( _T( "slot" ) , _T( "Texture/P02_UI/invenSlot.png" ) );
	loading->LoadTexture( _T( "characterInven" ) , _T( "Texture/P01_Inventory/playerUI.png" ) );

	loading->LoadTexture(_T("slot0"), _T("Texture/P01_Inventory/slot0.png"));
	loading->LoadTexture(_T("slot1"), _T("Texture/P01_Inventory/slot1.png"));
	loading->LoadTexture(_T("slot2"), _T("Texture/P01_Inventory/slot2.png"));
	loading->LoadTexture(_T("slot3"), _T("Texture/P01_Inventory/slot3.png"));
	loading->LoadTexture(_T("slot4"), _T("Texture/P01_Inventory/slot4.png"));
	loading->LoadTexture(_T("slot5"), _T("Texture/P01_Inventory/slot5.png"));
	loading->LoadTexture(_T("slot6"), _T("Texture/P01_Inventory/slot6.png"));
	loading->LoadTexture(_T("slot7"), _T("Texture/P01_Inventory/slot7.png"));
	loading->LoadTexture(_T("slot8"), _T("Texture/P01_Inventory/slot8.png"));
	loading->LoadTexture(_T("slot9"), _T("Texture/P01_Inventory/slot9.png"));
	loading->LoadTexture(_T("slot10"), _T("Texture/P01_Inventory/slot10.png"));
	loading->LoadTexture(_T("slot11"), _T("Texture/P01_Inventory/slot11.png"));
	loading->LoadTexture(_T("slot12"), _T("Texture/P01_Inventory/slot12.png"));
	loading->LoadTexture(_T("slot13"), _T("Texture/P01_Inventory/slot13.png"));
	loading->LoadTexture(_T("slot14"), _T("Texture/P01_Inventory/slot14.png"));



	//=================================������=======================================

	loading->LoadTexture( _T( "helmat" ) , _T( "Texture/P02_ItemIcon/helmat.png" ) );
	loading->LoadTexture( _T( "neck" ) , _T( "Texture/P02_ItemIcon/neck.png" ) );
	loading->LoadTexture( _T( "shoulder" ) , _T( "Texture/P02_ItemIcon/shoulder.png" ) );
	loading->LoadTexture( _T( "cape" ) , _T( "Texture/P02_ItemIcon/cape.png" ) );
	loading->LoadTexture( _T( "body" ) , _T( "Texture/P02_ItemIcon/chest.png" ) );
	loading->LoadTexture( _T( "wirst" ) , _T( "Texture/P02_ItemIcon/wrist.png" ) );
	loading->LoadTexture( _T( "hand" ) , _T( "Texture/P02_ItemIcon/hand.png" ) );
	loading->LoadTexture( _T( "belt" ) , _T( "Texture/P02_ItemIcon/belt.png" ) );
	loading->LoadTexture( _T( "pants" ) , _T( "Texture/P02_ItemIcon/pants.png" ) );
	loading->LoadTexture( _T( "shose" ) , _T( "Texture/P02_ItemIcon/shose.png" ) );
	loading->LoadTexture( _T( "ring" ) , _T( "Texture/P02_ItemIcon/ring.png" ) );
	loading->LoadTexture( _T( "atifact" ) , _T( "Texture/P02_ItemIcon/atifact.png" ) );

	//================================= �÷��̾� UI==================================

	loading->LoadTexture(_T("playerUI"), _T("Texture/P01_Inventory/playerUI.png"));
	loading->LoadTexture(_T("platerGauge"), _T("Texture/P02_UI/gauge03.png"));
	loading->LoadTexture(_T("platerGaugeColor"), _T("Texture/P02_UI/playerGauge01.png"));
}



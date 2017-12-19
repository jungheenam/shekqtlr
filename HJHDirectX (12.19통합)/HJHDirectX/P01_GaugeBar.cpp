#include "stdafx.h"
#include "P01_GaugeBar.h"


P01_GaugeBar::P01_GaugeBar()
{
}


P01_GaugeBar::~P01_GaugeBar()
{
}

HRESULT P01_GaugeBar::Init()
{
	playerGauge = TEXTUREM->Find("playerGauge");
	
	
	return S_OK;
}

void P01_GaugeBar::Release()
{
}

void P01_GaugeBar::Updata()
{
}

void P01_GaugeBar::Render()
{
	RECT imageSize;
	SetRect(&imageSize, 0, 0, 233, 83);
	
	playerGauge->Render(&imageSize, &VEC3(0, 0, 0), NULL, 0.0f, &VEC2(1.0f, 1.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

}

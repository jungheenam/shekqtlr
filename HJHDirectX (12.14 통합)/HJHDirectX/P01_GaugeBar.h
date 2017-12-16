#pragma once
#include "SingletonBase.h"

class P01_GaugeBar : public SingletonBase<P01_GaugeBar>
{
private:
	Texture* playerGauge;
	
public:
	P01_GaugeBar();
	~P01_GaugeBar();

	HRESULT Init();
	void Release();
	void Updata();
	void Render();
};


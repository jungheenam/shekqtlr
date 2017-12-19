#pragma once
#include "SingletonBase.h"



class P01_Inventory :public SingletonBase<P01_Inventory>
{
public:
	P01_Inventory();
	~P01_Inventory();


	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


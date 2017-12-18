#pragma once
class P01_Inventory :public GameNode
{
public:
	P01_Inventory();
	~P01_Inventory();


	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


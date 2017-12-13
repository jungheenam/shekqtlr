#pragma once
class P01_Inventory :public GameNode
{
private:

	vector<tagItem> vItem;
	vector<tagInventory> vInven;

	bool select;


public:
	P01_Inventory();
	~P01_Inventory();


	HRESULT Init();
	void Release();
	void Update();
	void KeyDown();
	void SetSlot();
	void ItemMove();
	void InvenMove();
	void Render();

	vector<tagInventory> getInventory() { return vInven; }
};


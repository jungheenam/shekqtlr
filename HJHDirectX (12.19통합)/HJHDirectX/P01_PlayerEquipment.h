#pragma once
struct tagCharacterUI
{
	Texture* Texture;
	RECT rc;
	VEC3 rcPosition;
	VEC2 rcSize;

};
class P01_PlayerEquipment
{
private:

	vector<tagItem> vItem;
	vector<tagInventory> vInven;

	bool select;


public:
	P01_PlayerEquipment();
	~P01_PlayerEquipment();

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


#pragma once
#include "SingletonBase.h"

enum INVENTORYSLOT
{
	//SLOT_NONE
	INVEN_SLOT_NONE_HELMAT,
	INVEN_SLOT_NONE_NECK,
	INVEN_SLOT_NONE_SHOULDER,
	INVEN_SLOT_NONE_CAPE,
	INVEN_SLOT_NONE_BODY,
	INVEN_SLOT_NONE_WRIST,
	INVEN_SLOT_NONE_HAND,
	INVEN_SLOT_NONE_BELT,
	INVEN_SLOT_NONE_PANTS,
	INVEN_SLOT_NONE_SHOES,
	INVEN_SLOT_NONE_RING01,
	INVEN_SLOT_NONE_RING02,
	INVEN_SLOT_NONE_WEAPON,
	INVEN_SLOT_NONE_SHIELD,
	
	//SLOT_IN
	INVEN_SLOT_IN_HELMAT,
	INVEN_SLOT_IN_NECK,
	INVEN_SLOT_IN_SHOULDER,
	INVEN_SLOT_IN_CAPE,
	INVEN_SLOT_IN_BODY,
	INVEN_SLOT_IN_WRIST,
	INVEN_SLOT_IN_HAND,
	INVEN_SLOT_IN_BELT,
	INVEN_SLOT_IN_PANTS,
	INVEN_SLOT_IN_SHOES,
	INVEN_SLOT_IN_RING01,
	INVEN_SLOT_IN_RING02,
	INVEN_SLOT_IN_WEAPON,
	INVEN_SLOT_IN_SHIELD,
	
	INVEN_SLOT_NONE,
	INVEN_SLOT_INITEM,
	INVEN_SLOT_END
};

struct tagInven
{
	Texture* TextureI;						//인벤토리창 슬롯
	Texture* TextureC[SLOT_END];			//캐릭터창 슬롯
	RECT rc;
	VEC3 rcPosition;
	VEC2 rcSize;

	bool isItem;
};



class P01_Inventory :public SingletonBase<P01_Inventory>
{

private:
	vector<tagInven> vInven;


public:
	P01_Inventory();
	~P01_Inventory();


	void Init();
	void Release();
	void Update();
	void Render();
	void SetSlot();

	void pushItem(tagInventory* _inven);

	vector<tagItem> vItem;
	vector<tagInven> getInventory() { return vInven; }
	void SetInventoryState(int num, bool state) { vInven[num].isItem = state; }


};


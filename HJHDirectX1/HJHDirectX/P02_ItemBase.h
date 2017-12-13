#pragma once
#include "SingletonBase.h"
enum ITEMKIND
{
	ITEMKIND_HELMAT = 0 ,
	ITEMKIND_NECK ,
	ITEMKIND_SHOULDER ,
	ITEMKIND_CAPE ,
	ITEMKIND_BODY ,
	ITEMKIND_WRIST ,
	ITEMKIND_HAND ,
	ITEMKIND_BELT ,
	ITEMKIND_PANTS ,
	ITEMKIND_SHOSE ,
	ITEMKIND_RING ,
	ITEMKIND_ATIFACT ,
	//..

	ITEMKIND_END
};
enum INVENTORYSLOT
{
	SLOT_NONE,
	SLOT_INITEM,
	SLOT_END

};

struct tagItem
{
	ITEMKIND itemKind;
	Texture* texture[ ITEMKIND_END ];
	RECT rc;
	VEC3 rcPosition;
	VEC2 rcSize;
	int DEX;
	int CON;

	bool isPicked;
};


struct tagInventory
{
	Texture* Texture[SLOT_END];
	RECT rc;
	VEC3 rcPosition;
	VEC2 rcSize;

	bool isItem;
};

class P02_ItemBase :public SingletonBase<P02_ItemBase>
{
private:
	vector<tagItem> vItem;
	ITEMKIND itemKind;

	bool select = false;

public:
	P02_ItemBase();
	~P02_ItemBase();

	void Init();
	void Release();
	void Update();
	void Render();

	void SetItemInfo();
	void ItemIconDraw();
	void ItemIconMove();

	vector<tagItem> getItem() { return vItem; }
};


class P02_Inventory : public SingletonBase<P02_Inventory>
{
public:
	P02_Inventory();
	~P02_Inventory();

	void Init();
	void Update();
	void Render();
	void SetSlot();
	
	vector<tagInventory> getInventory() { return vInven; }


private:
	vector<tagInventory> vInven;


};
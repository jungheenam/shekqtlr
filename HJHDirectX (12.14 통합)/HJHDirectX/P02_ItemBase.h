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
	//SLOT_NONE
	SLOT_NONE_HELMAT ,
	SLOT_NONE_NECK ,
	SLOT_NONE_SHOULDER ,
	SLOT_NONE_CAPE ,
	SLOT_NONE_BODY ,
	SLOT_NONE_WRIST ,
	SLOT_NONE_HAND ,
	SLOT_NONE_BELT ,
	SLOT_NONE_PANTS ,
	SLOT_NONE_SHOES ,
	SLOT_NONE_RING01 ,
	SLOT_NONE_RING02 ,
	SLOT_NONE_WEAPON ,
	SLOT_NONE_SHIELD ,

	//SLOT_IN
	SLOT_IN_HELMAT ,
	SLOT_IN_NECK ,
	SLOT_IN_SHOULDER ,
	SLOT_IN_CAPE ,
	SLOT_IN_BODY ,
	SLOT_IN_WRIST ,
	SLOT_IN_HAND ,
	SLOT_IN_BELT ,
	SLOT_IN_PANTS ,
	SLOT_IN_SHOES ,
	SLOT_IN_RING01 ,
	SLOT_IN_RING02 ,
	SLOT_IN_WEAPON ,
	SLOT_IN_SHIELD ,


	SLOT_NONE,
	SLOT_INITEM ,
	SLOT_END
};


struct tagItem
{
	tstring  Name;
	ITEMKIND itemKind;
	Texture* texture;
	RECT rc;
	VEC3 rcPosition;
	VEC2 rcSize;
	int DEX;
	int CON;

	bool isPicked;
	Texture* textureTT;
	VEC3 tooltipPos;
	bool onToolTip;
};


struct tagInventory
{
	Texture* TextureI;						//인벤토리창 슬롯
	Texture* TextureC[ SLOT_END ];			//캐릭터창 슬롯
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
	tagItem toolTip;

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
	void ItemToolTip( tagItem* _item );

	vector<tagItem> getItem() { return vItem; }
};


class P02_Inventory : public SingletonBase<P02_Inventory>
{
public:
	P02_Inventory() {};
	~P02_Inventory() {};

	void Init();
	void Update();
	void Render();
	void SetSlot();
	
	vector<tagInventory> getInventory() { return vInven; }


private:
	vector<tagInventory> vInven;


};


class P01_CharacterUI : public SingletonBase<P01_CharacterUI>
{
private:

	vector<tagItem> vItem;
	vector<tagInventory> vInven;

	bool select;


public:
	P01_CharacterUI() {};
	~P01_CharacterUI() {};


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
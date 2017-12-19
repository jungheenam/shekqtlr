#pragma once

enum ITEMTYPE
{
	ITEMTYPE_HELMAT,
	ITEMTYPE_NECK,
	ITEMTYPE_SHOULDER,
	ITEMTYPE_CAPE,
	ITEMTYPE_BODY,
	ITEMTYPE_WRIST,
	ITEMTYPE_HAND,
	ITEMTYPE_BELT,
	ITEMTYPE_PANTS,
	ITEMTYPE_SHOES,
	ITEMTYPE_RING01,
	ITEMTYPE_RING02,
	ITEMTYPE_WEAPON,
	ITEMTYPE_SHIL

};

//enum INVENTORYSLOT
//{
//	//SLOT_NONE
//	SLOT_NONE_HELMAT,
//	SLOT_NONE_NECK,
//	SLOT_NONE_SHOULDER,
//	SLOT_NONE_CAPE,
//	SLOT_NONE_BODY,
//	SLOT_NONE_WRIST,
//	SLOT_NONE_HAND,
//	SLOT_NONE_BELT,
//	SLOT_NONE_PANTS,
//	SLOT_NONE_SHOES,
//	SLOT_NONE_RING01,
//	SLOT_NONE_RING02,
//	SLOT_NONE_WEAPON,
//	SLOT_NONE_SHIELD,
//
//	//SLOT_IN
//	SLOT_IN_HELMAT,
//	SLOT_IN_NECK,
//	SLOT_IN_SHOULDER,
//	SLOT_IN_CAPE,
//	SLOT_IN_BODY,
//	SLOT_IN_WRIST,
//	SLOT_IN_HAND,
//	SLOT_IN_BELT,
//	SLOT_IN_PANTS,
//	SLOT_IN_SHOES,
//	SLOT_IN_RING01,
//	SLOT_IN_RING02,
//	SLOT_IN_WEAPON,
//	SLOT_IN_SHIELD,
//
//
//	SLOT_NONE,
//	SLOT_INITEM,
//	SLOT_END
//};

//struct tagItem
//{
//	tstring Name;
//	ITEMTYPE itemKind;
//	Texture* texture;
//	RECT rc;
//	VEC3 rcPosition;
//	VEC2 rcSize;
//	
//	bool isPicked;
//	bool canUse, canEquip;
//	
//};
//
//struct tagInventory
//{
//	Texture* Texture;
//	RECT rc;
//	VEC3 rcPosition;
//	VEC2 rcSize;
//	
//};


class P01_Item 
{
private:
	int _invenScroll;
	int _invenNum;
	int _itemNum;

	ITEMTYPE _itemType;

	Texture _invenImg;
	Texture _itemSelect;


	float _x, _y;
	RECT _rc;

	bool _onInven;
public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	void itemSelect();
	void invenSelet();
	void itemSelectDraw();
	void invenDraw();
	void startDraw();

	void invenPick();


	P01_Item();
	~P01_Item();


	

};


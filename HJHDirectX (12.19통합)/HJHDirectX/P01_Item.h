#pragma once

enum ITEMTYPE
{
	ITEMTYPE_HELMAT = 0,
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
	ITEMTYPE_SHIL,

	ITEMTYPE_END

};



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


#pragma once


#define INVEN_MAX 16


enum ITEMKINDQ
{
	ITEMKINDq_HELMAT = 0 ,
	ITEMKINDq_NECK ,
	ITEMKINDq_SHOULDER ,
	ITEMKINDq_CAPE ,
	ITEMKINDq_BODY ,
	ITEMKINDq_WRIST ,
	ITEMKINDq_HAND ,
	ITEMKINDq_BELT ,
	ITEMKINDq_PANTS ,
	ITEMKINDq_SHOSE ,
	ITEMKINDq_RING ,
	ITEMKINDq_ATIFACT ,
	//..

	ITEMKINDq_END
};

struct tagItemInfo
{
	tstring		name;

	int			nItemKind;
	Texture*	pTexture;

	VEC3		vPosition;

	int			nDex;
	int			nCon;
	RECT		rc;
	bool		bPicked;
	bool		bToolTip;

	Texture*	pTextureToolTip;
	VEC3		tooltipPos;
};

struct tagInvenInfo
{
	Texture*	pTexture;

	int		nIndex;
	VEC3	vPosition;
	RECT	rc;

	bool	bIsItem;
};

struct tagToolTip
{

};

class P02_Inven
{
public:
	P02_Inven();
	~P02_Inven();


	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void addItem(int ItemKind ,tstring name , VEC3 pos );
	void ItemMove();
	void InsertItem();
	void ItemToolTip( tagItemInfo* _item );

	
private:
	vector<tagItemInfo*> vItem;
	vector<tagInvenInfo*> vInven;
	tagItemInfo toolTip;
	bool select;
};


#pragma once

enum LOADKIND
{
	LOADKIND_TEXTURE0,
	LOADKIND_TEXTURE1,
	LOADKIND_X,
	LOADKIND_END
};
struct tagTextureResource
{
	tstring keyName;
	TCHAR* fileName;

};


class loadItem
{
private:
	LOADKIND loadkind;
	tagTextureResource texture;

public:
	HRESULT initForTexture( tstring _keyName , TCHAR* _fileName );


	LOADKIND getLoadKind() { return loadkind; }
	tagTextureResource getTexture() { return texture; }

	loadItem();
	~loadItem();
};

class P02_Loading : public GameNode
{
private:
	typedef vector<loadItem*> vLoad;
	typedef vector<loadItem*>::iterator viLoad;

private:
	P02_Progressbar* bar;
	vLoad load;

	int currentGauge;

public:
	P02_Loading();
	~P02_Loading();

	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void LoadTexture( tstring _keyName , TCHAR* _fileName  );


	BOOL LoadingDone();

	vector<loadItem*> getLoadItem() { return load; }
};


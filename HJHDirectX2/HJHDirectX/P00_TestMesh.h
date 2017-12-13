#pragma once
class P00_TestMesh
{
private:
	LPMESH  _pMesh;
	int		_nSubset;
	LPTXUR  _pTex[6];
public:
	P00_TestMesh();
	~P00_TestMesh();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


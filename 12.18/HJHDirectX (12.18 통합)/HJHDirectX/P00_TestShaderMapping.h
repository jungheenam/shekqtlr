#pragma once
class P00_TestShaderMapping
{
private:
	LPVS _pVS;
	LPVD _pFVF;

	MAT		_mWorld;
	LPMESH	_pMesh;
	LPTXUR	_pTex;
public:
	P00_TestShaderMapping();
	~P00_TestShaderMapping();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


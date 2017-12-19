#pragma once
class P00_TestShaderBase
{
private:
	LPVS		_pVS;
	LPVD		_pFVF;
	tagVertexPD _aVtx[24];
	tagIndex	_aIdx[12];
public:
	P00_TestShaderBase();
	~P00_TestShaderBase();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


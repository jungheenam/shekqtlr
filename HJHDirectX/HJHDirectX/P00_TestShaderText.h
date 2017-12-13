#pragma once
class P00_TestShaderText
{
private:
	LPVS _pVS;
	LPVD _pFVF;

	tagVertexPDT _aVtx[4];
	LPTXUR		 _pTex;

	MAT			  _mWorld;
	int			  _nIdx;
	tagVertexPDT* _pVtx;
public:
	P00_TestShaderText();
	~P00_TestShaderText();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


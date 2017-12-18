#pragma once
class P00_TestSkinning
{
private:
	tagVertexPBT	_aVtx[42];
	MAT				_mWorld[256];
	LPTXUR			_pTex;
	int				_nMaxWorld;
public:
	P00_TestSkinning();
	~P00_TestSkinning();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};


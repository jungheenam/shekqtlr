#pragma once
class P00_TestSplatting
{
private:
	int				_nVtx;
	int				_nIdx;

	tagIndex*		_pIdx;
	tagVertexPDT*	_pVtx;

	int				_iTile;
	float			_fWidth;

	int					_nTex;
	tagWeightTexture*	_pTex;

	DWORD			_dTexFactor;
	VEC3			_vLightDir;
public:
	P00_TestSplatting();
	~P00_TestSplatting();
	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void CalulateMap();
	void CalculateMapTile(int nTex, DWORD* &pTextureAlpha);

	void VectorToRGB();

	//void SetTextureFilter() { _bFilter ^= 1; }

	HRESULT LoadTexture(TCHAR* sFilename, LPTXUR& pTexture, DWORD color = 0x00FFFFFF,
		DIMG* pImageInfo = NULL, DWORD dFilter = (D3DX_FILTER_TRIANGLE | D3DX_FILTER_MIRROR),
		DWORD dMipFilter = (D3DX_FILTER_TRIANGLE | D3DX_FILTER_MIRROR), D3DFORMAT dFormat = D3DFMT_UNKNOWN);
};


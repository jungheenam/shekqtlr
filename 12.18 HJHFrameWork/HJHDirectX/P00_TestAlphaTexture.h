#pragma once
class P00_TestAlphaTexture
{
private:
	int _nVtx;
	int _nIdx;

	tagVertexPDT3*	_pVtx;	
	tagIndex*		_pIdx;
	
	int		_iTile;
	float	_fWidth;

	int					_nTex;
	tagAlphaTexture*	_pTex;

	DWORD	_dTexFactor;
	VEC3	_vLight;

	bool _bFilter;
public:
	P00_TestAlphaTexture();
	~P00_TestAlphaTexture();
	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void CalculateMap();
	void CalculateMapTile(int nTex, LPTXUR& pTextureAlpha);

	void VectorToRGB();

	void SetTextureFilter() { _bFilter ^= 1; }

	HRESULT LoadTexture(TCHAR* sFilename, LPTXUR& pTexture, DWORD color = 0x00FFFFFF,
		DIMG* pImageInfo = NULL, DWORD dFilter = (D3DX_FILTER_TRIANGLE | D3DX_FILTER_MIRROR),
		DWORD dMipFilter = (D3DX_FILTER_TRIANGLE | D3DX_FILTER_MIRROR), D3DFORMAT dFormat = D3DFMT_UNKNOWN);
};


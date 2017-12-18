#include "stdafx.h"
#include "P00_TestAlphaTexture.h"

int _nTileIndex[][33] =
{
	{ 1,0,0,0,0,0,0,0, 1,2,0,0,0,0,0,0, 1,2,3,0,0,0,0,0, 1,2,3,0,1,2,3,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 1,2,2,2,3,2,2,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,3,3,2,3,3,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,1,1,3,1,1,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 1,1,2,2,3,3,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },

	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, },
};


P00_TestAlphaTexture::P00_TestAlphaTexture()
{
	_nVtx	= 0;
	_nIdx	= 0;

	_pVtx	= NULL;
	_iTile	= 0;
	_fWidth = 0;

	_nTex	= 0;
	_pTex	= NULL;

	_dTexFactor = 0;
	_vLight = { 0, 0, 0 };

	_bFilter = true;

	ZeroMemory(&_pIdx, sizeof(tagIndex));
}


P00_TestAlphaTexture::~P00_TestAlphaTexture()
{
	this->Release();
}

HRESULT P00_TestAlphaTexture::Init()
{
	int nTile = 32;

	_iTile	= nTile + 1;
	_fWidth = 32;
	_nTex	= 4;

	_nVtx = _iTile * _iTile;
	_nIdx = nTile * nTile * 2;

	_pVtx = new tagVertexPDT3[_nVtx];
	_pIdx = new tagIndex[_nIdx];

	int i = 0;
	for (int z = 0; z < nTile / 2; ++z) for (int x = 0; x < nTile / 2; ++x)
	{
		WORD s, d, a;
		WORD f[9];

		s = nTile + 2;
		d = (nTile + 1) * 2;
		a = x * 2 + z * d + s;

		f[1] = a + nTile + 0; f[2] = a + nTile + 1; f[3] = a + nTile + 2;
		f[8] = a - 1		; f[0] = a			  ; f[4] = a + 1		;
		f[7] = a - nTile - 2; f[6] = a - nTile - 1; f[5] = a - nTile - 0;

		_pIdx[i + 0] = tagIndex(f[0], f[1], f[2]);
		_pIdx[i + 1] = tagIndex(f[0], f[2], f[3]);
		_pIdx[i + 2] = tagIndex(f[0], f[3], f[4]);	
		_pIdx[i + 3] = tagIndex(f[0], f[4], f[5]);
		_pIdx[i + 4] = tagIndex(f[0], f[5], f[6]);
		_pIdx[i + 5] = tagIndex(f[0], f[6], f[7]);
		_pIdx[i + 6] = tagIndex(f[0], f[7], f[8]);
		_pIdx[i + 7] = tagIndex(f[0], f[8], f[1]);

		i += 8;
	}

	for (int z = 0; z < _iTile; ++z) for (int x = 0; x < _iTile; ++x)
	{
		int nIdx = z * _iTile + x;

		/*_pVtx[nIdx].p = VEC3(x * _fWidth, 0, z * _fWidth);
		_pVtx[nIdx].d = 0x00FFFFFF;

		_pVtx[nIdx].t1.x = x / 8.0f;
		_pVtx[nIdx].t2.x = x / 32.0f;

		_pVtx[nIdx].t1.y = z / 8.0f;
		_pVtx[nIdx].t2.y = z / 32.0f;*/

		_pVtx[nIdx] = tagVertexPDT3(x * _fWidth, 0, z * _fWidth, 0xFFFFFFFF,
			x /  6.0f, z /  6.0f,
			x /	 6.0f, z /  6.0f,
			x / 32.0f, z / 32.0f);
	}

	_pTex = new tagAlphaTexture[_nTex];

	TCHAR* _pTexList[] =
	{
		_T("Base_03.png"),
		_T("Base_03_n.png"),
		_T("Base_01.tga"),
		_T("Base_01_n.tga"),
		_T("Base_02.tga"),
		_T("Base_02_n.tga"),
		_T("Base_04.tga"),
		_T("Base_04_n.tga"),
	};

	for (int n = 0; n < _nTex; ++n)
	{
		TCHAR sFile[MAX_PATH] = { 0 };
		_stprintf(sFile, _T("Texture/P00_TestAlphaTexture/%s"), _pTexList[2 * n + 0]);
		LoadTexture(sFile, _pTex[n].pTextureBase);

		_stprintf(sFile, _T("Texture/P00_TestAlphaTexture/%s"), _pTexList[2 * n + 1]);
		LoadTexture(sFile, _pTex[n].pTextureNormal);

		D3DXCreateTexture(DXDEV, nTile, nTile, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &_pTex[n].pTextureAlpha);
	}

	this->CalculateMap();

	_vLight = VEC3(1.0f, 1.0f, 1.0f);

	this->VectorToRGB();

	return S_OK;
}

void P00_TestAlphaTexture::Release()
{
	SAFE_DELETE_ARRAY(_pVtx);
	SAFE_DELETE_ARRAY(_pIdx);	
	SAFE_DELETE_ARRAY(_pTex);
}

void P00_TestAlphaTexture::Update()
{
	if (INPUTM->KeyDown(VK_SPACE)) this->SetTextureFilter();

	if (INPUTM->KeyStay(VK_LEFT))  _vLight.x -= 0.05; this->VectorToRGB();
	if (INPUTM->KeyStay(VK_RIGHT)) _vLight.x += 0.05; this->VectorToRGB();
}

void P00_TestAlphaTexture::Render()
{
	DXDEV->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	DXDEV->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DXDEV->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DXDEV->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// 범프
	DXDEV->SetRenderState(D3DRS_TEXTUREFACTOR, _dTexFactor);

	// 컬러 ARG 설정 -> 컬러 옵션 -> 알파 옵션
	// 베이스
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TFACTOR);
	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DOTPRODUCT3);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	// 노말
	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE2X);
	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	
	// 알파
	DXDEV->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_CURRENT);
	DXDEV->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	DXDEV->SetTextureStageState(2, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(2, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);


	for (int i = 0; i<4; ++i)
	{
		DXDEV->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
		DXDEV->SetSamplerState(i, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	}

	// 필터 OFF
	if (!_bFilter)
	{
		DXDEV->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
		DXDEV->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_NONE);
		DXDEV->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

		DXDEV->SetSamplerState(2, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
		DXDEV->SetSamplerState(2, D3DSAMP_MINFILTER, D3DTEXF_NONE);
		DXDEV->SetSamplerState(2, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	}


	DXDEV->SetFVF(tagVertexPDT3::FVF);
	//DXDEV->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	for (int i = 0; i<_nTex; ++i)
	{
		// 노말 -> 베이스 -> 알파
		DXDEV->SetTexture(0, _pTex[i].pTextureNormal);
		DXDEV->SetTexture(1, _pTex[i].pTextureBase);
		DXDEV->SetTexture(2, _pTex[i].pTextureAlpha);
		DXDEV->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, _nVtx, _nIdx, _pIdx, D3DFMT_INDEX16,
			_pVtx, sizeof(tagVertexPDT3));
	}


	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	DXDEV->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

	DXDEV->SetTexture(0, NULL);
	DXDEV->SetTexture(1, NULL);
	DXDEV->SetTexture(2, NULL);
}

void P00_TestAlphaTexture::CalculateMap()
{
	for (int i = 0; i < _nTex; ++i)
	{
		this->CalculateMapTile(i, _pTex[i].pTextureAlpha);
	}
}

void P00_TestAlphaTexture::CalculateMapTile(int nTex, LPTXUR& pTextureAlpha)
{
	int nBeginX, nEndX;
	int nBeginZ, nEndZ;

	float fAlpha;
	float fN;

	D3DLOCKED_RECT		dRect;
	D3DSURFACE_DESC		dDesc;
	LPDIRECT3DSURFACE9	pSurface;

	pTextureAlpha->GetLevelDesc(0, &dDesc);
	pTextureAlpha->GetSurfaceLevel(0, &pSurface);

	pSurface->LockRect(&dRect, 0, 0);

	DWORD* pPixel = (DWORD*)dRect.pBits;

	for (int z = 0; z < (int)dDesc.Height; ++z) for (int x = 0; x < (int)dDesc.Width; ++x)
	{
		fAlpha = 0.0f;

		if (z == 0)
		{
			if (x == 0)
			{
				nBeginX = 0; nEndX = 1;
				nBeginZ = 0; nEndZ = 1;
			}
			else if (x == _iTile - 1)
			{
				nBeginX = -1; nEndX = 0;
				nBeginZ = 0; nEndZ = 1;
			}
			else
			{
				nBeginX = -1; nEndX = 1;
				nBeginZ = 0; nEndZ = 1;
			}
		}

		else if (z == _iTile - 1)
		{
			if (x == 0)
			{
				nBeginX = 0; nEndX = 1;
				nBeginZ = -1; nEndZ = 0;
			}
			else if (x == _iTile - 1)
			{
				nBeginX = -1; nEndX = 0;
				nBeginZ = -1; nEndZ = 0;
			}
			else
			{
				nBeginX = -1; nEndX = 1;
				nBeginZ = -1; nEndZ = 1;
			}
		}

		else
		{
			if (x == 0)
			{
				nBeginX = 0; nEndX = 1;
				nBeginZ = -1; nEndZ = 1;
			}
			else if (x == _iTile - 1)
			{
				nBeginX = -1; nEndX = 0;
				nBeginZ = -1; nEndZ = 1;
			}
			else
			{
				nBeginX = -1; nEndX = 1;
				nBeginZ = -1; nEndZ = 1;
			}
		}

		for (int m = nBeginZ; m <= nEndZ; ++m) for (int n = nBeginX; n <= nEndX; ++n)
		{
			if (_nTileIndex[z + m][x + n] == nTex) fAlpha += 1.0f;
		}

		fN = fabs((nEndX - nBeginX) * (nEndZ - nBeginZ));

		fAlpha *= 2.0f;
		fAlpha /= fN;

		if (fAlpha > 1.0f) fAlpha = 1.0f;

		if (z == 31) int d = 10;

		pPixel[dDesc.Width * z + x] = D3DXCOLOR(1, 1, 1, fAlpha);
	}

	pSurface->UnlockRect();

	// 알파 텍스쳐 생성
	/*TCHAR sFile[128] = { 0 };
	_stprintf(sFile, _T("Texture/P00_TestAlphaTexture/alpha_%d.tga"), nTex);
	D3DXSaveSurfaceToFile(sFile, D3DXIFF_TGA, pSurface, NULL, NULL);*/

	pSurface->Release();
}

void P00_TestAlphaTexture::VectorToRGB()
{
	D3DXVec3Normalize(&_vLight, &_vLight);

	DWORD dR = (DWORD)(100.0f * _vLight.x + 155.0f);
	DWORD dG = (DWORD)(100.0f * _vLight.y + 155.0f);
	DWORD dB = (DWORD)(100.0f * _vLight.z + 155.0f);

	_dTexFactor = (DWORD)(0xff000000 + (dR << 16) + (dG << 8) + dB);
}

HRESULT P00_TestAlphaTexture::LoadTexture(TCHAR * sFilename, LPTXUR & pTexture, DWORD color, DIMG * pImageInfo, DWORD dFilter, DWORD dMipFilter, D3DFORMAT dFormat)
{
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(DXDEV, sFilename, D3DX_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT,
		0, dFormat, D3DPOOL_MANAGED, dFilter, dMipFilter, color, pImageInfo, NULL, &pTexture);
	if (FAILED(hr))
	{
		pTexture = NULL;
		return E_FAIL;
	}
	return S_OK;
}

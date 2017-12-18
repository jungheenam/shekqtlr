#include "stdafx.h"
#include "P00_TestSplatting.h"


int _nTileIndex2[][33] =
{
	{ 0,0,0,1,1,1,1,1,	1,1,3,3,3,3,0,0,	0,2,2,2,2,1,1,1,	3,1,3,3,1,1,1,1,1, },
	{ 0,0,0,1,1,1,1,1,	1,1,3,3,3,3,0,0,	0,2,2,2,2,1,1,1,	3,1,3,3,1,1,1,1,1, },
	{ 0,0,0,1,1,1,1,1,	1,1,3,3,3,3,0,0,	0,2,2,2,2,1,1,1,	3,1,3,3,1,1,1,1,1, },
	{ 0,0,0,1,1,1,1,1,	1,1,3,3,3,3,0,0,	0,2,2,2,2,1,1,1,	3,1,3,3,1,1,1,1,1, },

	{ 0,0,0,1,1,1,1,1,	3,3,3,3,3,3,3,3,	0,1,1,2,0,0,2,1,	2,3,3,2,0,1,1,1,1, },
	{ 0,0,0,1,1,1,1,1,	3,3,3,3,3,3,3,3,	0,1,1,2,2,3,0,1,	2,1,1,2,0,1,1,1,1, },
	{ 0,0,0,1,1,1,1,1,	3,3,3,2,3,3,3,1,	0,0,1,3,3,1,1,1,	1,1,1,2,0,1,1,1,1, },
	{ 0,0,0,1,1,1,3,3,	3,3,3,3,3,2,2,0,	0,1,1,1,3,1,1,1,	2,2,2,1,0,1,1,1,1, },

	{ 0,0,0,1,1,1,3,3,	3,3,3,3,2,2,2,0,	0,1,1,1,3,1,1,1,	1,1,1,1,1,1,1,1,1, },
	{ 0,0,0,3,3,3,3,3,	3,3,2,2,2,2,2,0,	0,2,2,2,3,1,2,2,	2,2,2,2,1,2,2,2,2, },
	{ 0,0,0,3,3,3,3,3,	3,3,2,2,2,2,0,0,	0,1,2,0,2,2,2,1,	1,1,2,2,2,1,1,1,1, },
	{ 0,0,0,3,3,3,3,3,	3,3,2,2,2,2,2,0,	0,0,2,2,0,2,2,0,	2,0,2,2,1,1,1,1,1, },

	{ 0,0,0,3,3,3,3,3,	2,2,2,2,2,2,2,1,	0,0,1,2,0,0,2,1,	2,1,1,2,3,1,1,1,1, },
	{ 0,0,0,3,3,3,3,3,	2,2,2,2,2,2,2,0,	0,0,1,2,0,0,0,1,	2,1,3,3,3,1,1,1,1, },
	{ 0,0,0,1,1,1,2,2,	2,2,2,2,2,2,1,0,	0,0,1,2,0,1,3,3,	1,0,1,2,1,1,1,1,1, },
	{ 0,0,0,1,1,1,2,2,	2,2,2,2,2,1,1,0,	0,0,2,1,0,1,3,3,	2,2,2,1,1,1,1,1,1, },

	{ 0,0,0,1,1,1,1,1,	2,2,2,2,2,1,1,0,	0,0,1,3,3,1,1,1,	3,1,3,3,1,2,2,2,2, },
	{ 0,0,0,2,2,2,2,2,	2,2,2,2,2,2,2,0,	0,0,2,2,2,2,2,2,	2,2,2,2,2,2,2,2,2, },
	{ 0,0,0,2,2,2,2,0,	0,2,2,3,2,2,2,1,	0,0,0,0,2,2,2,1,	1,3,2,3,2,1,1,1,1, },
	{ 0,0,0,2,2,2,2,0,	0,3,3,3,3,2,2,0,	2,0,0,2,0,2,2,2,	2,3,3,3,2,1,1,1,1, },

	{ 0,0,0,2,2,0,2,0,	0,3,3,3,3,0,0,0,	0,0,1,2,0,0,2,2,	2,3,3,2,2,1,1,1,1, },
	{ 0,0,0,2,2,0,0,0,	1,1,1,3,3,0,0,0,	0,0,0,2,2,2,2,2,	2,1,1,2,2,1,1,1,1, },
	{ 0,0,0,0,0,0,0,0,	0,0,1,3,3,3,3,0,	0,0,0,3,3,1,1,1,	1,1,1,1,1,1,1,1,1, },
	{ 0,0,0,2,2,0,0,0,	0,1,1,1,1,1,1,0,	0,0,0,1,3,1,1,1,	1,1,1,1,1,1,1,1,1, },

	{ 0,0,0,2,2,0,0,0,	0,1,1,1,1,1,1,0,	0,0,0,1,3,1,1,1,	1,1,1,1,1,1,1,1,1, },
	{ 0,0,0,2,2,2,2,0,	0,2,2,2,2,1,1,0,	0,0,2,2,3,1,2,2,	2,2,2,2,1,1,1,1,1, },
	{ 0,0,0,2,2,2,2,0,	0,2,2,2,2,1,1,0,	0,0,2,0,0,2,2,1,	1,1,2,1,1,1,1,1,1, },
	{ 0,0,0,0,0,2,2,0,	0,2,2,2,2,2,2,0,	0,0,2,0,0,2,2,1,	2,1,2,2,1,1,1,1,1, },

	{ 0,0,0,0,0,0,0,1,	1,1,1,1,1,2,2,0,	0,1,1,0,0,0,2,1,	2,1,2,2,2,1,1,1,1, },
	{ 0,0,0,0,0,0,0,0,	1,1,1,1,0,0,0,0,	0,1,1,1,1,1,1,1,	1,1,1,1,2,2,2,2,2, },
	{ 0,0,0,0,0,0,0,0,	1,1,1,1,0,0,0,0,	0,1,1,1,1,1,1,1,	1,1,1,1,2,2,2,2,2, },
	{ 0,0,0,0,0,0,0,0,	1,1,1,1,0,0,0,0,	0,1,1,1,1,1,1,1,	1,1,1,1,2,2,2,2,2, },
	{ 0,0,0,0,0,0,0,0,	1,1,1,1,0,0,0,0,	0,1,1,1,1,1,1,1,	1,1,1,1,2,2,2,2,2, },
};

P00_TestSplatting::P00_TestSplatting()
{
	_nVtx = 0;
	_nIdx = 0;

	_pIdx = NULL;
	_pVtx = NULL;

	_iTile	= 0;
	_fWidth = 0;

	_nTex = 0;
	_pTex = NULL;

	_dTexFactor = 0;
}


P00_TestSplatting::~P00_TestSplatting()
{
	this->Release();
}

HRESULT P00_TestSplatting::Init()
{
	/*for (int i = 0; i < _nTex; ++i)
	{
		TCHAR sFile[MAX_PATH] = { 0 };

		_stprintf(sFile, _T("Texture/P00_TestSplatting/Base_0%d.png"), i + 1);
		this->LoadTexture(sFile, _pTexB[i]);

		_stprintf(sFile, _T("Texture/P00_TestSplatting/Alpha_0%d.png"), i + 1, i + 1);
		this->LoadTexture(sFile, _pTexA[i], 0x00FFFFFF);
	}

	_aVtx[0][0] = tagVertexPDT(   0,   0,	 256,	0xFFFFFFFF, 0.0F, 0.0F);
	_aVtx[0][1] = tagVertexPDT( 256,   0,    256,	0x00FFFFFF, 1.0F, 0.0F);
	_aVtx[0][2] = tagVertexPDT( 256,   0,	   0,	0x00FFFFFF, 1.0F, 1.0F);
	_aVtx[0][3] = tagVertexPDT(   0,   0,	   0,	0xFFFFFFFF, 0.0F, 1.0F);
	_aVtx[1][0] = tagVertexPDT(   0,   0,    256,	0x00FFFFFF, 0.0F, 0.0F);
	_aVtx[1][1] = tagVertexPDT( 256,   0,    256,	0xFFFFFFFF, 1.0F, 0.0F);
	_aVtx[1][2] = tagVertexPDT( 256,   0,	   0,	0xFFFFFFFF, 1.0F, 1.0F);
	_aVtx[1][3] = tagVertexPDT(   0,   0,	   0,	0x00FFFFFF, 0.0F, 1.0F);*/

	int nTile = 32;

	_iTile	= nTile + 1;
	_fWidth = 32;
	_nTex	= 4;

	_nVtx = _iTile * _iTile;
	_nIdx = nTile * nTile * 2;

	_pVtx = new tagVertexPDT[_nVtx];
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

		_pVtx[nIdx] = tagVertexPDT(x * _fWidth, 0, z * _fWidth, 0x00FFFFFF,
			x /  5.0f, z /  5.0f);
	}

	_pTex = new tagWeightTexture[_nTex];

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
		_stprintf(sFile, _T("Texture/P00_TestSplatting/%s"), _pTexList[2 * n + 0]);
		LoadTexture(sFile, _pTex[n].pTextureBase);

		_stprintf(sFile, _T("Texture/P00_TestSplatting/%s"), _pTexList[2 * n + 1]);
		LoadTexture(sFile, _pTex[n].pTextureNormal);

		_pTex[n].pWeight = (DWORD*)malloc(_iTile * _iTile * sizeof(DWORD));
		memset(_pTex[n].pWeight, 0xFF, _iTile * _iTile * sizeof(DWORD));
	}

	this->CalulateMap();

	_vLightDir = VEC3(1.0f, 1.0f, 1.0f);
	this->VectorToRGB();

	return S_OK;
}

void P00_TestSplatting::Release()
{
	SAFE_DELETE_ARRAY(_pVtx);
	SAFE_DELETE_ARRAY(_pIdx);
	SAFE_DELETE_ARRAY(_pTex);
}

void P00_TestSplatting::Update()
{
	if (INPUTM->KeyStay(VK_LEFT))  _vLightDir.x -= 0.05; this->VectorToRGB();
	if (INPUTM->KeyStay(VK_RIGHT)) _vLightDir.x += 0.05; this->VectorToRGB();
}

void P00_TestSplatting::Render()
{
	DXDEV->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	DXDEV->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DXDEV->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DXDEV->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	DXDEV->SetRenderState(D3DRS_TEXTUREFACTOR, _dTexFactor);

	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TFACTOR);
	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DOTPRODUCT3);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	DXDEV->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE2X);

	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);


	for (int i = 0; i < 3; ++i)
	{
		DXDEV->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
		DXDEV->SetSamplerState(i, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
		DXDEV->SetSamplerState(i, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	}


	DXDEV->SetFVF(tagVertexPDT::FVF);

	for (int i = 0; i < _nTex; ++i)
	{
		DXDEV->SetTexture(0, _pTex[i].pTextureNormal);
		DXDEV->SetTexture(1, _pTex[i].pTextureBase);

		for (int z = 0; z < _iTile; ++z) for (int x = 0; x < _iTile; ++x)
		{
			_pVtx[z * _iTile + x].d = _pTex[i].pWeight[z * _iTile + x];
		}

		DXDEV->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, _nVtx, _nIdx, _pIdx,
			D3DFMT_INDEX16, _pVtx, sizeof(tagVertexPDT));
	}

	//for (int z = 0; z < _iTile; ++z) for (int x = 0; x < _iTile; ++x)
	//{
	//	_pVtx[z * _iTile + x].d = 0xFFFFFFFF;
	//}

	DXDEV->SetTexture(0, NULL);
	DXDEV->SetTexture(1, NULL);

	/*DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	DXDEV->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DXDEV->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
	DXDEV->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCCOLOR);

	DXDEV->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, _nVtx, _nIdx, _pIdx,
		D3DFMT_INDEX16, _pVtx, sizeof(tagVertexPDT));*/

	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	DXDEV->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void P00_TestSplatting::CalulateMap()
{
	for (int i = 0; i < _nTex; ++i)
	{
		this->CalculateMapTile(i, _pTex[i].pWeight);
	}
}

void P00_TestSplatting::CalculateMapTile(int nTex, DWORD *& pTextureAlpha)
{
	int nBeginX, nEndX;
	int nBeginZ, nEndZ;

	float fAlpha;
	float fN;

	for (int z = 0; z < _iTile; ++z) for (int x = 0; x < _iTile; ++x)
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
			if (_nTileIndex2[z + m][x + n] == nTex) fAlpha += 1.0f;
		}

		fN = fabs((nEndX - nBeginX) * (nEndZ - nBeginZ));

		fAlpha *= 2.0f;
		fAlpha /= fN;

		if (fAlpha > 1.0f) fAlpha = 1.0f;

		pTextureAlpha[_iTile * z + x] = D3DXCOLOR(1, 1, 1, fAlpha);
	}

}

void P00_TestSplatting::VectorToRGB()
{
	D3DXVec3Normalize(&_vLightDir, &_vLightDir);

	DWORD dR = (DWORD)(100.0f * _vLightDir.x + 155.0f);
	DWORD dG = (DWORD)(100.0f * _vLightDir.y + 155.0f);
	DWORD dB = (DWORD)(100.0f * _vLightDir.z + 155.0f);

	_dTexFactor = (DWORD)(0xff000000 + (dR << 16) + (dG << 8) + dB);
}

HRESULT P00_TestSplatting::LoadTexture(TCHAR * sFilename, LPTXUR & pTexture, DWORD color, DIMG * pImageInfo, DWORD dFilter, DWORD dMipFilter, D3DFORMAT dFormat)
{
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(DXDEV, sFilename, D3DX_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT,
		0, dFormat, D3DPOOL_MANAGED, dFilter, dMipFilter, color, pImageInfo, NULL, &pTexture);
	if (FAILED(hr)) return E_FAIL;
	return S_OK;
}

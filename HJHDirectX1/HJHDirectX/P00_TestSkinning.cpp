#include "stdafx.h"
#include "P00_TestSkinning.h"


P00_TestSkinning::P00_TestSkinning()
{
	_pTex		= nullptr;
	_nMaxWorld	= 0;

	ZeroMemory(&_aVtx, sizeof(tagVertexPBT));
}


P00_TestSkinning::~P00_TestSkinning()
{
	this->Release();
}

HRESULT P00_TestSkinning::Init()
{
	for (int i = 0; i < 21; ++i)
	{
		_aVtx[2 * i + 0].p = VEC3(i - 10.0f, -7.0f, 0.0f) * 5;
		_aVtx[2 * i + 0].t = VEC2(i / 20.0f,  1.0f);

		_aVtx[2 * i + 1].p = VEC3(i - 10.0f,  7.0f, 0.0f) * 5;
		_aVtx[2 * i + 1].t = VEC2(i / 20.0f,  0.0f);

		_aVtx[2 * i + 0].g[0] = 1.0f;
		_aVtx[2 * i + 0].m[0] = i;

		_aVtx[2 * i + 1].g[0] = 1.0f;
		_aVtx[2 * i + 1].m[0] = i;
	}

	D3DXCreateTextureFromFile(DXDEV, _T("Texture/P00_TestSkinning/taegeukgi.png"), &_pTex);

	D3DCAPS9 dCaps;
	DXDEV->GetDeviceCaps(&dCaps);
	_nMaxWorld = dCaps.MaxVertexBlendMatrices;

	for (int i = 0; i < 256; ++i) D3DXMatrixIdentity(&_mWorld[i]);

	return S_OK;
}

void P00_TestSkinning::Release()
{
	SAFE_RELEASE(_pTex);
}

void P00_TestSkinning::Update()
{
	if (INPUTM->KeyStay(VK_SPACE))
	{
		float fAngle = GetTickCount() * 0.4f;

		for (int i = 0; i < 256; ++i)
		{
			float fA = fAngle + i * (360.0f / 15);
			_mWorld[i]._41 = cosf(D3DXToRadian(fA)) * 1.5f;
			_mWorld[i]._42 = sinf(D3DXToRadian(fA)) * 4.0f;
		}
	}
}

void P00_TestSkinning::Render()
{
	if (_nMaxWorld < 128) DXDEV->SetSoftwareVertexProcessing(TRUE);

	DXM->BaseSamplerState();

	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	DXDEV->SetRenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, TRUE);
	DXDEV->SetRenderState(D3DRS_VERTEXBLEND, D3DVBF_3WEIGHTS);

	for (int i = 0; i < 256; ++i) DXDEV->SetTransform(D3DTS_WORLDMATRIX(i), &_mWorld[i]);

	DXDEV->SetTexture(0, _pTex);
	DXDEV->SetFVF(tagVertexPBT::FVF);
	DXDEV->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 40, _aVtx, sizeof(tagVertexPBT));

	DXDEV->SetRenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, FALSE);
	DXDEV->SetRenderState(D3DRS_VERTEXBLEND, D3DVBF_DISABLE);
	DXDEV->SetSoftwareVertexProcessing(FALSE);

	static MAT mIdt(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);
	for (int i = 0; i < 256; ++i) DXDEV->SetTransform(D3DTS_WORLDMATRIX(i), &mIdt);
}

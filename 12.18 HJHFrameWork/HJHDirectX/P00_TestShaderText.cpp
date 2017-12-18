#include "stdafx.h"
#include "P00_TestShaderText.h"


P00_TestShaderText::P00_TestShaderText()
{
	_pVS  = nullptr;
	_pFVF = nullptr;

	ZeroMemory(&_aVtx, sizeof(tagVertexPDT));

	_pTex = nullptr;
}


P00_TestShaderText::~P00_TestShaderText()
{
	this->Release();
}

HRESULT P00_TestShaderText::Init()
{
	HRESULT hr;
	HWND	hWnd;

	D3DDEVICE_CREATION_PARAMETERS dParam;

	DXDEV->GetCreationParameters(&dParam);
	hWnd = dParam.hFocusWindow;

	/*_aVtx[0] = tagVertexPDT(-8, 6, 0, D3DXCOLOR(1, 1, 1, 1), 0, 0);
	_aVtx[1] = tagVertexPDT( 8, 6, 0, D3DXCOLOR(1, 1, 1, 1), 1, 0);
	_aVtx[2] = tagVertexPDT( 8,-6, 0, D3DXCOLOR(1, 1, 1, 1), 1, 1);
	_aVtx[3] = tagVertexPDT(-8,-6, 0, D3DXCOLOR(1, 1, 1, 1), 0, 1);*/

	DWORD dFlag = 0;
	
#if defined(_DEBUG) || defined(DEBUG)
	dFlag |= D3DXSHADER_DEBUG;
#endif

	LPD3DXBUFFER pShader = NULL;
	LPD3DXBUFFER pError  = NULL;

	hr = D3DXAssembleShaderFromFile(_T("Shader/TestShader/TestTexture/shader.vsh"),
		NULL, NULL, dFlag, &pShader, &pError);
	if (FAILED(hr)) return E_FAIL;

	hr = DXDEV->CreateVertexShader((DWORD*)pShader->GetBufferPointer(), &_pVS);
	SAFE_RELEASE(pShader);
	if (FAILED(hr)) return E_FAIL;

	D3DVERTEXELEMENT9 dVertexDecl[MAX_FVF_DECL_SIZE] = { 0 };

	D3DXDeclaratorFromFVF(tagVertexPDT::FVF, dVertexDecl);

	hr = DXDEV->CreateVertexDeclaration(dVertexDecl, &_pFVF);
	if (FAILED(hr)) return E_FAIL;

	D3DXCreateTextureFromFile(DXDEV, _T("Texture/P00_TestShader/earth.bmp"), &_pTex);

	INT	iNSphereSegments = 128;
	_nIdx = 2 * iNSphereSegments*(iNSphereSegments + 1);

	FLOAT fDeltaRingAngle = (D3DX_PI / iNSphereSegments);
	FLOAT fDeltaSegAngle = (2.0f * D3DX_PI / iNSphereSegments);

	_pVtx = new tagVertexPDT[_nIdx];
	tagVertexPDT* pVtx = _pVtx;

	for (DWORD ring = 0; ring < iNSphereSegments; ring++)
	{
		FLOAT r0 = 5 * sinf((ring + 0) * fDeltaRingAngle);
		FLOAT r1 = 5 * sinf((ring + 1) * fDeltaRingAngle);
		FLOAT y0 = 5 * cosf((ring + 0) * fDeltaRingAngle);
		FLOAT y1 = 5 * cosf((ring + 1) * fDeltaRingAngle);

		for (DWORD seg = 0; seg < (iNSphereSegments + 1); seg++)
		{
			FLOAT x0 = r0 * sinf(seg * fDeltaSegAngle);
			FLOAT z0 = r0 * cosf(seg * fDeltaSegAngle);
			FLOAT x1 = r1 * sinf(seg * fDeltaSegAngle);
			FLOAT z1 = r1 * cosf(seg * fDeltaSegAngle);

			pVtx->p.x = x0;
			pVtx->p.y = y0;
			pVtx->p.z = z0;
			pVtx->t.x = -((FLOAT)seg) / iNSphereSegments;
			pVtx->t.y = (ring + 0) / (FLOAT)iNSphereSegments;
			pVtx++;

			pVtx->p.x = x1;
			pVtx->p.y = y1;
			pVtx->p.z = z1;
			pVtx->t.x = -((FLOAT)seg) / iNSphereSegments;
			pVtx->t.y = (ring + 1) / (FLOAT)iNSphereSegments;
			pVtx++;
		}

	}

	return S_OK;
}

void P00_TestShaderText::Release()
{
	SAFE_RELEASE(_pVS);
	SAFE_RELEASE(_pFVF);
	SAFE_RELEASE(_pTex);

	SAFE_DELETE_ARRAY(_pVtx);
}

void P00_TestShaderText::Update()
{
	static float fSpeed = 0;
	fSpeed = GetTickCount() * 0.1f;

	if (fSpeed > 360.0f) fSpeed -= 360.0f;

	MAT mRotY;
	MAT mRotZ;

	D3DXMatrixIdentity(&_mWorld);
	D3DXMatrixRotationY(&mRotY, D3DXToRadian(-fSpeed));
	D3DXMatrixRotationY(&mRotZ, D3DXToRadian(-23.5f));

	_mWorld = mRotY * mRotZ;
}

void P00_TestShaderText::Render()
{
	//MAT mWorld; D3DXMatrixIdentity(&mWorld);
	MAT mView;
	MAT mProj;
	D3DXCOLOR c(1.0f, 0.3f, 0.7f, 1.0f);
	
	DXDEV->GetTransform(D3DTS_VIEW, &mView);
	DXDEV->GetTransform(D3DTS_PROJECTION, &mProj);

	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	DXDEV->SetVertexShader(_pVS);
	DXDEV->SetVertexDeclaration(_pFVF);

	MAT mVP = _mWorld * mView * mProj;
	D3DXMatrixTranspose(&mVP, &mVP);
	DXDEV->SetVertexShaderConstantF(0, (float*)&mVP, 4);
	DXDEV->SetVertexShaderConstantF(10, (float*)&c, 1);
	DXDEV->SetTexture(0, _pTex);
	//DXDEV->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _aVtx, sizeof(tagVertexPDT));
	DXDEV->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, _nIdx - 2, _pVtx, sizeof(tagVertexPDT));

	DXDEV->SetVertexShader(NULL);
}

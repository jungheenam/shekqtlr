#include "stdafx.h"
#include "P00_TestShaderMapping.h"


P00_TestShaderMapping::P00_TestShaderMapping()
{
	_pVS	= nullptr;
	_pFVF	= nullptr;

	_pMesh	= nullptr;
	_pTex	= nullptr;

	D3DXMatrixIdentity(&_mWorld);
}


P00_TestShaderMapping::~P00_TestShaderMapping()
{
	this->Release();
}

HRESULT P00_TestShaderMapping::Init()
{
	HRESULT hr;
	HWND	hWnd;
	D3DDEVICE_CREATION_PARAMETERS dParam;

	DXDEV->GetCreationParameters(&dParam);
	hWnd = dParam.hFocusWindow;

	DWORD dFlag = 0;
#if defined(_DEBUG) || defined(DEBUG)
	dFlag |= D3DXSHADER_DEBUG;
#endif

	LPD3DXBUFFER pShader = NULL;
	LPD3DXBUFFER pError  = NULL;

	hr = D3DXAssembleShaderFromFile(_T("Shader/TestShader/TestMapping/shader.vsh"),
		NULL, NULL, dFlag, &pShader, &pError);
	if (FAILED(hr)) return E_FAIL;

	hr = DXDEV->CreateVertexShader((DWORD*)pShader->GetBufferPointer(), &_pVS);
	SAFE_RELEASE(pShader);
	if (FAILED(hr)) return E_FAIL;

	D3DVERTEXELEMENT9 dVertexDecl[MAX_FVF_DECL_SIZE] = { 0 };
	D3DXDeclaratorFromFVF(tagVertexPN::FVF, dVertexDecl);
	hr = DXDEV->CreateVertexDeclaration(dVertexDecl, &_pFVF);
	if (FAILED(hr)) return E_FAIL;

	LPMESH pMesh;
	D3DXCreateTeapot(DXDEV, &pMesh, NULL);
	pMesh->CloneMeshFVF(D3DXMESH_SYSTEMMEM, tagVertexPN::FVF, DXDEV, &_pMesh);
	pMesh->Release();

	DWORD nVtx = _pMesh->GetNumVertices();

	tagVertexPN* pVtx = NULL;
	_pMesh->LockVertexBuffer(0, (void**)&pVtx);
	for (DWORD i = 0; i < nVtx; ++i)
	{
		pVtx[i].p *= 8.0f;
	}
	_pMesh->UnlockVertexBuffer();

	D3DXCreateTextureFromFile(DXDEV, _T("Texture/P00_TestMapping/spheremap.bmp"), &_pTex);


	return S_OK;
}

void P00_TestShaderMapping::Release()
{
	SAFE_RELEASE(_pFVF);
	SAFE_RELEASE(_pVS);

	SAFE_RELEASE(_pMesh);
	SAFE_RELEASE(_pTex);
}

void P00_TestShaderMapping::Update()
{
}

void P00_TestShaderMapping::Render()
{
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_MIRROR);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_MIRROR);

	MAT mWorld; D3DXMatrixIdentity(&mWorld);
	MAT mView;
	MAT mProj;

	DXDEV->GetTransform(D3DTS_VIEW, &mView);
	DXDEV->GetTransform(D3DTS_PROJECTION, &mProj);

	DXDEV->SetVertexShader(_pVS);
	DXDEV->SetVertexDeclaration(_pFVF);

	MAT mTrans = mWorld * mView * mProj;
	D3DXMatrixTranspose(&mTrans, &mTrans);
	DXDEV->SetVertexShaderConstantF(0, (float*)&mTrans, 4);

	mTrans = mView;
	D3DXMatrixTranspose(&mTrans, &mTrans);
	DXDEV->SetVertexShaderConstantF(4, (float*)&mTrans, 4);

	DXDEV->SetTexture(0, _pTex);
	_pMesh->DrawSubset(0);

	DXDEV->SetTexture(0, nullptr);
	DXDEV->SetVertexShader(NULL);
}

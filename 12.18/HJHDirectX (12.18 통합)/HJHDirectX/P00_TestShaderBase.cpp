#include "stdafx.h"
#include "P00_TestShaderBase.h"


P00_TestShaderBase::P00_TestShaderBase()
{
	_pVS  = nullptr;
	_pFVF = nullptr;

	ZeroMemory(&_aVtx, sizeof(tagVertexPC));

	_aVtx[ 0] = tagVertexPD(-1.f, -1.f, -1.f, D3DXCOLOR(1.0F, 0.0F, 0.0F, 1.0F));
	_aVtx[ 1] = tagVertexPD(-1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[ 2] = tagVertexPD( 1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[ 3] = tagVertexPD( 1.f, -1.f, -1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[ 4] = tagVertexPD(-1.f, -1.f,  1.f, D3DXCOLOR(1.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[ 5] = tagVertexPD( 1.f, -1.f,  1.f, D3DXCOLOR(0.0F, 1.0F, 1.0F, 1.0F));
	_aVtx[ 6] = tagVertexPD( 1.f,  1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 0.0F, 1.0F));
	_aVtx[ 7] = tagVertexPD(-1.f,  1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[ 8] = tagVertexPD(-1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[ 9] = tagVertexPD(-1.f,  1.f,  1.f, D3DXCOLOR(0.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[10] = tagVertexPD( 1.f,  1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[11] = tagVertexPD( 1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 1.0F, 1.0F, 1.0F));
	_aVtx[12] = tagVertexPD(-1.f, -1.f, -1.f, D3DXCOLOR(1.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[13] = tagVertexPD( 1.f, -1.f, -1.f, D3DXCOLOR(0.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[14] = tagVertexPD( 1.f, -1.f,  1.f, D3DXCOLOR(0.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[15] = tagVertexPD(-1.f, -1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 0.0F, 1.0F));
	_aVtx[16] = tagVertexPD(-1.f, -1.f,  1.f, D3DXCOLOR(1.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[17] = tagVertexPD(-1.f,  1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[18] = tagVertexPD(-1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 1.0F, 1.0F, 1.0F));
	_aVtx[19] = tagVertexPD(-1.f, -1.f, -1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[20] = tagVertexPD( 1.f, -1.f, -1.f, D3DXCOLOR(1.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[21] = tagVertexPD( 1.f,  1.f, -1.f, D3DXCOLOR(0.0F, 1.0F, 0.0F, 1.0F));
	_aVtx[22] = tagVertexPD( 1.f,  1.f,  1.f, D3DXCOLOR(1.0F, 0.0F, 1.0F, 1.0F));
	_aVtx[23] = tagVertexPD( 1.f, -1.f,  1.f, D3DXCOLOR(0.0F, 0.0F, 1.0F, 1.0F));

	for (int i = 0; i < 24; ++i)
	{
		_aVtx[i].p *= 30;
	}

	_aIdx[ 0] = tagIndex( 0,  1,  2);
	_aIdx[ 1] = tagIndex( 0,  2,  3);
	_aIdx[ 2] = tagIndex( 4,  5,  6);
	_aIdx[ 3] = tagIndex( 4,  6,  7);
	_aIdx[ 4] = tagIndex( 8,  9, 10);
	_aIdx[ 5] = tagIndex( 8, 10, 11);
	_aIdx[ 6] = tagIndex(12, 13, 14);
	_aIdx[ 7] = tagIndex(12, 14, 15);
	_aIdx[ 8] = tagIndex(16, 17, 18);
	_aIdx[ 9] = tagIndex(16, 18, 19);
	_aIdx[10] = tagIndex(20, 21, 22);
	_aIdx[11] = tagIndex(20, 22, 23);
}


P00_TestShaderBase::~P00_TestShaderBase()
{
	this->Release();
}

HRESULT P00_TestShaderBase::Init()
{
	HRESULT hr;
	HWND hWnd;
	D3DDEVICE_CREATION_PARAMETERS dParam;

	DXDEV->GetCreationParameters(&dParam);

	hWnd = dParam.hFocusWindow;

	//_aVtx[0] = tagVertexPD(-10,  0, 0, D3DXCOLOR(1, 0, 0, 1));
	//_aVtx[1] = tagVertexPD( 10,  0, 0, D3DXCOLOR(0, 1, 0, 1));
	//_aVtx[2] = tagVertexPD( 10, 20, 0, D3DXCOLOR(0, 0, 1, 1));
	//_aVtx[3] = tagVertexPD(-10, 20, 0, D3DXCOLOR(1, 0, 1, 1));

	/*const TCHAR sShader[] =
	{
		_T("vs_1_1				\n")
		_T("dcl_position v0		\n")
		_T("dcl_color v1		\n")	
		_T("m4x4 oPos, v0, c0	\n")
		_T("mov oD0, v1			\n")
	};*/

	DWORD dFlag = 0;

#if defined(_DEBUG) ||defined(DEBUF)
	dFlag |= D3DXSHADER_DEBUG;
#endif

	LPD3DXBUFFER pShader = NULL;
	LPD3DXBUFFER pError  = NULL;
	//int			 iLen	 = _tcslen(sShader);

//	hr = D3DXAssembleShader(sShader, iLen, NULL, NULL, dFlag, &pShader, &pError);
	hr = D3DXAssembleShaderFromFile(_T("Shader/TestShader/ConstShader/shader.vsh"),
		NULL, NULL, dFlag, &pShader, &pError);
	if (FAILED(hr)) return E_FAIL;

	hr = DXDEV->CreateVertexShader((DWORD*)pShader->GetBufferPointer(), &_pVS);
	SAFE_RELEASE(pShader);
	if (FAILED(hr)) return E_FAIL;

	D3DVERTEXELEMENT9 dVertexDecl[MAX_FVF_DECL_SIZE] = { 0 };
	D3DXDeclaratorFromFVF(tagVertexPC::FVF, dVertexDecl);
	hr = DXDEV->CreateVertexDeclaration(dVertexDecl, &_pFVF);
	if (FAILED(hr)) return E_FAIL;

	return S_OK;
}

void P00_TestShaderBase::Release()
{
	SAFE_RELEASE(_pFVF);
	SAFE_RELEASE(_pVS);
}

void P00_TestShaderBase::Update()
{
}

void P00_TestShaderBase::Render()
{
	MAT mWorld; D3DXMatrixIdentity(&mWorld);
	MAT mView;
	MAT mProj;

	MAT mRotX;
	MAT mRotY;
	MAT mRotZ;


	float fAngle = D3DXToRadian(GetTickCount() * 0.1f);
	D3DXMatrixRotationY(&mRotY, fAngle * 3.0f);
	D3DXMatrixRotationZ(&mRotZ, fAngle * 2.0f);
	D3DXMatrixRotationX(&mRotX, fAngle * 1.0f);

	mWorld = mRotY * mRotZ * mRotX;
	mWorld._42 =  40.0f;
	mWorld._43 = -30.0f;


	DXDEV->GetTransform(D3DTS_VIEW, &mView);
	DXDEV->GetTransform(D3DTS_PROJECTION, &mProj);

	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	MAT mVP = mWorld * mView * mProj;
	D3DXMatrixTranspose(&mVP, &mVP);

	DXDEV->SetVertexShader(_pVS);
	DXDEV->SetVertexDeclaration(_pFVF);

	// 상수 연결
	/*MAT mTrans;
	D3DXMatrixTranspose(&mTrans, &mWorld);
	DXDEV->SetVertexShaderConstantF(0, (float*)&mTrans, 4);

	D3DXMatrixTranspose(&mTrans, &mView);
	DXDEV->SetVertexShaderConstantF(4, (float*)&mTrans, 4);

	D3DXMatrixTranspose(&mTrans, &mProj);
	DXDEV->SetVertexShaderConstantF(8, (float*)&mTrans, 4);*/


	D3DXCOLOR c(1, 1, 1, 1);
	DXDEV->SetVertexShaderConstantF( 0, (float*)&mVP, 4);
	DXDEV->SetVertexShaderConstantF(10, (float*)&c, 1);
	DXDEV->SetVertexShaderConstantF(11, (float*)&c, 1);




	//DXDEV->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, _aVtx, sizeof(tagVertexPD));
	DXDEV->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 24, 12, _aIdx, D3DFMT_INDEX16, _aVtx, sizeof(tagVertexPD));



	DXDEV->SetVertexShader(NULL);
	//DXDEV->SetVertexDeclaration(NULL);
}

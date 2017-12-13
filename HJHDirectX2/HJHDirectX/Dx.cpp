#include "stdafx.h"
#include "Dx.h"


Dx::Dx()
{
}


Dx::~Dx()
{
}


HRESULT Dx::Init()
{
	if ((_pDx9 = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) return E_FAIL;

	D3DDISPLAYMODE d3ddm = { 0 };
	if (FAILED(_pDx9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm))) return E_FAIL;

	D3DCAPS9 caps;
	_pDx9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	D3DPRESENT_PARAMETERS d3dpp = { 0 };
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;//D3DFMT_X8R8G8B8;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;//D3DFMT_D24S8;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;



	// 해상도 퀄리티의 최적화 수치 찾기
	DWORD qualityLevel;
	for (int i = D3DMULTISAMPLE_16_SAMPLES; i >= 0; --i)
	{
		if (SUCCEEDED(_pDx9->CheckDeviceMultiSampleType
		(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			d3dpp.BackBufferFormat,
			TRUE,
			(D3DMULTISAMPLE_TYPE)i,
			&qualityLevel
			)))
		{
			d3dpp.MultiSampleType = (D3DMULTISAMPLE_TYPE)i;
			d3dpp.MultiSampleQuality = qualityLevel - 1;
			break;
		}
	}

	if (FAILED(_pDx9->CreateDevice
	(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &_pDev)))
	{
		if (FAILED(_pDx9->CreateDevice
		(
			D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp, &_pDev)))
		{
			SAFE_RELEASE(_pDx9);
			return E_FAIL;
		}
	}

	// View Matrix
	D3DXMATRIX mView;
	D3DXVECTOR3 vEye(10.0f, 30.0f, -55.0f); // 카메라의 위치
	D3DXVECTOR3 vLka(0.0f, 0.0f, 0.0f); // 카메라의 시선
	D3DXVECTOR3 vUpv(0.0f, 1.0f, 0.0f); // 카메라의 법선
	D3DXMatrixLookAtLH(&mView, &vEye, &vLka, &vUpv);
	_pDev->SetTransform(D3DTS_VIEW, &mView);

	// Projection Matrix
	D3DXMATRIX mProj;
	float fScrW = (float)WINSIZEX;
	float fScrH = (float)WINSIZEY;
	float fFov = D3DX_PI / 4.0f;
	float fAspt = (float)fScrW / (float)fScrH;
	float fNear = 1.0f;
	float fFar = 5000.0f;
	D3DXMatrixPerspectiveFovLH(&mProj, fFov, fAspt, fNear, fFar);
	_pDev->SetTransform(D3DTS_PROJECTION, &mProj);

	_cGrid .Init();
	_cLight.Init();

	return S_OK;
}

void Dx::Release()
{
	_cGrid .Release();
	_cLight.Release();

	SAFE_RELEASE(_pDx9);
	SAFE_RELEASE(_pDev);	
}

void Dx::Update()
{
}

HRESULT Dx::BeginDraw()
{
	// 0x00006699
	if (_pDev == NULL) return E_FAIL;
	_pDev->Clear
	(
		0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL),
		D3DCOLOR_XRGB(0, 150, 0), 1.0f, 0
	);
	if (FAILED(_pDev->BeginScene())) return E_FAIL;

	_cGrid .Render();
	_cLight.Render();

	return S_OK;
}

void Dx::EndDraw()
{
	CAM->Render();
	INPUTM->Render();
	_pDev->EndScene();
	_pDev->Present(NULL, NULL, NULL, NULL);
}

void Dx::BaseSamplerState()
{
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
}

void Dx::InitWorldMatrix()
{
	D3DXMATRIXA16 mWorld(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);
	DXDEV->SetTransform(D3DTS_WORLD, &mWorld);
}

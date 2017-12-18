#include "stdafx.h"
#include "DxLight.h"


DxLight::DxLight()
{
}


DxLight::~DxLight()
{
}

HRESULT DxLight::Init()
{
	D3DLIGHT9 dLight;
	D3DXVECTOR3 vDir(1, 1, 1);

	vDir = -vDir;
	D3DXVec3Normalize(&vDir, &vDir);

	memset(&dLight, 0, sizeof(dLight));
	dLight.Type = D3DLIGHT_DIRECTIONAL;
	dLight.Direction = vDir;
	dLight.Range = 15000;
	dLight.Position = D3DXVECTOR3(100, 20, 300);
	dLight.Diffuse = D3DXCOLOR(1, 1, 1, 1);

	dLight.Theta = 0.3f;
	dLight.Phi = 1.0f;
	dLight.Falloff = 1.0f;
	dLight.Attenuation0 = 1.0f;

	DXDEV->SetLight(0, &dLight);
	DXDEV->LightEnable(0, TRUE);
	DXDEV->SetRenderState(D3DRS_LIGHTING, TRUE);
	DXDEV->SetRenderState(D3DRS_AMBIENT, 0xFF555555);

	return S_OK;
}

void DxLight::Release()
{
}

void DxLight::Update()
{
}

void DxLight::Render()
{
}


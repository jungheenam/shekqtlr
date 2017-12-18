#include "stdafx.h"
#include "DxCamera.h"


DxCamera::DxCamera() : _vEye(0, 0, 0), _vLka(0, 0, 0), _vUpv(0, 0, 0), _fDist(5), _fRotX(0), _fRotY(0)
{
}


DxCamera::~DxCamera()
{
}

HRESULT DxCamera::Init()
{
	_vEye = D3DXVECTOR3(0.0f, 35.0f, -10.0f);
	_vLka = D3DXVECTOR3(0.0f, 35.0f, 0.0f);
	_vUpv = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DDEVICE_CREATION_PARAMETERS pp = { 0 };
	RECT rc = { 0 };
	DXDEV->GetCreationParameters(&pp);
	GetClientRect(pp.hFocusWindow, &rc);

	D3DXMatrixLookAtLH(&_mView, &_vEye, &_vLka, &_vUpv);
	DXDEV->SetTransform(D3DTS_VIEW, &_mView);

	_fScrW = (float)WINSIZEX;
	_fScrH = (float)WINSIZEY;
	_fFov = D3DX_PI / 4.0f;
	_fAspt = (float)_fScrW / (float)_fScrH;
	_fNear = 1.0f;
	_fFar = 5000.0f;
	D3DXMatrixPerspectiveFovLH(&_mProj, _fFov, _fAspt, _fNear, _fFar);
	DXDEV->SetTransform(D3DTS_PROJECTION, &_mProj);

	return S_OK;
}

void DxCamera::Release()
{
}

void DxCamera::Update()
{

}

void DxCamera::Render()
{
	TCHAR str[256];
	_stprintf(str, _T("Camera Position: x: %f		, y: %f		, z: %f"), _mView._41, _mView._42, _mView._43);
	FONTM->DxDrawText(str, 6, WINSIZEY - 20, WINSIZEX, 30, D3DXCOLOR(1, 1, 0, 1));
}

void DxCamera::MovePosition(D3DXVECTOR3 vPos)
{
	_vEye = D3DXVECTOR3(0, 0, -_fDist);

	D3DXMATRIX mRotX, mRotY, mR;
	D3DXMatrixRotationX(&mRotX, _fRotX);
	D3DXMatrixRotationY(&mRotY, _fRotY);
	mR = mRotX * mRotY;
	D3DXVec3TransformCoord(&_vEye, &_vEye, &mR);

	_vEye = vPos + _vEye;
	_vLka = vPos;

	D3DXMatrixLookAtLH(&_mView, &_vEye, &_vLka, &_vUpv);
	DXDEV->SetTransform(D3DTS_VIEW, &_mView);

	static POINT nPrePos = { 0, 0 };
	static POINT nCurPos = { 0, 0 };
	static bool  bBtnDown = false;
	if (INPUTM->BtnDown(0))
	{
		GetCursorPos(&nPrePos);
		bBtnDown = true;
	}
	if (INPUTM->BtnUp(0))
	{
		bBtnDown = false;
	}
	if (bBtnDown)
	{
		GetCursorPos(&nCurPos);

		_fRotY += (nCurPos.x - nPrePos.x) * 0.01f;
		_fRotX += (nCurPos.y - nPrePos.y) * 0.01f;

		if (_fRotX <= -D3DX_PI * 0.5f + D3DX_16F_EPSILON) _fRotX = -D3DX_PI * 0.5f + D3DX_16F_EPSILON;
		else if (_fRotX >= D3DX_PI * 0.5f) _fRotX = D3DX_PI * 0.5f - D3DX_16F_EPSILON;

		nPrePos = nCurPos;
	}

}

void DxCamera::MoveFree()
{
	D3DXVECTOR3 vcDelta = INPUTM->GetMouseEps();

	if (vcDelta.z != 0.f)		MoveForward(vcDelta.z * 0.1f * BASETIME, 1.f);

	if (INPUTM->KeyState('W'))	MoveForward(	 1.0f * BASETIME, 1.0f);
	if (INPUTM->KeyState('S'))	MoveForward(	-1.0f * BASETIME, 1.0f);
	if (INPUTM->KeyState('A'))	MoveSideward(	-1.0f * BASETIME, 1.0f);
	if (INPUTM->KeyState('D'))	MoveSideward(	 1.0f * BASETIME, 1.0f);

	if (INPUTM->BtnState(0)) Rotate(&vcDelta, 0.1f * BASETIME);

	D3DXMatrixLookAtLH(&_mView, &_vEye, &_vLka, &_vUpv);

	DXDEV->SetTransform(D3DTS_VIEW, &_mView);
	DXDEV->SetTransform(D3DTS_PROJECTION, &_mProj);

	D3DXMATRIX		mtVP;	
	D3DXMATRIX		mtVPInv;

	mtVP = _mView * _mProj;
	D3DXMatrixInverse(&mtVPInv, NULL, &mtVP);

	D3DXVECTOR3		vcZ = D3DXVECTOR3(_mView._13, _mView._23, _mView._33);
	FLOAT			Near = _fNear;
	FLOAT			Far = _fFar;
	D3DXVECTOR3		vcEye = _vEye;

	D3DXVECTOR3		vcNear;
	FLOAT			Dnear;

	vcNear = -vcZ;
	Dnear = -D3DXVec3Dot(&vcNear, &vcEye) + Near;
	m_Frst[0] = D3DXPLANE(vcNear.x, vcNear.y, vcNear.z, Dnear);

	D3DXVECTOR3		vcFar;
	FLOAT			Dfar;

	vcFar = vcZ;
	Dfar = -D3DXVec3Dot(&vcFar, &vcEye) - Far;
	m_Frst[1] = D3DXPLANE(vcFar.x, vcFar.y, vcFar.z, Dfar);

	D3DXVECTOR3	vcPyr[4];	
	vcPyr[0] = D3DXVECTOR3(-1.f, -1.f, 0.f);
	vcPyr[1] = D3DXVECTOR3(-1.f, 1.f, 0.f);
	vcPyr[2] = D3DXVECTOR3(1.f, 1.f, 0.f);
	vcPyr[3] = D3DXVECTOR3(1.f, -1.f, 0.f);

	for (int i = 0; i < 4; ++i) D3DXVec3TransformCoord(&vcPyr[i], &vcPyr[i], &mtVPInv);

	D3DXPlaneFromPoints(&m_Frst[2], vcPyr + 0, vcPyr + 1, &vcEye);
	D3DXPlaneFromPoints(&m_Frst[3], vcPyr + 2, vcPyr + 3, &vcEye);
	D3DXPlaneFromPoints(&m_Frst[4], vcPyr + 1, vcPyr + 2, &vcEye);
	D3DXPlaneFromPoints(&m_Frst[5], vcPyr + 3, vcPyr + 0, &vcEye);
}

void DxCamera::MoveForward(float fSpeed, float fY)
{
	D3DXVECTOR3 vTmp(_mView._13, _mView._23 * fY, _mView._33);
	D3DXVec3Normalize(&vTmp, &vTmp);

	_vEye += vTmp * fSpeed;
	_vLka += vTmp * fSpeed;
}

void DxCamera::MoveSideward(float fSpeed, float fY)
{
	D3DXVECTOR3 vTmp(_mView._11, _mView._21 * fY, _mView._31);
	D3DXVec3Normalize(&vTmp, &vTmp);

	_vEye += vTmp * fSpeed;
	_vLka += vTmp * fSpeed;
}

void DxCamera::Rotate(const D3DXVECTOR3 * vDelta, float fSpeed)
{
	D3DXVECTOR3 vcEps = *vDelta;

	FLOAT	fYaw;
	FLOAT	fPitch;

	D3DXVECTOR3 vcZ;
	D3DXVECTOR3 vcY;
	D3DXVECTOR3 vcX;

	D3DXMATRIX rtY;
	D3DXMATRIX rtX;

	fYaw = D3DXToRadian(vcEps.x * fSpeed);
	D3DXMatrixRotationY(&rtY, fYaw);

	vcZ = _vLka - _vEye;
	vcY = D3DXVECTOR3(_mView._12, _mView._22, _mView._32);

	D3DXVec3TransformCoord(&vcZ, &vcZ, &rtY);
	D3DXVec3TransformCoord(&vcY, &vcY, &rtY);

	_vLka = vcZ + _vEye;
	_vUpv = vcY;
	D3DXMatrixLookAtLH(&_mView, &_vEye, &_vLka, &_vUpv);

	fPitch = D3DXToRadian(vcEps.y * fSpeed);
	vcX = D3DXVECTOR3(_mView._11, _mView._21, _mView._31);
	vcY = D3DXVECTOR3(_mView._12, _mView._22, _mView._32);
	vcZ = _vLka - _vEye;

	D3DXMatrixRotationAxis(&rtX, &vcX, fPitch);
	D3DXVec3TransformCoord(&vcZ, &vcZ, &rtX);
	D3DXVec3TransformCoord(&vcY, &vcY, &rtX);

	_vLka = vcZ + _vEye;
	_vUpv = vcY;
	D3DXMatrixLookAtLH(&_mView, &_vEye, &_vLka, &_vUpv);
}

LRESULT DxCamera::WndProc(UINT uMsg, WPARAM wParam)
{
	if (uMsg == WM_MOUSEWHEEL)
	{
		if (_fDist >= 2.0f) _fDist -= GET_WHEEL_DELTA_WPARAM(wParam) * 0.01f;
		if (_fDist <  2.0f) _fDist = 2.0f;
	}
	return TRUE;
}

VEC3 DxCamera::GetCameraPos()
{
	D3DXVECTOR3 vCamPos;

	vCamPos.x = _mView._41;
	vCamPos.y = _mView._42;
	vCamPos.z = _mView._43;

	return vCamPos;
}

void DxCamera::GetPickLayDirection(VEC3 * pOut, float fMouseX, float fMouseY)
{
	float fW = _mProj._11;
	float fH = _mProj._22;

	float fX = (2.0f * fMouseX / _fScrW - 1) / fW;
	float fY = -(2.0f * fMouseY / _fScrH - 1) / fH;

	VEC3 vCamX = VEC3(_mView._11, _mView._21, _mView._31);
	VEC3 vCamY = VEC3(_mView._12, _mView._22, _mView._32);
	VEC3 vCamZ = VEC3(_mView._13, _mView._23, _mView._33);

	*pOut = fX * vCamX + fY * vCamY + vCamZ;
}

void DxCamera::GetPickLayDirection3D(VEC3 * pOut, float fMouseX, float fMouseY)
{
	float fW = _mProj._11;
	float fH = _mProj._22;

	float fX = (2.0f * fMouseX / _fScrW - 1) / fW;
	float fY = -(2.0f * fMouseY / _fScrH - 1) / fH;

	VEC3 vScn(fX, fY, 1.0f);
	MAT  mI;
	D3DXMatrixInverse(&mI, 0, &_mView);

	pOut->x = D3DXVec3Dot(&vScn, &VEC3(mI._11, mI._21, mI._31));
	pOut->y = D3DXVec3Dot(&vScn, &VEC3(mI._12, mI._22, mI._32));
	pOut->z = D3DXVec3Dot(&vScn, &VEC3(mI._13, mI._23, mI._33));
}


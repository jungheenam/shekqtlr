#pragma once
#include "SingletonBase.h"
enum CAMERA_STATE
{
	CAMERA_STATE_FIRST,
	CAMERA_STATE_THIRD,
};
class DxCamera : public SingletonBase<DxCamera>
{
private:
	D3DXVECTOR3 _vEye;
	D3DXVECTOR3 _vLka;
	D3DXVECTOR3 _vUpv;

	D3DXMATRIX _mView;
	D3DXMATRIX _mProj;

	float _fScrW;
	float _fScrH;
	float _fFov;
	float _fAspt;
	float _fNear;
	float _fFar;

	float _fDist;
	float _fRotX;
	float _fRotY;

	D3DXPLANE		m_Frst[6];
public:
	DxCamera();
	~DxCamera();
	HRESULT Init();
	void Release();
	void Update();
	void Render();

	void MovePosition(D3DXVECTOR3 vPos);
	void MoveFree();
	void MoveForward(float fSpeed, float fY = 0.0f);
	void MoveSideward(float fSpeed, float fY = 0.0f);
	void Rotate(const D3DXVECTOR3* vDelta, float fSpeed);

	LRESULT WndProc(UINT uMsg, WPARAM wParam);

	void SetEye(VEC3 v)		{ _vEye = v; }
	void SetLookAt(VEC3 v)	{ _vLka = v; }
	void SetUp(VEC3 v)		{ _vUpv = v; }
		
	VEC3 GetEye()		{ return _vEye; }
	VEC3 GetLookAt()	{ return _vLka; }
	VEC3 GetUp()		{ return _vUpv; }

	VEC3 GetCameraPos();
	void GetPickLayDirection(VEC3* pOut, float fMouseX, float fMouseY);
	void GetPickLayDirection3D(VEC3* pOut, float fMouseX, float fMouseY);
};


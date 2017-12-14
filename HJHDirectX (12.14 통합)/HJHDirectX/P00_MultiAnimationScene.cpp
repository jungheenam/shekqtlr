#include "stdafx.h"
#include "P00_MultiAnimationScene.h"


P00_MultiAnimationScene::P00_MultiAnimationScene()
{
	memset(_sMeshFilename, 0, sizeof(_sMeshFilename));
	_tcscpy(_sMeshFilename, _T("XFile/SkinnedMesh/Zealot/Zealot.X"));

	_pMultiAniOrig = NULL;
	_pMultiAniCopy = NULL;

	D3DXMatrixIdentity(&_mWorld);
}


P00_MultiAnimationScene::~P00_MultiAnimationScene()
{
	this->Release();
}

HRESULT P00_MultiAnimationScene::Init()
{
	//CreateAnimationUnit(NULL, &_pMultiAniOrig, _sMeshFilename);
	CreateAnimationUnit(NULL, &_pMultiAniOrig, _T("XFile/skinnedMesh/minion/minion_main.x"));
	CreateAnimationUnit(NULL, &_pMenu, _T("XFile/skinnedMesh/menu/player.x"));

	for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j)
	{
		P00_SkinnedMeshPure* pZealot;
		CreateAnimationUnit(NULL, &pZealot, NULL, _pMultiAniOrig);
		

		MAT mRot(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1);
		D3DXMatrixRotationY(&mRot, D3DX_PI / 2);
		pZealot->SetAttribute(_T("World Matrix"), &mRot);

		pZealot->SetPosition(VEC3(i * 40, 0, j * 40));

		_vZealot.push_back(pZealot);
	}
	
	

	return S_OK;
}

void P00_MultiAnimationScene::Release()
{
	SAFE_DELETE(_pMultiAniOrig);
	SAFE_DELETE(_pMultiAniCopy);
}

void P00_MultiAnimationScene::Update()
{
	static float fSpeed = 1.0f;

	if (INPUTM->KeyDown(VK_OEM_PLUS))
	{
		fSpeed += 0.1f;
	}
	if (INPUTM->KeyDown(VK_OEM_MINUS))
	{
		fSpeed -= 0.1f;
	}

	for (int i = 0; i < _vZealot.size(); ++i)
	{
		if (INPUTM->KeyDown('1'))
		{
			int nAni = 0; _vZealot[i]->SetAttribute(_T("Animation"), &nAni);
		}
		if (INPUTM->KeyDown('2'))
		{
			int nAni = 1; _vZealot[i]->SetAttribute(_T("Animation"), &nAni);
		}
		if (INPUTM->KeyDown('3'))
		{
			int nAni = 2; _vZealot[i]->SetAttribute(_T("Animation"), &nAni);
		}
		if (INPUTM->KeyDown('4'))
		{
			int nAni = 3; _vZealot[i]->SetAttribute(_T("Animation"), &nAni);
		}
		if (INPUTM->KeyDown('5'))
		{
			int nAni = 4; _vZealot[i]->SetAttribute(_T("Animation"), &nAni);
		}

		float fFrameSpeed = _fElapsedTime * fSpeed;
		_vZealot[i]->SetAttribute(_T("Frame Speed"), &fFrameSpeed);
	}

	_pMenu->SetAttribute(_T("Frame Speed"), &_fElapsedTime);
}

void P00_MultiAnimationScene::Render()
{
	TCHAR str[1024];
	for (int i = 0; i < _vZealot.size(); ++i)
	{
		_vZealot[i]->Render();
	}

	static VEC3 vCenter(0, 0, 0);
	static float fRadius = 0;

	_pMultiAniOrig->GetAttribute(_T("Center"), &vCenter);
	_stprintf(str, _T("x: %f, y: %f, z: %f"), vCenter.x, vCenter.y, vCenter.z);
	FONTM->DxDrawText(str, 0, 100);

	_pMultiAniOrig->GetAttribute(_T("Radius"), &fRadius);
	_stprintf(str, _T("r: %f"), fRadius);
	FONTM->DxDrawText(str, 0, 120);

	_pMenu->Render();
}

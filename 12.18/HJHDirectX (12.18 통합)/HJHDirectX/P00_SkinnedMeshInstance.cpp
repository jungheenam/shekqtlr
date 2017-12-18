#include "stdafx.h"
#include "P00_SkinnedMeshInstance.h"


P00_SkinnedMeshInstance::P00_SkinnedMeshInstance()
{
	_pOrig = NULL;
	_pAC   = NULL;

	_pFrameRoot = NULL;
	_dTimeCur	= 0;

	D3DXMatrixIdentity(&_mWorld);

	_nAniMax = 0;
	_nAniCur = 0;
}


P00_SkinnedMeshInstance::~P00_SkinnedMeshInstance()
{
	Release();
}

HRESULT P00_SkinnedMeshInstance::Init(void * p1, void * p2, void * p3, void * p4)
{
	_pOrig		= (P00_SkinnedMesh*)p2;
	_pFrameRoot = (tagFrame*)_pOrig->GetRootFrame();

	LPD3DXANIMATIONCONTROLLER pAC = (LPD3DXANIMATIONCONTROLLER)_pOrig->GetAnimationController();

	if (pAC)
	{
		UINT MaxNumAnimationOutputs	= pAC->GetMaxNumAnimationOutputs();
		UINT MaxNumAnimationSets	= pAC->GetMaxNumAnimationSets();
		UINT MaxNumTracks			= pAC->GetMaxNumTracks();
		UINT MaxNumEvents			= pAC->GetMaxNumEvents();

		pAC->CloneAnimationController(MaxNumAnimationOutputs,
			MaxNumAnimationSets, MaxNumTracks, MaxNumEvents, &_pAC);
	}

	//float fRand	= float(rand() % 1000);
	//_dTimeCur		= fRand / 100.0f;

	D3DXTRACK_DESC dDesc;
	_pAC->GetTrackDesc(0, &dDesc);

	_nAniMax = _pAC->GetNumAnimationSets();
	for (int i = 0; i < _nAniMax; ++i)
	{
		HRESULT hr;
		LPD3DXANIMATIONSET pAniSet = NULL;
		hr = _pAC->GetAnimationSet(i, &pAniSet);
		if (FAILED(hr)) continue;

		_vAniSet.push_back(pAniSet);
	}

	if (_nAniMax) _pAC->SetTrackAnimationSet(0, _vAniSet[_nAniMax - 1]);

	_pAC->SetTrackEnable(0, TRUE);

	return S_OK;
}

void P00_SkinnedMeshInstance::Release()
{
	if (!_vAniSet.empty())
	{
		for (int i = 0; i < _vAniSet.size(); ++i)
		{
			_vAniSet[i]->Release();
		}
		_vAniSet.clear();
	}
}

void P00_SkinnedMeshInstance::Update()
{
	
}

void P00_SkinnedMeshInstance::Render()
{
	_pAC->SetTrackPosition(0, 0);
	_pAC->AdvanceTime(_dTimeCur, NULL);

	_pOrig->UpdateFrameMatrices(_pFrameRoot, &_mWorld);
	_pOrig->DrawFrame(_pFrameRoot);
}

int P00_SkinnedMeshInstance::SetAttribute(TCHAR * sCommand, void * pValue)
{
	if (_tcsicmp(sCommand, _T("Animation")) == 0)
	{
		int nAni = *((int*)pValue);

		if (nAni >= _nAniMax || nAni < 0) return -1;

		_nAniCur = nAni;
		_pAC->SetTrackAnimationSet(0, _vAniSet[_nAniCur]);

		return 0;
	}
	return P00_MultiAnimationUnit::SetAttribute(sCommand, pValue);
}

int P00_SkinnedMeshInstance::GetAttribute(TCHAR * sCommand, void * pValue)
{
	return P00_MultiAnimationUnit::SetAttribute(sCommand, pValue);
}

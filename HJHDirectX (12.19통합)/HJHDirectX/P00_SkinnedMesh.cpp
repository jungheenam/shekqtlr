#include "stdafx.h"
#include "P00_SkinnedMesh.h"


P00_SkinnedMesh::P00_SkinnedMesh()
{
	_pFrameRoot = NULL;
	_pAC		= NULL;

	_nSkinningMethod	= D3DNONINDEXED;
	_pBoneMatrices		= NULL;
	_nBoneMatricesMax	= 0;

	D3DXMatrixIdentity(&_mWorld);

	_dTimeCur = 0;
}


P00_SkinnedMesh::~P00_SkinnedMesh()
{
	Release();
}

HRESULT P00_SkinnedMesh::Init(void * p1, void *, void *, void *)
{
	P00_AllocateHierarchy Alloc(this);

	TCHAR* sFile	= NULL;
	sFile			= (TCHAR*)p1;

	_tcscpy(_sFile, sFile);

	/*HRESULT hr;
	hr = D3DXLoadMeshHierarchyFromX(_sFile, D3DXMESH_MANAGED, DXDEV, &Alloc, NULL, (LPD3DXFRAME*)&_pFrameRoot, &_pAC);
	if (FAILED(hr)) return hr;*/

	
	D3DXLoadMeshHierarchyFromX(_sFile, D3DXMESH_MANAGED, DXDEV, &Alloc, NULL, (LPD3DXFRAME*)&_pFrameRoot, &_pAC);

	FindBones(_pFrameRoot);

	D3DXFrameCalculateBoundingSphere((const D3DXFRAME*)_pFrameRoot, &_vObjectCenter, &_fObjectRadius);


	return S_OK;
}

void P00_SkinnedMesh::Release()
{
	if (!_pFrameRoot) return;

	P00_AllocateHierarchy Alloc(this);
	D3DXFrameDestroy((LPD3DXFRAME)_pFrameRoot, &Alloc);

	SAFE_RELEASE(_pAC);
	SAFE_DELETE_ARRAY(_pBoneMatrices);

	_pFrameRoot = NULL;
}

void P00_SkinnedMesh::Update()
{
	
}

void P00_SkinnedMesh::Render()
{
	if (_pAC)
	{
		_pAC->SetTrackPosition(0, 0);
		_pAC->AdvanceTime(_dTimeCur, NULL);
	}

	UpdateFrameMatrices(_pFrameRoot, &_mWorld);
	DrawFrame(_pFrameRoot);
}

int P00_SkinnedMesh::SetAttribute(TCHAR * sCommand, void * pValue)
{
	if (_tcsicmp(sCommand, _T("Method")) == 0)
	{
		int nMethod = *((int*)pValue);
		SetMethod(nMethod);
		return 0;
	}

	return P00_MultiAnimationUnit::SetAttribute(sCommand, pValue);
}

int P00_SkinnedMesh::GetAttribute(TCHAR * sCommand, void * pValue)
{
	if (_tcsicmp(sCommand, _T("Method")) == 0)
	{
		*((int*)pValue) = GetMethod();
		return 0;
	}
	else if (_tcsicmp(sCommand, _T("Center")) == 0)
	{
		*((VEC3*)pValue) = _vObjectCenter;
		return 0;
	}
	else if (_tcsicmp(sCommand, _T("Radius")) == 0)
	{
		*((float*)pValue) = _fObjectRadius;
		return 0;
	}

	return P00_MultiAnimationUnit::GetAttribute(sCommand, pValue);
}

float P00_SkinnedMesh::GetRadius()
{
	return _fObjectRadius;
}

VEC3 * P00_SkinnedMesh::GetCenter()
{
	return &_vObjectCenter;
}

int P00_SkinnedMesh::GetMethod()
{
	return _nSkinningMethod;
}

void P00_SkinnedMesh::SetMethod(int v)
{
	_nSkinningMethod = v;
	UpdateSkinningMethod(_pFrameRoot);
}

void * P00_SkinnedMesh::GetRootFrame()
{
	return _pFrameRoot;
}

void * P00_SkinnedMesh::GetAnimationController()
{
	return _pAC;
}

void P00_SkinnedMesh::UpdateFrameMatrices(tagFrame * pFrameBase, D3DXMATRIX * pParentMatrix)
{
	tagFrame* pFrame = (tagFrame*)pFrameBase;

	if (pParentMatrix != NULL)	D3DXMatrixMultiply(&pFrame->mWorld, &pFrame->mTransformation, pParentMatrix);
	else						pFrame->mWorld = pFrame->mTransformation;

	if (pFrame->pFrameSibling != NULL)		UpdateFrameMatrices(pFrame->pFrameSibling, pParentMatrix);
	if (pFrame->pFrameFirstChild != NULL)	UpdateFrameMatrices(pFrame->pFrameFirstChild, &pFrame->mWorld);
}

void P00_SkinnedMesh::DrawFrame(tagFrame * pFrame)
{
	tagMeshContainer* pMeshContainer;

	pMeshContainer = pFrame->pMesh;

	while (pMeshContainer != NULL)
	{
		DrawMeshContainer(pMeshContainer, pFrame);

		pMeshContainer = pMeshContainer->pNextMeshContainer;
	}

	if (pFrame->pFrameSibling != NULL)		DrawFrame(pFrame->pFrameSibling);
	if (pFrame->pFrameFirstChild != NULL)	DrawFrame(pFrame->pFrameFirstChild);
}

HRESULT P00_SkinnedMesh::GenerateSkinnedMesh(tagMeshContainer * pMeshContainer)
{
	D3DCAPS9 dCaps;
	DXDEV->GetDeviceCaps(&dCaps);

	if (pMeshContainer->pSkinInfo == NULL) return S_OK;

	SAFE_RELEASE(pMeshContainer->MeshData.pMesh);
	SAFE_RELEASE(pMeshContainer->pBoneCombinationBuf);

	if (_nSkinningMethod == D3DNONINDEXED)
	{
		HRESULT hr;
		hr = pMeshContainer->pSkinInfo->ConvertToBlendedMesh
		(
			pMeshContainer->pOrigMesh,
			D3DXMESH_MANAGED | D3DXMESHOPT_VERTEXCACHE,
			pMeshContainer->pAdjacency,
			NULL, NULL, NULL,
			&pMeshContainer->NumInfl,
			&pMeshContainer->NumAttributeGroups,
			&pMeshContainer->pBoneCombinationBuf,
			&pMeshContainer->MeshData.pMesh
		);
		if (FAILED(hr)) return S_OK;

		LPD3DXBONECOMBINATION pBoneCombinations =
			reinterpret_cast<LPD3DXBONECOMBINATION>(pMeshContainer->pBoneCombinationBuf->GetBufferPointer());

		for (pMeshContainer->iAttributeSW = 0; pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups; pMeshContainer->iAttributeSW++)
		{
			DWORD cInfl = 0;
			for (DWORD i = 0; i < pMeshContainer->NumInfl; i++)
			{
				if (pBoneCombinations[pMeshContainer->iAttributeSW].BoneId[i] != UINT_MAX)
				{
					++cInfl;
				}
			}
			if (cInfl > dCaps.MaxVertexBlendMatrices) break;
		}

		if (pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups)
		{
			HRESULT hr;
			LPMESH pMeshTmp;

			hr = pMeshContainer->MeshData.pMesh->CloneMeshFVF(
				D3DXMESH_SOFTWAREPROCESSING | pMeshContainer->MeshData.pMesh->GetOptions(),
				pMeshContainer->MeshData.pMesh->GetFVF(),
				DXDEV, &pMeshTmp);
			if (FAILED(hr)) return S_OK;

			pMeshContainer->MeshData.pMesh->Release();
			pMeshContainer->MeshData.pMesh = pMeshTmp;
			pMeshTmp = NULL;
		}
	}
	else
	{
		return E_INVALIDARG;
	}
}

void P00_SkinnedMesh::DrawMeshContainer(tagMeshContainer * pMeshContainerBase, tagFrame * pFrameBase)
{
	tagMeshContainer* pMeshContainer = (tagMeshContainer*)pMeshContainerBase;
	tagFrame* pFrame = (tagFrame*)pFrameBase;

	if (pMeshContainer->pSkinInfo)
	{
		if (_nSkinningMethod == D3DNONINDEXED) RenderNonIndexed(pMeshContainer);
		return;
	}

	RenderNonAnimation(pMeshContainer, pFrame);
}

void P00_SkinnedMesh::UpdateSkinningMethod(tagFrame * pFrameBase)
{
	tagFrame* pFrame = (tagFrame*)pFrameBase;
	tagMeshContainer* pMeshContainer;

	pMeshContainer = (tagMeshContainer*)pFrame->pMesh;

	while (pMeshContainer != NULL)
	{
		GenerateSkinnedMesh(pMeshContainer);
		pMeshContainer = (tagMeshContainer*)pMeshContainer->pNextMeshContainer;
	}

	if (pFrame->pFrameSibling != NULL)		DrawFrame(pFrame->pFrameSibling);
	if (pFrame->pFrameFirstChild != NULL)	DrawFrame(pFrame->pFrameFirstChild);
}

tagFrame * P00_SkinnedMesh::FindFrame(TCHAR * szName)
{
	if (_pFrameRoot == NULL) return NULL;
	return _pFrameRoot->FindFrame(szName);
}

HRESULT P00_SkinnedMesh::FindBones(tagFrame * pFrameCur)
{
	tagMeshContainer*	pMesh;
	tagFrame*			pFrameChild;

	pMesh = pFrameCur->pMesh;

	while (pMesh != NULL)
	{
		if (pMesh->pSkinInfo)
		{
			for (DWORD i = 0; i < pMesh->pSkinInfo->GetNumBones(); ++i)
			{
				tagFrame* pFrame = FindFrame((TCHAR*)pMesh->pSkinInfo->GetBoneName(i));
				if (pFrame) pMesh->ppBoneMatrix[i] = &(pFrame->mWorld);
			}
		}
		pMesh = (tagMeshContainer*)pMesh->pNextMeshContainer;
	}

	pFrameChild = pFrameCur->pFrameFirstChild;
	while (pFrameChild != NULL)
	{
		HRESULT hr;
		hr = FindBones(pFrameChild);
		if (FAILED(hr)) return S_OK;

		pFrameChild = pFrameChild->pFrameSibling;
	}

	return S_OK;
}

void P00_SkinnedMesh::RenderNonIndexed(tagMeshContainer * pMeshContainer)
{
	UINT	nBlend;
	DWORD	dPrevAtrId;

	LPD3DXBONECOMBINATION pBoneComb;

	UINT		iAtr;
	UINT		iMatrixIndex;
	D3DXMATRIX	mTmp;

	D3DCAPS9 dCaps;
	DXDEV->GetDeviceCaps(&dCaps);

	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

	dPrevAtrId = UNUSED32;
	pBoneComb = 
		reinterpret_cast<LPD3DXBONECOMBINATION>(pMeshContainer->pBoneCombinationBuf->GetBufferPointer());

	for (iAtr = 0; iAtr < pMeshContainer->NumAttributeGroups; iAtr++)
	{
		nBlend = 0;
		for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
		{
			if (pBoneComb[iAtr].BoneId[i] != UINT_MAX)
			{
				nBlend = i;
			}
		}

		if (dCaps.MaxVertexBlendMatrices >= nBlend + 1)
		{
			for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
			{
				iMatrixIndex = pBoneComb[iAtr].BoneId[i];
				if (iMatrixIndex != UINT_MAX)
				{
					D3DXMatrixMultiply(&mTmp, &pMeshContainer->pBoneOffsetMatrices[iMatrixIndex],
						pMeshContainer->ppBoneMatrix[iMatrixIndex]);

					DXDEV->SetTransform(D3DTS_WORLDMATRIX(i), &mTmp);
				}
			}

			DXDEV->SetRenderState(D3DRS_VERTEXBLEND, nBlend);

			if (dPrevAtrId != pBoneComb[iAtr].AttribId || dPrevAtrId == UNUSED32)
			{
				DXDEV->SetMaterial(&pMeshContainer->pMaterials[pBoneComb[iAtr].AttribId].MatD3D);
				DXDEV->SetTexture(0, pMeshContainer->ppTexture[pBoneComb[iAtr].AttribId]);

				dPrevAtrId = pBoneComb[iAtr].AttribId;
			}

			pMeshContainer->MeshData.pMesh->DrawSubset(iAtr);
		}
	}

	if (pMeshContainer->iAttributeSW < pMeshContainer->NumAttributeGroups)
	{
		dPrevAtrId = UNUSED32;
		DXDEV->SetSoftwareVertexProcessing(TRUE);

		for (iAtr = pMeshContainer->iAttributeSW; iAtr < pMeshContainer->NumAttributeGroups; iAtr++)
		{
			nBlend = 0;
			for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
			{
				if (pBoneComb[iAtr].BoneId[i] != UINT_MAX)
				{
					nBlend = i;
				}
			}

			if (dCaps.MaxVertexBlendMatrices < nBlend + 1)
			{
				for (DWORD i = 0; i < pMeshContainer->NumInfl; ++i)
				{
					iMatrixIndex = pBoneComb[iAtr].BoneId[i];
					if (iMatrixIndex != UINT_MAX)
					{
						D3DXMatrixMultiply(&mTmp, &pMeshContainer->pBoneOffsetMatrices[iMatrixIndex],
							pMeshContainer->ppBoneMatrix[iMatrixIndex]);

						DXDEV->SetTransform(D3DTS_WORLDMATRIX(i), &mTmp);
					}
				}

				DXDEV->SetRenderState(D3DRS_VERTEXBLEND, nBlend);

				if (dPrevAtrId != pBoneComb[iAtr].AttribId || dPrevAtrId == UNUSED32)
				{
					DXDEV->SetMaterial(&pMeshContainer->pMaterials[pBoneComb[iAtr].AttribId].MatD3D);
					DXDEV->SetTexture(0, pMeshContainer->ppTexture[pBoneComb[iAtr].AttribId]);

					dPrevAtrId = pBoneComb[iAtr].AttribId;
				}

				pMeshContainer->MeshData.pMesh->DrawSubset(iAtr);
			}
		}

		DXDEV->SetSoftwareVertexProcessing(FALSE);
	}
	
	DXDEV->SetRenderState(D3DRS_VERTEXBLEND, 0);
}

void P00_SkinnedMesh::RenderNonAnimation(tagMeshContainer * pMeshContainer, tagFrame * pFrame)
{
	UINT iMaterial;
	DXDEV->SetTransform(D3DTS_WORLD, &pFrame->mWorld);

	for (iMaterial = 0; iMaterial < pMeshContainer->NumMaterials; iMaterial++)
	{
		DXDEV->SetMaterial(&pMeshContainer->pMaterials[iMaterial].MatD3D);
		DXDEV->SetTexture(0, pMeshContainer->ppTexture[iMaterial]);
		pMeshContainer->MeshData.pMesh->DrawSubset(iMaterial);
	}

	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
}

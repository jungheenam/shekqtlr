#include "stdafx.h"
#include "P00_AllocateHierarchy.h"


tagFrame * tagFrame::FindFrame(TCHAR * szFrame)
{
	tagFrame* pFrame;
	
	if ((szName != NULL) && (_tcscmp(szName, szFrame) == 0)) return this;

	if (pFrameFirstChild != NULL)
	{
		pFrame = pFrameFirstChild->FindFrame(szFrame);
		if (pFrame != NULL) return pFrame;
	}

	if (pFrameSibling != NULL)
	{
		pFrame = pFrameSibling->FindFrame(szFrame);
		if (pFrame != NULL) return pFrame;
	}

	return NULL;
}


STDMETHODIMP P00_AllocateHierarchy::CreateFrame(LPCSTR Name, LPD3DXFRAME * ppNewFrame)
{
	HRESULT hr = S_OK;
	tagFrame* pFrame;
	*ppNewFrame = NULL;

	pFrame = new tagFrame;
	if (pFrame == NULL)
	{
		hr = E_OUTOFMEMORY;
		goto e_Exit;
	}

	hr = AllocateName(Name, &pFrame->szName);
	if (FAILED(hr)) goto e_Exit;

	D3DXMatrixIdentity(&pFrame->mTransformation);
	D3DXMatrixIdentity(&pFrame->mWorld);

	pFrame->pMesh				= NULL;
	pFrame->pFrameFirstChild	= NULL;
	pFrame->pFrameSibling		= NULL;

	*ppNewFrame = (LPD3DXFRAME)pFrame;
	pFrame		= NULL;

e_Exit:
	delete pFrame;
	return hr;
}

STDMETHODIMP P00_AllocateHierarchy::CreateMeshContainer(LPCSTR Name, CONST D3DXMESHDATA * pMeshData, CONST D3DXMATERIAL * pMaterials, CONST D3DXEFFECTINSTANCE * pEffectInstances, DWORD NumMaterials, CONST DWORD * pAdjacency, LPD3DXSKININFO pSkinInfo, LPD3DXMESHCONTAINER * ppNewMeshContainer)
{
	HRESULT hr;
	tagMeshContainer* pMeshContainer = NULL;

	UINT NumFaces;
	UINT iMaterial;
	UINT iBone, cBone;

	LPDIRECT3DDEVICE9 pDevice = NULL;

	LPMESH pMesh		= NULL;
	*ppNewMeshContainer = NULL;

	if (pMeshData->Type != D3DXMESHTYPE_MESH)
	{
		hr = E_FAIL;
		goto e_Exit;
	}

	pMesh = pMeshData->pMesh;

	if (pMesh->GetFVF() == 0)
	{
		hr = E_FAIL;
		goto e_Exit;
	}

	pMeshContainer = new tagMeshContainer;
	if (pMeshContainer == NULL)
	{
		hr = E_OUTOFMEMORY;
		goto e_Exit;
	}
	memset(pMeshContainer, 0, sizeof(tagMeshContainer));

	hr = AllocateName(Name, &pMeshContainer->Name);
	if (FAILED(hr)) goto e_Exit;

	pMesh->GetDevice(&pDevice);
	NumFaces = pMesh->GetNumFaces();

	if (!(pMesh->GetFVF() & D3DFVF_NORMAL))
	{
		pMeshContainer->MeshData.Type = D3DXMESHTYPE_MESH;

		hr = pMesh->CloneMeshFVF(pMesh->GetOptions(), pMesh->GetFVF() | D3DFVF_NORMAL,
			pDevice, &pMeshContainer->MeshData.pMesh);
		if (FAILED(hr)) goto e_Exit;

		pMesh = pMeshContainer->MeshData.pMesh;

		D3DXComputeNormals(pMesh, NULL);
	}
	else
	{
		pMeshContainer->MeshData.pMesh = pMesh;
		pMeshContainer->MeshData.Type = D3DXMESHTYPE_MESH;
		pMesh->AddRef();
	}

	pMeshContainer->NumMaterials = max(1, NumMaterials);
	pMeshContainer->pMaterials = new D3DXMATERIAL[pMeshContainer->NumMaterials];
	pMeshContainer->ppTexture = new LPDIRECT3DTEXTURE9[pMeshContainer->NumMaterials];
	pMeshContainer->pAdjacency = new DWORD[NumFaces * 3];
	if (pMeshContainer->pMaterials == NULL || pMeshContainer->pAdjacency == NULL)
	{
		hr = E_OUTOFMEMORY;
		goto e_Exit;
	}
	memcpy(pMeshContainer->pAdjacency, pAdjacency, sizeof(DWORD) * NumFaces * 3);
	memset(pMeshContainer->ppTexture, 0, sizeof(LPDIRECT3DTEXTURE9) * pMeshContainer->NumMaterials);

	if (NumMaterials > 0)
	{
		memcpy(pMeshContainer->pMaterials, pMaterials, sizeof(D3DXMATERIAL) * NumMaterials);

		TCHAR sDrive[_MAX_DRIVE] = { 0 };
		TCHAR sPath[_MAX_DIR]	 = { 0 };

		const TCHAR* sModelFile = _pSource->GetName();
		_splitpath(sModelFile, sDrive, sPath, NULL, NULL);

		for (iMaterial = 0; iMaterial < NumMaterials; iMaterial++)
		{
			if (pMeshContainer->pMaterials[iMaterial].pTextureFilename != NULL)
			{
				TCHAR sTexturePath[MAX_PATH] = _T("");
				TCHAR* szFilename;
#ifdef UNICODE
				TCHAR szBuf[MAX_PATH];
				szFilename = szBuf;
				MultiByteToWideChar(CP_ACP, 0, pMeshContainer->pMaterials[iMaterial].pTextureFilename, -1, szBuf, MAX_PATH);
				szBuf[MAX_PATH - 1] = _T('\0');
#else
				szFilename = pMeshContainer->pMaterials[iMaterial].pTextureFilename;
#endif
				TCHAR sFileFullPath[_MAX_DIR] = { 0 };
				if (_tcslen(szFilename) > 2)
				{
					_stprintf(sFileFullPath, _T("%s%s%s"), sDrive, sPath, szFilename);
				}

				if (FAILED(D3DXCreateTextureFromFile(pDevice, sFileFullPath,
					&pMeshContainer->ppTexture[iMaterial]))) pMeshContainer->ppTexture[iMaterial] = NULL;

				pMeshContainer->pMaterials[iMaterial].pTextureFilename = NULL;
			}
		}
	}
	else
	{
		pMeshContainer->pMaterials[0].pTextureFilename = NULL;
		memset(&pMeshContainer->pMaterials[0].MatD3D, 0, sizeof(D3DMATERIAL9));
		pMeshContainer->pMaterials[0].MatD3D.Diffuse.r = 0.5f;
		pMeshContainer->pMaterials[0].MatD3D.Diffuse.g = 0.5f;
		pMeshContainer->pMaterials[0].MatD3D.Diffuse.b = 0.5f;
		pMeshContainer->pMaterials[0].MatD3D.Specular = pMeshContainer->pMaterials[0].MatD3D.Diffuse;
	}

	if (pSkinInfo != NULL)
	{
		pMeshContainer->pSkinInfo = pSkinInfo;
		pSkinInfo->AddRef();

		pMeshContainer->pOrigMesh = pMesh;
		pMesh->AddRef();

		cBone = pSkinInfo->GetNumBones();

		pMeshContainer->pBoneOffsetMatrices = new D3DXMATRIX[cBone];
		pMeshContainer->ppBoneMatrix = new D3DXMATRIX*[cBone];

		if (pMeshContainer->pBoneOffsetMatrices == NULL)
		{
			hr = E_OUTOFMEMORY;
			goto e_Exit;
		}

		for (iBone = 0; iBone < cBone; iBone++)
		{
			pMeshContainer->pBoneOffsetMatrices[iBone] = *(pMeshContainer->pSkinInfo->GetBoneOffsetMatrix(iBone));
		}

		hr = ((P00_SkinnedMesh*)_pSource)->GenerateSkinnedMesh(pMeshContainer);
		if (FAILED(hr)) goto e_Exit;
	}

	*ppNewMeshContainer = (LPD3DXMESHCONTAINER)pMeshContainer;
	pMeshContainer = NULL;

e_Exit:
	SAFE_RELEASE(pDevice);
	if (pMeshContainer != NULL) DestroyMeshContainer((LPD3DXMESHCONTAINER)pMeshContainer);
	return hr;
}

STDMETHODIMP P00_AllocateHierarchy::DestroyFrame(LPD3DXFRAME pFrameToFree)
{
	SAFE_DELETE_ARRAY(pFrameToFree->Name);
	SAFE_DELETE(pFrameToFree);
	return S_OK;
}

STDMETHODIMP P00_AllocateHierarchy::DestroyMeshContainer(LPD3DXMESHCONTAINER pMeshContainerBase)
{
	UINT iMaterial;
	tagMeshContainer* pMeshContainer = (tagMeshContainer*)pMeshContainerBase;

	SAFE_DELETE_ARRAY(pMeshContainer->Name);
	SAFE_DELETE_ARRAY(pMeshContainer->pAdjacency);
	SAFE_DELETE_ARRAY(pMeshContainer->pMaterials);
	SAFE_DELETE_ARRAY(pMeshContainer->pBoneOffsetMatrices);

	if (pMeshContainer->ppTexture != NULL)
	{
		for (iMaterial = 0; iMaterial < pMeshContainer->NumMaterials; iMaterial++)
		{
			SAFE_RELEASE(pMeshContainer->ppTexture[iMaterial]);
		}
	}

	SAFE_DELETE_ARRAY(pMeshContainer->pAttributeTable);
	SAFE_DELETE_ARRAY(pMeshContainer->ppTexture);	
	SAFE_DELETE_ARRAY(pMeshContainer->ppBoneMatrix);
	SAFE_RELEASE(pMeshContainer->pBoneCombinationBuf);
	SAFE_RELEASE(pMeshContainer->MeshData.pMesh);
	SAFE_RELEASE(pMeshContainer->pSkinInfo);
	SAFE_RELEASE(pMeshContainer->pOrigMesh);
	SAFE_DELETE(pMeshContainer);

	return S_OK;
}

HRESULT P00_AllocateHierarchy::AllocateName(LPCSTR Name, LPSTR * pNewName)
{
	UINT cLength;

	if (Name != NULL)
	{
		cLength = (UINT)_tcslen(Name) + 1;
		*pNewName = new TCHAR[cLength];
		if (*pNewName == NULL) return E_OUTOFMEMORY;

		memcpy(*pNewName, Name, cLength * sizeof(TCHAR));
	}
	else
	{
		*pNewName = NULL;
	}

	return S_OK;
}
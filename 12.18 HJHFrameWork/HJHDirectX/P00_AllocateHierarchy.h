#pragma once
class P00_SkinnedMeshPure;

struct tagMeshContainer
{
	LPSTR					Name;
	D3DXMESHDATA			MeshData;
	LPD3DXMATERIAL			pMaterials;
	LPD3DXEFFECTINSTANCE	pEffects;
	DWORD					NumMaterials;
	DWORD*					pAdjacency;
	LPD3DXSKININFO			pSkinInfo;
	tagMeshContainer*		pNextMeshContainer;

	LPTXUR*					ppTexture;

	LPMESH					pOrigMesh;
	LPD3DXATTRIBUTERANGE	pAttributeTable;
	DWORD					NumAttributeGroups;
	DWORD					NumInfl;
	LPD3DXBUFFER			pBoneCombinationBuf;
	D3DXMATRIX**			ppBoneMatrix;
	D3DXMATRIX*				pBoneOffsetMatrices;
	bool					UseSoftwareVP;
	DWORD					iAttributeSW;

	tagMeshContainer()
	{
		Name				= NULL;
		pAdjacency			= NULL;
		pMaterials			= NULL;
		pBoneOffsetMatrices = NULL;
		ppTexture			= NULL;
		pAttributeTable		= NULL;
		ppBoneMatrix		= NULL;
		pBoneCombinationBuf = NULL;
		MeshData.pMesh		= NULL;
		pSkinInfo			= NULL;
		pOrigMesh			= NULL;
	}
};

struct tagFrame
{
	TCHAR*				szName;
	D3DXMATRIX			mTransformation;
	tagMeshContainer*	pMesh;
	tagFrame*			pFrameSibling;
	tagFrame*			pFrameFirstChild;
	D3DXMATRIX			mWorld;

	tagFrame* FindFrame(TCHAR* szFrame);
};

class P00_AllocateHierarchy : public ID3DXAllocateHierarchy
{
public:
	STDMETHOD(CreateFrame)(THIS_ LPCSTR Name, LPD3DXFRAME *ppNewFrame);

	STDMETHOD(CreateMeshContainer)(THIS_ LPCSTR Name,
		CONST D3DXMESHDATA *pMeshData,
		CONST D3DXMATERIAL *pMaterials,
		CONST D3DXEFFECTINSTANCE *pEffectInstances,
		DWORD NumMaterials,
		CONST DWORD *pAdjacency,
		LPD3DXSKININFO pSkinInfo,
		LPD3DXMESHCONTAINER *ppNewMeshContainer);

	STDMETHOD(DestroyFrame)(THIS_ LPD3DXFRAME pFrameToFree);
	STDMETHOD(DestroyMeshContainer)(THIS_ LPD3DXMESHCONTAINER pMeshContainerBase);
protected:
	P00_SkinnedMeshPure* _pSource;
public:
	P00_AllocateHierarchy(P00_SkinnedMeshPure* pSource) : _pSource(pSource) {}
	HRESULT AllocateName(LPCSTR Name, LPSTR* pNewName);
};


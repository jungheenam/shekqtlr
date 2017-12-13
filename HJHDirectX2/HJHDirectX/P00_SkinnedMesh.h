#pragma once
class P00_SkinnedMesh : public P00_MultiAnimationUnit
{
public:
	enum METHOD
	{
		NONE = 0,
		D3DNONINDEXED = 1,
	};
protected:
	TCHAR		_sFile[MAX_PATH];
	tagFrame*	_pFrameRoot;

	LPD3DXANIMATIONCONTROLLER _pAC;

	VEC3		_vObjectCenter;
	float		_fObjectRadius;
	int			_nSkinningMethod;

	UINT		_nBoneMatricesMax;
	D3DXMATRIX* _pBoneMatrices;
public:
	P00_SkinnedMesh();
	virtual ~P00_SkinnedMesh();
	virtual HRESULT Init(void* = 0, void* = 0, void* = 0, void* = 0);
	virtual void Release();
	virtual void Update();
	virtual void Render();

	virtual const TCHAR* const GetName() const { return _sFile; }
	virtual P00_SkinnedMeshPure* GetOriginal() { return this;	}

	virtual int SetAttribute(TCHAR* sCommand, void* pValue);
	virtual int GetAttribute(TCHAR* sCommand, void* pValue);
public:
	float	GetRadius();
	VEC3*	GetCenter();

	int		GetMethod();
	void	SetMethod(int);
	void*	GetRootFrame();
	void*	GetAnimationController();

	void UpdateFrameMatrices(tagFrame* pFrameBase, D3DXMATRIX* pParentMatrix);
	void DrawFrame(tagFrame* pFrame);

	HRESULT GenerateSkinnedMesh(tagMeshContainer* pMeshContainer);
protected:
	void DrawMeshContainer(tagMeshContainer* pMeshContainerBase, tagFrame* pFrameBase);
	void UpdateSkinningMethod(tagFrame* pFrameBaes);

	tagFrame*	FindFrame(TCHAR* szName);
	HRESULT		FindBones(tagFrame* pFrameCur);

	void RenderNonIndexed(tagMeshContainer* pMeshContainer);
	void RenderNonAnimation(tagMeshContainer* pMeshContainer, tagFrame* pFrame);
};


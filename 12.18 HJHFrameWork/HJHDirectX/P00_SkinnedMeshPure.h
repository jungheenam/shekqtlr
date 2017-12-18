#pragma once
class P00_SkinnedMeshPure
{
public:
	virtual ~P00_SkinnedMeshPure() {}

	virtual HRESULT Init(void* = 0, void* = 0, void* = 0, void* = 0)	= 0;
	virtual void Release()												= 0;
	virtual void Update()												= 0;
	virtual void Render()												= 0;

	virtual const TCHAR* const GetName() const = 0;
	virtual P00_SkinnedMeshPure* GetOriginal() = 0;

	virtual int SetAttribute(TCHAR* sCommand, void* pValue) = 0;
	virtual int GetAttribute(TCHAR* sCommand, void* pValue) = 0;

	virtual int SetPosition(VEC3 vPos) = 0;
	virtual int GetPosition(VEC3 vPos) = 0;
};

HRESULT CreateAnimationUnit(TCHAR* sCommand, P00_SkinnedMeshPure** pData, void* p1, void* p2 = NULL, void* p3 = NULL, void* p4 = NULL);
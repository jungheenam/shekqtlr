#pragma once
class P00_MultiAnimationUnit : public P00_SkinnedMeshPure
{
protected:
	D3DXMATRIX	_mWorld;
	double		_dTimeCur;
public:
	P00_MultiAnimationUnit();
	virtual ~P00_MultiAnimationUnit();
	virtual HRESULT Init(void* = 0, void* = 0, void* = 0, void* = 0);
	virtual void Release();
	virtual void Update();
	virtual void Render();

	virtual const TCHAR* const GetName() const { return NULL; }
	virtual P00_SkinnedMeshPure* GetOriginal() { return NULL; }

	virtual int SetAttribute(TCHAR* sCommand, void* pValue);
	virtual int GetAttribute(TCHAR* sCommand, void* pValue);

	virtual int SetPosition(VEC3 vPos);
	virtual int GetPosition(VEC3 vPos);
};


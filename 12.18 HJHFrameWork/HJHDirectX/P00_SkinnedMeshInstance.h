#pragma once
class P00_SkinnedMeshInstance : public P00_MultiAnimationUnit
{
protected:
	P00_SkinnedMesh*			_pOrig;
	LPD3DXANIMATIONCONTROLLER	_pAC;
	tagFrame*					_pFrameRoot;

	int _nAniMax;
	int _nAniCur;

	vector<LPD3DXANIMATIONSET> _vAniSet;
public:
	P00_SkinnedMeshInstance();
	~P00_SkinnedMeshInstance();
	HRESULT Init(void* = 0, void* = 0, void* = 0, void* = 0);
	void Release();
	void Update();
	void Render();

	const TCHAR* const GetName() const { return _pOrig->GetName();	}
	P00_SkinnedMeshPure* GetOriginal() { return _pOrig;				}

	int SetAttribute(TCHAR* sCommand, void* pValue);
	int GetAttribute(TCHAR* sCommand, void* pValue);
};


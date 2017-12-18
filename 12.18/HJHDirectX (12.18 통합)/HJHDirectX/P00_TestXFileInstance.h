#pragma once
class P00_TestXFileInstance : public P00_TestXFilePure
{
private:
	P00_TestXFile*	_pOrig;
	LPMESH			_pMesh;
	DMTL*			_pMtl;
	LPTXUR*			_pTex;
	int				_nSubset;
	MAT				_mWorld;
public:
	P00_TestXFileInstance();
	virtual ~P00_TestXFileInstance();
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	virtual HRESULT Load(TCHAR* sFile, void* pOriginal = NULL);

	virtual P00_TestXFilePure* GetOriginal() { return _pOrig; }
	virtual void SetWorldMatrix(const MAT* pMat) { _mWorld = *pMat; }
	virtual MAT* GetWorldMatrix() { return &_mWorld; }
};


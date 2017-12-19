#pragma once
class P00_TestXFile : public P00_TestXFilePure
{
private:
	TCHAR	_sFile[MAX_PATH];
	LPMESH	_pMesh;
	DMTL*	_pMtl;
	LPTXUR* _pTex;
	int		_nSubset;
public:
	P00_TestXFile();
	virtual ~P00_TestXFile();
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	virtual HRESULT Load(TCHAR* sFile, void* pOriginal = NULL);

	virtual P00_TestXFilePure* GetOriginal() { return this; }
	virtual void SetWorldMatrix(const MAT*) {}
	virtual MAT* GetWorldMatrix() { return NULL; }
public:
	LPMESH	GetMesh()		{ return _pMesh;	}
	DMTL*	GetMaterial()	{ return _pMtl;		}
	LPTXUR* GetTexture()	{ return _pTex;		}
	int		GetSubset()		{ return _nSubset;	}
};


#pragma once
class P00_TestXFilePure
{
public:
	virtual ~P00_TestXFilePure() {};
	virtual HRESULT Init() = 0;
	virtual void Release() = 0;
	virtual void Update()  = 0;
	virtual void Render()  = 0;

	virtual HRESULT Load(TCHAR* sFilename = NULL, void* pOriginal = NULL) = 0;

	virtual P00_TestXFilePure* GetOriginal() = 0;
	virtual void SetWorldMatrix(const MAT*)  = 0;
	virtual MAT* GetWorldMatrix()			 = 0;
};

HRESULT CreateXFile(P00_TestXFilePure** pOut, TCHAR* sFile, void* pOriginal = NULL);
#include "stdafx.h"
#include "P00_TestXFilePure.h"


HRESULT CreateXFile(P00_TestXFilePure ** pOut, TCHAR * sFile, void * pOriginal)
{
	P00_TestXFilePure* pObj = nullptr;

	if		(sFile)		pObj = new P00_TestXFile;
	else if (pOriginal) pObj = new P00_TestXFileInstance;

	else
	{
		*pOut = NULL;
		return E_FAIL;
	}

	if (FAILED(pObj->Load(sFile, pOriginal)))
	{
		delete pObj;
		*pOut = nullptr;
		return E_FAIL;
	}

	*pOut = pObj;

	return S_OK;
}

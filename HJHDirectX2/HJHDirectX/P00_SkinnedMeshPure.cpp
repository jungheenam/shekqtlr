#include "stdafx.h"
#include "P00_SkinnedMeshPure.h"


HRESULT CreateAnimationUnit(TCHAR * sCommand, P00_SkinnedMeshPure ** pData, void * p1, void * p2, void * p3, void * p4)
{
	P00_SkinnedMeshPure* pObj = NULL;
	*pData = NULL;

	if		(p1 != NULL) pObj = new P00_SkinnedMesh;
	else if (p2 != NULL) pObj = new P00_SkinnedMeshInstance;

	else	return E_FAIL;

	if (FAILED(pObj->Init(p1, p2, p3, p4)))
	{
		delete pObj;
		return E_FAIL;
	}

	*pData = pObj;

	return S_OK;
}



#include "stdafx.h"
#include "P00_TestMeshData.h"


P00_TestMeshData::P00_TestMeshData()
{
	_nGeo = 0;
	_nVtx = 0;
	_dVtx = 0;
	_dFVF = 0;
	_pVtx = nullptr;

	ZeroMemory(&_pTex, sizeof(_pTex));
	ZeroMemory(&_pGeo, sizeof(tagGeometry));
}


P00_TestMeshData::~P00_TestMeshData()
{
	this->Release();
}

HRESULT P00_TestMeshData::Init()
{
	LPMESH pMesh = nullptr;
	MeshData(&pMesh);

	int nVtxS = pMesh->GetNumVertices();
	int nIdxS = pMesh->GetNumFaces();

	_nVtx = nVtxS;
	_dVtx = (UINT)pMesh->GetNumBytesPerVertex();
	_dFVF = pMesh->GetFVF();
	_pVtx = malloc(_nVtx * _dVtx);

	tagVertexPT* pVtxS = nullptr;
	pMesh->LockVertexBuffer(0, (void**)&pVtxS);
	memcpy(_pVtx, pVtxS, sizeof(tagVertexPT) * nVtxS);
	pMesh->UnlockVertexBuffer();

	tagIndex* pIdx  = new tagIndex[nIdxS];
	tagIndex* pIdxS = nullptr;
	pMesh->LockIndexBuffer(0, (void**)&pIdxS);
	memcpy(pIdx, pIdxS, sizeof(tagIndex) * nIdxS);
	pMesh->UnlockIndexBuffer();

	DWORD nSubset = 0;
	pMesh->GetAttributeTable(0, &nSubset);

	_nGeo = nSubset;
	_pGeo = new tagGeometry[_nGeo];

	LPD3DXATTRIBUTERANGE atr = new D3DXATTRIBUTERANGE[nSubset];
	pMesh->GetAttributeTable(atr, &nSubset);

	for (int i = 0; i < _nGeo; ++i)
	{
		tagGeometry* pGeo = &_pGeo[i];

		pGeo->nIdx = atr[i].FaceCount;
		pGeo->nVtx = atr[i].VertexCount;

		int nFaceBegin = atr[i].FaceStart;

		pGeo->pIdx = new tagIndex[pGeo->nIdx];

		tagIndex* pIdxTmp = pIdx + nFaceBegin;
		memcpy(pGeo->pIdx, pIdxTmp, sizeof(tagIndex) * pGeo->nIdx);
	}

	SAFE_DELETE_ARRAY(atr);
	SAFE_DELETE_ARRAY(pIdx);
	SAFE_RELEASE(pMesh);

	TCHAR* pTex[] =
	{
		_T("Texture/P00_TestMesh/cellwall.png"  ),
		_T("Texture/P00_TestMesh/concrete.png"  ),
		_T("Texture/P00_TestMesh/greyBricks.png"),
		_T("Texture/P00_TestMesh/stones.png"    ),
		_T("Texture/P00_TestMesh/wood.png"      ),
		_T("Texture/P00_TestMesh/rocks.png"     ),
	};

	for (int i = 0; i < 6; ++i) D3DXCreateTextureFromFile(DXDEV, pTex[i], &_pTex[i]);

	return S_OK;
}

void P00_TestMeshData::Release()
{
	for (int i = 0; i < 6; ++i) SAFE_RELEASE(_pTex[i]);
	
	SAFE_DELETE_ARRAY(_pGeo);

	SAFE_FREE(_pVtx);
}

void P00_TestMeshData::Update()
{
}

void P00_TestMeshData::Render()
{
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	DXM->BaseSamplerState();

	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int i = 0; i < _nGeo; ++i)
	{
		tagGeometry* pGeo = &_pGeo[i];

		DXDEV->SetTexture(0, _pTex[i]);
		DXDEV->SetFVF(_dFVF);
		DXDEV->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, _nVtx, pGeo->nIdx, pGeo->pIdx, D3DFMT_INDEX16, _pVtx, _dVtx);
	}
}

void P00_TestMeshData::MeshData(LPMESH* pOut)
{
	vector<tagVertexPT> vVtxS;
	vector<tagIndex>	vIdxS;

	// Å¥ºê ÁÂÇ¥
	vVtxS.push_back(tagVertexPT(-1.f, -1.f, -1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f, -1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f, -1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f, -1.f, 1.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f, -1.f,  1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f,  1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f,  1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f,  1.f, 1.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f, -1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f,  1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f,  1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f, -1.f, 1.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f, -1.f, -1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f, -1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f,  1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT(-1.f, -1.f,  1.f, 1.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f, -1.f,  1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f,  1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT(-1.f,  1.f, -1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT(-1.f, -1.f, -1.f, 1.f, 0.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f, -1.f, 0.f, 0.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f, -1.f, 0.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f,  1.f,  1.f, 1.f, 1.f));
	vVtxS.push_back(tagVertexPT( 1.f, -1.f,  1.f, 1.f, 0.f));

	// Å¥ºê ÀÎµ¦½º
	vIdxS.push_back(tagIndex( 0,  1,  2));
	vIdxS.push_back(tagIndex( 0,  2,  3));
	vIdxS.push_back(tagIndex( 4,  5,  6));
	vIdxS.push_back(tagIndex( 4,  6,  7));
	vIdxS.push_back(tagIndex( 8,  9, 10));
	vIdxS.push_back(tagIndex( 8, 10, 11));
	vIdxS.push_back(tagIndex(12, 13, 14));
	vIdxS.push_back(tagIndex(12, 14, 15));
	vIdxS.push_back(tagIndex(16, 17, 18));
	vIdxS.push_back(tagIndex(16, 18, 19));
	vIdxS.push_back(tagIndex(20, 21, 22));
	vIdxS.push_back(tagIndex(20, 22, 23));

	LPMESH pMesh = nullptr;

	D3DXCreateMeshFVF(vIdxS.size(), vVtxS.size(), D3DXMESH_SYSTEMMEM, tagVertexPT::FVF, DXDEV, &pMesh);

	tagVertexPT* pVtx = nullptr;
	pMesh->LockVertexBuffer(0, (void**)&pVtx);
	memcpy(pVtx, &vVtxS[0], sizeof(tagVertexPT) * vVtxS.size());
	pMesh->UnlockVertexBuffer();

	tagIndex* pIdx = nullptr;
	pMesh->LockIndexBuffer(0, (void**)&pIdx);
	memcpy(pIdx, &vIdxS[0], sizeof(tagIndex) * vIdxS.size());
	pMesh->UnlockIndexBuffer();

	DWORD* atr = nullptr;
	pMesh->LockAttributeBuffer(0, &atr);
	atr[0] = 0;
	atr[1] = 0;
	atr[2] = 1;
	atr[3] = 1;
	atr[4] = 2;
	atr[5] = 2;
	atr[6] = 3;
	atr[7] = 3;
	atr[8] = 4;
	atr[9] = 4;
	atr[10] = 5;
	atr[11] = 5;
	pMesh->UnlockAttributeBuffer();

	DWORD* adj = new DWORD[vIdxS.size() * 3];
	pMesh->GenerateAdjacency(0.0f, adj);

	pMesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_COMPACT | D3DXMESHOPT_VERTEXCACHE,
		adj, 0, 0, 0);
	delete[] adj;

	*pOut = pMesh;
}

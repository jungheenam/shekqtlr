#include "stdafx.h"
#include "P00_TestMesh.h"


P00_TestMesh::P00_TestMesh()
{
	_pMesh	 = nullptr;
	_nSubset = 0;
	
	for (int i = 0; i < 6; ++i) _pTex[i] = nullptr;
}


P00_TestMesh::~P00_TestMesh()
{
	this->Release();
}

HRESULT P00_TestMesh::Init()
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

	D3DXCreateMeshFVF(vIdxS.size(), vVtxS.size(), D3DXMESH_SYSTEMMEM, tagVertexPT::FVF, DXDEV, &_pMesh);

	tagVertexPT* pVtx = nullptr;
	_pMesh->LockVertexBuffer(0, (void**)&pVtx);
	memcpy(pVtx, &vVtxS[0], sizeof(tagVertexPT) * vVtxS.size());
	_pMesh->UnlockVertexBuffer();

	tagIndex* pIdx = nullptr;
	_pMesh->LockIndexBuffer(0, (void**)&pIdx);
	memcpy(pIdx, &vIdxS[0], sizeof(tagIndex) * vIdxS.size());
	_pMesh->UnlockIndexBuffer();

	DWORD* atr = nullptr;
	_pMesh->LockAttributeBuffer(0, &atr);
	atr[ 0] = 0;
	atr[ 1] = 0;
	atr[ 2] = 1;
	atr[ 3] = 1;
	atr[ 4] = 2;
	atr[ 5] = 2;
	atr[ 6] = 3;
	atr[ 7] = 3;
	atr[ 8] = 4;
	atr[ 9] = 4;
	atr[10] = 5;
	atr[11] = 5;
	_pMesh->UnlockAttributeBuffer();

	DWORD* adj = new DWORD[vIdxS.size() * 3];
	_pMesh->GenerateAdjacency(0.0f, adj);

	_pMesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_COMPACT | D3DXMESHOPT_VERTEXCACHE,
		adj, 0, 0, 0);
	delete[] adj;

	DWORD dSubset = 0;
	_pMesh->GetAttributeTable(0, &dSubset);

	_nSubset = dSubset;

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

void P00_TestMesh::Release()
{
	SAFE_RELEASE(_pMesh);
	for (int i = 0; i < 6; ++i) SAFE_RELEASE(_pTex[i]);
}

void P00_TestMesh::Update()
{
}

void P00_TestMesh::Render()
{
	DXDEV->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int i = 0; i < _nSubset; ++i)
	{
		DXDEV->SetTexture(0, _pTex[i]);
		_pMesh->DrawSubset(i);
	}
}

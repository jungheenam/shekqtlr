#pragma once
class P00_TestMeshData
{
public:
	struct tagGeometry
	{
		UINT	  nVtx;
		UINT	  nIdx;
		tagIndex* pIdx;

		tagGeometry()
		{
			nVtx = 0;
			nIdx = 0;
			pIdx = nullptr;
		}
		~tagGeometry()
		{
			SAFE_DELETE(pIdx);
		}
	};
private:
	LPTXUR		 _pTex[6];
	int			 _nGeo;
	tagGeometry* _pGeo;
	UINT		 _nVtx;
	UINT		 _dVtx;
	DWORD		 _dFVF;
	void*		 _pVtx;
public:
	P00_TestMeshData();
	~P00_TestMeshData();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	void MeshData(LPMESH* pOut);
};


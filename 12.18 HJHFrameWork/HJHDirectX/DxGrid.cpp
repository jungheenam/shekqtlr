#include "stdafx.h"
#include "DxGrid.h"


DxGrid::DxGrid()
{
}


DxGrid::~DxGrid()
{
}

HRESULT DxGrid::Init()
{
	int i, j;
	float fMax = 10000.0;
	_pLine = new tagVertexPC[(6 + 20 * 4) * 2];

	_pLine[0]  = tagVertexPC(-fMax, 0, 0, 0xFFFF0000);
	_pLine[1]  = tagVertexPC(	0, 0, 0, 0xFFFF0000);
	_pLine[2]  = tagVertexPC(	0, 0, 0, 0xFFFF0000);
	_pLine[3]  = tagVertexPC( fMax, 0, 0, 0xFFFF0000);

	_pLine[4]  = tagVertexPC(0, -fMax, 0, 0xFF00FF00);
	_pLine[5]  = tagVertexPC(0,	    0, 0, 0xFF00FF00);
	_pLine[6]  = tagVertexPC(0,	    0, 0, 0xFF00FF00);
	_pLine[7]  = tagVertexPC(0,  fMax, 0, 0xFF00FF00);

	_pLine[8]  = tagVertexPC(0, 0, -fMax, 0xFF0000FF);
	_pLine[9]  = tagVertexPC(0, 0,	   0, 0xFF0000FF);
	_pLine[10] = tagVertexPC(0, 0,	   0, 0xFF0000FF);
	_pLine[11] = tagVertexPC(0, 0,  fMax, 0xFF0000FF);

	j = 6 * 2;

	DWORD	d1 = 0xFF999999;
	DWORD	d2 = 0xFF555555;

	tagVertexPC* pLine = &_pLine[j];

	for (i = 0; i < 20; ++i)
	{
		pLine[8 * i + 0] = tagVertexPC(-100, 0, 5 * (i + 1), (i % 2) ? d1 : d2);
		pLine[8 * i + 1] = tagVertexPC(100, 0, 5 * (i + 1), (i % 2) ? d1 : d2);
		pLine[8 * i + 2] = tagVertexPC(-100, 0, -5 * (i + 1), (i % 2) ? d1 : d2);
		pLine[8 * i + 3] = tagVertexPC(100, 0, -5 * (i + 1), (i % 2) ? d1 : d2);
		pLine[8 * i + 4] = tagVertexPC(5 * (i + 1), 0, -100, (i % 2) ? d1 : d2);
		pLine[8 * i + 5] = tagVertexPC(5 * (i + 1), 0, 100, (i % 2) ? d1 : d2);
		pLine[8 * i + 6] = tagVertexPC(-5 * (i + 1), 0, -100, (i % 2) ? d1 : d2);
		pLine[8 * i + 7] = tagVertexPC(-5 * (i + 1), 0, 100, (i % 2) ? d1 : d2);
	}


	return S_OK;
}

void DxGrid::Release()
{
	SAFE_DELETE_ARRAY(_pLine);
}

void DxGrid::Update()
{
}

void DxGrid::Render()
{
	D3DXMATRIX mWorld;
	D3DXMatrixIdentity(&mWorld);
	DXDEV->SetTransform(D3DTS_WORLD, &mWorld);
	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetTexture(0, nullptr);
	DXDEV->SetFVF(tagVertexPC::FVF);
	DXDEV->DrawPrimitiveUP(D3DPT_LINELIST, 6 + 4 * 20, _pLine, sizeof(tagVertexPC));
}

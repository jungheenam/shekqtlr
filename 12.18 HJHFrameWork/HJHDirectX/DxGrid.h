#pragma once
class DxGrid
{
private:
	tagVertexPC* _pLine;
public:
	DxGrid();
	~DxGrid();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};
#pragma once
class DxLight
{
public:
	DxLight();
	~DxLight();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};

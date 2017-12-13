#pragma once
class GameNode
{
public:
	GameNode();
	virtual ~GameNode();
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ReleaseSingleton();
};


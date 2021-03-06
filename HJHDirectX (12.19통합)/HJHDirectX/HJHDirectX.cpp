#include "stdafx.h"
#include "HJHDirectX.h"
#include "MainGame.h"

HWND	  _hWnd;
HINSTANCE _hInstance;
MainGame  _mg;
float	  _fElapsedTime;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PTSTR lpCmdLine, _In_ int nCmdShow)
	{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HJHDIRECTX));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;//MAKEINTRESOURCE(IDI_HJHDIRECTX);
	wcex.lpszClassName = WINNAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	if (FAILED(RegisterClassEx(&wcex))) return E_FAIL;

	RECT rc = { 0, 0, WINSIZEX, WINSIZEY };
	AdjustWindowRect(&rc, (DWORD)WINSTYLE, FALSE);
	_hInstance = hInstance;

	_hWnd = CreateWindow
	(
		WINNAME, WINNAME, WINSTYLE, WINSTARTX, WINSTARTY,
		(rc.right - rc.left), (rc.bottom - rc.top),
		nullptr, nullptr, _hInstance, nullptr
	);
	if (!_hWnd) return E_FAIL;
	ShowWindow(_hWnd, nCmdShow);
	UpdateWindow(_hWnd);

	if (FAILED(_mg.Init())) return E_FAIL;

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			TIMER->Update();
			_mg.Update();
			_mg.Render();
		}
	}

	_mg.Release();

	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return _mg.WndProc(hWnd, uMsg, wParam, lParam);
}
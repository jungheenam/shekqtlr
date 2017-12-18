#include "stdafx.h"
#include "GameNode.h"

GameNode::GameNode()
{
}


GameNode::~GameNode()
{
}

HRESULT GameNode::Init()
{
	// Base
	DXM->Init();
	TIMER->Init();

	// Framework
	INPUTM->Init();
	CAM->Init();
	SCENEM->Init();
	FONTM->Init();

	// Memory Managed
	//OBJECTM->Init();
	//AUTORELEASE->Init();

	// 
	

	return S_OK;
}

void GameNode::Release()
{
	// Base
	DXM->Release();
	TIMER->Release();

	// Framework
	INPUTM->Release();
	CAM->Release();
	SCENEM->Release();
	TEXTUREM->Release();
	FONTM->Release();

	// Memory Managed
	//OBJECTM->Release();
	//AUTORELEASE->Release();

	//
	ITEM->Release();
	


	// Singleton Release
	this->ReleaseSingleton();
}

void GameNode::Update()
{
}

void GameNode::Render()
{
}

LRESULT GameNode::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	INPUTM->WndProc(hWnd, uMsg, wParam, lParam);
	CAM->WndProc(uMsg, wParam);
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN: switch (wParam)
	case VK_ESCAPE:
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

void GameNode::ReleaseSingleton()
{
	DXM->ReleaseSingleton();
	TIMER->ReleaseSingleton();
	INPUTM->ReleaseSingleton();
	CAM->ReleaseSingleton();
	SCENEM->ReleaseSingleton();
	//TEXTUREM->ReleaseSingleton();
	FONTM->ReleaseSingleton();
	//OBJECTM->ReleaseSingleton();
	//AUTORELEASE->ReleaseSingleton();
}

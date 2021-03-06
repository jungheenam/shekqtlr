#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comctl32.lib")


#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
//#include <mmsystem.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cassert>
#include <algorithm>
using namespace std;

#include "MacroFunction.h"
#include "DxTypedef.h"
#include "DxUtility.h"


#include "SingletonHeader.h"

#include "ClassHeader.h"

#include "GameNode.h"
#include "MainGame.h"

extern HWND		 _hWnd;
extern HINSTANCE _hInstance;
extern float _fElapsedTime;

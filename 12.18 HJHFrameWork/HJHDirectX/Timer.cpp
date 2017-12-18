#include "stdafx.h"
#include "Timer.h"


Timer::Timer() : _lFrameRate(0), _fWorldTime(0), _fElapsTime(0), _nLastTime(0)
{
}


Timer::~Timer()
{
}

HRESULT Timer::Init()
{
	__int64 nPeriodFrequency;

	if (QueryPerformanceFrequency((LARGE_INTEGER*)&nPeriodFrequency))
	{
		_bHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_nLastTime);
		_fTimeScale = 1.0f / nPeriodFrequency;
	}
	else
	{
		_bHardware = false;
		//_nLastTime = timeGetTime();
		_fTimeScale = 0.001f;
	}

	D3DXFONT_DESC hFont =
	{
		16,
		0,
		FW_NORMAL,
		1,
		FALSE,
		HANGUL_CHARSET,
		OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE,
		_T("¸¼Àº°íµñ")
	};
	if (FAILED(D3DXCreateFontIndirect(DXDEV, &hFont, &_pFont))) return E_FAIL;

	return S_OK;
}

void Timer::Release()
{
}

void Timer::Update()
{
	static __int64 nCurTime = 0;

	if (_bHardware) QueryPerformanceCounter((LARGE_INTEGER*)&nCurTime);
	//else			nCurTime = timeGetTime();

	_fElapsedTime = (nCurTime - _nLastTime) * _fTimeScale;

	while (_fElapsedTime < (1 / 60.0))
	{
		if (_bHardware) QueryPerformanceCounter((LARGE_INTEGER*)&nCurTime);
		//else		   nCurTime = timeGetTime();

		_fElapsedTime = (nCurTime - _nLastTime) * _fTimeScale;
	}

//	_fElapsedTime = _fElapsTime;

	_nLastTime = nCurTime;

	static int		nFpsCount = 0;
	static float	fFpsElaps = 0;

	nFpsCount += 1;
	fFpsElaps += _fElapsedTime;
	_fWorldTime += _fElapsedTime;

	if (fFpsElaps > 1)
	{
		_lFrameRate = nFpsCount;
		nFpsCount = 0;
		fFpsElaps = 0;
	}
}

void Timer::Render()
{
	TCHAR str[256];

	_stprintf(str, _T("World Time  : %f\n"), _fWorldTime);
	FONTM->DxDrawText(str, 6, 0, WINSIZEX, 30, D3DXCOLOR(1, 1, 0, 1));

	_stprintf(str, _T("Elapsed Time: %f\n"), _fElapsedTime);
	FONTM->DxDrawText(str, 6, 20, WINSIZEX, 30, D3DXCOLOR(1, 1, 0, 1));

	_stprintf(str, _T("FPS         : %d"), _lFrameRate);
	FONTM->DxDrawText(str, 6, 40, WINSIZEX, 30, D3DXCOLOR(1, 1, 0, 1));

}

#pragma once

#include "SingletonBase.h"
class Timer : public SingletonBase<Timer>
{
private:
	BOOL	_bHardware;
	__int64 _nLastTime;

	unsigned long _lFrameRate;
	float		  _fTimeScale;
	float		  _fElapsTime;
	float		  _fWorldTime;

	LPD3DXFONT _pFont;
public:
	Timer();
	~Timer();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	float GetElapsedTime() { return _fElapsTime; }
};

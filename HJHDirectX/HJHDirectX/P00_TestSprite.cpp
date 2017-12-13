#include "stdafx.h"
#include "P00_TestSprite.h"


P00_TestSprite::P00_TestSprite()
{
	_pSprite = NULL;

	_pTex[0] = NULL;
	_pTex[1] = NULL;
}


P00_TestSprite::~P00_TestSprite()
{
}

HRESULT P00_TestSprite::Init()
{

	TEXTUREM->Add(_T("Test1"), _T("Texture/P00_TestSprite/animate.bmp"), D3DX_FILTER_NONE, D3DXCOLOR(0, 0, 0, 1));
	//				키값			파일이름										색상제거			제거할색깔


	TEXTUREM->Add(_T("Test2"), _T("Texture/P00_TestSprite/Sprites.dds"), D3DX_FILTER_NONE);
	//				키값			파일이름										색상제거(이미 파일에 제거되있음)

	return S_OK;
}

void P00_TestSprite::Release()
{
	SAFE_RELEASE(_pD3DSprite);


	SAFE_DELETE(_pSprite);
}

void P00_TestSprite::Update()
{
}

void P00_TestSprite::Render()
{
	// 2D 애니메이션 
	static RECT rcDraw = { 0, 0, 0, 32 };
	static DWORD dTimeBgn = 0;// timeGetTime();
	DWORD dTimeEnd = 0;// timeGetTime();

	if (dTimeEnd - dTimeBgn > 12)
	{
		// 프레임 크기 32, 이미지크기 960
		rcDraw.left += 32;

		if (rcDraw.left + 32 >= 960) rcDraw.left = 0;

		rcDraw.right = rcDraw.left + 32;
		dTimeBgn = dTimeEnd;
	}

	VEC3 vPos = VEC3(2 * cosf(D3DX_PI * dTimeBgn * 0.0001f), sinf(D3DX_PI * dTimeBgn * 0.0003f), 0);

	vPos *= 100.0f;
	vPos += VEC3(300.0f, 300.0f, 0.0f);

	//									이미지부분, 좌표, 회전축,					회전각,	스케일안함, 덧칠할색 + 알파
	TEXTUREM->Find(_T("Test1"))->Render(&rcDraw, &vPos, &VEC2(vPos.x, vPos.y), D3DX_PI / 2, NULL, D3DXCOLOR(1, 1, 1, 0.8f));



	// 우주선
	RECT rc = { 128, 0, 256, 128 }; // 이미지 파일에서 가져올 이미지 부분을 선택
	VEC3 pos = VEC3(100, 100, 0);	// 이미지 깔 좌표

									//						이미지부분, 회전안해, 안한다구, 좌표, 덧칠할색 + 알파
	TEXTUREM->Find(_T("Test2"))->Render(&rc, &pos, NULL, 0.0f, NULL, D3DXCOLOR(1, 1, 1, 1.0f));


	pos.x = 200;
	//								이미지부분, 좌표, 회전축,						회전각, 스케일링(배수),		덧칠할컬러+알파
	TEXTUREM->Find(_T("Test2"))->Render(&rc, &pos, &VEC2(pos.x, pos.y), 0.0f, &VEC2(2.0f, 2.0f), D3DXCOLOR(1, 1, 1, 0.5f));

	//TEXTUREM->Find(_T("Test2"))->Render(&rc, &pos, &VEC2(pos.x + 164, pos.y + 64), D3DX_PI / 2, &VEC2(3.0f, 2.0f), D3DXCOLOR(1, 1, 1, 0.5f));

	//TEXTUREM->Find(_T("Test2"))->Render(&rc, &pos, &VEC2(pos.x + 264, pos.y + 64), D3DX_PI / 3, &VEC2(2.0f, 4.0f), D3DXCOLOR(1, 1, 1, 0.5f));

	//TEXTUREM->Find(_T("Test2"))->Render(&rc, &pos, &VEC2(pos.x + 364, pos.y + 64), D3DX_PI * 2, &VEC2(5.0f, 5.0f), D3DXCOLOR(1, 1, 1, 0.2f));
}

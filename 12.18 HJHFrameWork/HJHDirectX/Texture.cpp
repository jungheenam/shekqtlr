#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
	_pImageInfo = NULL;
}


Texture::~Texture()
{
}

HRESULT Texture::Init(TCHAR* sFilename, DWORD dFilter, DWORD dColor)
{
	if (sFilename == NULL) return E_FAIL;

	this->SpriteState();

	_pImageInfo = new tagImageInfo;
	_pImageInfo->dColor = dColor;
	_pImageInfo->pDrawRect = { 0, 0, 0, 0 };
	
	SAFE_RELEASE(_pImageInfo->pTexture);

	UINT uMipLevels = (dFilter == -1 ? -1 : 1);

	D3DXCreateTextureFromFileEx(DXDEV, sFilename, D3DX_DEFAULT, D3DX_DEFAULT, uMipLevels, 0
		, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, dFilter, dFilter, dColor, &_pImageInfo->pInfo, NULL, &_pImageInfo->pTexture);

	if (_pImageInfo->pTexture == NULL) return E_FAIL;

	D3DSURFACE_DESC dDesc;

	_pImageInfo->pTexture->GetLevelDesc(0, &dDesc);
	_pImageInfo->fW = (float)dDesc.Width;
	_pImageInfo->fH = (float)dDesc.Height;



	return S_OK;
}

void Texture::Release()
{
	SAFE_RELEASE(_pImageInfo->pTexture);
}

void Texture::Update()
{
}

void Texture::Render(const RECT* pDrawRect, const VEC3* vPosition, const VEC2* vAxis, float fAngle, const VEC2* vScaling, DWORD dColor)
{
	float fDrawL = 0;
	float fDrawT = 0;
	float fDrawW = WINSIZEX;
	float fDrawH = WINSIZEY;

	float fImageW = _pImageInfo->fW;
	float fImageH = _pImageInfo->fH;

	_pImageInfo->fAngle = fAngle;
	_pImageInfo->dColor = dColor;

	VEC2 aPos[4];
	VEC2 vRot(0, 0);

	VEC2		vPos(0, 0);
	D3DXCOLOR	dC = _pImageInfo->dColor;
	VEC2		v0(0, 0);
	VEC2		v1(1, 1);

	if (pDrawRect)
	{
		fDrawL = (float)pDrawRect->left;
		fDrawT = (float)pDrawRect->top;
		fDrawW = (float)(pDrawRect->right - pDrawRect->left);
		fDrawH = (float)(pDrawRect->bottom - pDrawRect->top);
	}

	v0.x = fDrawL / fImageW;
	v0.y = fDrawT / fImageH;

	v1.x = (fDrawL + fDrawW) / fImageW;
	v1.y = (fDrawT + fDrawH) / fImageH;

	if (vPosition)
	{
		aPos[0].x = vPosition->x;
		aPos[0].y = vPosition->y;
	}
	else
	{
		aPos[0].x = 0;
		aPos[0].y = 0;
	}

	if (vScaling == NULL)
	{
		aPos[1] = aPos[0] + VEC2(fDrawW, 0);
		aPos[2] = aPos[0] + VEC2(fDrawW, fDrawH);
		aPos[3] = aPos[0] + VEC2(0, fDrawH);
	}
	else
	{
		float fScaleX = vScaling->x;
		float fScaleY = vScaling->y;

		if (fScaleX >= 0)
		{
			aPos[1].x = aPos[0].x + fDrawW * fScaleX;
			aPos[2].x = aPos[1].x;
			aPos[3].x = aPos[0].x;
		}
		else
		{
			aPos[1].x = aPos[0].x;
			aPos[2].x = aPos[1].x;
			aPos[0].x = aPos[1].x - fDrawW * fScaleX;
			aPos[3].x = aPos[0].x;
		}

		if (fScaleY >= 0)
		{
			aPos[1].y = aPos[0].y;
			aPos[3].y = aPos[0].y + fDrawH * fScaleY;
			aPos[2].y = aPos[3].y;
		}
		else
		{
			aPos[3].y = aPos[0].y;
			aPos[2].y = aPos[3].y;
			aPos[0].y = aPos[3].y - fDrawH * fScaleY;
			aPos[1].y = aPos[0].y;
		}
	}

	if (vAxis)
	{
		VEC2 vAxi = *vAxis;
		VEC2 vDir = VEC2(0, 0);

		float fCos = cosf(_pImageInfo->fAngle);
		float fSin = sinf(_pImageInfo->fAngle);

		for (int i = 0; i < 4; ++i)
		{
			VEC2 vTrans = aPos[i] - vAxi;

			vDir.x =  vTrans.x * fCos + vTrans.y * fSin;
			vDir.y = -vTrans.x * fSin + vTrans.y * fCos;

			aPos[i] = vAxi + vDir;
		}
	}


	tagVertexRHWDT aVtx[4] =
	{
		{		   aPos[0].x,		   aPos[0].y, 0, 1, _pImageInfo->dColor, v0.x, v0.y },
		{		   aPos[1].x,		   aPos[1].y, 0, 1, _pImageInfo->dColor, v1.x, v0.y },
		{		   aPos[2].x,		   aPos[2].y, 0, 1, _pImageInfo->dColor, v1.x, v1.y },
		{		   aPos[3].x,		   aPos[3].y, 0, 1, _pImageInfo->dColor, v0.x, v1.y },
	};

	_pStateCurrent->Capture();
	_pStateSprite->Apply();

	DXDEV->SetTexture(0, _pImageInfo->pTexture);
	DXDEV->SetFVF(tagVertexRHWDT::FVF);
	DXDEV->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, aVtx, sizeof(tagVertexRHWDT));

	DXDEV->SetTexture(0, nullptr);
	_pStateCurrent->Apply();
}

void Texture::SpriteState()
{
	DWORD	vCur[128] = { 0 };

	DXDEV->GetRenderState(D3DRS_FOGENABLE, &vCur[0]);
	DXDEV->GetRenderState(D3DRS_LIGHTING, &vCur[1]);
	DXDEV->GetRenderState(D3DRS_ZENABLE, &vCur[2]);

	DXDEV->GetRenderState(D3DRS_ALPHATESTENABLE, &vCur[3]);
	DXDEV->GetRenderState(D3DRS_ALPHABLENDENABLE, &vCur[4]);
	DXDEV->GetRenderState(D3DRS_SRCBLEND, &vCur[5]);
	DXDEV->GetRenderState(D3DRS_DESTBLEND, &vCur[6]);

	DXDEV->GetSamplerState(0, D3DSAMP_MINFILTER, &vCur[7]);
	DXDEV->GetSamplerState(0, D3DSAMP_MAGFILTER, &vCur[8]);
	DXDEV->GetSamplerState(0, D3DSAMP_MIPFILTER, &vCur[9]);

	DXDEV->GetSamplerState(0, D3DSAMP_ADDRESSU, &vCur[10]);
	DXDEV->GetSamplerState(0, D3DSAMP_ADDRESSV, &vCur[11]);
	DXDEV->GetSamplerState(0, D3DSAMP_ADDRESSW, &vCur[12]);

	DXDEV->GetSamplerState(1, D3DSAMP_MINFILTER, &vCur[13]);
	DXDEV->GetSamplerState(1, D3DSAMP_MAGFILTER, &vCur[14]);
	DXDEV->GetSamplerState(1, D3DSAMP_MIPFILTER, &vCur[15]);

	DXDEV->GetSamplerState(1, D3DSAMP_ADDRESSU, &vCur[16]);
	DXDEV->GetSamplerState(1, D3DSAMP_ADDRESSV, &vCur[17]);
	DXDEV->GetSamplerState(1, D3DSAMP_ADDRESSW, &vCur[18]);

	DXDEV->GetTextureStageState(0, D3DTSS_COLORARG1, &vCur[19]);
	DXDEV->GetTextureStageState(0, D3DTSS_COLORARG2, &vCur[20]);
	DXDEV->GetTextureStageState(0, D3DTSS_COLOROP, &vCur[21]);

	DXDEV->GetTextureStageState(0, D3DTSS_ALPHAARG1, &vCur[22]);
	DXDEV->GetTextureStageState(0, D3DTSS_ALPHAARG2, &vCur[23]);
	DXDEV->GetTextureStageState(0, D3DTSS_ALPHAOP, &vCur[24]);

	DXDEV->GetTextureStageState(1, D3DTSS_COLORARG1, &vCur[25]);
	DXDEV->GetTextureStageState(1, D3DTSS_COLORARG2, &vCur[26]);
	DXDEV->GetTextureStageState(1, D3DTSS_COLOROP, &vCur[27]);

	DXDEV->GetTextureStageState(1, D3DTSS_ALPHAARG1, &vCur[28]);
	DXDEV->GetTextureStageState(1, D3DTSS_ALPHAARG2, &vCur[29]);
	DXDEV->GetTextureStageState(1, D3DTSS_ALPHAOP, &vCur[30]);


	DXDEV->BeginStateBlock();

	DXDEV->SetRenderState(D3DRS_FOGENABLE, FALSE);
	DXDEV->SetRenderState(D3DRS_LIGHTING, FALSE);
	DXDEV->SetRenderState(D3DRS_ZENABLE, FALSE);

	DXDEV->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DXDEV->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DXDEV->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_NONE);
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
	DXDEV->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(0, D3DSAMP_ADDRESSW, D3DTADDRESS_CLAMP);


	DXDEV->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_NONE);
	DXDEV->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
	DXDEV->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

	DXDEV->SetSamplerState(1, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(1, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
	DXDEV->SetSamplerState(1, D3DSAMP_ADDRESSW, D3DTADDRESS_CLAMP);


	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	DXDEV->EndStateBlock(&_pStateSprite);

	DXDEV->BeginStateBlock();
	DXDEV->SetRenderState(D3DRS_FOGENABLE, vCur[0]);
	DXDEV->SetRenderState(D3DRS_LIGHTING, vCur[1]);
	DXDEV->SetRenderState(D3DRS_ZENABLE, vCur[2]);

	DXDEV->SetRenderState(D3DRS_ALPHATESTENABLE, vCur[3]);
	DXDEV->SetRenderState(D3DRS_ALPHABLENDENABLE, vCur[4]);
	DXDEV->SetRenderState(D3DRS_SRCBLEND, vCur[5]);
	DXDEV->SetRenderState(D3DRS_DESTBLEND, vCur[6]);

	DXDEV->SetSamplerState(0, D3DSAMP_MINFILTER, vCur[7]);
	DXDEV->SetSamplerState(0, D3DSAMP_MAGFILTER, vCur[8]);
	DXDEV->SetSamplerState(1, D3DSAMP_MINFILTER, vCur[9]);
	DXDEV->SetSamplerState(1, D3DSAMP_MAGFILTER, vCur[10]);

	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG1, vCur[11]);
	DXDEV->SetTextureStageState(0, D3DTSS_COLORARG2, vCur[12]);
	DXDEV->SetTextureStageState(0, D3DTSS_COLOROP, vCur[13]);

	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAARG1, vCur[14]);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAARG2, vCur[15]);
	DXDEV->SetTextureStageState(0, D3DTSS_ALPHAOP, vCur[16]);

	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG1, vCur[17]);
	DXDEV->SetTextureStageState(1, D3DTSS_COLORARG2, vCur[18]);
	DXDEV->SetTextureStageState(1, D3DTSS_COLOROP, vCur[19]);

	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAARG1, vCur[20]);
	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAARG2, vCur[21]);
	DXDEV->SetTextureStageState(1, D3DTSS_ALPHAOP, vCur[22]);

	DXDEV->EndStateBlock(&_pStateCurrent);
}
